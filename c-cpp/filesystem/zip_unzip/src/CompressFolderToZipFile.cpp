#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include <Windows.h>

#include "../inc/compress.hpp"

constexpr int BUFFER_LENGTH = 1024;

int GetAllFilesPath(const std::string& path, std::vector<std::string>& fullPathNames)
{
	WIN32_FIND_DATAA FindData;
	HANDLE hFileSearch;
	int FileCount = 0;
	char FilePathName[BUFFER_LENGTH];
	char FullPathName[BUFFER_LENGTH];
	strcpy_s(FilePathName, path.c_str());
	strcat_s(FilePathName, "\\*.*");
	hFileSearch = FindFirstFileA(FilePathName, &FindData);
	if (hFileSearch == INVALID_HANDLE_VALUE)
	{
		std::cout << "Open file handle error !!!" << std::endl;
		return -1;
	}

	while (::FindNextFileA(hFileSearch, &FindData))
	{
		if (strcmp(FindData.cFileName, ".") == 0
			|| strcmp(FindData.cFileName, "..") == 0)
		{
			continue;
		}

		sprintf_s(FullPathName, "%s\\%s", path.c_str(), FindData.cFileName);
		FileCount++;
		fullPathNames.push_back(FullPathName);

		if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			std::cout << "<DIR>" << std::endl;
			int res = GetAllFilesPath(FullPathName, fullPathNames);
			if (res >= 0)
			{
				FileCount += res;
			}
			else
			{
				return -1;
			}
		}
	}

	return FileCount;
}

// ����������·���еķָ��������˴���
// ��׼ʹ�õ���б��
// ����Windows��ʹ�õ��Ƿ�б��
bool CompressFolderToZipFile(const std::string& sourceFolder, const std::string& zipFileName)
{
	struct stat info;
	if (stat(sourceFolder.c_str(), &info) == 0 && info.st_mode & S_IFDIR)
	{
		std::vector<std::string> file_name_list;
		// ��ȡһ��·������������ļ���·����
		GetAllFilesPath(sourceFolder, file_name_list);
		std::size_t file_counter = file_name_list.size();

		ziputils::zipper zipFile;
		std::size_t index = sourceFolder.find_last_of("/\\");
		// ��ʾ�����Ŀ¼ѹ����ͬ��Ŀ¼�µ�һ��zip�ļ�
		std::string father_folder = sourceFolder.substr(0, index + 1);
		zipFile.open(father_folder.append(zipFileName).c_str());

		// add files to the zip file
		for (auto i = 0; i < file_counter; i++)
		{
			// ��һ�����ж��ǲ��Ƕ�����, ��Ϊ����file_counterֻ���ļ�������,������Ŀ¼
			if (stat(file_name_list[i].c_str(), &info) == 0 && info.st_mode & S_IFDIR)
			{
				continue;
			}

			std::ifstream file(file_name_list[i], std::ios::in | std::ios::binary);
			if (file.is_open())
			{
				std::string entryItem = file_name_list[i].substr(sourceFolder.length(), file_name_list[i].length());
				std::replace(entryItem.begin(), entryItem.end(), '\\', '/');
				zipFile.addEntry(entryItem.c_str());
				zipFile << file;
			}
		}
		zipFile.close();
		return true;
	}
	else
	{
		std::cout << "The folder for compress is error!!!";
		return false;
	}
}
