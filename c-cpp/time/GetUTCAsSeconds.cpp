#include <chrono>
/**
 * ���ַ�������ʽ��ȡ1990��1��1��0ʱ0��0�����������
 *
 * @return std::string
 */
std::string GetUTC() 
{
	auto timestamp = std::chrono::seconds(std::time(nullptr));
	int seconds = std::chrono::seconds(timestamp).count();
	auto str = std::to_string(seconds);
	return str;
}