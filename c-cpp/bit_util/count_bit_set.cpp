/**
 * ����һ���޷����������Ķ����Ʊ�ʾ���ж���λ����λ
 * 
 * @param v ������޷��ŵ�����
 * 
 * @return unsigned int
*/
unsigned int get_bit_sets(unsigned int v)
{
    unsigned int c = 0;
    for (c = 0; v; c++) 
	{
        v &= v - 1;
    }
}