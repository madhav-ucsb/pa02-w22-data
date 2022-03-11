#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Movie{

 public:
    string movie = "";
    double rating = 0;
    
    Movie(string m,double r)
    {
      this->rating = r;
      this->movie = m;
      
    }



    
    
    bool operator>(const Movie c1);
    /*    
    {

      if(this->rating<c1.rating)
      {
        return true;
      }
      else if(this->rating>c1.rating)
      {
        return false;
      }
      else
      {
        return c1.movie<this->movie;
      }
      
      
      
    }
    */
    bool operator<(const Movie c1);
    /*
    {
      
      if(this->rating>c1.rating)
      {
        return true;
      }
      else if(this->rating<c1.rating)
      {
        return false;
      }
      else
      {
        return c1.movie>this->movie;
      }
      
      
      
    }
    */
    bool operator==(const Movie& c1);
    /*
    {
      
      if(c1.rating == this->rating && c1.movie==this->movie)
      {
        return true;
      }
      return false;
      
  
    }
    */



    
    
 //store the binary heap tree as a dynamic array
};

#endif