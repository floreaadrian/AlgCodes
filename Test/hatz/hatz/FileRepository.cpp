#include "FileRepository.h"
#include "RepositoryException.h"
#include <fstream>
#include <iostream>
#include <assert.h>

FileRepository::FileRepository()
{
    
}

std::string FileRepository::getPath()
{
    return this->filePath;
}

void FileRepository::settings(std::string newPath)
{
    this->filePath = newPath;
}

void FileRepository::addEvidence(Evidence evidence)
{
    std::vector<Evidence> allEvidence = this->readFromFile();
    for (size_t i = 0; i < allEvidence.size(); i++)
        if (allEvidence[i].getId() == evidence.getId())
            throw(RepositoryException("Already there\n"));
    allEvidence.push_back(evidence);
    this->writeToFile(allEvidence);
}

void FileRepository::deleteEvidence(std::string id)
{
    std::vector<Evidence> allElements = this->readFromFile();
    int position = this->findPositionById(id);
    allElements.erase(allElements.begin() + position);
    this->writeToFile(allElements);
    
}

void FileRepository::updateEvidence(std::string id, Evidence newEvidence)
{
    std::vector<Evidence> allElements = this->readFromFile();
    int position = this->findPositionById(id);
    allElements[position] = newEvidence;
    this->writeToFile(allElements);
}

int FileRepository::findPositionById(std::string id)
{
    std::vector<Evidence> allEvidence = this->readFromFile();
    for (size_t i = 0; i < allEvidence.size(); i++)
        if (allEvidence[i].getId() == id)
            return i;
    return -1;
}

std::vector<Evidence> FileRepository::getEvidence()
{
    return this->readFromFile();
}

std::vector<Evidence> FileRepository::readFromFile()
{
    std::vector<Evidence> data;
    
    std::ifstream file(this->filePath);
    if (!file.good())
        return data;
    
    std::ifstream readFile(this->filePath);
    std::string current;
    
    while (!readFile.eof())
    {
        std::getline(readFile, current);
        std::string id;
        std::string measurement;
        float imageClarityLevel;
        float quantity;
        std::string photograph;
        int positionComma = current.find(',');
        if (positionComma == -1)
            continue;
        std::string arguments[10];
        int argumentsCounter = 0;
        
        while (positionComma != -1)
        {
            std::string currentArgumnt = current.substr(0, positionComma);
            arguments[argumentsCounter++] = currentArgumnt;
            current = current.substr(positionComma + 2, current.length());
            positionComma = current.find(',');
        }
        arguments[argumentsCounter++] = current;
        
        id = arguments[0];
        measurement = arguments[1];
        imageClarityLevel = stof(arguments[2]);
        quantity = stof(arguments[3]);
        photograph = arguments[4];
        
        Evidence evidence{ id,measurement,imageClarityLevel,quantity,photograph };
        data.push_back(evidence);
        
    }
    readFile.close();
    return data;
    
}

/*std::vector<Evidence> FileRepository::readFromFile()
 {
 std::vector<Evidence> list;
 std::ifstream file;
 file.open(this->filePath);
 Evidence e;
 
 while (file >> e)
 {
 list.push_back(e);
 
 }
 file.close();
 return list;
 }*/

void FileRepository::writeToFile(std::vector<Evidence> listOfEvidence)
{
    std::ofstream writeFile;
    writeFile.open(this->filePath);
    for (size_t i = 0; i < listOfEvidence.size(); i++)
        writeFile << listOfEvidence[i].displayEvidenceFile();
    
    //for (auto e : listOfEvidence)
    //    writeFile << e;
    
    writeFile.close();
}

void FileRepository::tests()
{
    this->addTest();
    //this->deleteTest();
    //this->updateTest();
}

void FileRepository::addTest()
{
    FileRepository fileRepository{};
    fileRepository.settings("RepoTest.txt");
    std::vector<Evidence> list;
    this->writeToFile(list);
    Evidence evidence1{ "12e","5x5x5",8,9,"DSC8,jpg" };
    fileRepository.addEvidence(evidence1);
    assert(fileRepository.getPath() == "RepoTest.txt");
    Evidence evidence2{ "13e","5x5x5",8,10,"DSC788,jpg" };
    try
    {
        fileRepository.addEvidence(evidence2);
    }
    catch (RepositoryException &add)
    {
        assert(true);
    }
    this->writeToFile(list);
    
}

void FileRepository::deleteTest()
{
    FileRepository fileRepository{};
    fileRepository.settings("RepoTest.txt");
    std::vector<Evidence> list;
    
    try
    {
        list = fileRepository.readFromFile();
    }
    catch (RepositoryException &noFile)
    {
        assert(true);
    }
    
    this->writeToFile(list);
    Evidence evidence1{ "12e","5x5x5",8,9,"DSC8,jpg" };
    fileRepository.addEvidence(evidence1);
    fileRepository.deleteEvidence("12e");
    try
    {
        fileRepository.deleteEvidence("8");
    }
    catch (RepositoryException &add)
    {
        assert(true);
    }
    this->writeToFile(list);
    
}

void FileRepository::updateTest()
{
    FileRepository fileRepository{};
    fileRepository.settings("RepoTest.txt");
    Evidence evidence1{ "12e","5x5x5",8,9,"DSC8,jpg" };
    fileRepository.addEvidence(evidence1);
    std::vector<Evidence> allEvidence = fileRepository.readFromFile();
    
    Evidence evidence2{ "12e","5x5x5",8,10,"DSC788,jpg" };
    fileRepository.updateEvidence("12e", evidence2);
    allEvidence = fileRepository.readFromFile();
    assert(allEvidence[0].getMeasurement() == "5x5x5");
    
    
}

FileRepository::~FileRepository()
{
    
}
