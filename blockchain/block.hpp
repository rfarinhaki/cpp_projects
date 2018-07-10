#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <cstring>
#include <iostream>
using std::string;
#include "info.hpp"
#include "info_interface.hpp"

class Block
{
    private:
        IInfo *info;
        string Hash;
    public:
        Block();
        Block(string _nome, int _idade, string _lastHash);
        Block(IInfo* _info);
        ~Block();
        IInfo* getInfo();
        string getHash();
};

#endif
