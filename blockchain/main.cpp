#include <iostream>
#include "chain.hpp"

using namespace std;

int main()
{
    int i; 
    /*
       Block b1 = Block("Ricardo", 33, "asdf");
       Block b2 = Block("Ricardo Farinhaki", 34, "");
       string s("Teste!");

       cout<<b1.getInfo().getName()<<" "<<b1.getInfo().getIdade()<<endl;
       cout<<"hash:"<<b1.getHash()<<endl;

       cout<<b2.getInfo().getName()<<" "<<b2.getInfo().getIdade()<<endl;
       cout<<"hash:"<<b2.getHash()<<endl;
       */

    Chain c;
    c.addBlock(new Info("Joao", 74));
    c.addBlock(new Info("Antonia", 64));
    c.addBlock(new Info("Monica", 36));
    c.addBlock(new Info("Gustavo", 33));
    c.addBlock(new Info("Ricardo", 33));

    for(i=0; i<c.size(); i++)
    {
        Info *info =(Info*) c.getBlock(i)->getInfo();
        cout<<info->getName()<<"\t "<<info->getIdade()<<":\t"<< c.getBlock(i)->getHash()<<endl;
    }
}
