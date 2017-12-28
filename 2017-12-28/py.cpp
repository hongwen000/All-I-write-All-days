#include <Python.h>

int main(int argc, char *argv[])
{
    if(!argc) return -1;
    Py_SetProgramName(argv[0]);
    Py_Initialize();
    PyRun_SimpleString("print 'Hello Python!'\n");
    Py_Finalize();
    return 0;
}

