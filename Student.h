#pragma once
#include <string>
#include <map>
#include <vector> 
#include <iostream>

using namespace std;


class Student
{
public:
	Student() = delete;

	Student(int id, string name);

	virtual ~Student();

	int getId() const;

	void setId(int id);

	string getName() const;

	void setName(string name);

	void getLecturesTaken() const;

	void getGrades() const;

	int addLecture(shared_ptr<string> lecture);

	int addGrade(const shared_ptr<string>& lecture, const int& grade);

	int changeGrade(const shared_ptr<string>& lecture, const int& grade);

private:
	int id{};
	string name{};
	vector<shared_ptr<string>> lecturesTaken{};
	map<shared_ptr<string>, int> grades{};


};

