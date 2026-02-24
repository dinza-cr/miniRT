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