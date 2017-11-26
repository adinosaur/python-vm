
#include <thread>
#include "python_vm.h"

using namespace std;

void thread_fun(struct PythonVM* pythonvm) {
	const char* code = "i = 1\n"
						"while 1:\n"
						"    i += 1\n";
	PyRun_SimpleString(pythonvm, code);
}

int main(int argc, char **argv) {

#ifdef _WIN32
	struct PythonVM* py1 = pythonvm_create("python36-1.dll");
	struct PythonVM* py2 = pythonvm_create("python36-2.dll");
#elif linux
	struct PythonVM* py1 = pythonvm_create("/usr/lib/x86_64-linux-gnu/libpython2.7.so.1.0-1");
	struct PythonVM* py2 = pythonvm_create("/usr/lib/x86_64-linux-gnu/libpython2.7.so.1.0-2");
#endif

	thread* threads[2];
	threads[0] = new thread(thread_fun, py1);
	threads[1] = new thread(thread_fun, py2);

	for (int i = 0; i < 2; i += 1) {
		threads[i]->join();
		delete threads[i];
	}

	pythonvm_destory(py2);
	pythonvm_destory(py1);

	return 0;
}