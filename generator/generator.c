/*
** anamorphic_cylinder.c
**
** Transforms an XPM image into its anamorphic version for a cylindrical mirror.
** When a reflective cylinder is placed at the center of the output image,
** the original image becomes visible in the reflection.
**
** Usage: ./anamorphic_cylinder <input.xpm> <output.xpm>
**        ./anamorphic_cylinder <input.xpm> <output.xpm> [cylinder_radius_ratio] [inner_radius_ratio]
**
** Compile: gcc -o anamorphic_cylinder anamorphic_cylinder.c -lm
**
** Parameters:
**   cylinder_radius_ratio : radius of the cylinder as fraction of half output size (default: 0.15)
**   inner_radius_ratio    : inner radius of drawn annulus as fraction (default: same as cylinder)
**
** Math:
**   Each pixel (src_x, src_y) of the source image maps to a polar position
**   in the output image around a center point.
**   - theta (angle) is derived from src_x (horizontal position → angle 0..2π)
**   - r (radius) is derived from src_y (vertical position → radius R..R_max)
**   The output pixel (dst_x, dst_y) = (cx + r*cos(theta), cy + r*sin(theta))
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_COLORS   4096
#define MAX_LINE     16384
#define MAX_DIM      4500

/* ─────────────────────────── XPM structures ──────────────────────────── */

typedef struct {
    char    key[8];     /* character(s) used in pixel data */
    int     r, g, b;   /* RGB color (0-255 each) */
    int     transparent;
} Color;

typedef struct {
    int     width;
    int     height;
    int     num_colors;
    int     chars_per_pixel;
    Color   palette[MAX_COLORS];
    int    *pixels;     /* flat array [height * width], index into palette */
} XpmImage;

/* ─────────────────────────── XPM parser ─────────────────────────────── */

static int hex_val(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}

static void parse_color(const char *spec, int *r, int *g, int *b, int *transparent)
{
    *transparent = 0;
    while (*spec == ' ' || *spec == '\t') spec++;

    /* "None" or "none" → transparent */
    if (strncasecmp(spec, "none", 4) == 0) {
        *r = *g = *b = 255;
        *transparent = 1;
        return;
    }

    /* #RRGGBB */
    if (*spec == '#') {
        spec++;
        int len = (int)strlen(spec);
        if (len >= 6) {
            *r = (hex_val(spec[0]) << 4) | hex_val(spec[1]);
            *g = (hex_val(spec[2]) << 4) | hex_val(spec[3]);
            *b = (hex_val(spec[4]) << 4) | hex_val(spec[5]);
        }
        return;
    }

    /* Named color fallback: white */
    *r = *g = *b = 255;
}

static char *next_xpm_string(FILE *fp, char *buf, int bufsz)
{
    int c;
    int in_str = 0;
    int i = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (!in_str) {
            if (c == '"') { in_str = 1; i = 0; }
        } else {
            if (c == '"') { buf[i] = '\0'; return buf; }
            if (i < bufsz - 1) buf[i++] = (char)c;
        }
    }
    return NULL;
}

