#include <stdio.h>
#include <unistd.h>

#define cr_start() \
	static int run_line = 0; \
	switch(run_line) { \
	case 0: \

#define cr_end() \
	} \
	run_line = 0

#define cr_yield() \
	usleep(500000); \
	run_line = __LINE__; \
	return; \
	case __LINE__:

void routine1(void)
{
	cr_start();

	while(1) {
		printf("hello1\n");
		cr_yield();
		printf("hello2\n");
		cr_yield();
	}

	cr_end();
}

void routine2(void)
{
	cr_start();

	while(1) {
		printf("hello3\n");
		cr_yield();
	}

	cr_end();
}

int main(void)
{
	while(1) {
		routine1();
		routine2();
	}

	return 0;
}
