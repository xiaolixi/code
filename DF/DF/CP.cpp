
#include "common.h"

class Chain{
public:
	Chain(int l) :m_level(l){}
	void setnext(Chain* next){
		m_next = next;
	}
	virtual void dosomething(int l,string message) = 0;
protected:
	Chain* m_next;
	int m_level;
};

class ConsoleLog :public Chain{
public:
	ConsoleLog(int l) :Chain(l){}
	
	void dosomething(int l, string message){
		if (m_level >= l){
			cout << "ConsoleLog handle " << message << endl;
		}
		else{
			m_next->dosomething(l, message);
		}
	}
};

class FileLog :public Chain{
public:
	FileLog(int l) :Chain(l){}

	void dosomething(int l, string message){
		if (m_level >= l){
			cout << "FileLog handle " << message << endl;
		}
		else{
			m_next->dosomething(l, message);
		}
	}
};

class ErrorLog :public Chain{
public:
	ErrorLog(int l) :Chain(l){}
	void dosomething(int l, string message){
		cout << "ErrorLog handle " << message << endl;
	}
};

int main(){
	unique_ptr<Chain> c(new ConsoleLog(1));
	unique_ptr<Chain> f (new FileLog(2));
	unique_ptr<Chain> e (new ErrorLog(3));
	c->setnext(f.get());
	f->setnext(e.get());

	c->dosomething(2, string("fileerror"));

	c->dosomething(3, string("Errorerror"));

	return 0;
}