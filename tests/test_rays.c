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

	cr_expect(top_compare( position(r, 0), cons_point(2, 3, 4)));
	cr_expect(top_compare( position(r, 1), cons_point(3, 3, 4)));
	cr_expect(top_compare( position(r, -1), cons_point(1, 3, 4)));
	cr_expect(top_compare( position(r, 2.5), cons_point(4.5, 3, 4)));
}

