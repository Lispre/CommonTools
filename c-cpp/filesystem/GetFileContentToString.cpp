#include <string>
#include <cstdio>
#include <cerrno>
#include <iostream>
#include <fstream>

/**
 * ��ȡ�ļ����ݵ��ַ���, (���ļ�ʧ�ܳ���쳣)
 *
 * @param filePath
 *
 * @return std::string
 */
std::string get_file_content(const std::string& filePath)
{
	std::FILE* fp = std::fopen(filePath.c_str(), "rb");
	if (!fp)
	{
		throw(errno); //�ļ������ݿ���Ϊ��,����ֻ��ͨ���׳��쳣�ķ�ʽ�����߳����˴���
	}

	std::string content;
	std::fseek(fp, 0, SEEK_END);
	content.resize(std::ftell(fp));
	std::rewind(fp);
	std::fread(&content[0], 1, content.size(), fp);
	std::fclose(fp);

	return content;
}
