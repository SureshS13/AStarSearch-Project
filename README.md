<h3> Make-File - Sachin - A* Search Algorithm Final Project </h3>

<p> Instructions </p>

<ol>

  <li> I have programmed a constructor in my program that allows you to submit the information from your graph/tree in a .txt file. I have provided two example .txt files, as well as one template .txt file, to assist you in figuring out how to properly organize
the .txt input file.

If the .txt input method is not working for you, the only other option to test the A* Search would be to manually go into the AStarSearchClass.h file and change the default constructor settings to with the information from your graph/tree.

  </li>
  
  <br>
  
  <li> To compile and test the program, you have two options. You can either use the MainFunctionTest.cpp file that I have provided, which already includes a main function and provided test functions, or you will have to create a new .cpp file, and include my AStarSearchClass.h header file within that your new .cpp file.
  
  To create a default object from the default constructor (which automatically sets the distanceMatrix, nodesAmt, etc, to the given graph/tree from the project, type the following into your main function):
  
    ASTAR Obj;
    Obj.ASTARSearch();
    
  To create a specialized object from the special constructor (which sets the distanceMatrix, nodesAmt, etc, to information from a custom .txt file, type the following into your main function):
  
    ASTAR Two("Full Pathname");
    Two.ASTARSearch();
    
  

  
