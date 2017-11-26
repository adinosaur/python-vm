
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

	struct PythonVM* py1 = pythonvm_create();
	struct PythonVM* py2 = pythonvm_create();

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