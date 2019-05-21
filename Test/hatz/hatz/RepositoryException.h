#pragma once
#include <string>

class RepositoryException : public std::exception
{
private:
    std::string message;
public:
    RepositoryException(const std::string &message);
    std::string get_message();
    ~RepositoryException();
};

