#include "movies.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Movie::operator>(const Movie c1)
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
bool Movie::operator<(const Movie c1)
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
bool Movie::operator==(const Movie& c1)
{
      if(c1.rating == this->rating && c1.movie==this->movie)
      {
        return true;
      }
      return false;
  
}