#include <criterion.h>
#include "../inc/minirt.h"

Test(normal, The_normal_on_a_sphere_at_a_point_on_the_x_axis)
{
	t_sphere *s = cons_sphere();

	t_tuple n = normal_at(s, cons_point(1, 0, 0));

	cr_expect(top_compare(n, cons_vector(1, 0, 0)));
}

Test(normalt, The_normal_on_a_sphere_at_a_point_on_the_y_axis)
{
	t_sphere *s = cons_sphere();

	t_tuple n = normal_at(s, cons_point(0, 1, 0));

	cr_expect(top_compare(n, cons_vector(0, 1, 0)));
}

Test(normal, The_normal_on_a_sphere_at_a_point_on_the_z_axis)
{
	t_sphere *s = cons_sphere();

	t_tuple n = normal_at(s, cons_point(0, 0, 1));

	cr_expect(top_compare(n, cons_vector(0, 0, 1)));
}

Test(normal, The_normal_on_a_sphere_at_a_nonaxial_point)
{
	t_sphere *s = cons_sphere();

	t_tuple n = normal_at(s, cons_point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));

	cr_expect(top_compare(n, cons_vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3)));
}

Test(normal, The_normal_is_a_normalized_vector)
{
	t_sphere *s = cons_sphere();

	t_tuple n = normal_at(s, cons_point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));

	cr_expect(top_compare(n, top_normalize(n)));
}

Test(normal, Computing_the_normal_on_a_translated_sphere)
{
	t_sphere *s = cons_sphere();
	set_transform(s, trsf_translation(0, 1, 0));

	t_tuple n = normal_at(s, cons_point(0, 1.70711, -0.70711));

	cr_expect(top_compare(n, cons_vector(0, 0.70711, -0.70711)));
}

Test(normal, Computing_the_normal_on_a_transformed_sphere)
{
	t_sphere *s = cons_sphere();
	t_matrix m = mop_multimat(trsf_scaling(1, 0.5, 1), trsf_rotz(PI/5));
	set_transform(s, m);

	t_tuple n = normal_at(s, cons_point(0, sqrt(2)/2, -sqrt(2)/2));

	cr_expect(top_compare(n, cons_vector(0,  0.97014, -0.24254)));
}

Test(reflect, Reflecting_a_vector_approaching_at_45)
{
	t_tuple v = cons_vector(1, -1, 0);
	t_tuple n = cons_vector(0, 1, 0);

	t_tuple r = reflect(v, n);

	cr_expect(top_compare(r, cons_vector(1, 1, 0)));
}

Test(reflect, Reflecting_a_vector_off_a_slanted_surface)
{
	t_tuple v = cons_vector(0, -1, 0);
	t_tuple n = cons_vector(sqrt(2)/2, sqrt(2)/2, 0);

	t_tuple r = reflect(v, n);

	cr_expect(top_compare(r, cons_vector(1, 0, 0)));
}

Test(light, A_point_light_has_a_position_and_intensity)
{
	t_color intensity = cons_color(1, 1, 1);
	t_tuple position  = cons_point(0, 0, 0);


	t_light l = cons_light(position, intensity);

	cr_expect(cop_compare(intensity, l.color));
	cr_expect(top_compare(position, l.coord));
}

Test(lighting, Lighting_with_the_eye_between_the_light_and_the_surface)
{
	t_material m = init_material();
	t_tuple position = cons_point(0, 0, 0);
	t_tuple eyev = cons_vector(0, 0, -1);
	t_tuple normalv = cons_vector(0, 0, -1);
	t_light light = cons_light(cons_point(0, 0, -10), cons_color(1, 1, 1));

	t_color result = lighting(m, light, position, eyev, normalv, 0);

	cr_expect(cop_compare(result, cons_color(1.9, 1.9, 1.9)));
}


Test(lighting, Lighting_with_the_eye_between_light_and_surface_eye_offset_45)
{
	t_material m = init_material();
	t_tuple position = cons_point(0, 0, 0);
	t_tuple eyev = cons_vector(0, sqrt(2)/2, -sqrt(2)/2);
	t_tuple normalv = cons_vector(0, 0, -1);
	t_light light = cons_light(cons_point(0, 0, -10), cons_color(1, 1, 1));

	t_color result = lighting(m, light, position, eyev, normalv, 0);

	cr_expect(cop_compare(result, cons_color(1.0, 1.0, 1.0)));
}

Test(lighting, Lighting_with_eye_opposite_surface_light_offset_45)
{
	t_material m = init_material();
	t_tuple position = cons_point(0, 0, 0);
	t_tuple eyev = cons_vector(0, 0, -1);
	t_tuple normalv = cons_vector(0, 0, -1);
	t_light light = cons_light(cons_point(0, 10, -10), cons_color(1, 1, 1));

	t_color result = lighting(m, light, position, eyev, normalv, 0);

	cr_expect(cop_compare(result, cons_color(0.7364, 0.7364, 0.7364)));
}

Test(lighting, Lighting_with_eye_in_the_path_of_the_reflection_vector)
{
	t_material m = init_material();
	t_tuple position = cons_point(0, 0, 0);
	t_tuple eyev = cons_vector(0, -sqrt(2)/2, -sqrt(2)/2);
	t_tuple normalv = cons_vector(0, 0, -1);
	t_light light = cons_light(cons_point(0, 10, -10), cons_color(1, 1, 1));

	t_color result = lighting(m, light, position, eyev, normalv, 0);

	cr_expect(cop_compare(result, cons_color(1.6364, 1.6364, 1.6364)));
}

Test(lighting, Lighting_with_the_light_behind_the_surface)
{
	t_material m = init_material();
	t_tuple position = cons_point(0, 0, 0);
	t_tuple eyev = cons_vector(0, 0, -1);
	t_tuple normalv = cons_vector(0, 0, -1);
	t_light light = cons_light(cons_point(0, 0, 10), cons_color(1, 1, 1));

	t_color result = lighting(m, light, position, eyev, normalv, 0);

	cr_expect(cop_compare(result, cons_color(0.1, 0.1, 0.1)));
}

Test(shadow, Lighting_with_the_surface_in_shadow)
{
	t_tuple eyev = cons_vector(0, 0, -1);
	t_tuple normalv = cons_vector(0, 0, -1);
	t_light light = cons_light(cons_point(0, 0, -10), cons_color(1, 1, 1));
	int in_shadow = 1;
	t_material m = init_material();
	t_tuple position = cons_point(0, 0, 0);

	t_color result = lighting(m, light, position, eyev, normalv, in_shadow);

	cr_expect(cop_compare(result, cons_color(0.1, 0.1, 0.1)));
}

Test(shadow, There_is_no_shadow_when_nothing_is_collinear_with_point_and_light)
{
	t_world *w = default_world();
	t_tuple p = cons_point(0, 10, 0);

	cr_expect(!is_shadowed(w, p));
}

Test(shadow, The_shadow_when_an_object_is_between_the_point_and_the_light)
{
	t_world *w = default_world();
	t_tuple p = cons_point(10, -10, 10);

	cr_expect(is_shadowed(w, p));
}

Test(shadow, There_is_no_shadow_when_an_object_is_behind_the_light)
{
	t_world *w = default_world();
	t_tuple p = cons_point(-20, 20, -20);

	cr_expect(!is_shadowed(w, p));
}

Test(shadow, There_is_no_shadow_when_an_object_is_behind_the_point)
{
	t_world *w = default_world();
	t_tuple p = cons_point(-2, 2, -2);

	cr_expect(!is_shadowed(w, p));
}

