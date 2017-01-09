/*******
 * Read input from cin
 * Use cout to output your result.
 * Use:
 *  localPrint( string mystring)
 * to display variable in a dedicated area.
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include <list>
#include <map>
// #include "exercise.hpp"

using namespace std;

int n;
list<int> g[2005];
map<string, int> m;

int level[2005];

void find_level(int node){
    // cout << node << endl;
    if(g[node].size() == 0){
        level[node] = 1;
        return;
    }
    else{
        int current_level = 10000;
        for(list<int>::iterator it = g[node].begin(); it != g[node].end(); it++){
            cout << *it << endl;
            if(level[*it] == 0) find_level(*it);
            if(level[*it] + 1 <= current_level) current_level = level[*it] + 1;
        }
        level[node] = current_level;
    }
}

// ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

int  main() {
    
   cin >> n;
  for(int i = 0; i < 2*n; i++) g[i].clear();
  m.clear();
   int current_id = 0;
   for(int i = 0; i < n; i++){
    //   localPrint("huy");
       string id1, id2; cin >> id1 >> id2;
       if(m.find(id1) == m.end()) m[id1] = current_id++;
       if(m.find(id2) == m.end()) m[id2] = current_id++;
       cout << endl << m[id1] << " " << m[id2] << endl;
       g[m[id1]].push_back(m[id2]);
   }

   cout << m["home"] << endl;
   cout << current_id << endl;
   
  
  for(int i = 0; i < current_id; i++){
    level[i] = 0;    
  }
  
  int max_level = 0;
//   localPrint("huy");
  for(int i = 0; i < current_id; i++){
     
    if(level[i] == 0) find_level(i);
    // localPrint("huy");
    if(level[i] > max_level) max_level = level[i];
  }
//   localPrint("huy");
  cout << max_level << endl;

  return 0;
   
   
   

	/* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}