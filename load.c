#include "stdio.h"
#include "load.h"

#ifdef __linux__
#include "dlfcn.h"
    #define DOWNLOAD lib=dlopen(s,RTLD_LAZY);
#else
#include <windows.h>
#define DOWNLOAD lib=LoadLibrary(s);
#endif

void* Load(const char * const s, void ** l, const char * const name) {
    void * lib;
    void * fun;

    DOWNLOAD //загрузка библиотеки в память;

    if (!lib) {
        printf("cannot open library '%s' \n", s);
        return 0;
    }
    *l = (void*)lib;

#ifdef __linux__
    fun=(void(*))dlsym(lib, name);
#else
    fun=(void(*))GetProcAddress((HINSTANCE)lib, name);
#endif

    if (fun == NULL)
        printf("cannot load function func\n");

    return fun;
}

void closeLib(void*lib)
{
#ifdef __linux__
    dlclose(lib);
#else
    FreeLibrary((HINSTANCE)lib);
#endif
}


