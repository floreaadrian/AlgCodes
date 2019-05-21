#pragma once
#include "Repository.h"
#include <string>
#include <vector>

class FileRepository :public Repository
{
private:
    std::string filePath;
    
public:
    FileRepository();
    
    std::string getPath();
    void settings(std::string newPath) override;
    
    void addEvidence(Evidence evidence) override;
    void deleteEvidence(std::string id) override;
    void updateEvidence(std::string id, Evidence newEvidence) override;
    
    int findPositionById(std::string id) override;
    
    std::vector<Evidence> getEvidence() override;
    std::vector<Evidence> readFromFile();
    
    void writeToFile(std::vector<Evidence> listOfEvidence);
    
    void tests();
    void addTest();
    void deleteTest();
    void updateTest();
    
    ~FileRepository() ;
    
};
