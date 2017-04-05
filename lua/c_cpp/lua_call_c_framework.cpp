#include "lua.h"

int function_name(lua_State* L) {
	// operation here
	// todo

	// m objects pushed to the lua stack
	return m;
}

const struct luaL_Reg myLib[] = {
	{"export_name", function_name},
	{nullptr, nullptr}
};

// This is for lua use interface like this:
// require("LIB_NAME")
// here the LIB_NAME.dll is in the lua find path
// ע��: LIB_NAME.dll���ܱ��ĳ�����������,������޷�����,�ļ���Ҫ�ͷ��ű��е����ֱ���һ��
extern "C" __declspec(dllexport) int luaopen_LIB_NAME(lua_State* L)
{
	luaL_register(L, "LIB_NAME", myLib);

	return 0;
}