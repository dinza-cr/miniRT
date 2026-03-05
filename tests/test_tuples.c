#include <criterion/criterion.h>
// #include <criterion.h>
#include "../inc/minirt.h"

Test(tuples, tuples0)
{
	t_tuple a; //Arrange

	a = cons_point(4.3,-4.2, 3.1); //Act

	cr_expect(a.w == 1); //Assert
	cr_expect(a.x == 4.3);
	cr_expect(a.y == -4.2);
	cr_expect(a.z == 3.1);
}


Test(tuples, tuples1)
{
	t_tuple a;

	a = cons_vector(4.3,-4.2, 3.1);
	
	cr_expect(a.w == 0);
	cr_expect(a.x == 4.3);
	cr_expect(a.y == -4.2);
	cr_expect(a.z == 3.1);
}

Test(tuples, tuples2)
{
	t_tuple a1 = cons_point(3, -2, 5);
	t_tuple a2 = cons_vector(-2, 3, 1);

	t_tuple res = top_add(a1, a2);

	cr_expect(res.x == 1);
	cr_expect(res.y == 1);
	cr_expect(res.z == 6);
	cr_expect(res.w == 1);
}

Test(tuples, tuples3)
{
	t_tuple a1 = cons_point(3, 2, 1);
	t_tuple a2 = cons_point(5, 6, 7);

	t_tuple res = top_subs(a1, a2);

	cr_expect(res.x == -2);
	cr_expect(res.y == -4);
	cr_expect(res.z == -6);
}

Test(tuples, tuples4)
{
	t_tuple a1 = cons_point(3, 2, 1);
	t_tuple a2 = cons_vector(5, 6, 7);

	t_tuple res = top_subs(a1, a2);

	cr_expect(res.x == -2);
	cr_expect(res.y == -4);
	cr_expect(res.z == -6);
	cr_expect(res.w == 1);
}

Test(tuples, tuples5)
{
	t_tuple a1 = cons_vector(3, 2, 1);
	t_tuple a2 = cons_vector(5, 6, 7);

	t_tuple res = top_subs(a1, a2);

	cr_expect(res.x == -2);
	cr_expect(res.y == -4);
	cr_expect(res.z == -6);
	cr_expect(res.w == 0);
}


Test(tuples, tuples6)
{
	t_tuple a = cons_vector(1,-2, 3);
	a.w = -4;

	a = top_negate(a);

	cr_expect(a.x == -1);
	cr_expect(a.y == 2);
	cr_expect(a.z == -3);
	cr_expect(a.w == 4);
}

Test(tuples, tuples7)
{
	t_tuple a = cons_point(1,-2, 3);
	a.w = -4;

	a = top_multi(a, 3.5);

	cr_expect(a.x == 3.5);
	cr_expect(a.y == -7);
	cr_expect(a.z == 10.5);
	cr_expect(a.w == -14);
}

Test(tuples, tuples8)
{
	t_tuple a = cons_point(1,-2, 3);
	a.w = -4;

	a = top_multi(a, 0.5);

	cr_expect(a.x == 0.5);
	cr_expect(a.y == -1);
	cr_expect(a.z == 1.5);
	cr_expect(a.w == -2);
}

Test(tuples, tuples9)
{
	t_tuple a = cons_point(1,-2, 3);
	a.w = -4;

	a = top_divi(a, 2);

	cr_expect(a.x == 0.5);
	cr_expect(a.y == -1);
	cr_expect(a.z == 1.5);
	cr_expect(a.w == -2);
}

Test(tuples, tuples10)
{
	t_tuple v = cons_vector(1, 0, 0);

	cr_expect (top_magnitude(v) == 1);
}

Test(tuples, tuples11)
{
	t_tuple v = cons_vector(0, 1, 0);

	cr_expect (top_magnitude(v) == 1);
}

Test(tuples, tuples12)
{
	t_tuple v = cons_vector(0, 0, 1);

	cr_expect (top_magnitude(v) == 1);
}

Test(tuples, tuples13)
{
	t_tuple v = cons_vector(1, 2, 3);

	cr_expect (top_magnitude(v) == sqrt(14));
}

Test(tuples, tuples14)
{
	t_tuple v = cons_vector(-1, -2, -3);

	cr_expect (top_magnitude(v) == sqrt(14));
}

Test(tuples, tuples15)
{
	t_tuple v = cons_vector(4, 0, 0);

	v = top_normalize(v);

	cr_expect (v.x == 1);
	cr_expect (v.y == 0);
	cr_expect (v.z == 0);
}

Test(tuples, tuples16)
{
	t_tuple v = cons_vector(1, 2, 3);

	v = top_normalize(v);

	cr_expect (v.x == 1/sqrt(14));
	cr_expect (v.y == 2/sqrt(14));
	cr_expect (v.z == 3/sqrt(14));
}

Test(tuples, tuples17)
{
	t_tuple v = cons_vector(1, 2, 3);

	v = top_normalize(v);

	cr_expect (v.x == 1/sqrt(14));
	cr_expect (v.y == 2/sqrt(14));
	cr_expect (v.z == 3/sqrt(14));
	cr_expect (top_magnitude(v) == 1);
}

Test(tuples, tuples18)
{
	t_tuple a = cons_vector(1, 2, 3);
	t_tuple b = cons_vector(2, 3, 4);

	cr_expect(top_dot(a, b) == 20);
}

Test(tuples, tuples19)
{
	t_tuple a = cons_vector(1, 2, 3);
	t_tuple b = cons_vector(2, 3, 4);

	t_tuple res = top_cross(a, b);

	cr_expect(res.x == -1);
	cr_expect(res.y == 2);
	cr_expect(res.z == -1);

	res = top_cross(b, a);
	
	cr_expect(res.x == 1);
	cr_expect(res.y == -2);
	cr_expect(res.z == 1);
}
