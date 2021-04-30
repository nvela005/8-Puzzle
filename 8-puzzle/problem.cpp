#include <vector>
#include <string>
#include "problem.hpp"
using namespace std;





vector<string> Problem::swap_up(vector<string> state) {

    unsigned int index;

    for(unsigned int i = 1; i < state.size(); ++i) {

        index = state[i].find("0");
        if(index != string::npos) {
            
            state[i][index] = state[i - 1][index];
            state[i - 1][index] = '0';
            return state;
                
        }
    }
    return state;
}
bool Problem::up_action(vector<string> state) {

    if(state[0][0] != '0' &&
        state[0][1] != '0' &&
        state[0][2] != '0') {

            return true;
    }
    return false;
}

vector<string> Problem::swap_down(vector<string> state) {

    unsigned int index;
        
    for(unsigned int i = 0; i < state.size() - 1; ++i) {
        index = state[i].find("0");
        if( index != string::npos) {
            
            state[i][index] = state[i + 1][index];
            state[i + 1][index] = '0';
            return state;
        }
    }
    return state;
}
bool Problem::down_action(vector<string> state) {

    if(state[2][0] != '0' &&
        state[2][1] != '0' &&
        state[2][2] != '0') {

            return true;
    }
    return false;
}

vector<string> Problem::swap_left(vector<string> state) {

        unsigned int index;
        for( unsigned int i = 0; i < state.size(); ++i) {

            index = state[i].find("0");
            if( index != string::npos) {
                state[i][index] = state[i][index - 1];
                state[i][index - 1] = '0';
            }
        }



    return state;
}

bool Problem::left_action(vector<string> state) {

    if(state[0][0] != '0' &&
        state[1][0] != '0' &&
        state[2][0] != '0' ) {

            return true;
    }
    return false;
}

vector<string> Problem::swap_right(vector<string> state) {

    unsigned index;
    for(unsigned int i = 0; i < state.size(); ++i) {
        index = state[i].find("0");
        if(index != string::npos) {

            state[i][index] = state[i][index + 1];
            state[i][index + 1] = '0';
            return state;
        }
    }
    return state;
}

bool Problem::right_action(vector<string> state) {

    if( state[0][2] != '0' &&
        state[1][2] != '0' &&
        state[2][2] != '0') {

            return true;
    }


    return false;
}

vector<string> Problem::result(vector<string> state, string action) {

        if( action == "up" && up_action(state)) {
            
            return swap_up(state);
        }

        if( action == "down" && down_action(state)) {
            return swap_down(state);
        }

        if( action == "left" && left_action(state)) {
            return swap_left(state);
        } 
        if( action == "right" && right_action(state)) {
            return swap_right(state);
        }       
    

    return state;
}

