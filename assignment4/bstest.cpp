/*
  000,000,000 ABD,BAC,DCA ABD,BAC,DCA
  011,101,110 ABD,BAC,DCA ABD,BAC,DCA
  011000,101000,110000,000011,000101,000110 ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

typedef std::pair<int,std::pair<int,int>> Set; // a set of two nodes and the cost between them
  #define node_A second.first // the value (id) of the first node
  #define node_B second.second // the value (id) of the second node
  #define set_Cost first // the cost (weight) of the road (edge)

typedef std::vector<std::vector<int>> intmat;

using namespace std;

struct Graph {
  vector<int> parent, weight;

  Graph() {} // default constructor
  Graph(int n) { // initialise with 'n' nodes of IDs ascending from 0
    for (int i=0; i<n; i++) // each int represents cities, A=0, B=1 ... matches the IDs as generated by the for-loops (also 0-based index) in the main
      this->create(i);
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return find(parent[x]); 
  } 
  void create(int x) {
    vector<int>::iterator loc = parent.begin() + x;
    parent.insert(loc,x);

    loc = weight.begin() + x;
    weight.insert(loc,1); // for initialisation
  }
  void n_union(int a, int b) { // a and b are vals, not node IDs. immaterial to this assignment however
    a = find(a); b = find(b);

    if (a == b) // no actions to unify node with itself
      return;

    // tree with smaller height becomes a subtree of the larger tree
    int cmp = weight[a] - weight[b]; // comparison optimisation
    if (cmp < 0) // b is bigger
      parent[a] = b;
    else if (cmp > 0) // a is bigger
      parent[b] = a;
    else { // trees are same weight, so make A root of B and increment weight of A (or, technically, vice-versa)
      parent[b] = a;
      weight[a]++;
    }

  } 
};


namespace RoadsCost {
  // cost comparison functions
  inline bool lt(Set x, Set y) {
    return x.set_Cost < y.set_Cost;
  }
  inline bool gt(Set x, Set y) {
    return x.set_Cost > y.set_Cost;
  }

  inline int cost(char a) {
    return (a >= 'a' && a<='z') ? (26+ a-'a') : (a-'A');
  }

  int calculate(intmat country, intmat build, intmat destroy) {
    int n = country.size(); // number of cities
    Graph G (n); // initialise the graph with n Sets as the cities

    vector<Set> N, E; // create the Set structure for New (N) and Existing (E) roads
    for (int i=0; i<n; i++) {
      for (int j=0; j<i; j++) { // j to i to only consider each connection/road once
        if (country[i][j] == 0)
          {
            N.push_back( Set(build[i][j], pair<int,int>(i,j)) );
            // std::cout << build[i][j] << " " << i << ' ' << j << "\n";
          }
        else 
        {
          E.push_back( Set(destroy[i][j], pair<int,int>(i,j)) );
          // std::cout << destroy[i][j] << " " << i << ' ' << j << "\n";
        }
      }
    }

    // sorting of each Set is necessary so that the below graph union loops consider the cheapest of each
    sort(E.begin(), E.end(),RoadsCost::gt); // sort the E roads from largest to smallest cost
    sort(N.begin(), N.end(),RoadsCost::lt); // sort the N roads from smallest to largest cost
    // std::cout << "\n";
    // for(auto a : N){
		// 	std::cout << a.first << " " << a.second.first << " " <<a.second.second <<"\n";
		// }
    int min_cost = 0;
    for (unsigned int i=0; i<E.size(); i++) { // E is destroy
      std::cout << E[i].set_Cost << "\n";
      std::cout << "here" << "\n";
      if (G.find(E[i].node_A) == G.find(E[i].node_B))
        {min_cost += E[i].set_Cost; }

      else
        G.n_union(E[i].node_A, E[i].node_B); // keep the road, add it to the graph
    }


    for (unsigned int i=0; i<N.size(); i++) { // N is build
      // std::cout << N[i].set_Cost << "\n\n";
      std::cout << N[i].set_Cost << " " << N[i].second.first << " " << N[i].second.second << "\n  " << (G.find(N[i].node_A)) << " " << (G.find(N[i].node_B)) << "\n";
      if (G.find(N[i].node_A) != G.find(N[i].node_B)) {
        min_cost += N[i].set_Cost;
        // std::cout << N[i].set_Cost << "\n\n";
        G.n_union(N[i].node_A, N[i].node_B); // 
      }
      


    }
    
    return min_cost;
  }
};

int main() {
  string t;
  getline(cin, t);
  stringstream parse(t);
  
  // the existing road matrix
  string inst;
  parse >> inst;
  stringstream c(inst);

  int i=0;
  getline(c, t, ','); // first element
  intmat country (t.length());
  do {
    for (unsigned int j=0; j<t.length(); j++) {
      country[i].push_back(t[j]-'0');
    }
    i++;
  } while (getline(c, t, ','));

  parse >> inst;
  stringstream b(inst);

  i=0;
  getline(b, t, ','); // first element
  intmat build (t.length());
  do {
    for (unsigned int j=0; j<t.length(); j++) {
      build[i].push_back( RoadsCost::cost( t[j]) );
    }
    i++;
  } while (getline(b, t, ','));

  parse >> inst;
  stringstream d(inst);

  i=0;
  getline(d, t, ','); // first element
  intmat destroy (t.length());
  do {
    for (unsigned int j=0; j<t.length(); j++) {
      destroy[i].push_back( RoadsCost::cost( t[j]) );
    }
    i++;
  } while (getline(d, t, ','));

  
  cout << RoadsCost::calculate(country,  build,  destroy) << endl;

  return 0;
}