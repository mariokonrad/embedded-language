/* tinyscheme: simple.c */

#include <stdlib.h>
#include <scheme-private.h>

static pointer hello_world(scheme * sc, pointer args)
{
	printf("Hello World!\n");
	return sc->NIL;
}

static pointer sqr(scheme * sc, pointer args)
{
	if (args != sc->NIL) {
		pointer arg = sc->vptr->pair_car(args);
		if (sc->vptr->is_number(arg)) {
			double v = sc->vptr->rvalue(arg);
			return sc->vptr->mk_real(sc, v * v);
		}
	}
	return sc->NIL;
}

static pointer sum(scheme * sc, pointer args)
{
	double v = 0.0;
	while (args != sc->NIL) {
		pointer arg = sc->vptr->pair_car(args);
		if (sc->vptr->is_number(arg)) {
			v += sc->vptr->rvalue(arg);
		} else {
			return sc->NIL;
		}
		args = sc->vptr->pair_cdr(args);
	}
	return sc->vptr->mk_real(sc, v);
}


int main(int argc, char ** argv)
{
	scheme * sc = NULL;
	FILE * file = NULL;

	if (argc != 2) {
		printf("\nusage: %s script-filename\n\n", argv[0]);
		return EXIT_FAILURE;
	}

	sc = scheme_init_new();
	scheme_set_input_port_file(sc, stdin);
	scheme_set_output_port_file(sc, stdout);

	scheme_define( sc, sc->global_env, mk_symbol(sc, "hello_world"), mk_foreign_func(sc, hello_world));
	scheme_define( sc, sc->global_env, mk_symbol(sc, "test-sqr"),    mk_foreign_func(sc, sqr));
	scheme_define( sc, sc->global_env, mk_symbol(sc, "test-sum"),    mk_foreign_func(sc, sum));

	file = fopen(argv[1], "rt");
	if (file) scheme_load_file(sc, file);
	fclose(file);

	scheme_deinit(sc);
	free(sc);
	return EXIT_SUCCESS;
}

