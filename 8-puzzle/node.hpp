#ifndef _NODE_HPP
#define _NODE_HPP

struct Node {

    vector<string> state;
    std::string action;
    int path_cost;
    Node* parent;

    public:
    Node() {}
    Node(vector<string> new_state, string ac, int cost,Node* par){
        state = new_state;
        action = ac;
        path_cost = cost;
        parent = par;
    }
    
    vector<string> get_state() {return state;}
    string get_action() {  return action;}
    int get_cost() { return path_cost;}
    Node* get_parent() { return parent;}
};

struct Compare_Cost {
     bool operator()(Node p1, Node p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.get_cost() > p2.get_cost(); 
    }



};



#endif
