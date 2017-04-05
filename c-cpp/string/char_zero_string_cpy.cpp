/**
 * ��ȫ��ʵ���ַ����ĸ���
 * 
 * @param dest Ŀ�껺����
 * @param src Դ������
 * @param max_bytes dest�����������ռ�
 * 
 * @return int (�������ַ�������,������ֵ��max_bytes��ȵ�ʱ��, Ӧ��֪��ʵ��������ĸ�����max_bytes-1, dest�����һbyte�������\0,
 *			   ���κ�һ��ָ���ǿյ�ʱ��ͷ���0
 */
int SafeStrCpy(char* dest, char* src, int max_bytes)
{
	int src_len_with_zero = 0;

	if (!dest || !src)
	{
		goto SafeStrCpy_END;
	}
	
	src_len_with_zero = static_cast<int>(strlen(src)) + 1;
	if (src_len_with_zero > max_bytes)
	{
		src_len_with_zero = max_bytes;
	}
	memcpy(dest, src, src_len_with_zero);
	*(dest+src_len-1) = '\0';

SafeStrCpy_END:
	return src_len_with_zero;
}