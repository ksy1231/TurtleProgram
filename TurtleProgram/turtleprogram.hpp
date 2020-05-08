//
//  turtleprogram.hpp
//  TurtleProgram
//
//  Created by Soo Yun Kim on 5/3/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#ifndef turtleprogram_hpp
#define turtleprogram_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class TurtleProgram {
    friend ostream& operator<<(ostream &outStream,const TurtleProgram &tp);
public:
    // 0 parameter constructor
    TurtleProgram();
    // 1 parameter constructor
    explicit TurtleProgram(TurtleProgram &&tp);
    // 2 parameters constructor
    TurtleProgram(string direation, string step);
    // copy constructor
    TurtleProgram(const TurtleProgram &tp);
    // destructor
    virtual ~TurtleProgram();
    
    // operator overloads
    bool operator==(const TurtleProgram &tp) const;
    bool operator!=(const TurtleProgram &tp) const;
    
    TurtleProgram& operator=(const TurtleProgram &tp);
    TurtleProgram operator+(const TurtleProgram &tp) const;
    TurtleProgram& operator+=(const TurtleProgram &tp);
    
    TurtleProgram operator*(const int &times) const;
    TurtleProgram& operator*=(const int &times);
    
    //  returns the number of strings in the program
    // (i.e. for program ​[F 10 PENUP R 90 F 100] getLength​ returns 7)
    int getLength();
    // returns the nth string in the program
    // (i.e. for program ​[F 10 PENUP R 90 F 100]
    // getIndex(0) would return "F",
    // getIndex(1)​ would return "10", and so on
    string getIndex(int index);
    // replace the string at the given index
    void setIndex(int index, string str);
    
private:
    // store data
    string *arr;
    // size of array
    int size;
};

#endif /* turtleprogram_hpp */
