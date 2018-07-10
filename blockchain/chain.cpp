#include "chain.hpp"

Chain::Chain()
{
    chain = new vector<Block*>();
}

Chain::~Chain()
{
    //cout<<"Chain destructor"<<endl;
    for(int i=0; i < (int)chain->size(); i++)
        delete (chain->at(i));
    delete chain;
}

void Chain::addBlock(IInfo* info)
{
    string lastHash = getLastHash();
    info->setLastHash(lastHash);
    chain->push_back(new Block(info) );
}

string Chain::getLastHash()
{
    string first_hash(64,'0');
    if(((int)chain->size())>0)
        return chain->back()->getHash();
    else
        return first_hash;
}

Block* Chain::getLastBlock()
{
    return chain->back();
}

Block* Chain::getBlock(int idx)
{
    if(idx>=(int)chain->size() || idx<0)
        return new Block("",0,"");
    else
        return chain->at(idx);
}

int Chain::size()
{
    return (int)chain->size();
}
