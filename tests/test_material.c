#include <criterion.h>
#include "../inc/minirt.h"

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
	t_sphere *s = cons_sphere();

	cr_expect(cop_compare(s->m.color, cons_color(1, 1, 1)));
	cr_expect(s->m.ambient == 0.1);
	cr_expect(s->m.diffuse == 0.9);
	cr_expect(s->m.specular == 0.9);
	cr_expect(s->m.shininess == 200.0);
}

Test(material, A_sphere_may_be_assigned_a_material)
{
	t_sphere *s = cons_sphere();
	t_material m = init_material();
	m.ambient = 1;

	s->m = m;

	cr_expect(cop_compare(s->m.color, m.color));
	cr_expect(s->m.ambient == m.ambient);
	cr_expect(s->m.diffuse == m.diffuse);
	cr_expect(s->m.specular == m.specular);
	cr_expect(s->m.shininess == m.shininess);
}