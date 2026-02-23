#include <criterion.h>
#include "../inc/minirt.h"

Test(ray, A_ray_intersects_a_sphere_at_two_points)
{
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersections xs = iop_intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.solutions[0].t == 4);
	cr_expect(xs.solutions[1].t == 6);
}

Test(ray, A_ray_intersects_a_sphere_at_a_tangent)
{
	t_ray r = cons_ray(cons_point(0, 1, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersections xs = iop_intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.solutions[0].t == 5);
	cr_expect(xs.solutions[0].t == 5);
}

Test(ray, A_ray_misses_a_sphere)
{
	t_ray	r = cons_ray(cons_point(0, 2, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersections xs = iop_intersect(s, r);

	cr_expect(xs.count == 0);
}

Test(ray, A_ray_originates_inside_a_sphere)
{
	t_ray	r = cons_ray(cons_point(0, 0, 0), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersections xs = iop_intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.solutions[0].t == -1);
	cr_expect(xs.solutions[1].t == 1);
}

Test(ray, A_sphere_is_behind_a_ray)
{
	t_ray	r = cons_ray(cons_point(0, 0, 5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersections xs = iop_intersect(s, r);

	cr_expect(xs.count == 2);
}


Test(inter, An_intersection_encapsulates_t_and_objec)
{
	t_sphere *s = init_sphere();
	t_intersection i;

	i = cons_intersection(3.5, s);

	cr_expect(i.t == 3.5);
	cr_expect(i.object == s);
}

Test(inter, Aggregating_intersections)
{
	t_sphere *s = init_sphere();
	t_intersection i1 = cons_intersection(1, s);
	t_intersection i2 = cons_intersection(2, s);
	t_intersection arr[2];
	arr[0] = i1;
	arr[1] = i2;

	t_intersections xs = iop_intersections(2, arr);

	cr_expect(xs.count == 2);
	cr_expect(xs.solutions[0].t == 1);
	cr_expect(xs.solutions[1].t == 2);
}

Test(inter, Intersect_sets_the_object_on_the_intersection)
{
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersections xs = iop_intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.solutions[0].object == s);
	cr_expect(xs.solutions[1].object == s);
}

Test(inter, Intersecting_a_scaled_sphere_with_a_ray)
{
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	set_transform(s, trsf_scaling(2, 2, 2));
	t_intersections xs = iop_intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.solutions[0].t == 3);
	cr_expect(xs.solutions[1].t == 7);
}

Test(inter, Intersecting_a_translated_sphere_with_a_ray)
{
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	set_transform(s, trsf_translation(5, 0, 0));
	t_intersections xs = iop_intersect(s, r);

	cr_expect(xs.count == 0);
}