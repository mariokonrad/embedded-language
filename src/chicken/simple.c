#include <chicken/chicken.h>
#include <stdlib.h>

int main()
{
	C_word val;
	char buf[256];

	CHICKEN_run(C_toplevel);

	CHICKEN_eval_string("(print (+ 3 4))", &val);

	CHICKEN_eval_string_to_string("(custom-sqr 6)", buf, 255);
	printf("result: [%s]\n", buf);

	return EXIT_SUCCESS;
}

