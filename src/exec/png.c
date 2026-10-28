#include "minirt.h"
#include <stdint.h>
#include <zlib.h>

static void	store_u32(unsigned char *dst, uint32_t value)
{
	dst[0] = value >> 24;
	dst[1] = value >> 16;
	dst[2] = value >> 8;
	dst[3] = value;
}

static int	write_chunk(FILE *file, const char *type,
		const unsigned char *data, uint32_t size)
{
	unsigned char	bytes[4];
	uLong			crc;

	store_u32(bytes, size);
	if (fwrite(bytes, 1, 4, file) != 4
		|| fwrite(type, 1, 4, file) != 4)
		return (0);
	crc = crc32(0, (const Bytef *)type, 4);
	if (size)
	{
		if (fwrite(data, 1, size, file) != size)
			return (0);
		crc = crc32(crc, data, size);
	}
	store_u32(bytes, crc);
	return (fwrite(bytes, 1, 4, file) == 4);
}

static unsigned char	*png_pixels(t_canva *canva, size_t stride)
{
	unsigned char	*raw;
	unsigned char	*pixel;
	int				x;
	int				y;
	size_t			i;

	raw = ft_calloc(canva->height, stride);
	if (!raw)
		return (NULL);
	y = -1;
	while (++y < canva->height)
	{
		x = -1;
		while (++x < canva->width)
		{
			i = (size_t)y * canva->width + x;
			pixel = raw + y * stride + 1 + 4 * x;
			pixel[0] = ft_convertcolor(canva->pixels[i].r);
			pixel[1] = ft_convertcolor(canva->pixels[i].g);
			pixel[2] = ft_convertcolor(canva->pixels[i].b);
			pixel[3] = canva->alpha[i];
		}
	}
	return (raw);
}

static int	png_file(t_canva *canva, unsigned char *data, uLongf size)
{
	FILE			*file;
	unsigned char	header[13];
	int				ok;

	file = fopen("canva.png", "wb");
	if (!file)
		return (perror("canva.png"), 0);
	ft_bzero(header, sizeof(header));
	store_u32(header, canva->width);
	store_u32(header + 4, canva->height);
	header[8] = 8;
	header[9] = 6;
	ok = (fwrite("\211PNG\r\n\032\n", 1, 8, file) == 8
			&& write_chunk(file, "IHDR", header, 13)
			&& write_chunk(file, "IDAT", data, size)
			&& write_chunk(file, "IEND", NULL, 0));
	if (fclose(file) != 0)
		ok = 0;
	if (!ok)
		ft_putendl_fd("Error: could not write canva.png", 2);
	return (ok);
}

int	canvas_to_png(t_canva *canva)
{
	unsigned char	*raw;
	unsigned char	*compressed;
	size_t			length;
	uLongf			size;
	int				ok;

	if (!canva || canva->width <= 0 || canva->height <= 0)
		return (0);
	length = ((size_t)canva->width * 4 + 1) * canva->height;
	raw = png_pixels(canva, (size_t)canva->width * 4 + 1);
	size = compressBound(length);
	compressed = malloc(size);
	if (!raw || !compressed)
		return (free(raw), free(compressed),
			ft_putendl_fd("Error: PNG allocation failed", 2), 0);
	ok = (compress2(compressed, &size, raw, length, Z_DEFAULT_COMPRESSION)
			== Z_OK);
	if (ok && size <= UINT32_MAX)
		ok = png_file(canva, compressed, size);
	else
		ok = (ft_putendl_fd("Error: PNG compression failed", 2), 0);
	free(raw);
	free(compressed);
	return (ok);
}
