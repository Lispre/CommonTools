typedef struct
{
	int head;
	int size;
	char data[0];
} PacketType;

// �÷�:
char* buf = new char[sizeof(PacketType) + dataSize];
PacketType* pkt_buf = (PacketType*)buf;
pkt_buf->data // �˾ͻ��������buf