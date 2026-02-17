#include <criterion.h>
#include "../inc/minirt.h"

Test(hit, The_hit_when_all_intersections_have_positive_t)
{
	t_sphere *s = cons_sphere();
	s->radius =1;
	t_intersection i1 = intersection(1, s);
	t_intersection i2 = intersection(2, s);

	t_intersect xs = intersections(i2, i1);

	double i = hit(xs);

	cr_expect(i == i1);
}

Test(hit, The_hit_when_some_intersections_have_negative_t)
{
	t_sphere *s = cons_sphere();
	s->radius =1;
	t_intersection i1 = intersection(-1, s);
	t_intersection i2 = intersection(1, s);

	t_intersect xs = intersections(i2, i1);

	double i = hit(xs);

	cr_expect(i == i2);
}

Test(hit, The_hit_when_all_intersections_have_negative_t)
{
	t_sphere *s = cons_sphere();
	s->radius =1;
	t_intersection i1 = intersection(-2, s);
	t_intersection i2 = intersection(-1, s);

	t_intersect xs = intersections(i2, i1);

	double i = hit(xs);

	cr_expect(i == i2);
}