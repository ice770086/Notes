#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
#include <string>
#include <mutex>

class Singleton {
public:
	static Singleton* GetInstance() {
		if (instance_ == nullptr) {
			// ������֤����̲߳�������getInstance()ʱֻ�ᴴ��һ��ʵ��
			m_mutex_.lock();
			if (instance_ == nullptr) {
				instance_ = new Singleton();
			}
			m_mutex_.unlock();
		}
		return instance_;
	}
private:
	Singleton() {}
	static Singleton* instance_;
	static std::mutex m_mutex_;
};

#endif  // SINGLETON_H_