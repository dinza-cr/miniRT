// #include <criterion.h>
// #include "../inc/minirt.h"

// Test(ray, Creating_and_querying_a_ray)
// {
// 	t_tuple origin = cons_point(1, 2, 3);
// 	t_tuple direction = cons_vector(4, 5, 6);

// 	// ray(origin, direction)

// 	cr_expect(r.origin == origin);
// 	cr_expect(r.direction == direction);
// }

// Test(ray, Computing_a_point_from_a_distance)
// {
// 	//ray(point(2, 3, 4), vector(1, 0, 0))

// 	cr_expect(top_compare(/*position(r, 0)*/, cons_point(2, 3, 4)));
// 	cr_expect(top_compare(/*position(r, 1)*/, cons_point(3, 3, 4)));
// 	cr_expect(top_compare(/*position(r, -1)*/, cons_point(1, 3, 4)));
// 	cr_expect(top_compare(/*position(r, 2.5)*/, cons_point(4.5, 3, 4)));
// }

// Test(ray, A_ray_intersects_a sphere_at_two_points)
// {
// 	// r ← ray(point(0, 0, -5), vector(0, 0, 1))
// 	t_sphere *s = init_sphere();
// 	s->diameter = 1;

// 	// xs ← intersect(s, r)

// 	cr_expect(xs.count == 2);
// 	cr_expect(xs.t0 == 4);
// 	cr_expect(xs.t1 == 6);
// }

// Test(ray, A_ray_intersects_a_sphere_at_a_tangent)
// {
// 	// r ← ray(point(0, 1, -5), vector(0, 0, 1))
// 	t_sphere *s = init_sphere();
// 	s->diameter = 1;

// 	// xs ← intersect(s, r)

// 	cr_expect(xs.count == 2);
// 	cr_expect(xs.t0 == 5);
// 	cr_expect(xs.t1 == 5);
// }

// Test(ray, A_ray_misses_a_sphere)
// {
// 	// r ← ray(point(0, 2, -5), vector(0, 0, 1))
// 	t_sphere *s = init_sphere();
// 	s->diameter = 1;

// 	// xs ← intersect(s, r)

// 	cr_expect(xs.count == 0);
// }

// Test(ray, A_ray_originates_inside_a_sphere)
// {
// 	// r ← ray(point(0, 0, 0), vector(0, 0, 1))
// 	t_sphere *s = init_sphere();
// 	s->diameter = 1;

// 	// xs ← intersect(s, r)

// 	cr_expect(xs.count == 2);
// 	cr_expect(xs.t0 == -1);
// 	cr_expect(xs.t1 == 1);
// }

// Test(ray, A_sphere_is_behind_a_ray)
// {
// 	// r ← ray(point(0, 0, 5), vector(0, 0, 1))
// 	t_sphere *s = init_sphere();
// 	s->diameter = 1;

// 	// xs ← intersect(s, r)

// 	cr_expect(xs.count == 2);
// 	cr_expect(xs.t0 == -6);
// 	cr_expect(xs.t1 == -4);
// }

// Test(ray, An_intersection_encapsulates_t_and_objec)
// {
// 	t_sphere *s = init_sphere();
// 	s->diameter = 1;

// 	//i ← intersection(3.5, s)

// 	cr_expect(i.t == 3.5);
// 	cr_expect(i.object == s);
// }
