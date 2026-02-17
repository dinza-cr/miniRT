#include <criterion.h>
#include "../inc/minirt.h"

Test(inter, An_intersection_encapsulates_t_and_objec)
{
	t_sphere *s = init_sphere();
	t_intersection i;

	i = intersection(3.5, s);

	cr_expect(i.t == 3.5);
	cr_expect(i.object == s);
}

Test(inter, Aggregating_intersections)
{
	t_sphere *s = init_sphere();
	t_intersection i1 = intersection(1, s);
	t_intersection i2 = intersection(2, s);

	t_intersect xs = intersections(i1, i2);

	cr_expect(xs.count == 2);
	cr_expect(xs.xs[0].t == 1);
	cr_expect(xs.xs[1].t == 2);
	cr_expect (xs.xs[0].object = s);
	cr_expect (xs.xs[1].object = s);
}

Test(inter, Intersect_sets_the_object_on_the_intersection)
{
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 0, 1));
	t_sphere *s = init_sphere();
	s->radius = 1;

	t_intersect xs = intersect(s, r);

	cr_expect(xs.count == 2);
	cr_expect(xs.xs[0].object == s);
	cr_expect(xs.xs[1].object == s);
}