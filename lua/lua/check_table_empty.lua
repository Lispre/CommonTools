-- ���lua�е�һ�����Ƿ�Ϊ��
function IsTableEmpty(tableName)
	local next_ = next
	if next_(tableName) == nil then
		return true
	else
		return false
	end
end

-- ��ȡlua��һ�������ж��ٸ�Ԫ��, ���ǵ�һ����Ԫ��
function GetTableSize(tableName)
	local size = 0
	for _ in pairs(table) do
		size = size + 1
	end

	return size
end