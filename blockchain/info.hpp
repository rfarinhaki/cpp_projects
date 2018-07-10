#ifndef INFO_H
#define INFO_H

#include <string>
#include "info_interface.hpp"
using std::string;

using namespace std;

class Info: public IInfo
{
    private:
       string lastHash;
       string nome;
       int idade;
    public:
       Info();
       Info(string _nome, int _idade );
       virtual ~Info();
       string getName();
       int getIdade();
       string getHash();
       void setName(string _name);
       void setIdade(int _idade);
       void setLastHash(string _lastHash);
};
#endif
