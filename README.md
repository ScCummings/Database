#School Database

1. Identifying Information
    * Name:  Dan Haub
    * Student ID#:  2315346
    * Chapman Email:  haub@chapman.edu
    * Name:  Scott Cummings
    * Student ID#:  2317991
    * Chapman Email:  scummings@chapman.edu
    * Course Number and Section:  CPSC 350-01
    * Assignment:  5 - School Database

2. Source Files
    * main.cpp
    * Makefile
    * GenTree.h
    * GenStack.h
    * GenDoubleLinkedList.h
    * LimitedAcceptingStack.h
    * Person.h
    * Faculty.h
    * Faculty.cpp
    * Student.h
    * Student.cpp
    * Database.h
    * Database.cpp
    * Rollback.h
    * Rollback.cpp
    * FileIO.h
    * FileIO.cpp
    * Manager.h
    * Manager.cpp
    * UnserializeEcxeption.h
    * UnserializeEcxeption.cpp
    * StackException.h
    * StackException.cpp


3. Description of any known compile/runtime errors, or bugs.
    * It is possible to create multiple students and faculty with the same ID 
        * This can only happen through the storage files by manually changing the data stored within

4. References used to complete the assignment
    * https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
    * https://isocpp.org/wiki/faq/serialization#serialize-no-cycles-no-joins
    * https://isocpp.org/wiki/faq/exceptions#selfcleaning-members
    * https://www.boost.org/doc/libs/1_69_0/libs/serialization/doc/tutorial.html
    * https://stackoverflow.com/questions/23599708/how-do-i-resolve-this-error-jump-to-case-label-crosses-initialization
    * Nicholas Mirchandani

5. Instructions for running the assignment
    * git clone from repository
    * cd to Database folder
    * input "make"
    * input "./assignment5.exe"
