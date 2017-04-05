/**
 * ��stringת����wstring
 * 
 * @param s
 * 
 * @return std::wstring
 */
std::wstring string2wstring(const std::string& s) 
{
    std::wstring ws{};
    ws.assin(s.begin(), s.end());
}

/**
 * ��wstringת����string
 * 
 * @param ws
 * 
 * @return std::string
 */
std::string wstring2string(const std::wstring& ws) 
{
    std::string s{};
    s.assign(ws.begin(), ws.end());
}
