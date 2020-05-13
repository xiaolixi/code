#include "common.h"

class Student{
private:
	string m_name;
	string m_address;
public:
	void set_name(string& name){
		m_name = name;
	}
	void set_address(string& address){
		m_address = address;
	}
	const string& get_name()const{
		return m_name;
	}

	const string& get_address()const{
		return m_address;
	}
};

class StudentView{
public:
	void display_details(const Student* stu){
		cout << "students:\n";
		cout << "address  ";
		cout << stu->get_address() << endl;
		cout << "name     ";
		cout << stu->get_name() << endl;
	}
};

class Control{
private:
	Student* m_pstudent;
	StudentView* m_pview;
public:
	Control(Student* stu, StudentView* view){
		m_pstudent = stu;
		m_pview = view;
	}
	void set_name(string& name){
		m_pstudent->set_name(name);
	}
	void set_address(string& address){
		m_pstudent->set_address(address);
	}
	void update_view(){
		m_pview->display_details(m_pstudent);
	}
};

static Student* get_student_from_database(){
	Student* ret = new Student();
	ret->set_address(string("ºÇºÇºÇºÇ"));
	ret->set_name(string("Ä­Ä­"));
	return ret;
}

int main(){
	shared_ptr<Student>stu(get_student_from_database());
	unique_ptr<StudentView> view(new StudentView());
	unique_ptr<Control> con(new Control(stu.get(), view.get()));

	con->update_view();

	con->set_address(string("O(¡É_¡É)O¹ş¹ş¹ş~"));
	con->update_view();
	return 0;
}