#ifndef UNSERIALIZE_EXCEPTION_H
#define UNSERIALIZE_EXCEPTION_H

#include <string>

using namespace std;

class UnserializeException : public exception{
    public:
        UnserializeException();
        UnserializeException(string message);

        string GetMessage();
    private:
        string message;
};

#endif //UNSERIALIZE_EXCEPTION_H