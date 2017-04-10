/**
 * ���ڻ�ȡ��i�е�ͷ���ַ��������ļ��е�λ��(position)
 * ע��: ҪŪ���һ���ļ�����β��������'\r\n', ����'\n'
 *
 * @param buf
 * @param lineNo ָ���к�
 * @param format �ļ���ʽ(dos => '\r\n', unix => '\n', mac => '\r')
 *
 * @return size_t
 */
size_t get_indexed_line_head_position(const std::string& buf, int lineNo, const std::string& format)
{
	size_t location = 0;
	std::string deli;
	if (format == "dos")
	{
		deli = "\r\n";
	}
	else if (format == "unix")
	{
		deli = "\n";
	}
	else if (format == "mac")
	{
		deli = "\r";
	}

	for (auto i = 0; i < lineNo - 1; i++)
	{
		auto index = buf.find(deli, location);
		if (index == -1)
		{
			return -1; //��ʾû��ָ���ķָ���
		}
		location = index + deli.length();
	}

	return location;
}


/**
 * ��content���뵽filePathָ���ļ��ĵ�line_no�п�ͷ��λ��
 *
 * @param filePath
 * @param line_no �к�(��1��ʼ)
 * @param content
 *
 * @return void
 */
void insert_content_to_file(const std::string& filePath, int line_no, const std::string& content)
{
	std::string old_content = get_file_content(filePath);
	size_t third_line_location = get_line_head_index(old_content, line_no, "dos");
	std::string head = old_content.substr(0, third_line_location);
	std::string tail = old_content.substr(third_line_location);
	std::ofstream fwstream(filePath, std::ios::out | std::ios::trunc);
	fwstream << head;
	fwstream << content;
	fwstream << tail;
	fwstream.close();
}