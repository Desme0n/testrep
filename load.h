#ifndef PR3_FIN_LOAD_H
#define PR3_FIN_LOAD_H
typedef void(*MatrixFunction)(int[][6], int, int); //указатель на функцию *MatrixFunction
typedef void (*ArrayFunction)(int*,int);

void* Load(const char * const s, void ** l,const char * const);
void closeLib(void*lib);

#endif //PR3_FIN_LOAD_H
