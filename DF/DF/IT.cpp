#include "common.h"

class SafearrayIterator{
	int* m_pcontainer;
	int index;
public:
	SafearrayIterator(int* pcon, int in){
		m_pcontainer = pcon;
		index = in;
	}
	int& operator*(){
		return m_pcontainer[index];
	}
	int operator[](int i){
		return m_pcontainer[index];
	}
	SafearrayIterator& operator++(int){
		++index;
		return *this;
	}
	bool operator!=(const SafearrayIterator& ot){
		return index != ot.index;
	}
};
class Safearray {
private:
	int* m_p;
	int length;
public:
	Safearray(int n){
		m_p = new int[n];
		length = n;
	}
	SafearrayIterator begin(){
		return SafearrayIterator(m_p, 0);
	}
	SafearrayIterator end(){
		return SafearrayIterator(m_p, length);
	}
};

int main(){
	Safearray c(10);
	SafearrayIterator it = c.begin();
	for (; it != c.end(); it++){
		*it = 0;
		cout << *it  << " " << it[0] << endl;
	}
	return 0;
}