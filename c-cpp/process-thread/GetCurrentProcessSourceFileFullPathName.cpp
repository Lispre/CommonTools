/**
 * ������ʱ��ȡ���̾����ļ���·��(��֧������)
 *
 * @return std::string
 */
std::string get_process_image_file_path()
{
	char path[2048];
	GetModuleFileNameA(nullptr, path, sizeof(path));
	return path;
}