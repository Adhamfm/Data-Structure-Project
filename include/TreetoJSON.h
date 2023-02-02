#ifndef TREETOJSON_H
#define TREETOJSON_H

#include "NodeTree.h"
#include <string>

class TreetoJSON
{
    private:
        std::string json="";

    public:
        std::string influencer="";
        std::string active="";
        std::string currentname="";
        int posts=0;
        int followers=0;
        void dfs(NodeTree *node);
        void treeToJson(NodeTree *node);
        bool isLeaf(NodeTree *node);
        std::string getJSON();
        NodeTree convertxml(std::string xml);
        void BFS(NodeTree *root);
        void mostFollower(NodeTree *node);
        void mostActive(NodeTree *node);
};

#endif // TREETOJSON_H
