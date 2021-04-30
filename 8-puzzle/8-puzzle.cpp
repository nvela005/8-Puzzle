#include <bits/stdc++.h>
#include "problem.hpp"
#include "node.hpp"
#include "cost.hpp"
using namespace std;




Node* heuristic_search(Problem puzzle) {

    Node* temps;
    Node temp;
    vector<string> new_state;
    vector<string> action = puzzle.get_actions();
    std::set<vector<string>> explored;
    priority_queue<Node,vector<Node>,Compare_Cost> frontier; 
    int expanded_nodes = 0; int max_queue = 1;
    frontier.push(Node(puzzle.get_initial(),"",0,nullptr));

    while(!frontier.empty()) {
        
        temp = frontier.top();
        frontier.pop();
        explored.insert(temp.get_state());
    
        if(puzzle.goal_test(temp.get_state())) {
            std::cout << "Expanded Nodes: " << expanded_nodes << endl;
            std::cout << "Max queue size: " << max_queue << endl;
            temps = new Node(); *temps = temp; return temps;}
        expanded_nodes += 1;
        for(unsigned int i = 0; i < action.size(); ++i) {
            new_state = puzzle.result(temp.get_state(),action[i]);
            if(new_state != temp.get_state() && !explored.count(new_state)){
                temps = new Node(); *temps = temp;
                frontier.push(Node(new_state,action[i], temp.get_cost() 
                + puzzle.step_cost(new_state),temps));
                explored.insert(new_state);
            }
            
        }
        if( max_queue < frontier.size()) { max_queue = frontier.size();}   


    }
    return nullptr;
}



int main() {
    
    cout << endl << "Welcome to 861246406's 8-puzzle solver." << endl;
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle."; 
    cout << endl << endl;

    string rows;
    getline(cin,rows);
    cout << endl;
    vector<string> initial(3);

    if(rows == "1") {
            initial = {"182","043","765"};
    }
    else if(rows == "2") {
            for(int i = 0; i < initial.size(); ++i) {
                    cout << "Enter " << i + 1 << " row, no spaces, use zero for blank: ";
                    getline(cin,rows);
                    initial[i] = rows;
                  
            }
            cout << endl;
    }
    else {return 0;}
    
    Cost* costs;
    cout << "Enter your choice of algorithm" << endl;
    cout << "Uniform Cost Search" << endl;
    cout << "A* with the Misplaced tile heuristic" << endl;
    cout << "A* with the Manhattan distance heuristic" << endl << endl;

    getline(cin, rows);
    if(rows == "1") { costs = new Cost();}
    else if(rows == "2") {costs = new MisPlaced();}
    else if(rows == "3") {costs = new Manhattan();}
    else {return 0;}
    Problem test_value(initial,costs);
    Node* solution = heuristic_search(test_value);
    if( solution != nullptr) {
        
        std::cout << "Cost of Solution: " << solution->get_cost() << endl << endl;
        while(solution != nullptr) {
            if(solution->get_parent() != nullptr) {
            std::cout << "Cost of Node: " << solution->get_cost()
             - solution->get_parent()->get_cost() << ": ";}
            else {cout << "Cost of Node: " << solution->get_cost() << ": ";}
            std::cout << solution->get_action() << endl;
            solution = solution->get_parent();
        }
        
    }
    
    return 0;
}
