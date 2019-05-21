#include "MemoryRepository.h"
#include "RepositoryException.h"
#include <assert.h>

MemoryRepository::MemoryRepository()
{
    
}

void MemoryRepository::addEvidence(Evidence evidence)
{
    
    for (size_t i = 0; i < evidenceDataBase.size(); i++)
        if (evidenceDataBase[i].getId() == evidence.getId())
            throw(RepositoryException("Already there\n"));
    evidenceDataBase.push_back(evidence);
}

void MemoryRepository::deleteEvidence(std::string id)
{
    
    int position = this->findPositionById(id);
    evidenceDataBase.erase(evidenceDataBase.begin() + position);
    
}

void MemoryRepository::updateEvidence(std::string id, Evidence newEvidence)
{
    int position = this->findPositionById(id);
    evidenceDataBase[position] = newEvidence;
}

int MemoryRepository::findPositionById(std::string id)
{
    for (size_t i = 0; i < evidenceDataBase.size(); i++)
        if (evidenceDataBase[i].getId() == id)
            return i;
    return -1;
}

std::vector<Evidence> MemoryRepository::getEvidence()
{
    return this->evidenceDataBase;
}

void MemoryRepository::settings(std::string new_path) {}

