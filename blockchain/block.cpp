#include "block.hpp"
using namespace std;

Block::Block()
{
    info = new Info();
}

Block::Block(string _nome, int _idade, string _lastHash)
{
    Info* _info;
    _info = new Info(_nome, _idade);
    _info->setName(_nome);
    _info->setIdade(_idade);
    _info->setLastHash(_lastHash);
    Hash = _info->getHash();

    info = _info;
}

Block::Block(IInfo* _info)
{
    info = _info;
    Hash = _info->getHash();
}

Block::~Block()
{
    //cout<<"Block destructor"<<endl;
    delete info;
}

IInfo* Block::getInfo()
{
    return info;
}

string Block::getHash()
{
    return Hash;
}
