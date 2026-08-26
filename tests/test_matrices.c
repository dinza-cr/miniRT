#include <criterion/criterion.h>
#include "minirt.h"

Test(matrices, matrices0)
{
	t_matrix A = cons_mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2);
	t_matrix B = cons_mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2);

	cr_expect(mop_compare(A, B));
}

Test(matrices, matrices1)
{
	t_matrix A = cons_mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2);
	t_matrix B = cons_mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1);

	cr_expect(!mop_compare(A, B));
}

Test(matrices, matrices2)
{
	t_matrix A = cons_mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2);
	t_matrix B = cons_mat4(-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8);

	t_matrix res = mop_multimat(A, B);

	t_matrix exp = cons_mat4(20, 22, 50, 48, 44, 54, 114, 108, 40, 58, 110, 102, 16, 26, 46, 42);
	cr_expect(mop_compare(res, exp));
}

Test(matrices, matrices3)
{
	t_matrix A = cons_mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2);
	t_matrix B = cons_idmatrix();

	t_matrix res = mop_multimat(A, B);

	cr_expect(mop_compare(A, res));
}

Test(matrices, matrices4)
{
	t_matrix A = cons_mat4(0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8);

	t_matrix res = mop_transpose(A);

	t_matrix exp = cons_mat4(0, 9, 1, 0, 9, 8, 8, 0, 3, 0, 5, 5, 0, 8, 3, 8);
	cr_expect(mop_compare(res, exp));
}

Test(matrices, matrices5)
{
	t_matrix id = cons_idmatrix();

	id = mop_transpose(id);

	cr_expect(mop_compare( id, cons_idmatrix()));
}

Test(matrices, matrices6)
{
	t_matrix A = cons_mat4(8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4);

	t_matrix res = mop_inverse(A);

	t_matrix exp = cons_mat4(-0.15385, -0.15385, -0.28205, -0.53846, -0.07692, 0.12308, 0.02564, 0.03077, 0.35897, 0.35897, 0.43590, 0.92308, -0.69231, -0.69231, -0.76923, -1.92308);
	cr_expect(mop_compare(res, exp));
}


Test(matrices, matrices7)
{
	t_matrix A = cons_mat4(9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2);

	t_matrix res = mop_inverse(A);

	t_matrix exp = cons_mat4(-0.04074, -0.07778, 0.14444, -0.22222, -0.07778, 0.03333, 0.36667, -0.33333, -0.02901, -0.14630, -0.10926, 0.12963, 0.17778, 0.06667, -0.26667, 0.33333);
	cr_expect(mop_compare(res, exp));
}

Test(matrices, matrices8)
{
	t_matrix A = cons_mat4(3, -9, 7, 3, 3, -8, 2, 9, -4, 4, 4, 1, -6, 5, -1, 1);
	t_matrix B = cons_mat4(8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5);

	t_matrix C = mop_multimat(A, B);
	t_matrix res = mop_multimat(C, mop_inverse(B));

	cr_expect(mop_compare(A, res));
}