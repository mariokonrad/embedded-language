// simple.cpp

#include <jsapi.h>
#include <cstring>
#include <sys/stat.h>
#include <fstream>

JS_STATIC_DLL_CALLBACK(void) error_reporter(JSContext * cx, const char * message, JSErrorReport * report)
{
	printf("\nERROR: ");
    printf(message);
	printf("\n");
}

JS_STATIC_DLL_CALLBACK(JSBool) js__hello_world(JSContext * cx, JSObject * obj, uintN argc, jsval * argv, jsval * rval)
{
	printf("Hello World\n");
	return JS_TRUE;
}

JS_STATIC_DLL_CALLBACK(JSBool) js__load(JSContext * cx, JSObject * obj, uintN argc, jsval * argv, jsval * rval)
{
	uintN i;
	JSString * str;
	const char * filename;
	JSScript * script;
	JSBool ok;
	jsval result;

	for (i = 0; i < argc; i++) {
		str = JS_ValueToString(cx, argv[i]);
		if (!str) return JS_FALSE;
		argv[i] = STRING_TO_JSVAL(str);
		filename = JS_GetStringBytes(str);
		script = JS_CompileFile(cx, obj, filename);
		if (!script) {
			ok = JS_FALSE;
		} else {
			ok = JS_ExecuteScript(cx, obj, script, &result);
			JS_DestroyScript(cx, script);
		}
        if (!ok) return JS_FALSE;
    }
    return JS_TRUE;
}

JS_STATIC_DLL_CALLBACK(JSBool) js__print(JSContext * cx, JSObject * obj, uintN argc, jsval * argv, jsval * rval)
{
	uintN i, n;
	JSString * str;

	for (i = n = 0; i < argc; i++) {
		str = JS_ValueToString(cx, argv[i]);
		if (!str) return JS_FALSE;
		fprintf(stdout, "%s%s", i ? " " : "", JS_GetStringBytes(str));
	}
	n++;
	if (n) fputc('\n', stdout);
	return JS_TRUE;
}

int main(int argc, char ** argv)
{
	if (argc != 2) {
		printf("\nusage: %s script-filename\n\n", argv[0]);
		return -1;
	}

	// evaluate script file size
	struct stat s;
	memset(&s, 0, sizeof(s));
	if (stat(argv[1], &s)) {
		fprintf(stderr, "ERROR: cannot get stat from file '%s'\n", argv[1]);
		return -1;
	}

	// read script from file
	char * source = new char[s.st_size];
	std::ifstream f(argv[1]);
	f.read(source, s.st_size);
	f.close();

	JSClass global_class = {
		"global", 0,
		JS_PropertyStub, JS_PropertyStub,
		JS_PropertyStub, JS_PropertyStub,
		JS_EnumerateStub, JS_ResolveStub,
		JS_ConvertStub, JS_FinalizeStub
	};

	// setup environment
	JSRuntime * runtime = JS_NewRuntime(0x100000);
	JSContext * context = JS_NewContext(runtime, 0x1000);
	JSObject * global = JS_NewObject(context, &global_class, NULL, NULL);
	JS_InitStandardClasses(context, global);
	JS_SetErrorReporter(context, error_reporter);

	// register functions
	static JSFunctionSpec functions[] = {
	//  name            native           nargs
		{"load",        js__load,        1},
		{"print",       js__print,       0},
		{"hello_world", js__hello_world, 0},
		{NULL}
	};
	JS_DefineFunctions(context, global, functions);

	// execute script
	jsval ret;
	JSBool rc = JS_EvaluateScript(context, global,
		source, s.st_size,
		argv[1], 0,
		&ret);
	if (rc == JS_FALSE) {
		fprintf(stderr, "ERROR: rc=%d, filename:'%s'\n", rc, argv[1]);
	}

	// clean up
	delete[] source;
	JS_DestroyContext(context);
	JS_DestroyRuntime(runtime);
	JS_ShutDown();
	return 0;
}

