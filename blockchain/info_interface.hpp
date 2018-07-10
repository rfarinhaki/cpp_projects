#ifndef INFO_INTERFACE_H
#define INFO_INTERFACE_H

#include <string>
using namespace std;
class IInfo
{
    public:
        virtual ~IInfo(){};
        virtual void setLastHash(string _lastHash)=0;
        virtual string getHash()=0;
};
#endif
