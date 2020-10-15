#include <iostream> 
#include <cmath> 

using namespace std; 

// people per percent
int ppp(double p) { 
    return ceil(sqrt(2*365*log(1/(1-p)))); 
} 
  
// percent per people *todo
int main() { 
   cout << ppp(.12); 
   return 0;

} 