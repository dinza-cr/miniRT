#include <criterion/criterion.h>
// #include <criterion.h>
#include "../inc/minirt.h"

Test(camera, Constructing_a_camera)
{
	int hsize = 160;
	int vsize = 120;
	double field_of_view = PI/2;

	t_camera c = cons_camera(hsize, vsize, field_of_view);

	cr_expect(c.hsize == 160);
	cr_expect(c.vsize == 120);
	cr_expect(c.field_of_view == PI/2);
	cr_expect(mop_compare(c.transform, cons_idmatrix()));
}

Test(camera, The_pixel_size_for_a_horizontal_canvas)
{
	t_camera c = cons_camera(200, 125, PI/2);

	cr_expect(c.pixel_size - 0.01 <= EPSILON);
}

Test(camera, The_pixel_size_for_a_vertical_canvas)
{
	t_camera c = cons_camera(125, 200, PI/2);

	cr_expect(c.pixel_size - 0.01 <= EPSILON);
}

Test(camera, Constructing_a_ray_through_the_center_of_the_canvas)
{
	t_camera c = cons_camera(201, 101, PI/2);

	t_ray r = ray_for_pixel(c, 100, 50);

	cr_expect(top_compare(r.origin, cons_point(0, 0, 0)));
	cr_expect(top_compare(r.direction, cons_vector(0, 0, -1)));
}

Test(camera, Constructing_a_ray_through_a_corner_of_the_canvas)
{
	t_camera c = cons_camera(201, 101, PI/2);

	t_ray r = ray_for_pixel(c, 0, 0);

	cr_expect(top_compare(r.origin, cons_point(0, 0, 0)));
	cr_expect(top_compare(r.direction, cons_vector(0.66519, 0.33259, -0.66851)));
}

Test(camera, Constructing_a_ray_when_the_camera_is_transformed)
{
	t_camera c = cons_camera(201, 101, PI/2);

	c.transform = mop_multimat(trsf_roty(PI/4), trsf_translation(0, -2, 5));
	t_ray r = ray_for_pixel(c, 100, 50);

	cr_expect(top_compare(r.origin, cons_point(0, 2, -5)));
	cr_expect(top_compare(r.direction, cons_vector(sqrt(2)/2, 0, -sqrt(2)/2)));
}

Test(camera, The_color_when_a_ray_misses)
{
	t_world *w = default_world();
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 1, 0));

	t_color c = color_at(w, r);

	cr_expect(cop_compare(c, cons_color(0, 0, 0)));
}

Test(camera, The_color_with_an_intersection_behind_the_ray)
{
	t_world *w = default_world();
	t_shape *outer = w->shapes;
	outer->material.ambient = 1;
	t_shape *inner = w->shapes->next;
	inner->material.ambient = 1;
	t_ray r = cons_ray(cons_point(0, 0, 0.75), cons_vector(0, 0, -1));

	t_color c = color_at(w, r);

	cr_expect(cop_compare(c, inner->material.color));
}