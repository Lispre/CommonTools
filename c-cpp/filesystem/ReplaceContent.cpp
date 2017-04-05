/**
 * �ж�һ���ַ����Ƿ�����һ���ַ�����Ϊ��β
 *
 * @param src
 * @param test
 * 
 * @return bool
 */

static bool IsEndWith(const std::string& src, const std::string& test)
{
    size_t src_len = src.length();
    size_t test_len = test.length();
    if (src_len < test_len)
    {
        return false;
    }
    std::string end_str = src.substr(src_len - test_len, src_len - 1);
    if (test == end_str)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * �޸��ı��ļ��е�����, ���ļ���Ѱ�ҵ�map�е�key, ���滻��value
 * ע��: ����һ����ȫƥ�䲢�滻�Ĺ���, ���� abc_defƥ��abc_def, ��������ƥ��abc_defg, 
 * 
 * @param filePath ��Ҫ�޸ĵ��ļ��ľ���·��
 * @param modifyContent Ҫ�޸ĵ�������ɵ�map
 * 
 * @return void
 */
void modify_content(const std::string& filePath, std::map<std::string, std::string>& modifyContent)
{
	if (IsEndWith(filePath, ".ocs") || IsEndWith(filePath, ".obj")) {
		auto content = std::make_shared<std::vector<std::string>>();
		std::ifstream file_before_modify(filePath);
		std::string line{};

		while (std::getline(file_before_modify, line))
		{
			if (line.empty())
			{
				continue;
			}
			content->push_back(line);
		}
		file_before_modify.close();

		for (auto& x : modifyContent)
		{
			// set this for pattern match entity world
			std::regex reg(R"(\b)" + x.first R"(\b)");
			std::string replacement(x.second);
			for (auto& line_ : *content)
			{
				std::string result = std::regex_replace(line_, reg, replacement);
				line_ = result;
			}
		}

		std::ofstream file_after_modify(filePath);
		for (auto& line_ : *content)
		{
			file_after_modify << line_ << "\n";
		}
		file_after_modify.close();
	}
}
