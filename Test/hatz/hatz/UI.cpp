#include "UI.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "RepositoryException.h"

using namespace std;

UI::UI(Controller controller):controller{controller}{}

void UI::printMenu()
{
    cout << endl;
    cout << "-Mode A-" << endl;
    cout << "-Mode B-" << endl;
    cout << "-0-exit-" << endl;
    cout << endl;
}

void UI::run()
{
    printMenu();
    
    //read path
    string input;
    string command;
    string fileName;
    int spacePosition;
    
    string id, measurement,photograph;
    float imageClarityLevel, quantity;
    
    getline(cin, input);
    spacePosition = input.find(' ');
    command = input.substr(0, spacePosition);
    fileName = input.substr(spacePosition + 1, input.length());
    
    if (command == "fileLocation")
    {
        try
        {
            this->controller.setFileName(fileName);
        }
        catch (RepositoryException &fileProblem)
        {
            cout<<fileProblem.get_message();
            return;
        }
    }
    else
    {
        cout << "Invalid command \n";
        cout << "Try again \n";
        return;
    }
    
    //read mode
    string accessMode;
    getline(cin, accessMode);
    int spaceposition = accessMode.find(' ');
    accessMode = accessMode.substr(spaceposition + 1, accessMode.size());
    bool restrictedAccess = false;
    if (accessMode == "A")
        restrictedAccess = false;
    else if (accessMode == "B")
        restrictedAccess = true;
    else
    {
        cout << "Access denied \n";
        return;
    }
    
    int currentPositionInRepository = -1;
    
    while (1)
    {
        string command;
        string *arguments = new string[30];
        int argumentCount = 0;
        string inputText;
        
        getline(cin, inputText);
        
        int positionComma = inputText.find(' ');
        
        if (positionComma == -1)
            command = inputText;
        else
        {
            command = inputText.substr(0, positionComma);
            inputText = inputText.substr(command.length() + 1, inputText.length());
            positionComma = inputText.find(',');
            while (positionComma != -1)
            {
                arguments[argumentCount++] = inputText.substr(0, positionComma);
                inputText = inputText.substr(positionComma + 2, inputText.length());
                positionComma = inputText.find(',');
            }
            arguments[argumentCount++] = inputText;
        }
        
        if (command == "exit")
        {
            delete[] arguments;
            break;
        }
        else if (command == "mode")
        {
            string mode = arguments[0];
            if (mode == "A")
                restrictedAccess = false;
            else if (mode == "B")
                restrictedAccess = true;
            else
                cout << "No permission :(";
        }
        //COMMANDS FOR MODE A
        else if (command == "add")
        {
            if (restrictedAccess == false)
            {
                id = arguments[0];
                measurement = arguments[1];
                imageClarityLevel = stof(arguments[2]);
                quantity = stof(arguments[3]);
                photograph = arguments[4];
                //string error=this->controller.addEvidenceToRepository(arguments[0], arguments[1], atof(arguments[2].c_str()), atof(arguments[3].c_str()), arguments[4]);
                this->controller.addEvidenceToRepository(id, measurement, imageClarityLevel, quantity, photograph);
                //if (error != "")
                //    cout << error << endl;
                
            }
            else
                cout << "No permission :(";
        }
        else if (command == "delete")
        {
            if (restrictedAccess == false)
            {
                id = arguments[0];
                //this->controller.deleteEvidenceFromRepository(arguments[0]);
                this->controller.deleteEvidenceFromRepository(id);
            }
            else
                cout << "No permission :(";
        }
        else if (command == "update")
        {
            if (restrictedAccess == false)
            {
                id = arguments[0];
                measurement = arguments[1];
                imageClarityLevel = stof(arguments[2]);
                quantity = stof(arguments[3]);
                photograph = arguments[4];
                //this->controller.updateEvidence(arguments[0], arguments[1], atof(arguments[2].c_str()), atof(arguments[3].c_str()), arguments[4]);
                this->controller.updateEvidence(id, measurement, imageClarityLevel, quantity, photograph);
            }
            else
                cout << "No permission :(";
        }
        else if (command == "list")
        {
            if (argumentCount == 0)
            {
                std::vector<Evidence> allEvidence = this->controller.getAllEvidence();
                int size = allEvidence.size();
                if (size > 0)
                    for_each(allEvidence.begin(), allEvidence.end(), [](Evidence evidence) {cout << evidence.displayEvidence(); });
                
            }
            else
            {
                string measurement = arguments[0];
                float quantity = stof(arguments[1]);
                std::vector<Evidence> allEvidence = this->controller.getAllEvidence();
                std::vector<Evidence> listFiler;
                copy_if(allEvidence.begin(), allEvidence.end(), back_inserter(listFiler), [measurement, quantity](Evidence evidence) {return (evidence.getMeasurement() == measurement && evidence.getQuantity() >= quantity); });
                
                if (listFiler.size() > 0)
                    for_each(listFiler.begin(), listFiler.end(), [](Evidence evidence) {cout << evidence.displayEvidence(); });
                else
                    cout << "Nothing here" << endl;
                
            }
        }
        else if (command == "fileLocation")
        {
            std::string fileName = arguments[0];
            try
            {
                this->controller.setFileName(fileName);
                
            }
            catch (RepositoryException &file)
            {
                file.get_message();
                continue;
            }
        }
        //COMMANDS FOR MODE B
        else if (command == "save")
        {
            if (restrictedAccess == true)
            {
                string id = arguments[0];
                std::vector<Evidence> allEvidence = this->controller.getAllEvidence();
                std::vector<Evidence> myList;
                
                copy_if(allEvidence.begin(), allEvidence.end(), back_inserter(myList), [id](Evidence evidence) {return evidence.getId() == id; });
                this->controller.addEvidenceToMyList(myList[0]);
            }
            else cout << "No permission" << endl;
        }
        else if (command == "mylist")
        {
            if (restrictedAccess == true)
            {
                std::vector<Evidence> myList = this->controller.getMyListOfEvidence();
                Evidence *evidence;
                if (myList.size() > 0)
                    for (auto &evidence : myList)
                        cout << evidence.displayEvidence();
            }
            else cout << "No permission" << endl;
        }
        else if (command == "next")
        {
            std::vector<Evidence> allEvidence = this->controller.getAllEvidence();
            
            if (restrictedAccess == true)
            {
                if (currentPositionInRepository == -1)
                    currentPositionInRepository = 0;
                else
                {
                    currentPositionInRepository += 1;
                    if (currentPositionInRepository == allEvidence.size())
                        currentPositionInRepository = 0;
                }
                cout << allEvidence[currentPositionInRepository].displayEvidence();
            }
            else cout << "No permission" << endl;
        }
        
        delete[] arguments;
        
    }
    
    
}
