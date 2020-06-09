#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <list>
#include <string>

#define MAX_NAME_SZ 32

class Interface
{
    std::string name;
    std::string ipAddr;
    Link link;
    bool connected;

public:
    Interface(std::string name, std::string ipAddr=0):name(name), ipAddr(ipAddr)
    {
        connected = false;
    };
    int setIpAddr(std::string ipAddr);
    bool isIfConnected();
    void setIfConnectionStatus(bool state);
};

class Node
{
    std::string name;
    std::vector<Interface *> vpIfs;

public:
    Node(std::string name):name(name){};
    void addIf(Interface *pIf);

};

class Link
{
    Node *pNodeA;
    Node *pNodeB;
    Interface *pIfA;
    Interface *pIfB;

    uint32 cost;
public:
    Link(Node *pNodeA, Node *pNodeB, Interface *pifA, Interface *pIfB, cost=0): pNodeA(pNodeA), pNodeB(pNodeB), pIfA(pIfA), pIfB(pIfB), cost(cost){};

}

class Graph 
{
    std::string name;
    std::list<Node *> nodeList;

public:
    Graph(std::string graph_name): name(graph_name){};
    void addNode(Node *pNode);
    Node* getNodeList();
};

#endif

