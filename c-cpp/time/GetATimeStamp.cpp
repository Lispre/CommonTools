#include <ctime>

/**
 * ����һ��ָ����ʽ��ʱ���
 * @param buf ���������buf��ַ
 * @param bufSize ���������buf�Ĵ�С
 * @param timeFormatString ���ʱ���ַ����ĸ�ʽ, ����:"%Y/%m/%d_%H:%M:%S"
 *
 * @return int �����ַ����ĳ���,�������û�а�������\0
 */
static int GetATimeStamp(char* buf, int bufSize, const char* timeFormatString)
{
	time_t raw_time;
	struct tm* time_info = nullptr;
	int len = 0;
	time(&raw_time);
	time_info = localtime(&raw_time);
	len = strftime(buf, bufSize, timeFormatString, time_info);
	buf[len] = '\0';

	return len;
}

//-------------------------------------------------------------------------------------
#include <ctime>

/**
 * ������timeFormatStringָ���ĸ�ʽ��ʱ����ַ���
 *
 * @param timeFormatString ָ��ʱ����ĸ�ʽ, ��"%Y/%m/%d_%H:%M:%S"
 *
 * @return std::string, Ϊ�ձ�ʾ�����˴���
 */
static std::string GetATimeStamp(const std::string& timeFormatString)
{
	std::array<char, 40> buf{};
	time_t raw_time;
	struct tm* time_info = nullptr;
	time(&raw_time);
	time_info = localtime(&raw_time);
	int len = strftime(buf.data(), buf.size(), timeFormatString.c_str(), time_info);
	if (len == 0)
	{
		return "";
	}
	else
	{
		return std::string(std::begin(buf), std::end(buf));
	}
}