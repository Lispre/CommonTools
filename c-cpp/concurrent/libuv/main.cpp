#include <stdio.h>
#include <stdlib.h>
#include <uv.h>
/**
 * libuv.lib
 * ws2_32.lib
 * Psapi.lib
 * Iphlpapi.lib
 * userenv.lib
 * msvcrt.lib
 * ������Щ��̬��һ��Ҫ���ӵ�������, ��Ȼ���޷�ʹ��libuv�ľ�̬��
*/

int main() {
	uv_loop_t *loop = (uv_loop_t*)malloc(sizeof(uv_loop_t));
	uv_loop_init(loop);

	printf("Now quitting.\n");
	uv_run(loop, UV_RUN_DEFAULT);

	uv_loop_close(loop);
	free(loop);
	return 0;
}