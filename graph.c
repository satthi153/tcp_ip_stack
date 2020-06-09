/*
 * Graph member function definitions
 * */

#include <iostream.h>
#include <arpa/inet.h>

void
Graph::addNode(Node *pNode)
{
    nodeList.push_back(pNode)  
}


/*Node member functions*/
void
Node::addIf(Interface *pIf)
{
    vpIfs.push_back(pIf);
}

/*Interface member functions*/
int
Interface::addIpAddr(std::string ipAddr)
{
    if(!inet_pton(ipAddr.c_str()))
    {
        std::cout << "Invalid ipAddr" << endl; 
        return 1;
    }
    
    ipAddr = ipAddr;
    return 0;
}

void
Interface::isIfConnected()
{
    return connected;
}

void
Interface::setIfConnectionStatus(bool status)
{
    connected = status;
}
