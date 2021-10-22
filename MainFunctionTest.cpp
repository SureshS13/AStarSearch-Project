//  MainFunctionTest
//  Created by Sachin Suresh on 10/6/20.
//  Copyright © 2020 Sachin Suresh. All rights reserved.

#include <iostream>
#include "AStarSearchClass.h"

int main()
{
    
    ASTAR Obj;
    Obj.ASTARSearch();
    
    cout << endl;
    
    ASTAR Two("/Users/SachinSuresh/Documents/Audacity Stuff/COLLEGE FILES/C++ Files/Intro to AI Project Files/MainFunctionTest/MainFunctionTest/A* Example (1).txt");
    Two.ASTARSearch();
    
    cout << endl;
    
    ASTAR Three("/Users/SachinSuresh/Documents/Audacity Stuff/COLLEGE FILES/C++ Files/Intro to AI Project Files/MainFunctionTest/MainFunctionTest/A* Example (2).txt");
    Three.ASTARSearch();
    
    cout << endl;

    
    return 0;
}
