#include <criterion.h>
#include "../inc/minirt.h"

Test(matrices, matrices0)
{
	t_matrix A = cons_matrix(4);
	t_matrix B = cons_matrix(4);

	A.m[0][0] = 1;
	A.m[0][1] = 2;
	A.m[0][2] = 3;
	A.m[0][3] = 4;

	A.m[1][0] = 5;
	A.m[1][1] = 6;
	A.m[1][2] = 7;
	A.m[1][3] = 8;

	A.m[2][0] = 9;
	A.m[2][1] = 8;
	A.m[2][2] = 7;
	A.m[2][3] = 6;

	A.m[3][0] = 5;
	A.m[3][1] = 4;
	A.m[3][2] = 3;
	A.m[3][3] = 2;


	B.m[0][0] = 1;
	B.m[0][1] = 2;
	B.m[0][2] = 3;
	B.m[0][3] = 4;

	B.m[1][0] = 5;
	B.m[1][1] = 6;
	B.m[1][2] = 7;
	B.m[1][3] = 8;

	B.m[2][0] = 9;
	B.m[2][1] = 8;
	B.m[2][2] = 7;
	B.m[2][3] = 6;

	B.m[3][0] = 5;
	B.m[3][1] = 4;
	B.m[3][2] = 3;
	B.m[3][3] = 2;

	cr_expect(mop_compare(A, B));
}

Test(matrices, matrices1)
{
	t_matrix A = cons_matrix(4);
	t_matrix B = cons_matrix(4);

	A.m[0][0] = 1;
	A.m[0][1] = 2;
	A.m[0][2] = 3;
	A.m[0][3] = 4;

	A.m[1][0] = 5;
	A.m[1][1] = 6;
	A.m[1][2] = 7;
	A.m[1][3] = 8;

	A.m[2][0] = 9;
	A.m[2][1] = 8;
	A.m[2][2] = 7;
	A.m[2][3] = 6;

	A.m[3][0] = 5;
	A.m[3][1] = 4;
	A.m[3][2] = 3;
	A.m[3][3] = 2;


	B.m[0][0] = 1;
	B.m[0][1] = 2;
	B.m[0][2] = 3;
	B.m[0][3] = 4;

	B.m[1][0] = 4;
	B.m[1][1] = 6;
	B.m[1][2] = 7;
	B.m[1][3] = 8;

	B.m[2][0] = 9;
	B.m[2][1] = 8;
	B.m[2][2] = 7;
	B.m[2][3] = 6;

	B.m[3][0] = 5;
	B.m[3][1] = 4;
	B.m[3][2] = 3;
	B.m[3][3] = 2;

	cr_expect(!mop_compare(A, B));
}

Test(matrices, matrices2)
{
	t_matrix A = cons_matrix(4);
	t_matrix B = cons_matrix(4);

	A.m[0][0] = 1;
	A.m[0][1] = 2;
	A.m[0][2] = 3;
	A.m[0][3] = 4;

	A.m[1][0] = 5;
	A.m[1][1] = 6;
	A.m[1][2] = 7;
	A.m[1][3] = 8;

	A.m[2][0] = 9;
	A.m[2][1] = 8;
	A.m[2][2] = 7;
	A.m[2][3] = 6;

	A.m[3][0] = 5;
	A.m[3][1] = 4;
	A.m[3][2] = 3;
	A.m[3][3] = 2;


	B.m[0][0] = -2;
	B.m[0][1] = 1;
	B.m[0][2] = 2;
	B.m[0][3] = 3;

	B.m[1][0] = 3;
	B.m[1][1] = 2;
	B.m[1][2] = 1;
	B.m[1][3] = -1;

	B.m[2][0] = 4;
	B.m[2][1] = 3;
	B.m[2][2] = 6;
	B.m[2][3] = 5;

	B.m[3][0] = 1;
	B.m[3][1] = 2;
	B.m[3][2] = 7;
	B.m[3][3] = 8;

	t_matrix res = mop_multimat(A, B);

	cr_expect(res.m[0][0] == 20);
	cr_expect(res.m[0][1] == 22);
	cr_expect(res.m[0][2] == 50);
	cr_expect(res.m[0][3] == 48);

	cr_expect(res.m[1][0] == 44);
	cr_expect(res.m[1][1] == 54);
	cr_expect(res.m[1][2] == 114);
	cr_expect(res.m[1][3] == 108);

	cr_expect(res.m[2][0] == 40);
	cr_expect(res.m[2][1] == 58);
	cr_expect(res.m[2][2] == 110);
	cr_expect(res.m[2][3] == 102);

	cr_expect(res.m[3][0] == 16);
	cr_expect(res.m[3][1] == 26);
	cr_expect(res.m[3][2] == 46);
	cr_expect(res.m[3][3] == 42);
}