static int load_xpm(const char *filename, XpmImage *img)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) { fprintf(stderr, "Cannot open %s\n", filename); return 0; }

    char buf[MAX_LINE];

    /* Skip until we find the first quoted string (header) */
    if (!next_xpm_string(fp, buf, MAX_LINE)) goto fail;

    /* Parse header: width height num_colors chars_per_pixel */
    if (sscanf(buf, "%d %d %d %d",
               &img->width, &img->height,
               &img->num_colors, &img->chars_per_pixel) != 4)
        goto fail;

    if (img->width <= 0 || img->height <= 0 ||
        img->width > MAX_DIM || img->height > MAX_DIM) {
        fprintf(stderr, "Image dimensions out of range: %dx%d\n",
                img->width, img->height);
        goto fail;
    }
    if (img->chars_per_pixel < 1 || img->chars_per_pixel > 4) {
        fprintf(stderr, "Unsupported chars_per_pixel: %d\n", img->chars_per_pixel);
        goto fail;
    }

    /* Parse color table */
    for (int i = 0; i < img->num_colors; i++) {
        if (!next_xpm_string(fp, buf, MAX_LINE)) goto fail;

        /* First chars_per_pixel characters are the key */
        memcpy(img->palette[i].key, buf, img->chars_per_pixel);
        img->palette[i].key[img->chars_per_pixel] = '\0';

        /* Find "c <colorspec>" */
        char *p = buf + img->chars_per_pixel;
        char *c_tok = NULL;
        while (*p) {
            while (*p == ' ' || *p == '\t') p++;
            if (*p == 'c' && (*(p+1) == ' ' || *(p+1) == '\t')) {
                c_tok = p + 2;
                break;
            }
            /* Skip this token */
            while (*p && *p != ' ' && *p != '\t') p++;
            /* Skip its value */
            while (*p == ' ' || *p == '\t') p++;
            while (*p && *p != ' ' && *p != '\t') p++;
        }

        if (c_tok) {
            parse_color(c_tok,
                        &img->palette[i].r,
                        &img->palette[i].g,
                        &img->palette[i].b,
                        &img->palette[i].transparent);
        } else {
            img->palette[i].r = img->palette[i].g = img->palette[i].b = 255;
            img->palette[i].transparent = 0;
        }
    }

    /* Allocate pixel buffer */
    img->pixels = (int *)calloc(img->width * img->height, sizeof(int));
    if (!img->pixels) { fprintf(stderr, "Out of memory\n"); goto fail; }

    /* Parse pixel rows */
    for (int row = 0; row < img->height; row++) {
        if (!next_xpm_string(fp, buf, MAX_LINE)) goto fail;
        for (int col = 0; col < img->width; col++) {
            char key[8] = {0};
            memcpy(key, buf + col * img->chars_per_pixel, img->chars_per_pixel);
            /* Find matching palette entry */
            int found = 0;
            for (int k = 0; k < img->num_colors; k++) {
                if (memcmp(img->palette[k].key, key, img->chars_per_pixel) == 0) {
                    img->pixels[row * img->width + col] = k;
                    found = 1;
                    break;
                }
            }
            if (!found) img->pixels[row * img->width + col] = 0;
        }
    }

    fclose(fp);
    return 1;
fail:
    fclose(fp);
    return 0;
}

/* ─────────────────────────── XPM writer ─────────────────────────────── */

/*
 * We reuse the exact palette from the source XPM (colors are already exact),
 * and add white (#FFFFFF) if it is not already present, for the background.
 * This avoids any color quantization: the output pixel indices map 1-to-1
 * back to the source palette entries.
 *
 * The output pixel buffer stores palette indices directly (not RGB), so
 * no color is ever approximated.
 */

/* Generate a 2-character key for a palette index (supports up to ~8000 colors) */
static void make_key(int idx, char *key)
{
    /* Use printable ASCII excluding '"' and '\' which would break XPM strings */
    const char charset[] =
        " !#$%&'()*+,-./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`"
        "abcdefghijklmnopqrstuvwxyz{|}~";
    int n = (int)strlen(charset);
    key[0] = charset[idx / n];
    key[1] = charset[idx % n];
    key[2] = '\0';
}

typedef struct {
    unsigned char r, g, b, a;  /* a=0 → transparent (unused, kept for clarity) */
} Pixel;

/*
 * save_xpm_indexed: write an XPM using the source palette directly.
 *
 * pixel_indices : flat array [height * width] of indices into src->palette.
 *                 The special value WHITE_IDX means "white background pixel".
 * white_pal_idx : index in src->palette that is white, or src->num_colors
 *                 if white was added as an extra entry.
 */
