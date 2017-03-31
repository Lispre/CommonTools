#include <thread>
#include <future>

std::atomic<bool> thread_finished(false);

//�����Ǻ�̨�̵߳���ں���ԭ��
return_type func_name(param_type1, param_type2);

//����һ��future�Ĺ������
std::packaged_task<return_type(param_type1, param_type2)>(func_name);
//�����������ʽҲ����
std::packaged_task<return_type(param_type1, param_type2)>([](param_type1 p1, param_type2 p2){});

std::future<return_type> thread_return_result = task.get_future();

//���ɹ����߳�
std::thread worker(std::move(task), true_p1, true_p2);

//����UI�߳���ѭ������̨�߳��Ƿ��Ѿ�����
//ע��:work_finished��һ��ȫ�ֵ�ԭ���Եı���
//Ҫ�ں�̨�߳��ж��������޸�, ��̨������ÿһ�����ڴ�������λ
while (!work_finished.load())
{
	//�޸�ͼ�ν���, ˢ��ͼ�ν���, ��ʱһ����ʱ��
	
}

//���̵߳ȴ����̵߳Ľ���
worker.join();

return_type result = thread_return_result.get()

//ʹ��return_type_result���к�������
//...