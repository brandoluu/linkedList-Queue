#include <algorithm>
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Queue.h"
using namespace std;

/**
 * Define messages for use in the tester
 */
#define MESSAGE_SUCCESS "Success"
#define MESSAGE_WRONG_SIZE "Incorrect size"
#define MESSAGE_WRONG_POP "Incorrect string returned by pop()"

/**
 * Generate a random string
 *
 * Adapted from here: https://stackoverflow.com/a/12468109/2134991
 */
string randomString(unsigned int length) {
    auto randomCharacter = []() -> char {
        const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const unsigned int maxIndex = (sizeof(alphabet) - 1);
        return alphabet[rand() % maxIndex];
    };
    string out(length, 0);
    generate_n(out.begin(), length, randomCharacter);
    return out;
}

/**
 * Randomly test the Queue class
 */
int main() {
    // set things up
    cout << "=== STARTING TEST ===" << endl;
    cout << endl;
    cout << endl;
    cout << "==== STARTING PERSONAL TEST ====" << endl;
    Queue personalQueue; 
    cout << "==== PUSING OBJECTS ====" << endl; 
    personalQueue.push("hello");
    personalQueue.push("this");
    personalQueue.push("is");
    personalQueue.push("a");
    personalQueue.push("test");
    if (personalQueue.size() != 5){
        cout << "Error: invalid size!" << endl; 
    }
    cout << "==== SUCCSESS ====" << endl; 
    cout << endl; 
    cout << "==== POPING OBJECTS ====" << endl; 
    for (unsigned int i = 0; i < 5; i++){
        string toPrint = personalQueue.pop(); 
        cout << "String Removed: " << toPrint << endl; 
        cout << "New size: " << personalQueue.size() << endl; 
    }
    if (personalQueue.size() == 0){
        cout << "SUCCESS" << endl;
    }

    




    srand(time(0));
    unsigned int numAdd1 = (rand() % 100) + 20;
    unsigned int numRemove1 = (rand() % (numAdd1-10)) + 10;
    unsigned int numAdd2 = (rand() % 40) + 10;
    unsigned int numAdd3 = (rand() % 100) + 20;
    Queue studentQ;
    queue<string> trueQ;

    // check initial size
    cout << "=== CHECKING INITIAL SIZE ===" << endl; 
    if(studentQ.size() != trueQ.size()) {
        cout << MESSAGE_WRONG_SIZE << endl;
        return 1;
    }


    // simple test
    cout << "=== TESTING PUSH FUNCTION ===" << endl; 
    studentQ.push("Niema");
    if(studentQ.size() != 1) {
        cout << MESSAGE_WRONG_SIZE << endl;
        return 1;
    }
    cout << "Current Size: " << studentQ.size() << endl; 

    //testing pop method.
    string test1 = studentQ.pop(); 
    if(test1 != "Niema") {
        cout << MESSAGE_WRONG_POP << endl;
        return 1;
    }

    else{
        cout << test1 << endl;
        cout << "=== POP METHOD SUCCESS ===" << endl; 
    }

    if(studentQ.size() != 0) {
        cout << MESSAGE_WRONG_SIZE << endl;
        return 1;
    }

    cout << "=== ADDING BUNCH OF STRINGS ===" << endl; 
    // add a bunch of strings and check size
    cout << "total iterations: " << numAdd1 << endl; 
    for(unsigned int i = 0; i < numAdd1; ++i) {
        string curr = randomString((rand() % 10) + 10);
        studentQ.push(curr);
        trueQ.push(curr); 
        if(studentQ.size() != trueQ.size()) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
    }
     cout << "=== ADDING SUCCESS ===" << endl; 

    cout << "=== TESTING REMOVAL ===" << endl; 
    // remove a bunch of strings and check size + correctness
    cout << "total iterations: " << numRemove1 << endl; 
    for(unsigned int i = 0; i < numRemove1; ++i) {
        cout << "current iteration: " << i << endl; 
        cout << "==== removing string from linked list ====" << endl; 
        string studentCurr = studentQ.pop();
        string trueCurr = trueQ.front();
        trueQ.pop();
         cout << "==== comparing the two strings ====" << endl;
         cout << "Student size: " << studentQ.size() << endl;
         cout << "True size: " << trueQ.size() << endl; 
        if(studentQ.size() != trueQ.size()) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
        cout << "====== Success 1 ======" << endl;
        if(studentCurr != trueCurr) {
            cout << MESSAGE_WRONG_POP << endl;
            return 1;
        }
    }

    // add a bunch of strings and check size
    for(unsigned int i = 0; i < numAdd2; ++i) {
        string curr = randomString((rand() % 10) + 10);
        studentQ.push(curr);
        trueQ.push(curr);
        if(studentQ.size() != trueQ.size()) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
    }
    cout << "====== Success 2 ======" << endl;
    // clear and check size
    studentQ.clear();
    trueQ = queue<string>();
    if(studentQ.size() != trueQ.size()) {
        cout << MESSAGE_WRONG_SIZE << endl;
        return 1;
    }

    cout << "====== Success 3 ======" << endl;

    // add a bunch of strings and check size
    for(unsigned int i = 0; i < numAdd3; ++i) {
        string curr = randomString((rand() % 10) + 10);
        studentQ.push(curr);
        trueQ.push(curr);
        if(studentQ.size() != trueQ.size()) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
    }

    
    // if it didn't fail yet, success!
    cout << MESSAGE_SUCCESS << endl;
    return 0;
}