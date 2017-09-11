#pragma once

template <class T>
Class Singleton {
protected:
	Singleton() {};
	Singleton(const Singleton&) = delete;
	Singleton& operator =(const Singleton&) = delete;
	Singleton(const Singleton&&) = delete;
	Singleton& operator =(const Singleton&&) = delete;

private:
	static T* instance_;

public:
	static T* GetInstance();
};

template <class T>
T* Singleton<T>::GetInstance()
{
	static T t;
	return &t;
}

// exmaple
// class Student : Singleton<Student> {
//		xxxx
// };
// ����Student�ͳ�Ϊ�˵�����, ���������ɶ���ʱ�̰߳�ȫ��