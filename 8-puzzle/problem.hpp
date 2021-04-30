#ifndef _PROBLEM_HPP
#define _PROBLEM_HPP

#include <vector>
#include <string>
#include "cost.hpp"
using namespace std;




class Problem {

    private:

        vector<string> initial_state;
        vector<string> goal_state;
        vector<string> actions;
        Cost* node_cost;


        bool up_action(vector<string>);
        bool down_action(vector<string>);
        bool left_action(vector<string>);
        bool right_action(vector<string>);

        vector<string>swap_up(vector<string>);
        vector<string>swap_down(vector<string>);
        vector<string>swap_left(vector<string>);
        vector<string>swap_right(vector<string>);

    public:

    
        Problem(vector<string> initial,Cost* node_cost) {
            actions = {"up", "down","left","right"};
            goal_state = {"123", "456", "780"};
            initial_state = initial;
            this->node_cost = node_cost;

        }
        int step_cost(vector<string> state) {
            
            
            return node_cost->cost(state, goal_state) + 1;
            
        }
        vector<string> get_initial() {
            return initial_state;
        }
        vector<string> get_actions() {
            return actions;
        }
        bool goal_test(vector<string> test) {
            if(test == goal_state) {
                return true;
            }
            return false;
        }
        vector<string> result(vector<string> state, string action);

};


#endif
