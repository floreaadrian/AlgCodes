#pragma once
#include "Evidence.h"
#include <string>
#include <vector>

class EvidenceException
{
private:
    std::vector<std::string> errors;
    
public:
    EvidenceException(std::vector<std::string> _errors);
    std::vector<std::string> getErrors() const;
    ~EvidenceException() {}
    
    
};

class EvidenceValidator
{
public:
    EvidenceValidator() {}
    void validate(const Evidence &evidence);
    void tests();
    ~EvidenceValidator() {}
};
