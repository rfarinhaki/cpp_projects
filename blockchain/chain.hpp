#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <iostream>
#include "block.hpp"

class Chain
{
    private:
        std::vector<Block*> *chain;
        string getLastHash();
    public:
        Chain();
        ~Chain();
        void addBlock(IInfo *info);
        Block* getLastBlock();
        Block* getBlock(int idx);
        int size();
};
#endif
