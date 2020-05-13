#include <iostream>

using namespace std;
//1 auto decltype
template<typename T1,typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1+t2){
	return t1 + t2;
}
//2 override final
//重写const 和 参数错误，变成重载了
class A{
public:
	virtual void f(short i){
		cout << "A::f()" << endl;
	}
	virtual void g(short i) const {
		cout << "A::g()" << endl;
	}
};
class B : public A{
public:
	virtual void f(int i){
		cout << "B::f()" << endl;
	}
	virtual void g(short i) {
		cout << "B::g()" << endl;
	}
};
int main(){
	//auto v = add(2, 9.09);
	//cout << v << endl;

	A& a = B();
	a.f(int(0));
	a.g(0);
	return 0;
}