static int save_xpm_indexed(const char *filename,
                             const int *pixel_indices,
                             int width, int height,
                             const XpmImage *src,
                             int white_pal_idx)
{
    /* Total palette = source colors + possibly 1 extra white */
    int total_pal = (white_pal_idx < src->num_colors)
                    ? src->num_colors          /* white already in palette */
                    : src->num_colors + 1;     /* white added as extra */

    FILE *fp = fopen(filename, "w");
    if (!fp) { fprintf(stderr, "Cannot write %s\n", filename); return 0; }

    fprintf(fp, "/* XPM */\n");
    fprintf(fp, "static char *xpm[] = {\n");
    fprintf(fp, "/* width height ncolors cpp */\n");
    fprintf(fp, "\"%d %d %d 2\",\n", width, height, total_pal);

    /* Write palette: source colors first */
    char key[3];
    for (int i = 0; i < src->num_colors; i++) {
        make_key(i, key);
        if (src->palette[i].transparent)
            fprintf(fp, "\"%s c #FFFFFF\",\n", key); /* treat src-transparent as white */
        else
            fprintf(fp, "\"%s c #%02X%02X%02X\",\n", key,
                    src->palette[i].r, src->palette[i].g, src->palette[i].b);
    }
    /* Extra white entry if needed */
    if (white_pal_idx >= src->num_colors) {
        make_key(white_pal_idx, key);
        fprintf(fp, "\"%s c #FFFFFF\",\n", key);
    }

    /* Write pixel rows */
    for (int row = 0; row < height; row++) {
        fprintf(fp, "\"");
        for (int col = 0; col < width; col++) {
            make_key(pixel_indices[row * width + col], key);
            fprintf(fp, "%s", key);
        }
        if (row < height - 1)
            fprintf(fp, "\",\n");
        else
            fprintf(fp, "\"\n");
    }

    fprintf(fp, "};\n");
    fclose(fp);
    return 1;
}

/* ─────────────────────────── Anamorphic transform ───────────────────── */

/*
 * Cylindrical mirror anamorphosis:
 *
 * Returns a flat array of palette indices [out_size * out_size].
 * Indices 0..src->num_colors-1 map directly to src->palette.
 * *white_pal_idx_out receives the index to use for white background pixels:
 *   - if white already exists in src->palette, its index is returned
 *   - otherwise src->num_colors is returned (caller adds an extra entry)
 *
 * No RGB conversion happens here — colors are preserved exactly.
 *
 * Mapping for each output pixel:
 *   dx = col - cx,  dy = row - cy
 *   r     = sqrt(dx^2 + dy^2)
 *   theta = atan2(dy, dx)                        in [-pi, pi]
 *   t     = (r - R_inner) / (R_outer - R_inner)  in [0, 1]
 *   norm  = (theta + pi) / (2*pi)                in [0, 1]
 *   src_x = norm  * (src_w - 1)
 *   src_y = (1-t) * (src_h - 1)   <- (1-t) flips image for mirror
 */
static int *transform_anamorphic(const XpmImage *src,
                                 int out_size,
                                 double cylinder_ratio,
                                 double outer_ratio,
                                 int *white_pal_idx_out)
{
    /* Find or reserve white palette index */
    int white_idx = src->num_colors; /* default: extra entry */
    for (int i = 0; i < src->num_colors; i++) {
        if (!src->palette[i].transparent &&
            src->palette[i].r == 255 &&
            src->palette[i].g == 255 &&
            src->palette[i].b == 255) {
            white_idx = i;
            break;
        }
    }
    *white_pal_idx_out = white_idx;

    int *out = (int *)malloc(out_size * out_size * sizeof(int));
    if (!out) { fprintf(stderr, "Out of memory for output buffer\n"); return NULL; }

    double cx = out_size / 2.0;
    double cy = out_size / 2.0;
    double R_inner = cylinder_ratio * out_size / 2.0;
    double R_outer = outer_ratio  * out_size / 2.0;

    for (int row = 0; row < out_size; row++) {
        for (int col = 0; col < out_size; col++) {
            double dx = col - cx;
            double dy = row - cy;
            double r  = sqrt(dx * dx + dy * dy);

            /* Outside annulus → white background */
            if (r < R_inner || r > R_outer) {
                out[row * out_size + col] = white_idx;
                continue;
            }

            /* Subtract pi/2: top of source image maps to North (12h) in the annulus
            /* Subtract pi/2: top of source image maps to North (12 o'clock) */
            /* atan2(dy,dx) at North = -pi/2; +pi/2 shifts it to 0 => norm=0.5 (center of source) */
            double theta = atan2(dy, dx) - M_PI / 2.0;
            if (theta > M_PI)  theta -= 2.0 * M_PI;
            if (theta < -M_PI) theta += 2.0 * M_PI;
            double t    = (r - R_inner) / (R_outer - R_inner); /* [0,1]: 0=inner,1=outer */
            double norm = (theta + M_PI) / (2.0 * M_PI);       /* [0,1]: angle→horizontal */

            int src_x = (int)(norm * (src->width  - 1) + 0.5);
            /* (1 - t): flips vertically so the image is right-side up in the mirror */
            int src_y = (int)((1.0 - t) * (src->height - 1) + 0.5);

            src_x = src_x < 0 ? 0 : (src_x >= src->width  ? src->width  - 1 : src_x);
            src_y = src_y < 0 ? 0 : (src_y >= src->height ? src->height - 1 : src_y);

            int pal_idx = src->pixels[src_y * src->width + src_x];

            /* Transparent source pixel → white background */
            if (src->palette[pal_idx].transparent)
                out[row * out_size + col] = white_idx;
            else
                out[row * out_size + col] = pal_idx;
        }
    }
    return out;
}

