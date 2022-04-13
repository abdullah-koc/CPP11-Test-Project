#include "Student.h"

Student::Student(int id, string name)
{
	this->id = id;
	this->name = name;
}

int Student::GetId() const
{
	return id;
}

void Student::SetId(int id)
{
	this->id = id;
}

string Student::GetName() const
{
	return name;
}

void Student::SetName(string name)
{
	this->name = name;
}

void Student::GetLecturesTaken() const
{
	for (auto const& l : lecturesTaken)
	{
		cout << "Lecture " << *l << endl;
	}
	if (lecturesTaken.size() == 0)
	{
		cout << "  No Lectures" << endl;
	}
}

void Student::GetGrades() const
{
	for (auto& g : grades)
	{
		cout << "Lecture: " << *g.first << ", Grade: " << g.second << endl;
	}
}

int Student::AddLecture(shared_ptr<string> lecture)
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

int Student::AddGrade(const shared_ptr<string>& lecture, const int& grade)
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
					return ChangeGrade(lecture, grade);
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

int Student::ChangeGrade(const shared_ptr<string>& lecture, const int& grade)
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
