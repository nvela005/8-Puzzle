#ifndef _COST_HPP
#define _COST_HPP
#include<iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std; 


class Cost {


    public:
    virtual int cost(vector<string> state, vector<string> goal_state) {return 0;}

};

class MisPlaced : public Cost {


    public:

    int cost(vector<string> state, vector<string> goal_state) {

        int num_misplaced = 0;
        for(unsigned int i = 0; i < state.size(); ++i ) {
            for(unsigned int j = 0; j < state[i].size(); ++j) {
                if( state[i][j] != goal_state[i][j]) { num_misplaced += 1;}
            }
        }
        return num_misplaced;
    }
}; 

class Manhattan : public Cost {
    int cost(vector<string> state, vector<string> goal_state) {
        string manhattan = "";
      
       for(int j = 0; j < state.size(); ++j) {manhattan += state[j]; }
     
        int distance = 0;
        int ind;
        char c = '1';
        char d;
        int sdistance = 0;
        for( int i = 0; i < manhattan.size() - 1; ++i) {
            d = c + i;
            if(d == '4' || d ==  '7') { sdistance = 0;}
            for( int j = 0; j < state.size(); ++j) {

                ind = state[j].find(d);
                if(ind != string::npos) {
                    if( d <= '3') { distance += abs(ind - sdistance) + j;}
                    else if( d <= '6') {distance += abs(j - 1) + abs(ind - sdistance);}
                    else { distance += abs(j - 2) + abs(ind - sdistance);}
                }
            }
            sdistance += 1;
             
        }
        return distance;
    }

};





#endif