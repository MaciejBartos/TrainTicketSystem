#ifndef TICKETSTRAINSYSTEM_EXCEPTION_H
#define TICKETSTRAINSYSTEM_EXCEPTION_H

#include <string>

class Exception : public std::exception{
private:
    const char* _msg;
public:
    Exception(const char* statement): _msg(statement){};
    ~Exception() throw(){};
    virtual const char* what() const throw(){
        return _msg;
    };
};


#endif //TICKETSTRAINSYSTEM_EXCEPTION_H
