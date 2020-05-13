#include "common.h"
#include <Windows.h>
mutex g_mutex;


class Singletion{
public:
	static Singletion* get_instance(){
		if (pins == nullptr){
			g_mutex.lock();
			if (pins == nullptr){
				Sleep(1000);
				pins = new Singletion;
			}
			g_mutex.unlock();
		}
		return pins;
	}
	static void free_instance(){
		delete pins;
	}
	void run(){
		cout << " run..... \n";
	}
private:
	Singletion(){}
	static Singletion* pins;
};

Singletion* Singletion::pins = nullptr;


void thread1(){
	Singletion* p1 = Singletion::get_instance();
	int i = 0;
	while (i++ != 20){
		cout << (int)(p1) << " thread1 ";
		p1->run();
	}
}

void thread2(){
	Singletion* p2 = Singletion::get_instance();
	int i = 0;
	while (i++ != 20){
		cout << (int)(p2) << " thread2 ";
		p2->run();
	}
}
int main(){

	thread first(thread1);
	thread second(thread2);
	Singletion* pm = Singletion::get_instance();
	int i = 0;
	while (i++ != 20){
		cout << (int)(pm) << " main thread ";
		pm->run();
	}

	first.join();
	second.join();
	delete pm;
	return 0;
}