#include <stdio.h>
#include <iostream>

using namespace std;

// define the tree node structure
struct Node{
  int v;
  Node *left;
  Node *right;
  bool has_value;

  Node(){ // constructor function
    has_value = false;
    left = NULL;
    right = NULL;
  }
};

void addNode(int v, string location, Node* root){
  if (location.length() == 0){ // this is the root
    root->v = v;
    root->has_value = true;
    return;
  }

  // e.g. LLR
  Node *cursor = root;
  for (char s: location){
    if (s == 'L'){
      // create left child if cursor does not has left child
      if (!cursor->left)
        cursor->left = new Node();
      cursor = cursor->left;
    }
    
    if (s == 'R'){
      if(!cursor->right)
        cursor->right = new Node();
      cursor = cursor->right;
    }

    cursor->v = v;
    cursor->has_value = true;
  }
}

Node* create_a_tree_from_input(){
  char s[100]; // 100 is randomly set.
  Node *root = new Node();
  // read all inputs
  while(true){
    if(scanf("%s", s) != 1) exit(0); // ending the whole program
    if(!strcmp(s, "()")) return NULL;
    
    // otherwise, we have s = "(v,LLLRRR)"
    int v;
    sscanf(&s[1], "%d", &v);  // starting from the first char of s
    string ss(s);
    string location = ss.substr(ss.find(',')+1, ss.length()-ss.find(',')-2);
    cout << v << " " << location << endl;
    addNode(v, location, root);
  }

  // finishing creation.
  return root;
}

int main(){
  while(true){
    create_a_tree_from_input();
  }

  return 0;
}
