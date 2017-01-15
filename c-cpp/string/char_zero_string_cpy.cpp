// Char* �ַ�������
// ����:Ŀ�ĵ�ַ, Դ��ַ, ����������ֽ���
void SafeStrCpy(char* dest, char* src, int max_bytes)
{
	int src_len = static_cast<int>(strlen(src)) + 1;
	if (!dest)
	{
		goto SafeStrCpy_END;
	}
	if (!src)
	{
		goto SafeStrCpy_END;
	}
	if (src_len > max_bytes)
	{
		src_len = max_bytes;
	}
	memcpy(dest, src, src_len);
	*(dest+src_len-1) = '\0';

SafeStrCpy_END:
	return;
}