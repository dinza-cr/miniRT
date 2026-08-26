#include <criterion/criterion.h>
#include "minirt.h"

Test(material, The_default_material)
{
	t_material m = init_material();

	cr_expect(cop_compare(m.color, cons_color(1, 1, 1)));
	cr_expect(m.ambient == 0.1);
	cr_expect(m.diffuse == 0.9);
	cr_expect(m.specular == 0.9);
	cr_expect(m.shininess == 200.0);
}

Test(material, A_sphere_has_a_default_material)
{
	t_shape *s = cons_shape();


	cr_expect(cop_compare(s->material.color, cons_color(1, 1, 1)));
	cr_expect(s->material.ambient == 0.1);
	cr_expect(s->material.diffuse == 0.9);
	cr_expect(s->material.specular == 0.9);
	cr_expect(s->material.shininess == 200.0);
}

Test(material, A_sphere_may_be_assigned_a_material)
{
	t_shape *s = cons_shape();

	t_material m = init_material();
	m.ambient = 1;

	s->material = m;

	cr_expect(cop_compare(s->material.color, m.color));
	cr_expect(s->material.ambient == m.ambient);
	cr_expect(s->material.diffuse == m.diffuse);
	cr_expect(s->material.specular == m.specular);
	cr_expect(s->material.shininess == m.shininess);
}