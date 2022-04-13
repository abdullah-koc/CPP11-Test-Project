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

	int GetId() const;

	void SetId(int id);

	string GetName() const;

	void SetName(string name);

	void GetLecturesTaken() const;

	void GetGrades() const;

	int AddLecture(shared_ptr<string> lecture);

	int AddGrade(const shared_ptr<string>& lecture, const int& grade);

	int ChangeGrade(const shared_ptr<string>& lecture, const int& grade);

private:
	int id{};
	string name{};
	vector<shared_ptr<string>> lecturesTaken{};
	map<shared_ptr<string>, int> grades{};


};

