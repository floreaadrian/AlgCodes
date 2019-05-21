#include "EvidenceValidator.h"

using namespace std;

EvidenceException::EvidenceException(std::vector<std::string> _errors)
:errors{ _errors } {}

std::vector<std::string> EvidenceException::getErrors() const
{
    return this->errors;
}

void EvidenceValidator::validate(const Evidence &evidence)
{
    vector<string> errors;
    if (evidence.getQuantity() < 0)
        errors.push_back("Quantity problem \n");
    if (evidence.getimageClarityLevel() < 0)
        errors.push_back("Image clarity level problem \n");
    if (evidence.getId() == "")
        errors.push_back("id problem \n");
    if (evidence.getMeasurement() == "")
        errors.push_back("measurement problem \n");
    
    if (errors.size() > 0)
        throw EvidenceException(errors);
}

void EvidenceValidator::tests()
{
    Evidence evidence{"","5x5x5",-2,9,"abs" };
    try {
        validate(evidence);
    }
    catch (EvidenceException &evidence)
    {
        for (auto s : evidence.getErrors())
            std::cout << s;
    }
}
