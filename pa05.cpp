/* Sample tester (for debugging, add the -g flag if you want to use gdb)
 * We've included std::list below to show you how your types should behave.
 * Test all your MyList functions here or in multiple mains.
 * Hint: Build and test one function at a time!!
 */

// USE THIS TO TEST, BUT REMOVE LATER TO VALIDATE YOUR OWN IMPLEMENTAION
//#include <list>

// Uncomment this to test with your own list implementation
#include "MyList.h"

int main()
{
    // Uncomment this to test with your own list implementation
    MyList<int> l;
    //std::list<int> l;

    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    cout << l.front() << endl;
    l.front() = 33;
    cout << l.front() << endl;
    cout << l.back() << endl;

    cout << l.size() << endl;

    l.push_front(423);

    cout << l.front() << endl;

    // Uncomment this to test with your own list implementation
    
    MyList<int> sink;
    sink = l;
    cout << sink.front() << endl;
    cout << sink.back() << endl;
    
    l.insert(l.begin(), 3);
    l.insert(l.end(), 20);
    l.pop_front();
    l.reverse();

    int j = 0;
    for(auto i = 0; i < l.size(); i++)
    {
        cout << l.back() << endl;
        l.pop_back();
        j++;
    }

    return 0;
}