/* ─────────────────────────── main ──────────────────────────────────── */

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr,
            "Usage: %s <input.xpm> <output.xpm> [cylinder_ratio] [outer_ratio]\n"
            "\n"
            "  cylinder_ratio : radius of mirror cylinder / (half output size)  [default 0.15]\n"
            "  outer_ratio    : outer radius of anamorphic ring / (half output size) [default 0.90]\n"
            "\n"
            "Example:\n"
            "  %s face.xpm face_anamorphic.xpm 0.15 0.85\n",
            argv[0], argv[0]);
        return 1;
    }

    double cylinder_ratio = 0.15;
    double outer_ratio    = 0.90;

    if (argc >= 4) cylinder_ratio = atof(argv[3]);
    if (argc >= 5) outer_ratio    = atof(argv[4]);

    if (cylinder_ratio <= 0.0 || cylinder_ratio >= 1.0) {
        fprintf(stderr, "cylinder_ratio must be in (0, 1)\n"); return 1;
    }
    if (outer_ratio <= cylinder_ratio || outer_ratio > 1.0) {
        fprintf(stderr, "outer_ratio must be in (cylinder_ratio, 1]\n"); return 1;
    }

    /* Load source */
    XpmImage src;
    memset(&src, 0, sizeof(src));
    printf("Loading %s ...\n", argv[1]);
    if (!load_xpm(argv[1], &src)) return 1;
    printf("  Loaded: %d × %d, %d colors, %d cpp\n",
           src.width, src.height, src.num_colors, src.chars_per_pixel);

    /* Determine output size: use max dimension, rounded to even */
    int out_size = (src.width > src.height ? src.width : src.height);
    if (out_size < 256) out_size = 256;
    if (out_size % 2) out_size++;

    printf("Output size: %d × %d\n", out_size, out_size);
    printf("Cylinder radius : %.1f px (ratio %.2f)\n",
           cylinder_ratio * out_size / 2.0, cylinder_ratio);
    printf("Outer radius    : %.1f px (ratio %.2f)\n",
           outer_ratio * out_size / 2.0, outer_ratio);

    /* Transform — returns palette indices, no RGB conversion */
    printf("Computing anamorphic transform...\n");
    int white_pal_idx;
    int *out_buf = transform_anamorphic(&src, out_size, cylinder_ratio, outer_ratio,
                                        &white_pal_idx);
    if (!out_buf) { free(src.pixels); return 1; }

    /* Save — reuses source palette exactly, zero color loss */
    printf("Saving %s ...\n", argv[2]);
    if (!save_xpm_indexed(argv[2], out_buf, out_size, out_size, &src, white_pal_idx)) {
        free(src.pixels); free(out_buf); return 1;
    }

    printf("Done. Place a reflective cylinder of radius %.0f px at the\n"
           "center of the output image to see the original image restored.\n",
           cylinder_ratio * out_size / 2.0);

    free(src.pixels);
    free(out_buf);
    return 0;
}