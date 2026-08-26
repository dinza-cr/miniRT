#include <criterion/criterion.h>
#include "minirt.h"

Test(transformation, transformation0)
{
	t_matrix transform = trsf_translation(5, -3, 2);
	t_tuple	p = cons_point(-3, 4, 5);

	cr_expect(top_compare(mop_multitup(transform, p), cons_point(2, 1, 7)));
}

Test(transformation, transformation1)
{
	t_matrix transform = trsf_translation(5, -3, 2);
	t_matrix inv = mop_inverse(transform);
	t_tuple	p = cons_point(-3, 4, 5);

	cr_expect(top_compare(mop_multitup(inv, p), cons_point(-8, 7, 3)));
}

Test(transformation, transformation2)
{
	t_matrix transform = trsf_translation(5, -3, 2);
	t_tuple v = cons_vector(-3, 4, 5);

	cr_expect(top_compare(mop_multitup(transform, v), v));
}

Test(transformation, transformation3)
{
	t_matrix transform = trsf_scaling(2, 3, 4);
	t_tuple	p = cons_point(-4, 6, 8);

	cr_expect(top_compare(mop_multitup(transform, p), cons_point(-8, 18, 32)));
}

Test(transformation, transformation4)
{
	t_matrix transform = trsf_scaling(2, 3, 4);
	t_tuple	p = cons_vector(-4, 6, 8);

	cr_expect(top_compare(mop_multitup(transform, p), cons_vector(-8, 18, 32)));
}

Test(transformation, transformation5)
{
	t_matrix transform = trsf_scaling(2, 3, 4);
	t_matrix inv = mop_inverse(transform);
	t_tuple	p = cons_vector(-4, 6, 8);

	cr_expect(top_compare(mop_multitup(inv , p), cons_vector(-2, 2, 2)));
}

Test(transformation, transformation6)
{
	t_matrix transform = trsf_scaling(-1, 1, 1);
	t_tuple	p = cons_point(2, 3, 4);

	cr_expect(top_compare(mop_multitup(transform , p), cons_point(-2, 3, 4)));
}

Test(transformation, transformation7)
{
	t_tuple	p = cons_point(0, 1, 0);
	t_matrix half_quarter = trsf_rotx(PI / 4);
	t_matrix full_quarter = trsf_rotx(PI / 2);

	cr_expect(top_compare(mop_multitup(half_quarter, p), cons_point(0, sqrt(2)/2, sqrt(2)/2)));
	cr_expect(top_compare(mop_multitup(full_quarter, p), cons_point(0, 0, 1)));
}

Test(transformation, transformation8)
{
	t_tuple	p = cons_point(0, 1, 0);
	t_matrix half_quarter = trsf_rotx(PI / 4);
	t_matrix inv = mop_inverse(half_quarter);

	cr_expect(top_compare(mop_multitup(inv, p), cons_point(0, sqrt(2)/2, -sqrt(2)/2)));
}

Test(transformation, transformation9)
{
	t_tuple	p = cons_point(0, 0, 1);
	t_matrix half_quarter = trsf_roty(PI / 4);
	t_matrix full_quarter = trsf_roty(PI / 2);

	cr_expect(top_compare(mop_multitup(half_quarter, p), cons_point(sqrt(2)/2, 0, sqrt(2)/2)));
	cr_expect(top_compare(mop_multitup(full_quarter, p), cons_point(1, 0, 0)));
}

Test(transformation, transformation10)
{
	t_tuple	p = cons_point(0, 1, 0);
	t_matrix half_quarter = trsf_rotz(PI / 4);
	t_matrix full_quarter = trsf_rotz(PI / 2);

	cr_expect(top_compare(mop_multitup(half_quarter, p), cons_point(-sqrt(2)/2, sqrt(2)/2, 0)));
	cr_expect(top_compare(mop_multitup(full_quarter, p), cons_point(-1, 0, 0)));
}

Test(transformation, transformation11)
{
	t_matrix transform = trsf_shearing(1, 0, 0, 0, 0, 0);
	t_tuple	p = cons_point(2, 3, 4);

	cr_expect(top_compare(mop_multitup(transform , p), cons_point(5, 3, 4)));
}

Test(transformation, transformation12)
{
	t_matrix transform = trsf_shearing(0, 1, 0, 0, 0, 0);
	t_tuple	p = cons_point(2, 3, 4);

	cr_expect(top_compare(mop_multitup(transform , p), cons_point(6, 3, 4)));
}

Test(transformation, transformation13)
{
	t_matrix transform = trsf_shearing(0, 0, 1, 0, 0, 0);
	t_tuple	p = cons_point(2, 3, 4);

	cr_expect(top_compare(mop_multitup(transform , p), cons_point(2, 5, 4)));
}

Test(transformation, transformation14)
{
	t_matrix transform = trsf_shearing(0, 0, 0, 1, 0, 0);
	t_tuple	p = cons_point(2, 3, 4);

	cr_expect(top_compare(mop_multitup(transform , p), cons_point(2, 7, 4)));
}

Test(transformation, transformation15)
{
	t_matrix transform = trsf_shearing(0, 0, 0, 0, 1, 0);
	t_tuple	p = cons_point(2, 3, 4);

	cr_expect(top_compare(mop_multitup(transform , p), cons_point(2, 3, 6)));
}

Test(transformation, transformation16)
{
	t_matrix transform = trsf_shearing(0, 0, 0, 0, 0, 1);
	t_tuple	p = cons_point(2, 3, 4);

	cr_expect(top_compare(mop_multitup(transform , p), cons_point(2, 3, 7)));
}

Test(transformation, The_transformation_matrix_for_the_default_orientation)
{
	t_tuple from = cons_point(0, 0, 0);
	t_tuple to = cons_point(0, 0, -1);
	t_tuple up = cons_vector(0, 1, 0);

	t_matrix t = trsf_view_transform(from, to, up);

	cr_expect(mop_compare(t, cons_idmatrix()));
}

Test(transformation, A_view_transformation_matrix_looking_in_positive_z_direction)
{
	t_tuple from = cons_point(0, 0, 0);
	t_tuple to = cons_point(0, 0, 1);
	t_tuple up = cons_vector(0, 1, 0);

	t_matrix t = trsf_view_transform(from, to, up);

	cr_expect(mop_compare(t, trsf_scaling(-1, 1, -1)));
}

Test(transformation, The_view_transformation_moves_the_world)
{
	t_tuple from = cons_point(0, 0, 8);
	t_tuple to = cons_point(0, 0, 0);
	t_tuple up = cons_vector(0, 1, 0);

	t_matrix t = trsf_view_transform(from, to, up);

	cr_expect(mop_compare(t, trsf_translation(0, 0, -8)));
}


Test(transformation, An_arbitrary_view_transformation)
{
	t_tuple from = cons_point(1, 3, 2);
	t_tuple to = cons_point(4, -2, 8);
	t_tuple up = cons_vector(1, 1, 0);

	t_matrix t = trsf_view_transform(from, to, up);

	cr_expect(mop_compare(t, cons_mat4(-0.50709, 0.50709, 0.67612, -2.36643, 0.76772, 0.60609, 0.12122, -2.82843, -0.35857, 0.59761, -0.71714, 0.00000, 0.00000, 0.00000, 0.00000, 1.00000)));
}

