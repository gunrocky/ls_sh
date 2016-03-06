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
#include <memory>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <bitset>

//using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc < 2 || argc > 2)
    {
        std::cout << "usage: " << argv[0] << " <directory path>";
        return 1;
    }
    
    std::unique_ptr<DIR, void (*)(DIR *)> udir(opendir(argv[1]),
            [] (DIR *udir)
            {
                closedir(udir);
            });
    
    struct dirent *entry = NULL;
    struct stat fileStat {};
    int ret = 0;
    errno = 0;
    while ((entry = readdir(udir.get())) != NULL)
    {
        // TODO: correct output of file type and permissions
        ret = stat(entry->d_name, &fileStat);
        if (ret)
        {
            std::cout << "error to get stat of " << entry->d_name << std::endl;
            continue;
        }
        std::bitset<(sizeof(__mode_t) * 8)> b(fileStat.st_mode);
        std::cout << b.to_string() << "  " << entry->d_name << std::endl;
    }
    
    return 0;
}

