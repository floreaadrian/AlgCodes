#pragma once
#include "Evidence.h"
#include <vector>
#include <string>

class Repository
{
public:
    Repository();
    virtual void addEvidence(Evidence evidence) = 0;
    virtual void deleteEvidence(std::string id) = 0;
    virtual void updateEvidence(std::string id, Evidence newEvidence) = 0;
    virtual std::vector<Evidence> getEvidence() = 0;
    virtual int findPositionById(std::string id)=0;
    virtual void settings(std::string newFile) = 0;
    ~Repository();
};
