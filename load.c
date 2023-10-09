#include "stdio.h"
#include "load.h"
#include <windows.h>
#define DOWNLOAD lib=LoadLibrary(s);


void* Load(const char * const s, void ** l, const char * const name) {
    void * lib;
    void * fun;

    DOWNLOAD //загрузка библиотеки в память;

    if (!lib) {
        printf("cannot open library '%s' \n", s);
        return 0;
    }
    *l = (void*)lib;

    fun=(void(*))GetProcAddress((HINSTANCE)lib, name);

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


