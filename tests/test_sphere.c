#include <criterion/criterion.h>
#include "minirt.h"

Test(sphere, A_sphere_s_default_transformation)
{
	t_shape *s = cons_shape();

	cr_expect(mop_compare(s->transformation, cons_idmatrix()));
}

Test(sphere, Changing_a_sphere_transformation)
{
	t_shape *s = cons_shape();
	t_matrix t = trsf_translation(2, 3, 4);

	set_transform(s, t);

	cr_expect(mop_compare(s->transformation, t));
}
