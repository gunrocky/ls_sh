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
#include <string>

// count of access bits of file
static const unsigned short g_count_accessbits = 9;

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
    std::string dirPath(argv[1]);
    if (dirPath.back() != '/')
    {
        dirPath.append("/");
    }
    char filetype = 0;
    std::string fullPath;
    
    int ret = 0;
    errno = 0;
    while ((entry = readdir(udir.get())) != NULL)
    {
        fullPath.assign(dirPath + entry->d_name);
        ret = lstat(fullPath.c_str(), &fileStat);
        if (ret)
        {
            std::cout << "error " << errno << " to get stat of " << entry->d_name << std::endl;
            continue;
        }
        /* Just example of all mode options getting
         * std::bitset<(sizeof(__mode_t) * 8)> b(fileStat.st_mode);
        */
        switch(fileStat.st_mode & __S_IFMT)
        {
            case __S_IFDIR:
                // directory
                filetype = 'd';
                break;
            case __S_IFCHR:
                // character file
                filetype = 'c';
                break;
            case __S_IFBLK:
                // block file
                filetype = 'b';
                break;
            case __S_IFREG:
                // regular file
                filetype = '-';
                break;
            case __S_IFIFO:
                // fifo, pipe
                filetype = 'p';
                break;
            case __S_IFLNK:
                // sym link
                filetype = 'l';
                break;
            case __S_IFSOCK:
                // socket
                filetype = 's';
                break;
            default:
                // unknown type of file
                filetype = '?';
                break;
        }
        std::bitset<g_count_accessbits> b(fileStat.st_mode);
        std::cout << filetype << ' ' << b.to_string() << "  " << entry->d_name << std::endl;
    }
    
    return 0;
}

