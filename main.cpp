// Winter'22
// Instructor: Diba Mirza
// Student name: 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include "movies.h"
using namespace std;
/*
vector <Movie> prefixed(string pre, vector<Movie> &s , int length)
{
  vector<Movie> v;

  string upper = pre;

  
  if(s.size()==0 || pre.length()>length)
  {
    return v;
  }
  
  if (pre=="")
  {
    return s;
  }

  for(int i = 0; i<pre.length() - length; i++)
  {
    s = s + "z";
      
  }
  int lower = 0;
  int ub = 
  if (Movie(pre , 0) > s.at(0))
  {
    return v;
  }
  
}
*/
bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){

  if(argc < 2){
    cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
    cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
    exit(1);
  }


  ifstream movieFile (argv[1]);
 

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[1];
    exit(1);
  }
  
//Create an object of a STL data-structure to store all the movies

string line, movieName;
double movieRating;
//Movie a = Movie("tesla" , 0);
string a;

vector<string> prefixes;
vector<vector<Movie>> moves;
vector<Movie> temp;
if (argc>2)
{
  for(int i = 2; i<argc; i++)
  {
    prefixes.push_back((string) argv[i]);
    moves.push_back(temp);
    
    
      
  }
}

vector <string> lst;
//set<Movie , classcomp> s;
//vector<vector<Movie>> moves;
// Read each file and store the name and rating
while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
  //a = Movie(movieName,movieRating);
  if (movieRating==10.0) a = movieName + ", " + to_string(movieRating).substr(0,4);
  else a = movieName + ", " + to_string(movieRating).substr(0,3);
  

  
  lst.push_back(a);
  for (int i = 0; i<(int) prefixes.size();i++)
    {
      if(prefixes.at(i).length()<=movieName.length())
      {
        if(prefixes.at(i)==movieName.substr(0,prefixes.at(i).length()))
        {
          moves.at(i).push_back(Movie(movieName, movieRating));
          
        }
      }
    }
  //s.insert(a);// Use std::string movieName and double movieRating
  // to construct your Movie objects
  // cout << movieName << " has rating " << movieRating << endl;
  // insert elements into your data structure
}

movieFile.close();


if(argc == 2){
  sort(lst.begin(), lst.end());
  //cout<<endl;
  for(int i = 0; i<(int) lst.size(); i++)
    {
      cout<<lst.at(i)<<endl;
      
    }
  /*
  for(int i = 0; i<lst.size();i++)
    {

      cout<<lst.at(i).movie<<", "<<lst.at(i).rating<<endl;
    }
   for(auto it = lst.begin(); it != lst.end(); it++)
    {
        cout << it->movie <<","<<it->rating<< endl;
    }
  */
  
  //print all the movies in ascending alphabetical order of movie names
  return 0;
}


//  For each prefix,
//  Find all movies that have that prefix and store them in an appropriate data structure
//  If no movie with that prefix exists print the following message

for(int i = 0; i<(int) moves.size(); i++)
  {
    sort(moves.at(i).begin() , moves.at(i).end());
  }
for(int i = 0; i<(int) moves.size(); i++)
{
  if(moves.at(i).size()==0)
  {
    cout<<"No movies found with prefix "<<prefixes.at(i) << endl<<endl;
    }
    
}
//cout<<"movie test:" << moves.at(0).at(1).movie<<endl;
for(int i = 0; i<(int) moves.size() ; i++)
{
  if(moves.at(i).size()>0)
  {
    //int size = moves.at(i).size();
    for(int j = 0; j<(int) moves.at(i).size(); j++)
      {
        
        if(moves.at(i).at(j).rating==10.0)
        {
          cout<<moves.at(i).at(j).movie<<", "<<to_string(moves.at(i).at(j).rating).substr(0,4)<<endl;
        }
        else
        {

          cout<<moves.at(i).at(j).movie<<", "<<to_string(moves.at(i).at(j).rating).substr(0,3)<<endl;
          
        }
        
      }
    
  }
  cout<<endl;
}
  for(int i = 0; i<(int) moves.size(); i++)
  {
    if((int) moves.at(i).size()>0)
    {
      if(moves.at(i).at(0).rating!=10.0)
      {
        cout<<"Best movie with prefix "<<prefixes.at(i)<<" is: "<<moves.at(i).at(0).movie<< " with rating "<< moves.at(i).at(0).rating<<endl;
        }
      else
      {
        cout<<"Best movie with prefix "<<prefixes.at(i)<<" is: "<<moves.at(i).at(0).movie<< " with rating "<< "10.0"<<endl;
        
      }
        
      
    }
    
      
  }
    


return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/



bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < (int) line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
		  if(i==0 && line[0]=='"') continue;
		  if(line[i]=='"'){ i++; flag=true; continue;}
		  movieName += line[i];
	  }
  }
  
  movieRating = stod(tempRating);
  return true;
}