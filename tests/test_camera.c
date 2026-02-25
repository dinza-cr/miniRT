#include <criterion.h>
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