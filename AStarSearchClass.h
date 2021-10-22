//  A* Search
//  Sachin Suresh

#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#ifndef AStarSearchClass_H_
#define AStarSearchClass_H_

class ASTAR
{
    
private:

    int nodesAmt = 8;
    int START = 0;
    int GOAL = nodesAmt - 1;
    int to = 0;
    int from = 0;

    vector<char> labels = {'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<double> heuristicCosts = {10, 10, 6, 1.4, 9, 7, 2, 0};
    vector<bool> closed;
    vector<bool> open;

    vector<vector<double>> distanceMatrix =
    {
        { INT_MAX, 3, INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX         },
        { 3, INT_MAX, 4, INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX               },
        { INT_MAX, 4, INT_MAX, 4, INT_MAX, 5, INT_MAX, INT_MAX               },
        { INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, 5, 1.4             },
        { 4, 5, INT_MAX, INT_MAX, INT_MAX, 2, INT_MAX, INT_MAX               },
        { INT_MAX, INT_MAX, 5, INT_MAX, 2, INT_MAX, 4, INT_MAX               },
        { INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, 4, INT_MAX, INT_MAX         },
        { INT_MAX, INT_MAX, INT_MAX, 1.4, INT_MAX, INT_MAX, INT_MAX, INT_MAX }
    };

    
    /*
     // All vector code
     
     int nodesAmt = 8;
     int START = 0;
     int GOAL = nodesAmt - 1;

     vector<char> labels = {'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
     vector<double> heuristicCosts = {10, 10, 6, 1.4, 9, 7, 2, 0};
     vector<bool> closed;
     vector<bool> open;

     double distanceMatrix[8][8] =
     {
         { INT_MAX, 3, INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX         },
         { 3, INT_MAX, 4, INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX               },
         { INT_MAX, 4, INT_MAX, 4, INT_MAX, 5, INT_MAX, INT_MAX               },
         { INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, 5, 1.4             },
         { 4, 5, INT_MAX, INT_MAX, INT_MAX, 2, INT_MAX, INT_MAX               },
         { INT_MAX, INT_MAX, 5, INT_MAX, 2, INT_MAX, 4, INT_MAX               },
         { INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, 4, INT_MAX, INT_MAX         },
         { INT_MAX, INT_MAX, INT_MAX, 1.4, INT_MAX, INT_MAX, INT_MAX, INT_MAX }
     };
     */
    
    /*
     // ORIGINAL CODE
     
     int nodesAmt = 8;

     int START = 0;
     int GOAL = nodesAmt - 1;

     char labels[8] = {'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};

     double distanceMatrix[8][8] =
     {
         { INT_MAX, 3, INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX         },
         { 3, INT_MAX, 4, INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX               },
         { INT_MAX, 4, INT_MAX, 4, INT_MAX, 5, INT_MAX, INT_MAX               },
         { INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, 5, 1.4             },
         { 4, 5, INT_MAX, INT_MAX, INT_MAX, 2, INT_MAX, INT_MAX               },
         { INT_MAX, INT_MAX, 5, INT_MAX, 2, INT_MAX, 4, INT_MAX               },
         { INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, 4, INT_MAX, INT_MAX         },
         { INT_MAX, INT_MAX, INT_MAX, 1.4, INT_MAX, INT_MAX, INT_MAX, INT_MAX }
     };

     double heuristicCosts[8] = {10, 10, 6, 1.4, 9, 7, 2, 0};

     vector<bool> closed;
     vector<bool> open;
     */

public:
    
    ASTAR()
    {
        
        cout << "Default Values Have Been Assigned For The Search" << endl;
        cout << "If You Would Like To Set Your Own Values, Call The readFile Function" << endl;
        cout << endl;
    }
    
    ASTAR(string filePath)
    {
        ifstream fileReader(filePath, ios::in);
        int nodesTemp = 0;
        fileReader >> nodesTemp;
        this->nodesAmt = nodesTemp;
        this->GOAL = nodesTemp - 1;
        //cout << nodesAmt << " " << GOAL << endl;

        labels.resize(nodesAmt);
        for (int i = 0; i < nodesAmt; i++)
        {
            fileReader >> labels[i];
            //cout << labels[i] << " ";
        }
        //cout << endl;

        //cout << labels[2] << endl;
        //cout << endl;
        
        heuristicCosts.resize(nodesAmt);

        for (int i = 0; i < nodesAmt; i++)
        {
            fileReader >> heuristicCosts[i];
            //cout << heuristicCosts[i] << " ";

        }
        //cout << endl;

        //cout << heuristicCosts[3] << endl;
        //cout << endl;
        
        int tracker = 0;
        
        for (int i = 0; i < nodesAmt; i++)
        {
            distanceMatrix[i].resize(nodesAmt);
        }
        
        while (tracker != nodesAmt)
        {
            for (int i = 0; i < nodesAmt; i++)
            {
                fileReader >> distanceMatrix[tracker][i];
                //cout << distanceMatrix[tracker][i] << " ";
            }
            //cout << endl;
            tracker++;
        }
        //cout << endl;
                   
        //cout << distanceMatrix[1][3] << endl;
        
        fileReader.close();
    }
    
    ~ASTAR()
    {
        cout << "Destructor Has Been Called" << endl;
    }
    
    void ASTARSearch()
    {
        vector<int> gScore(nodesAmt, INT_MAX);
        vector<int> fScore(nodesAmt, INT_MAX);
        vector<int> cameFrom(nodesAmt, 0);
        
        open.resize(nodesAmt);
        closed.resize(nodesAmt);
        int numClosed = 0;
        
        open[START] = true;

        gScore[START] = 0;
        
        fScore[START] = heuristicCosts[START];
        
        
        while (numClosed != nodesAmt)
        {
            int current = 0, minDist = INT_MAX;
            
            for (int i = 0; i < nodesAmt; i++)
            {
                if (open[i] == true)
                {
                    if (fScore[i] < minDist)
                    {
                        minDist = fScore[i];
                        current = i;
                    }
                }
            }

            if (current == GOAL)
            {
                break;
            }
            
            open[current] = false;
            closed[current] = true;
            numClosed++;
            
            double neighbors[nodesAmt];

            for (int i = 0; i < nodesAmt; i++)
            {
                neighbors[i] = distanceMatrix[current][i];
                
                if (neighbors[i] == INT_MAX)
                {
                    continue;
                }
                
                int g = gScore[current] + neighbors[i];
                
                double f = g + heuristicCosts[i];
                
                // from here on out, its all doubt
                
                if (open[i] == false && f >= fScore[i])
                {
                    continue;
                }
                
                if (open[i] == false)
                {
                    open[i] = true;
                    cameFrom[i] = current;
                    gScore[i] = g;
                    fScore[i] = gScore[i] + heuristicCosts[i];
                }
                else if (open[i] == true && f >= fScore[i])
                {
                    continue;
                }
                else if (open[i] == true && f < fScore[i])
                {
                    // putting Step* inside this else if statement
                    // changed it
                    cameFrom[i] = current;
                    gScore[i] = g;
                    fScore[i] = gScore[i] + heuristicCosts[i];
                    break;
                }
                else if (closed[i] == true && f < fScore[i])
                {
                    closed[i] = false;
                    numClosed--;
                    open[i] = true;
                    cameFrom[i] = current;
                    gScore[i] = g;
                    fScore[i] = gScore[i] + heuristicCosts[i];
                }
                
                
            }
            
        }
        
        this->to = GOAL;
        this->from = cameFrom[to];
        cout << "This Search Algorithm Predicts The Following Path, Shown Below, Starting From The GOAL (On Top), And Ending With The START (On Bottom):" << endl;

        while (true)
        {
            cout << labels[from] << " -> " << labels[to] << endl;
            
            if (from == START)
            {
                break;
            }
            
            this->to = from;
            this->from = cameFrom[to];
        }
        
    }
    

};

#endif /* AStarSearchClass_H_*/
