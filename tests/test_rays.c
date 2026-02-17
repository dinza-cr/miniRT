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

Test(ray, A_ray_intersects_a_sphere_at_two_points)
{
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersect xs = intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.xs[0].t == 4);
	cr_expect(xs.xs[1].t == 6);
}

Test(ray, A_ray_intersects_a_sphere_at_a_tangent)
{
	t_ray r = cons_ray(cons_point(0, 1, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersect xs = intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.xs[0].t == 5);
	cr_expect(xs.xs[0].t == 5);
}

Test(ray, A_ray_misses_a_sphere)
{
	t_ray	r = cons_ray(cons_point(0, 2, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersect xs = intersect(s, r);

	cr_expect(xs.count == 0);
}

Test(ray, A_ray_originates_inside_a_sphere)
{
	t_ray	r = cons_ray(cons_point(0, 0, 0), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersect xs = intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.xs[0].t == -1);
	cr_expect(xs.xs[1].t == 1);
}

Test(ray, A_sphere_is_behind_a_ray)
{
	t_ray	r = cons_ray(cons_point(0, 0, 5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersect xs = intersect(s, r);

	cr_expect(xs.count == 2);
}
