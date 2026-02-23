#include <criterion.h>
#include "../inc/minirt.h"

Test(sphere, A_sphere_s_default_transformation)
{
	t_sphere *s = init_sphere();

	cr_expect(mop_compare(s->transform, cons_idmatrix()));
}

Test(sphere, Changing_a_sphere_transformation)
{
	t_sphere *s = init_sphere();
	t_matrix t = trsf_translation(2, 3, 4);

	set_transform(s, t);

	cr_expect(mop_compare(s->transform, t));
}
