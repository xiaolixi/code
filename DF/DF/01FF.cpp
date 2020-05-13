#include "common.h"


class Shape{
public:
	virtual void draw() = 0;
	virtual ~Shape(){}
};

class Circle : public Shape{
public:
	virtual void draw(){
		cout << "��һ��Բ��" << endl;
	}
	~Circle(){
		cout << "����һ��Բ��" << endl;
	}
};

class Square : public Shape{
public:
	virtual void draw(){
		cout << "��һ��������" << endl;
	}
	~Square(){
		cout << "����һ��������" << endl;
	}
};

class Reatangle : public Shape{
public:
	virtual void draw(){
		cout << "��һ��������" << endl;
	}
	~Reatangle(){
		cout << "����һ��������" << endl;
	}
};

template <typename BASECLASS ,typename CLASSNAME>
BASECLASS* create_object(){
	return new CLASSNAME();
}

template <typename BASECLASS>
class Factory{
public:
	typedef typename BASECLASS baseClass;
	typedef baseClass* (*fun)();
private:
	map<string, fun> m_map;
public:
	baseClass* get_shape(string& classname){
		if (m_map.find(classname) != m_map.end()){
			return m_map[classname]();
		}
		cout << "��ע�����" << endl;
		return nullptr;
	}
	void register_class(string& classname, fun f){
		m_map.insert(make_pair(classname,f));
	}
};

int main(){

	Factory<Shape> f;
	f.register_class(string("Square"), create_object<Shape, Square>);
	f.register_class(string("Circle"), create_object<Shape, Circle>);

	unique_ptr<Shape> re(f.get_shape(string("Square")));
	re->draw();

	re = unique_ptr<Shape>(f.get_shape(string("Circle")));
	re->draw();

	re = unique_ptr<Shape>(f.get_shape(string("Reatangle")));
	return 0;
}