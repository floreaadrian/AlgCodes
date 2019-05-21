#include "Evidence.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>

using namespace std;

Evidence::Evidence()
: id(""), measurement(""), imageClarityLevel(), quantity(), photograph("") {}

Evidence::~Evidence()
{
    
}

Evidence::Evidence(const std::string &id,const std::string &measurement,
                   const float &imageClarityLevel,const float &quantity,
                   const std::string &photograph) {
    this->id = id;
    this->measurement = measurement;
    this->imageClarityLevel = imageClarityLevel;
    this->quantity = quantity;
    this->photograph = photograph;
}

bool Evidence::operator==(Evidence evidence1) {
    return (this->id == evidence1.getId()) ;
    
}

std::string Evidence::displayEvidence()
{
    std::string toDisplay = this->id + " " + this->measurement + " " + std::to_string(this->imageClarityLevel) + " " + std::to_string(this->quantity) + " " + this->photograph + "\n";
    return toDisplay;
}

std::string Evidence::displayEvidenceFile()
{
    std::string evidence;
    evidence += this->id + ", ";
    evidence += this->measurement + ", ";
    evidence += std::to_string(this->imageClarityLevel) + ", ";
    evidence += std::to_string(this->quantity) + ", ";
    evidence += this->photograph + "\n";
    return evidence;
    
}

vector<string> tokenize(string str, char delimiter)
{
    vector <string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    
    return result;
}

std::istream& operator>>(std::istream& is, Evidence& evidence)
{
    string line;
    getline(is, line);
    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return is;
    evidence.id = tokens[0];
    evidence.measurement = tokens[1];
    evidence.imageClarityLevel = stof(tokens[2]);
    evidence.quantity = stof(tokens[3]);
    evidence.photograph = tokens[4];
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const Evidence& evidence)
{
    os << evidence.id << "," << evidence.measurement << "," << evidence.imageClarityLevel << "," << evidence.quantity << "," << evidence.photograph << "\n";
    return os;
}

/*bool operator==(const Evidence &evidence1, const Evidence &evidence2)
 {
 if (evidence1.getId() == evidence2.getId())
 return true;
 return false;
 }*/

void Evidence::tests()
{
    this->idTest();
    this->measurementTest();
    this->imageClarityTest();
    this->quantityTest();
    this->photoTest();
    //this->equalTest();
}

void Evidence::idTest()
{
    Evidence test{ "12e","5x5x5",8,9,"DSC89.jpg" };
    assert(test.getId() == "12e");
    Evidence test1{ "1","5x5x5",8,9,"DSC89.jpg" };
    assert(test1.getId() != "12e");
}

void Evidence::measurementTest()
{
    Evidence test{ "12e","5x5x5",8,9,"DSC89.jpg" };
    assert(test.getMeasurement() == "5x5x5");
    Evidence test1{ "1","5x5",8,9,"DSC89.jpg" };
    assert(test1.getId() != "5x5x5");
}

void Evidence::imageClarityTest()
{
    Evidence test{ "12e","5x5x5",8,9,"DSC89.jpg" };
    assert(test.getimageClarityLevel() == 8);
    Evidence test1{ "1","5x5x5",10,9,"DSC89.jpg" };
    assert(test1.getimageClarityLevel() != 8);
}

void Evidence::quantityTest()
{
    Evidence test{ "12e","5x5x5",8,9,"DSC89.jpg" };
    assert(test.getQuantity() == 9);
    Evidence test1{ "1","5x5x5",8,10,"DSC89.jpg" };
    assert(test1.getQuantity() != 9);
}

void Evidence::photoTest()
{
    Evidence test{ "12e","5x5x5",8,9,"DSC89.jpg" };
    assert(test.getPhotograph() == "DSC89.jpg");
    Evidence test1{ "1","5x5x5",8,9,"DSC8.jpg" };
    assert(test1.getPhotograph() != "DSC89.jpg");
}

void Evidence::equalTest()
{
    Evidence test{ "12e","5x5x5",8,9,"DSC89.jpg" };
    Evidence test1{ "12e","5x5x5",8,9,"DSC89.jpg" };
    Evidence test2{ "12","5x5x5",8,10,"DSC89.jpg" };
    assert((test == test1) == true);
    assert((test == test2) == false);
}
