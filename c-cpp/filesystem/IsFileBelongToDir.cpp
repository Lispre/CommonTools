/**
 * ����һ������·�����д���,�������·����\��β, 
 * ����ȥ��\���ַ���, ��ֱ�ӷ��� 
 *
 * @param foldPath ��Ҫ����ľ���·�����ַ���
 * @return std::string
 */
static std::string preprocess(const std::string& foldPath)
{
    size_t len = foldPath.length();
    if (foldPath[len - 1] == '\\')
    {
        return foldPath.substr(0, len - 1);
    }
    else
    {
        return foldPath;
    }
}

/**
 * ����һ���ַ������ľ���·���ĸ�·��, 
 * ��������ǰ�ļ���Ŀ¼���� 
 * 
 * @param path �ļ�����Ŀ¼�ľ���·��
 * 
 * @return std::string
 */
static std::string get_parent_path(const std::string& path)
{
    std::string folder_path = preprocess(folderPath);
    if (folder_path.empty())
    {
        return "";
    }
    size_t index = folder_path.find_last_of('\\');
    if (index == std::string::npos)
    {
        return "";
    }
    return folder_path.substr(0, index);
}

/**
 * �ж�һ���ļ�(��ͨ�ļ�����Ŀ¼)�Ƿ�λ����һ��Ŀ¼�� 
 * 
 * @param fullPathFileName �����жϵ��ļ�
 * @param fullPathDirName Ŀ��Ŀ¼
 * 
 * @return bool 
 */
static bool is_file_belong_to(const std::string& fullPathFileName, 
                              const std::string& fullPathDirName)
{
    std::string parent_path = get_parent_path(fullPathDirName);
    if (parent_path.compare(fullPathDirName) == 0) //��ʾ�ļ��ĸ�Ŀ¼������Ŀ¼��ͬ, Ҳ�����ļ�����ָĿ¼��
    {
        return true;
    }
    return false;
}
