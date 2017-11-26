#pragma once

struct PythonVM;
struct PyObject;

struct PythonVM* pythonvm_create(const char* sLibName);
void pythonvm_destory(struct PythonVM* p);

void pythonvm__PyRun_SimpleString(struct PythonVM* p, const char *command);
#define PyRun_SimpleString pythonvm__PyRun_SimpleString

PyObject* pythonvm__PyImport_ImportModule(struct PythonVM* p, const char* sModuleName);
#define PyImport_ImportModule pythonvm__PyImport_ImportModule

PyObject* pythonvm__PyObject_GetAttrString(struct PythonVM* p, const char* sFunctionName);
#define PyObject_GetAttrString pythonvm__PyObject_GetAttrString

PyObject* pythonvm__PyObject_CallObject(struct PythonVM* p, PyObject *callable_object, PyObject *args);
#define PyObject_CallObject pythonvm__PyObject_CallObject