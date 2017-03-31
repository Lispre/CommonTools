/**
 * ������һ���ļ�����һ���ļ�, ���Ŀ���ļ��Ѿ������򸲸���������
 * 
 * @param oldFullPathName
 * @param newFullPathName
 * 
 * @return 0��ʾ�����˴���, ��0��ʾ�ɹ�
 */

static inline int rename_file(const std::string& oldFullPathName, 
                              const std::string& newFullPathName)
{
    return MoveFileEx(oldFullPathName.c_str(), 
                      newFullPathName.c_str(), 
                      MOVEFILE_REPLACE_EXISTING | MOVEFILE_COPY_ALLOWED);
}
