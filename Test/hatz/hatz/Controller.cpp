#include "Controller.h"
#include "RepositoryException.h"
#include "FileRepository.h"
#include "MemoryRepository.h"
#include <assert.h>
#include <iostream>

Controller::Controller(Repository *repository,
                       Repository *userRepository,
                       EvidenceValidator validator) :
repository{ repository }, userRepository{ userRepository },
validator{ validator } {}

std::string Controller::addEvidenceToMyList(Evidence evidence)
{
    try
    {
        this->userRepository->addEvidence(evidence);
    }
    catch (RepositoryException &addException)
    {
        return addException.get_message();
    }
    return "hatz";
}

std::string Controller::addEvidenceToRepository(const std::string &id, const std::string &measurement,
                                                const float &imageClarityLevel, const float &quantity,
                                                const std::string &photograph)
{
    Evidence evidence{ id,measurement,imageClarityLevel,quantity,photograph };
    try
    {
        this->validator.validate(evidence);
    }
    catch (RepositoryException &invalidInput)
    {
        return invalidInput.get_message();
    }
    try
    {
        this->repository->addEvidence(evidence);
    }
    catch (RepositoryException &add)
    {
        return add.get_message();
    }
    return "hatz";

}

std::string Controller::deleteEvidenceFromRepository(std::string id)
{
    try
    {
        this->repository->deleteEvidence(id);
    }
    catch (RepositoryException &deleteProblem)
    {
        return deleteProblem.get_message();
    }
    return "hatz";

}

std::string Controller::updateEvidence(const std::string &id, const std::string &measurement,
                                       const float &imageClarityLevel, const float &quantity,
                                       const std::string &photograph)
{
    Evidence newEvidence{ id,measurement,imageClarityLevel,quantity,photograph };
    try
    {
        this->validator.validate(newEvidence);
    }
    catch (RepositoryException &invalidInput)
    {
        return invalidInput.get_message();
    }
    try
    {
        this->repository->updateEvidence(id, newEvidence);
    }
    catch (RepositoryException &update)
    {
        return update.get_message();
    }
    return "hatz";

}

std::vector<Evidence> Controller::getAllEvidence()
{
    return this->repository->getEvidence();
}
std::vector<Evidence> Controller::getMyListOfEvidence()
{
    return this->userRepository->getEvidence();
}

void Controller::setFileName(std::string newName)
{
    this->repository->settings(newName);
}
