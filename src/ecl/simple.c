#include <ecl/ecl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	cl_boot(argc, argv);
	cl_object obj = c_string_to_object("\"Hello world\"");
	cl_pprint(1, obj);
	cl_shutdown();
	return EXIT_SUCCESS;
}

