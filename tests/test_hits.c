#include <criterion.h>
#include "../inc/minirt.h"

Test(hit, The_hit_when_all_intersections_have_positive_t)
{
	t_sphere *s = cons_sphere();
	t_intersection i1 = cons_intersection(1, s);
	t_intersection i2 = cons_intersection(2, s);
	t_intersection arr[2];
	arr[0] = i1;
	arr[1] = i2;
	t_intersections xs = iop_intersections(2, arr);

	double i = iop_hit(xs);

	cr_expect(i == i1.t);
}

Test(hit, The_hit_when_some_intersections_have_negative_t)
{
	t_sphere *s = cons_sphere();
	t_intersection i1 = cons_intersection(-1, s);
	t_intersection i2 = cons_intersection(1, s);
	t_intersection arr[2];
	arr[0] = i1;
	arr[1] = i2;
	t_intersections xs = iop_intersections(2, arr);

	double i = iop_hit(xs);

	cr_expect(i == i2.t);
}

Test(hit, The_hit_when_all_intersections_have_negative_t)
{
	t_sphere *s = cons_sphere();
	t_intersection i1 = cons_intersection(-2, s);
	t_intersection i2 = cons_intersection(-1, s);
	t_intersection arr[2];
	arr[0] = i1;
	arr[1] = i2;
	t_intersections xs = iop_intersections(2, arr);

	double i = iop_hit(xs);

	cr_expect(i == INFINITY);
}

Test(hit, The_hit_is_always_the_lowest_nonnegative_intersection)
{
	t_sphere *s = cons_sphere();
	t_intersection i1 = cons_intersection(5, s);
	t_intersection i2 = cons_intersection(7, s);
	t_intersection i3 = cons_intersection(-3, s);
	t_intersection i4 = cons_intersection(2, s);
	t_intersection arr[4];
	arr[0] = i1;
	arr[1] = i2;
	arr[2] = i3;
	arr[3] = i4;
	t_intersections xs = iop_intersections(4, arr);

	double i = iop_hit(xs);

	cr_expect(i == i4.t);
}