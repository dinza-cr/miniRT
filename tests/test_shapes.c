#include <criterion/criterion.h>
#include "minirt.h"

Test(shape, The_default_transformation)
{
    t_shape *s = cons_shape();

    cr_expect(mop_compare(s->transformation, cons_idmatrix()));
}

Test(shape, Assigning_a_transformation)
{
    t_shape *s = cons_shape();

    set_transform(s, trsf_translation(2, 3, 4));

    cr_expect(mop_compare(s->transformation, trsf_translation(2, 3, 4)));
}

Test(shape, The_default_material)
{
    t_shape *s = cons_shape();

    t_material m = init_material();

    cr_expect(s->material.ambient == m.ambient);
    cr_expect(cop_compare(s->material.color, m.color));
    cr_expect(s->material.diffuse == m.diffuse);
    cr_expect(s->material.shininess == m.shininess);
    cr_expect(s->material.specular == m.specular);
}

Test(shape, Assigning_a_material)
{
    t_shape *s = cons_shape();
    t_material m = init_material();
    m.ambient = 1;

    s->material = m;

    cr_expect(s->material.ambient == 1);
}