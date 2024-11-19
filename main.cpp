#include <iostream>             // It is a preprocessor directive in C++
#include "inc/exercise123linkList.hpp" // Include the header file exercise123linkList.hpp from the inc directory into the program
#include "inc/exercise4singletonPattern.hpp" // Include the header file exercise4singletonPattern.hpp from the inc directory into the program
#include "inc/exercise5factoryDesignPattern.hpp" // Include the header file exercise5factoryDesignPattern.hpp from the inc directory into the program
using namespace std; // Don't need to use the std:: prefix to access components in the standard library.

#define _chooseExercise123_ // Add a comment // if you don't want to run Exercise 1, 2, 3
#define _chooseExercise4_ // Add a comment // if you don't want to run Exercise 4
#define _chooseExercise5_ // Add a comment // if you don't want to run Exercise 5

int main() {
    #ifdef _chooseExercise123_ // If this macro is defined: ercise123linkList.cpp, ercise123linkList.hpp will be called.
        cout << endl << "         *** Exercise123: linkList ***" << endl;
        SLL linkedList;
        init(&linkedList);
        printList(&linkedList);

        addHead(&linkedList, 1);
        printList(&linkedList);

        addTail(&linkedList, 3);
        printList(&linkedList);

        addTail(&linkedList, 5);
        printList(&linkedList);

        addTail(&linkedList, 7);
        printList(&linkedList);

        deleteNode(&linkedList, 5);
        printList(&linkedList);

        insertNode(&linkedList, 2, 2);
        printList(&linkedList);

        insertNode(&linkedList, 9, 9);
        printList(&linkedList);

        Node *max = findMax(&linkedList);
        cout << max->data << endl << endl;

        Node *min = findMin(&linkedList);
        cout << min->data << endl << endl;
        
        cout << containsLoop(&linkedList) << endl;
        cout << "........................................................................" << endl;
    #endif

    #ifdef _chooseExercise4_ // If this macro is defined: ercise4singleton.cpp, ercise4singleton.hpp will be called.
        cout << endl << "           *** Exercise4: Singleton Pattern ***" << endl;
        Singleton* instance =  Singleton::getInstance("getInstance");
        cout << instance->getValue() << endl;
        cout << "........................................................................" << endl;
    #endif

    #ifdef _chooseExercise5_ // If this macro is defined: ercise5factory.cpp, ercise5factory.hpp will be called.
        cout << endl << "        *** Exercise5: Factory Design Pattern ***" << endl;
        /*
        Creating Logger for Console:
        CreateLogger(LoggerFactory::LoggerType::Console) returns a pointer to a ConsoleLogger object.
        Call Log("This is a console log message.")
        */
        auto consoleLogger = LoggerFactory::CreateLogger(LoggerFactory::LoggerType::Console);
        consoleLogger->Log("This is a console log message.");

        /*
        Creating Logger for File:
        CreateLogger(LoggerFactory::LoggerType::File) returns a pointer to a FileLogger object.
        Call Log("This is a file log message.")
        */
        auto fileLogger = LoggerFactory::CreateLogger(LoggerFactory::LoggerType::File);
        fileLogger->Log("This is a file log message.");
        cout << "........................................................................" << endl;
    #endif

    return 0;
}