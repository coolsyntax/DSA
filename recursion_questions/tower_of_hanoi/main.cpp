#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int no_of_blocks, char source, char destination, char helper)
{
    if (no_of_blocks == 0)
    {
        return;
    }
    
    tower_of_hanoi(no_of_blocks-1, source, helper, destination);
    cout << "Move from " << source << " to " << destination << "\n";
    tower_of_hanoi(no_of_blocks-1, helper, destination, source);
}


int main()
{
    tower_of_hanoi(3, 'A', 'C', 'B');
}