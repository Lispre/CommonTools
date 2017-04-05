/**
 * �ж�һ�������Ƿ񻹴����ڽ����б���
 * 
 * @param processName ���̵���������
 *
 * @return bool
 */
bool IsProcessExists(const std::string& processName)
{
	auto result = false;

	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (handle == INVALID_HANDLE_VALUE)
	{
		goto END;
	}
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(entry);
	if (!Process32First(handle, &entry))
	{
		goto END;
	}

	do
	{
		if (strcmp(entry.szExeFile, processName.c_str()) == 0)
		{
			result = true;
		}
	} while (Process32Next(handle, &entry));
END:
	CloseHandle(handle);
	return result;
}
