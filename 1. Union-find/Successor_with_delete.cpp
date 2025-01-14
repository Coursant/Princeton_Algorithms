/*
Statement of the problem:
Successor with delete. Given a set of N integers S = {0, 1, ..., N−1} and a sequence of requests of the following form:
    - Remove x from S
    - Find the successor of x: the smallest y in S such that y >= x.

Design a data type so that all operations (except construction) should take logarithmic time or better.
*/

/*
Solution: 
We use a structure similar to the Weighted Quick Union-Find class. The interface can be found in Successor.h and the implementation in Successor.cpp.

We hold an extra array where we remember the successor of each element.
The successor of each element in a connected component will be the largest element found in that connected component.
		  
At initialization, every element is their own successor.
When we remove an element i, we create a link between i and i+1. The successor of i becomes equal to the successor of i+1. We are updating only the successors of the roots.
When we remove i = n-1, there is no successor. We indicate this by setting the successor = n.
*/

#include "Successor.h"

using std::cin;
using std::cout;

int main()
{
    int n = 5;
    Successor rec(n);
	
    cout << "Enter a number from 1 to " << n << " to remove: ";
	size_t a;
    while ((cin >> a) && (a < n) && (!rec.empty())) {
		rec.remove(a);
        print(cout, rec) << endl << endl;
		if (!rec.empty())
			cout << "Enter a number from 1 to " << n << " to remove: ";
		else {
			cout << "All elements were removed" << endl;
			break;
		}
    }
}
