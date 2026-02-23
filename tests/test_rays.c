#include <criterion.h>
#include "../inc/minirt.h"

Test(ray, Creating_and_querying_a_ray)
{
	t_tuple origin = cons_point(1, 2, 3);
	t_tuple direction = cons_vector(4, 5, 6);

	t_ray r = cons_ray(origin, direction);

	cr_expect(top_compare(r.origin, origin));
	cr_expect(top_compare(r.direction, direction));
}

Test(ray, Computing_a_point_from_a_distance)
{
	t_ray r = cons_ray(cons_point(2, 3, 4), cons_vector(1, 0, 0));

	cr_expect(top_compare( rop_position(r, 0), cons_point(2, 3, 4)));
	cr_expect(top_compare( rop_position(r, 1), cons_point(3, 3, 4)));
	cr_expect(top_compare( rop_position(r, -1), cons_point(1, 3, 4)));
	cr_expect(top_compare( rop_position(r, 2.5), cons_point(4.5, 3, 4)));
}

Test(ray, Translating_a_ray)
{
	t_ray r = cons_ray(cons_point(1, 2, 3), cons_vector(0, 1, 0));
	t_matrix m = trsf_translation(3, 4, 5);

	t_ray r2 = rop_transform(r, m);

	cr_expect(top_compare(r2.origin, cons_point(4, 6, 8)));
	cr_expect(top_compare(r2.direction, cons_vector(0, 1, 0)));
}

Test(ray, Scaling_a_ray)
{
	t_ray r = cons_ray(cons_point(1, 2, 3), cons_vector(0, 1, 0));
	t_matrix m = trsf_scaling(2, 3, 4);

	t_ray r2 = rop_transform(r, m);

	cr_expect(top_compare(r2.origin, cons_point(2, 6, 12)));
	cr_expect(top_compare(r2.direction, cons_vector(0, 3, 0)));
}