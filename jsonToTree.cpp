#include "NodeTree.h"
#include <iostream>
#include <stack>
#include <queue>
#include "JsonObject.h"
using namespace std;

NodeTree convertxml(string xml)
{
    stack<NodeTree*> tags;
    string element="";
    string value="";
    NodeTree root("");
    int currentChar=0;
    while(xml[currentChar]!='\0')
    {
        if(xml[currentChar] == '<')
        {
            currentChar++;
            // Case 1: Not Closing Tag
            if(xml[currentChar]!='/')
            {

                while(xml[currentChar] != '>')
                {

                    element+=xml[currentChar];
                    currentChar++;

                } // element is tag

                if (tags.empty())
                {
                    root.setElement(element);    //created root
                    tags.push(&root);
                }
                else
                {
                    NodeTree* parentNode = tags.top();
                    NodeTree* node = new NodeTree(element);
                    parentNode->addChild(node);
                    tags.push(node);
                }
                if(xml[currentChar+1]!='<')
                {
                    while(xml[currentChar]!='<')
                    {
                        value += xml[currentChar];
                        currentChar++;
                    }
                    tags.top()->setValue(value);
                    //cout<< value;
                    value="";
                    tags.pop();
                }
                element=""; //reset element
            }
            else if(xml[currentChar] =='/')
            {
                tags.pop(); // remove tag from stack
            }
        }
        //cout << xml[currentChar];
        currentChar++;
    }
    //NodeTree* ptr = root.getChildren()[0];
    return root;
}
//TO check tree
void bfs(NodeTree* root)
{
    if (root == nullptr) return;

    queue<NodeTree*> q;
    q.push(root);

    while (!q.empty())
    {
        NodeTree* current = q.front();
        q.pop();
        for (NodeTree* child : current->getChildren())
        {
            //cout << "\nPushed to queue: " << child->getKey() << "\n";
            if (child) q.push(child);
            if(child)
            {
                //cout<< " from bfs: " << child->getKey();
                bool c = child->hasMultipleChildrenWithSameKey();
                if (c) cout<< "Parent: " << child->getKey() << " has Duplicate childs \n";
            }
        }
    }
}


bool isLeaf(NodeTree *node)
{
    return node->getChildren().empty();
}

//Function to change XML Tree to JSON string
string treetoJSON(NodeTree *node, string json,bool isRepeated=false)
{
    if (node == nullptr)
    {
        return "";
    }
    // Check if Leaf
    if (isLeaf(node)) json+= "\"" + node ->getKey() + "\" : ";
    // Process the current node
    else if(isRepeated) {json+= "{\"" + node ->getKey() + "\" : "+"";}
    else json+= "{\"" +node->getKey() + "\" : ";
    if(isRepeated) json+= "[";


    if (node->hasMultipleChildrenWithSameKey()){isRepeated=true;}
    else isRepeated=false;

    if (node->getValue()!="") json+= "\"" + node->getValue() + "\"";

    // Recursively visit the children
    for (NodeTree *child : node->getChildren())
    {
        json = dfs2(child,json,isRepeated);
    }

    if (isRepeated) json+= "]";
    else if (isLeaf(node)) json += ",";
    else json+="}";
    return json;
}
