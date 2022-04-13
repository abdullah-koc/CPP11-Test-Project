#include "Instructor.h"

Instructor::Instructor()
{
}

Instructor::Instructor(int insId, shared_ptr<string> lecture)
{
	id = insId;
	this->lecture = lecture;
	cout << "Instructor " << insId << " constructor" << endl;

}

Instructor::~Instructor()
{
	cout << "Instructor " << id << " constructor" << endl;
}

int Instructor::getInsId() const
{
	return id;
}

string Instructor::getLecture() const
{
	return *lecture;
}


