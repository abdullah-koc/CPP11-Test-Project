#include <iostream>
#include "Student.h"
#include "Instructor.h"
#include <utility>

using namespace std;

typedef string Lecture;

auto ShowStudents = [](const vector<Student*>& students)
{
	cout << endl << "Students:" << endl;
	for (auto& s : students)
	{
		printf("%4s %10s\n", "ID", "Name");
		printf("%4d %10s\n", s->GetId(), s->GetName().c_str());
		cout << "Lectures Taken: " << endl;
		s->GetLecturesTaken();
		cout << endl;
	}
};

auto ShowInstructors = [](const vector <Instructor*>& instructors)
{
	cout << endl << "Instructors:" << endl;
	for (auto& i : instructors)
	{
		printf("%4s %10s\n", "ID", "Lecture");
		printf("%4d %10s\n", i->GetInsId(), i->GetLecture().c_str());
	}
};

int main(int argc, char* argv[]) {

	vector<Student*> students;
	vector <Instructor*> instructors;

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
	unique_ptr<Student> st5 = make_unique<Student>(5, "Oya");
	students.push_back(st5.get());
	unique_ptr<Student> st6 = make_unique<Student>(6, "Cem");
	students.push_back(st6.get());
	unique_ptr<Student> st7 = make_unique<Student>(7, "Selim");
	students.push_back(st7.get());

	unique_ptr<Instructor> i1 = make_unique <Instructor>(1, l1);
	instructors.push_back(i1.get());
	unique_ptr<Instructor> i2 = make_unique <Instructor>(2, l2);
	instructors.push_back(i2.get());

	students[0]->AddLecture(l1);
	students[0]->AddLecture(l2);
	students[0]->AddLecture(l3);
	students[0]->AddLecture(l4);
	students[0]->AddLecture(l5);
	students[0]->AddLecture(l6);
	students[0]->AddGrade(l1, 100);
	students[0]->AddGrade(l1, 120);
	students[0]->AddGrade(l2, 60);
	students[0]->AddGrade(l3, 80);
	students[0]->AddGrade(l4, 30);

	students[1]->AddLecture(l1);
	students[1]->AddGrade(l1, 120);

	students[0]->GetGrades();

	students[1]->GetGrades();

	ShowStudents(students);
	students[0]->GetGrades();

	ShowInstructors(instructors);

	return 0;
}
