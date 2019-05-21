#pragma once
#include "Repository.h"
#include "EvidenceValidator.h"

class Controller
{
private:
    Repository *repository;
    Repository *userRepository;
    EvidenceValidator validator;
    
public:
    Controller(Repository *repository,
               Repository *userRepository,
               EvidenceValidator validator);
    
    std::string addEvidenceToRepository(const std::string &id, const std::string &measurement,
                                        const float &imageClarityLevel, const float &quantity,
                                        const std::string &photograph);
    std::string addEvidenceToMyList(Evidence evidence);
    std::string deleteEvidenceFromRepository(std::string id);
    std::string updateEvidence(const std::string &id, const std::string &measurement,
                               const float &imageClarityLevel, const float &quantity,
                               const std::string &photograph);
    std::vector<Evidence> getAllEvidence();
    std::vector<Evidence> getMyListOfEvidence();
    
    void setFileName(std::string newName);
    
    void tests();
    
    void testAdd();
    void testDelete();
    void testUpdate();
    
    
    
};
