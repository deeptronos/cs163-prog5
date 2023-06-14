
#ifndef SOURCE_MY_EXCEPTIONS_H
#define SOURCE_MY_EXCEPTIONS_H

#include <iostream>
#include <stdexcept>
#include <string>


using namespace std;

class TargetNotFoundException : public logic_error{
public:
//	TargetNotFoundException(const string& message = "") : exception("Target not found: " + (message.c_str())){}
	TargetNotFoundException(const string& message = "") : logic_error("Target not found: " + (message)){}
};

class PreconditionViolatedException: public logic_error{
public:
	PreconditionViolatedException(const string& message = "") : logic_error("Violation of precondition: " + message){
	}

};

class NotFoundException: public logic_error{
public:
	NotFoundException(const string& message = "") : logic_error("Not found: " + message){
	}

};

class ConnectionException: public logic_error{
public:
	ConnectionException(const string& message="") : logic_error("An exception was encountered while dealing with a connection: " + message){
	}
};

#endif //SOURCE_MY_EXCEPTIONS_H

