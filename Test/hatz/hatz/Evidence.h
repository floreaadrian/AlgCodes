
#pragma once

#include <iostream>
#include <string>


class Evidence {
private:
    std::string id;
    std::string measurement;
    float imageClarityLevel;
    int quantity;
    std::string photograph;
    
public:
    Evidence();
    
    ~Evidence();
    
    Evidence(const std::string &id,const std::string &measurement,
             const float &imageClarityLevel,const float &quantity,
             const std::string &photograph);
    
    std::string getId() const { return id; }
    std::string getMeasurement() const { return measurement; }
    float getimageClarityLevel() const { return imageClarityLevel; }
    float getQuantity() const { return quantity; }
    std::string getPhotograph() const { return photograph; }
    
    std::string displayEvidence();
    std::string displayEvidenceFile();
    
    bool operator==(Evidence evidence1);
    friend std::istream& operator>>(std::istream& is, Evidence& evidence);
    friend std::ostream& operator<<(std::ostream& os, const Evidence& evidence);
    
    void tests();
    void idTest();
    void measurementTest();
    void imageClarityTest();
    void quantityTest();
    void photoTest();
    void equalTest();
    
    
    
};






