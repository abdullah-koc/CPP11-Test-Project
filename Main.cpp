#include <iostream>
#include "Student.h"
#include "Instructor.h"
#include <utility>
using namespace std;


vector<Student*> students;
vector <Instructor*> instructors;
typedef string Lecture;

auto showStudents = []()
{
	cout << endl << "Students:" << endl;
	for (auto& s : students)
	{
		printf("%4s %10s\n", "ID", "Name");
		printf("%4d %10s\n", s->getId(), s->getName().c_str());
		cout << "Lectures Taken: " << endl;
		s->getLecturesTaken();
		cout << endl;
	}
};

auto showInstructors = []()
{
	cout << endl << "Instructors:" << endl;
	for (auto& i : instructors)
	{
		printf("%4s %10s\n", "ID", "Lecture");
		printf("%4d %10s\n", i->getInsId(), i->getLecture().c_str());
	}
};

int main() {
	
	shared_ptr<Lecture> l1 = make_shared<Lecture>("L1");
	shared_ptr<Lecture> l2 = make_shared<Lecture>("L2");
	shared_ptr<Lecture> l3 = make_shared<Lecture>("L3");
	shared_ptr<Lecture> l4 = make_shared<Lecture>("L4");
	shared_ptr<Lecture> l5 = make_shared<Lecture>("L5");
	shared_ptr<Lecture> l6 = make_shared<Lecture>("L6");
	shared_ptr<Lecture> l7 = make_shared<Lecture>("L7");
	shared_ptr<Lecture> l8 = make_shared<Lecture>("L8");
	shared_ptr<Lecture> l9 = make_shared<Lecture>("L9");
	shared_ptr<Lecture> l10 = make_shared<Lecture>("L10");



	unique_ptr<Student> st1 = make_unique<Student>(1, "Ahmet");
	students.push_back(st1.get());
	unique_ptr<Student> st2 = make_unique<Student>(2, "Mehmet");
	students.push_back(st2.get());
	unique_ptr<Student> st3 = make_unique<Student>(3, "Ayse");
	students.push_back(st3.get());
	unique_ptr<Student> st4 = make_unique<Student>(4, "Veli");
	students.push_back(st4.get());
	unique_ptr<Student> st5 = make_unique<Student>(5, "Ahmet");
	students.push_back(st5.get());
	unique_ptr<Student> st6 = make_unique<Student>(6, "Ahmet");
	students.push_back(st6.get());
	unique_ptr<Student> st7 = make_unique<Student>(7, "Ahmet");
	students.push_back(st7.get());

	unique_ptr<Instructor> i1 = make_unique <Instructor>(1, l1);
	instructors.push_back(i1.get());
	unique_ptr<Instructor> i2 = make_unique <Instructor>(2, l2);
	instructors.push_back(i2.get());
	
	students[0]->addLecture(l1);
	students[0]->addLecture(l2);
	students[0]->addLecture(l3);
	students[0]->addLecture(l4);
	students[0]->addLecture(l5);
	students[0]->addLecture(l6);
	cout << "test" << endl;

	students[0]->addGrade(l1, 100);
	students[0]->addGrade(l1, 120);
	students[0]->addGrade(l2, 60);
	students[0]->addGrade(l3, 80);
	students[0]->addGrade(l4, 30);

	students[1]->addLecture(l1);
	students[1]->addGrade(l1, 120);

	students[0]->getGrades();

	students[1]->getGrades();

	showStudents();

	students[0]->getGrades();

	showInstructors();

	return 0;
}