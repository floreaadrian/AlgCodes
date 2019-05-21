//
//  main.cpp
//  hatz
//
//  Created by Adrian-Paul Florea on 4/19/19.
//  Copyright © 2019 Adrian-Paul Florea. All rights reserved.
//

#include "Evidence.h"
#include "EvidenceValidator.h"
#include "FileRepository.h"
#include "MemoryRepository.h"
#include "Controller.h"
#include "UI.h"
#include <iostream>

using namespace std;

void testAll()
{
    Evidence evidence{};
    evidence.tests();
    
    EvidenceValidator evidenceValidator{};
    evidenceValidator.tests();
    
    Repository *repository{};
    
    MemoryRepository memoryRepository{};
    
    FileRepository fileRepository{};
    //fileRepository.tests();
    
    Controller controller{ &fileRepository,&memoryRepository,evidenceValidator };
}

int main()
{
    testAll();
    cout << "Done" << endl;
    
    EvidenceValidator validator{};
    
    Repository *repository{};
    
    MemoryRepository memoryRepository{};
    
    FileRepository fileRepository{};
    
    Controller controller{&fileRepository,&memoryRepository,validator };
    
    UI ui{ controller };
    
    ui.run();
    
    //system("pause");
    return 0;
}
