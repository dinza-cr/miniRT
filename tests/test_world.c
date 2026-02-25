#include <criterion.h>
#include "../inc/minirt.h"

Test(world, Creating_a_world0)
{
	t_world *world;

	world = cons_world();

	cr_expect(world->spheres == NULL);
	cr_expect(world->planes == NULL);
	cr_expect(world->cylinders == NULL);
	cr_expect(world->has_ambient == 0);
	cr_expect(world->has_camera == 0);
	cr_expect(world->has_light == 0);
	dest_world(world);
}

Test(world, The_default_world)
{
	t_world *w = default_world();

	cr_expect(top_compare(w->L.coord, cons_point(-10, 10, -10)));
	cr_expect(cop_compare(w->L.color, cons_color(1, 1, 1)));
	cr_expect(w->spheres);
	cr_expect(w->spheres->next);
	cr_expect(!w->spheres->next->next);
}

Test(world, Intersect_a_world_with_a_ray)
{
	t_world *w = default_world();
	t_ray r = cons_ray(cons_point(0,0,-5), cons_vector(0, 0, 1));

	t_intersections xs = iop_intersect_world(w, r);

	cr_expect(xs.count == 4);
	cr_expect(xs.solutions[0].t == 4);
	cr_expect(xs.solutions[1].t == 4.5);
	cr_expect(xs.solutions[2].t == 5.5);
	cr_expect(xs.solutions[3].t == 6);
}

Test(world, Precomputing_the_state_of_an_intersection)
{
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 0, 1));
	t_sphere *shape = init_sphere();
	shape->radius = 1;
	t_intersection i = cons_intersection(4, shape);

	t_comps comps = cons_comps(i, r);

	cr_expect(comps.t == i.t);
	cr_expect(comps.s == i.object);
	cr_expect(top_compare(comps.point, cons_point(0, 0, -1)));
	cr_expect(top_compare(comps.eyev, cons_vector(0, 0, -1)));
	cr_expect(top_compare(comps.normalv, cons_vector(0, 0, -1)));
}

Test(world, The_hit_when_an_intersection_occurs_on_the_outside)
{
	t_ray r = cons_ray(cons_point(0, 0, -5), cons_vector(0, 0, 1));
	t_sphere *shape = init_sphere();
	shape->radius = 1;
	t_intersection i = cons_intersection(4, shape);

	t_comps comps = cons_comps(i, r);

	cr_expect(comps.inside == 0);
}

Test(world, The_hit_when_an_intersection_occurs_on_the_inside)
{
	t_ray r = cons_ray(cons_point(0, 0, 0), cons_vector(0, 0, 1));
	t_sphere *shape = init_sphere();
	shape->radius = 1;
	t_intersection i = cons_intersection(1, shape);

	t_comps comps = cons_comps(i, r);

	cr_expect(top_compare(comps.point, cons_point(0, 0, 1)));
	cr_expect(top_compare(comps.eyev, cons_vector(0, 0, -1)));
	cr_expect(comps.inside == 1);
	cr_expect(top_compare(comps.normalv, cons_vector(0, 0, -1)));
}
