//
//  turtleprogram.cpp
//  TurtleProgram
//
//  Created by Soo Yun Kim on 5/3/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#include "turtleprogram.hpp"

// [] -- empty TP
// [F 10 R 20] -- TP length 4
ostream& operator<<(ostream &output, const TurtleProgram &tp) {
    output << "[";
    for (int i = 0; i < tp.size; i++) {
        output << tp.arr[i];
        if (i + 1 < tp.size) {
            output << " ";
        }
    }
    output << "]";
    return output;
}

// 0 parameters, 0 size - not size of 1
// use initialization list when possible
TurtleProgram::TurtleProgram() : arr{nullptr}, size{0} {
    
}

// 1 parameter constructors should be explicit
TurtleProgram::TurtleProgram(TurtleProgram &&tp) {
    size = tp.size;
    arr = new string[size];
    for(int i = 0; i < size; i++) {
        arr[i] = tp.arr[i];
    }
}

// create object with two strings
TurtleProgram::TurtleProgram(string direation, string step) {
    size = 2;
    arr = new string[size];
    arr[0] = direation;
    arr[1] = step;
}

// 0 sized programs for copy-constructor
TurtleProgram::TurtleProgram(const TurtleProgram &tp) : size{tp.size} {
    if (size == 0) {
        arr = nullptr;
    } else {
        arr = new string[size];
    }
    for (int i = 0; i < size; i++) {
        arr[i] = tp.arr[i];
    }
}

// deleting nullptr is OK
// nobody can access TP,
// so no need to set it to nullptr
TurtleProgram::~TurtleProgram() {
    delete [] arr;
}

// define one not both
bool TurtleProgram::operator==(const TurtleProgram &tp) const {
    if (size == tp.size) {
        for (int i = 0; i < size; i++) {
            if (arr[i] != tp.arr[i]) {
                return false;
            }
        }
    }
    return true;
}

// define one not both
bool TurtleProgram::operator!=(const TurtleProgram &tp) const {
    return !(this == &tp);
}

// check whether they are same or not, delete array and create new array
TurtleProgram& TurtleProgram::operator=(const TurtleProgram &tp) {
    if (this == &tp) {
        return *this;
    }
    if (arr != 0) {
        delete [] arr;
        size = 0;
    }
    size = tp.size;
    arr = new string[size];
    for (int i = 0; i < size; i++) {
        arr[i] = tp.arr[i];
    }
    return *this;
}

// calculate addiction
TurtleProgram TurtleProgram::operator+(const TurtleProgram &tp) const {
    TurtleProgram add;
    add.size = size + tp.size;
    add.arr = new string[add.size];
    for (int i = 0; i < size; i++) {
        add.arr[i] = arr[i];
    }
    for (int i = 0; i < tp.size; i++) {
        add.arr[i + size] = tp.arr[i];
    }
    return add;
}

// add object by making new array
TurtleProgram& TurtleProgram::operator+=(const TurtleProgram &tp) {
    int newSize = size + tp.size;
    string *newArr = new string[newSize];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < tp.size; i++) {
        newArr[i + size] = tp.arr[i];
    }
    size = newSize;
    arr = newArr;
    return *this;
}

// calculate multiplication
TurtleProgram TurtleProgram::operator*(const int &times) const {
    TurtleProgram mult;
    mult.size = size * times;
    mult.arr = new string[mult.size];
    for (int i = 0; i < mult.size; i++) {
        mult.arr[i] = arr[i % size];
    }
    return mult;
}

// multiply object by creating new array
TurtleProgram& TurtleProgram::operator*=(const int &times) {
    int newSize = size * times;
    string *newArr = new string[newSize];
    for (int i = 0; i < newSize; i++) {
        newArr[i] = arr[i % size];
    }
    size = newSize;
    arr = newArr;
    return *this;
}

// return length of array
int TurtleProgram::getLength() {
    return size;
}

// return index of string by receiving integer
string TurtleProgram::getIndex(int index) {
    return arr[index];
}

// set index in array based on integer and string
void TurtleProgram::setIndex(int index, string str) {
    arr[index] = str;
}
