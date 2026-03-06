// #include <criterion/criterion.h>
#include <criterion.h>
#include "../inc/minirt.h"


Test(colors, colors0)
{
	t_color c;

	c = cons_color(-0.5, 0.4, 1.7);

	cr_expect(c.r == -0.5);
	cr_expect(c.g == 0.4);
	cr_expect(c.b == 1.7);
}

Test(colors, colors1)
{
	t_color c1 = cons_color(0.9, 0.6, 0.75);
	t_color c2 = cons_color(0.7, 0.1, 0.25);

	t_color res = cop_add(c1, c2);

	cr_expect(res.r == 1.6);
	cr_expect(res.g == 0.7);
	cr_expect(res.b == 1.0);
}

Test(colors, colors2)
{
	t_color c1 = cons_color(0.9, 0.6, 0.75);
	t_color c2 = cons_color(0.7, 0.1, 0.25);
	
	t_color res = cop_subs(c1, c2);

	cr_expect(res.r - 0.2 < EPSILON);
	cr_expect(res.g == 0.5);
	cr_expect(res.b == 0.5);
}

Test(colors, colors3)
{
	t_color c1 = cons_color(0.2, 0.3, 0.4);

	t_color res = cop_multi(c1, 2);

	cr_expect(res.r == 0.4);
	cr_expect(res.g == 0.6);
	cr_expect(res.b == 0.8);
}

Test(colors, colors4)
{
	t_color c1 = cons_color(1, 0.2, 0.4);
	t_color c2 = cons_color(0.9, 1, 0.1);
	
	t_color res = cop_blend(c1, c2);

	cr_expect(res.r == 0.9);
	cr_expect(res.g == 0.2);
	cr_expect(res.b - 0.04 < EPSILON);
}

Test(canvas, canvas0)
{
	t_canva *c = cons_canva(10, 20);

	for(int i = 0; i < 10 * 20; i++)
	{
		cr_expect(c->pixels->r == 0);
		cr_expect(c->pixels->g == 0);
		cr_expect(c->pixels->b == 0);
	}
}

Test(shading, Shading_an_intersection)
{
	t_world *w = default_world();
	t_ray	r = cons_ray(cons_point(0,0,-5), cons_vector(0, 0, 1));
	t_shape *s = w->shapes;
	t_intersection	i = cons_intersection(4.0, s);

	t_comps comps = cons_comps(i, r);
	t_color c = cop_shade_hit(w, comps);

	cr_expect(cop_compare(c, cons_color(0.38066, 0.47583, 0.2855)));
}

Test(shading, Shading_an_intersection_from_the_inside)
{
	t_world *w = default_world();
	w->L = cons_light(cons_point(0, 0.25, 0), cons_color(1, 1, 1));
	t_ray	r = cons_ray(cons_point(0,0,0), cons_vector(0, 0, 1));
	t_shape *s = w->shapes->next;
	t_intersection	i = cons_intersection(0.5, s);

	t_comps comps = cons_comps(i, r);
	t_color c = cop_shade_hit(w, comps);

	cr_expect(cop_compare(c, cons_color(0.90498, 0.90498, 0.90498)));
}