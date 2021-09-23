#include <Windows.h>

#include "shared_defines.h"

#include "step_timer.h"

class test {
public :
	void tt() {
		printf("tick\n");
	}
};

int main() {


	step_timer st;
	test t;
	while (true) {

		st.update([&t]() { t.tt(); });

		Sleep(1);
	}

	syspause
	return 0;
}