Test(matrices, matrices3)
{
	t_matrix A = cons_matrix(4);
	t_matrix B = cons_idmatrix();

	A.m[0][0] = 1;
	A.m[0][1] = 2;
	A.m[0][2] = 3;
	A.m[0][3] = 4;

	A.m[1][0] = 5;
	A.m[1][1] = 6;
	A.m[1][2] = 7;
	A.m[1][3] = 8;

	A.m[2][0] = 9;
	A.m[2][1] = 8;
	A.m[2][2] = 7;
	A.m[2][3] = 6;

	A.m[3][0] = 5;
	A.m[3][1] = 4;
	A.m[3][2] = 3;
	A.m[3][3] = 2;
	
	t_matrix res = mop_multimat(A, B);

	cr_expect(mop_compare(A, res));
}

Test(matrices, matrices4)
{
	t_matrix A = cons_matrix(4);

	A.m[0][0] = 0;
	A.m[0][1] = 9;
	A.m[0][2] = 3;
	A.m[0][3] = 0;

	A.m[1][0] = 9;
	A.m[1][1] = 8;
	A.m[1][2] = 0;
	A.m[1][3] = 8;

	A.m[2][0] = 1;
	A.m[2][1] = 8;
	A.m[2][2] = 5;
	A.m[2][3] = 3;

	A.m[3][0] = 0;
	A.m[3][1] = 0;
	A.m[3][2] = 5;
	A.m[3][3] = 8;

	t_matrix res = mop_transpose(A);

	cr_expect(res.m[0][0] == 0);
	cr_expect(res.m[0][1] == 9);
	cr_expect(res.m[0][2] == 1);
	cr_expect(res.m[0][3] == 0);

	cr_expect(res.m[1][0] == 9);
	cr_expect(res.m[1][1] == 8);
	cr_expect(res.m[1][2] == 8);
	cr_expect(res.m[1][3] == 0);

	cr_expect(res.m[2][0] == 3);
	cr_expect(res.m[2][1] == 0);
	cr_expect(res.m[2][2] == 5);
	cr_expect(res.m[2][3] == 5);

	cr_expect(res.m[3][0] == 0);
	cr_expect(res.m[3][1] == 8);
	cr_expect(res.m[3][2] == 3);
	cr_expect(res.m[3][3] == 8);
}

Test(matrices, matrices5)
{
	t_matrix id = cons_idmatrix();

	id = mop_transpose(id);

	cr_expect(mop_compare( id, cons_idmatrix()));
}

Test(matrices, matrices6)
{
	t_matrix A = cons_matrix(4);

	A.m[0][0] = 8;
	A.m[0][1] = -5;
	A.m[0][2] = 9;
	A.m[0][3] = 2;

	A.m[1][0] = 7;
	A.m[1][1] = 5;
	A.m[1][2] = 6;
	A.m[1][3] = 1;

	A.m[2][0] = -6;
	A.m[2][1] = 0;
	A.m[2][2] = 9;
	A.m[2][3] = 6;

	A.m[3][0] = -3;
	A.m[3][1] = 0;
	A.m[3][2] = -9;
	A.m[3][3] = -4;

	t_matrix res = mop_inverse(A);

	cr_expect(res.m[0][0] - -0.15385 < EPSILON);
	cr_expect(res.m[0][1] - -0.15385 < EPSILON);
	cr_expect(res.m[0][2] - -0.28205 < EPSILON);
	cr_expect(res.m[0][3] - -0.53846 < EPSILON);

	cr_expect(res.m[1][0] - -0.07692 < EPSILON);
	cr_expect(res.m[1][1] - 0.12308 < EPSILON);
	cr_expect(res.m[1][2] - 0.02564 < EPSILON);
	cr_expect(res.m[1][3] - 0.03077 < EPSILON);

	cr_expect(res.m[2][0] - 0.35897 < EPSILON);
	cr_expect(res.m[2][1] - 0.35897 < EPSILON);
	cr_expect(res.m[2][2] - 0.43590 < EPSILON);
	cr_expect(res.m[2][3] - 0.92308 < EPSILON);

	cr_expect(res.m[3][0] - -0.69231 < EPSILON);
	cr_expect(res.m[3][1] - -0.69231 < EPSILON);
	cr_expect(res.m[3][2] - -0.76923 < EPSILON);
	cr_expect(res.m[3][3] - -1.92308 < EPSILON);
}


