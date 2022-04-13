#include "Student.h"

Student::Student(int id, string name)
{
	this->id = id;
	this->name = name;
	cout << "Student " << id << " constructor" << endl;
}

Student::~Student()
{
	cout << "Student " << id << " destructor" << endl;
}

int Student::getId() const
{
	return id;
}

void Student::setId(int id)
{
	this->id = id;
}

string Student::getName() const
{
	return name;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::getLecturesTaken() const
{
	for (auto const& l : lecturesTaken)
	{
		cout <<"Lecture " <<  *l << endl;
	}
	if (lecturesTaken.size() == 0)
	{
		cout << "  No Lectures" << endl;
	}
}

void Student::getGrades() const
{
	for (auto& g : grades)
	{
		cout << "Lecture: " << *g.first << ", Grade: " << g.second << endl;
	}
}

int Student::addLecture(shared_ptr<string> lecture)
{
	for (auto& l : lecturesTaken) 
	{
		if (*l == *lecture)
		{
			cout << "Lecture " << *lecture << " already exists." << endl;
			return -1;
		}
	}
	lecturesTaken.push_back(lecture);
	cout << "Lecture " << *lecture << " was successfully added." << endl;
	return 0;
}

int Student::addGrade(const shared_ptr<string>& lecture, const int& grade)
{
	for (auto& l : lecturesTaken)
	{
		if (*l == *lecture)
		{
			for (auto& g : grades)
			{
				if (*g.first == *lecture)
				{
					cout << "Student " << id << " has already got a grade from lecture " << *lecture << ". Updating the grade..." << endl;
					return changeGrade(lecture, grade);
				}
			}
			grades.emplace(lecture, grade);
			cout << "Grade inserted successfully." << endl;
			return 0;
		}
	}
	cout << "Lecture " << *lecture << " does not exist." << endl;
	return -1;
}

int Student::changeGrade(const shared_ptr<string>& lecture, const int& grade)
{
	for (auto& l : lecturesTaken)
	{
		if (*l == *lecture)
		{
			for (auto& g : grades)
			{
				if (*g.first == *lecture)
				{
					g.second = grade;
					cout << "Grade changed successfully." << endl;
					return 0;
				}
			}
		}
	}
	cout << "Lecture " << *lecture << " does not exist." << endl;
	return -1;
}
