#include "RepositoryException.h"



RepositoryException::RepositoryException(const std::string &message) :
message{ message }
{
}

std::string RepositoryException::get_message()
{
    return this->message;
}

RepositoryException::~RepositoryException()
{
}
