// ʹ��VC����ʱ�ṩ�Ĺ���������Ƿ����ڴ�й©
// ��Ȼ���ֻ����Debugģʽ��ʹ��

#define _CRTDBG_MAP_ALLOC
#include <Windows.h>
#include <crtdbg.h>

int main(int argc, char* argv[])
{
	// all functions write here
	
	// �����������֮��, debugģʽ�¾Ϳ��Կ���������п���
	// �ڴ�й©����ı���
	_CrtDumpMemoryLeaks();

	return 0;
}