Test(matrices, matrices7)
{
	t_matrix A = cons_matrix(4);

	A.m[0][0] = 9;
	A.m[0][1] = 3;
	A.m[0][2] = 0;
	A.m[0][3] = 9;

	A.m[1][0] = -5;
	A.m[1][1] = -2;
	A.m[1][2] = -6;
	A.m[1][3] = -3;

	A.m[2][0] = -4;
	A.m[2][1] = 9;
	A.m[2][2] = 6;
	A.m[2][3] = 4;

	A.m[3][0] = -7;
	A.m[3][1] = 6;
	A.m[3][2] = 6;
	A.m[3][3] = 2;

	t_matrix res = mop_inverse(A);

	cr_expect(res.m[0][0] - -0.04074 < EPSILON);
	cr_expect(res.m[0][1] - -0.07778 < EPSILON);
	cr_expect(res.m[0][2] - 0.14444 < EPSILON);
	cr_expect(res.m[0][3] - -0.22222 < EPSILON);

	cr_expect(res.m[1][0] - -0.07778 < EPSILON);
	cr_expect(res.m[1][1] - 0.03333 < EPSILON);
	cr_expect(res.m[1][2] - 0.36667 < EPSILON);
	cr_expect(res.m[1][3] - -0.33333 < EPSILON);

	cr_expect(res.m[2][0] - -0.02901 < EPSILON);
	cr_expect(res.m[2][1] - -0.14630 < EPSILON);
	cr_expect(res.m[2][2] - -0.10926 < EPSILON);
	cr_expect(res.m[2][3] - 0.12963 < EPSILON);

	cr_expect(res.m[3][0] - 0.17778 < EPSILON);
	cr_expect(res.m[3][1] - 0.06667 < EPSILON);
	cr_expect(res.m[3][2] - -0.26667 < EPSILON);
	cr_expect(res.m[3][3] - 0.33333 < EPSILON);
}

Test(matrices, matrices8)
{
	t_matrix A = cons_matrix(4);
	t_matrix B = cons_matrix(4);

	A.m[0][0] = 3;
	A.m[0][1] = -9;
	A.m[0][2] = 7;
	A.m[0][3] = 3;

	A.m[1][0] = 3;
	A.m[1][1] = -8;
	A.m[1][2] = 2;
	A.m[1][3] = 9;

	A.m[2][0] = -4;
	A.m[2][1] = 4;
	A.m[2][2] = 4;
	A.m[2][3] = 1;

	A.m[3][0] = -6;
	A.m[3][1] = 5;
	A.m[3][2] = -1;
	A.m[3][3] = 1;


	B.m[0][0] = 8;
	B.m[0][1] = 2;
	B.m[0][2] = 2;
	B.m[0][3] = 2;

	B.m[1][0] = 3;
	B.m[1][1] = -1;
	B.m[1][2] = 7;
	B.m[1][3] = 0;

	B.m[2][0] = 7;
	B.m[2][1] = 0;
	B.m[2][2] = 5;
	B.m[2][3] = 4;

	B.m[3][0] = 6;
	B.m[3][1] = -2;
	B.m[3][2] = 0;
	B.m[3][3] = 5;

	t_matrix C = mop_multimat(A, B);

	cr_expect(mop_compare(A, mop_multimat(C, mop_inverse(B))));
}