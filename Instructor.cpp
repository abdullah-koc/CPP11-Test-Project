#include "Instructor.h"

Instructor::Instructor()
{
}

Instructor::Instructor(int insId, shared_ptr<string> lecture)
{
	id = insId;
	this->lecture = lecture;
}

int Instructor::getInsId() const
{
	return id;
}

string Instructor::getLecture() const
{
	return *lecture;
}


