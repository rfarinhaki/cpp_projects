#include "info.hpp"
#include <sstream>
#include <iostream>
#include <openssl/sha.h>
#include <string>
#include <cstring>
using std::string;


using namespace std;

Info::Info(string _nome, int _idade)
{
    nome = _nome;
    idade = _idade;
}

Info::Info()
{
    nome = "";
    idade = 0;
}

Info::~Info()
{
    //cout<<"Info destructor "<<nome<<endl;
}

string Info::getName()
{
    return nome;
}

int Info::getIdade()
{
    return idade;
}

void Info::setName(string _name)
{
    nome = _name;
}

void Info::setIdade(int _idade)
{
    idade = _idade;
}

string Info::getHash()
{
    ostringstream convert;

    unsigned char digest[SHA256_DIGEST_LENGTH];
    string text;
    text = nome+":";
    convert << idade;
    text +=convert.str();
    text += ":";
    text += lastHash;
    //cout<<"texto:"<<text<<endl;;

    char *cstr = new char[text.length() + 1];
    strcpy(cstr, text.c_str());

    //cout<<"cstr:"<<cstr<<endl;
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, cstr, strlen(cstr));
    SHA256_Final(digest, &ctx);

    char mdString[SHA256_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    string restr(mdString);
    return restr;
}

void Info::setLastHash(string _lastHash)
{
    lastHash = _lastHash;
}
