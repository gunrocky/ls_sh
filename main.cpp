/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gunrocky
 * Task: Reading the contents of file system directories
 * Task description:
 * Write a program that reads the content of
 * the directory specified (by the startup command line parameter),
 * and displays brief information about all names
 * in this directory (at least: name, type, access flags)
 *
 * Created on March 6, 2016, 9:46 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc < 2 || argc > 2)
    {
        cout << "usage: " << argv[0] << " <directory path>";
    }
    return 0;
}

