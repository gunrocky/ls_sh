/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gunrock
 * Задание: Чтение содержимого каталогов файловой системы
 * Описание задания:
 * Написать программу, которая читает содержимое
 * указанного (параметром командной строки запуска) каталога,
 * и выводит краткую информацию о всех именах
 * в этом каталоге (как минимум: имя, тип, флаги доступа)
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

