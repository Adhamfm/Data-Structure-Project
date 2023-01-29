#include "NodeTree.h"
#include <iostream>
#include <stack>
#include <queue>

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
bool isLeaf(NodeTree *node)
{
    return node->getChildren().empty();
}
string json="";
int openbrackets=0;

void treeToJson(NodeTree *node)
{
    int comma=0;
    int grandcomma=0;
    if (!isLeaf(node))
    {
        json+= "{\"" + node->getKey() + "\" : ";
        openbrackets++;
        if (node->hasMultipleChildrenWithSameKey())
        {
            vector<NodeTree*>children = node->getChildren();
            json += "{\"" + children[0] ->getKey()+ "\": "; // get a copy of the key
            comma = children.size()-1;
                json += "[";
            for (NodeTree *child : children)
            {
                json += "{";
                vector<NodeTree*> grandchildren = child->getChildren();
                int grandcomma=grandchildren.size()-1;

                for (NodeTree *grandchild : grandchildren)
                {
                    json += "\""+ grandchild->getKey() +"\":\""+ grandchild->getValue().substr(1)+ "\"";
                    if (grandcomma>0){
                        json +=",";
                        grandcomma--;
                    }
                }
            json+="}";
                if (comma >0){
                    json+=",";
                    comma--;
                }
            }
                json +="]}";
        }

    }

    if (!node->hasMultipleChildrenWithSameKey()){

        for (NodeTree *child : node->getChildren())
        {
            treeToJson(child); // recursively call dfs on each child
            json+="}";
        }
    }
    else
    json+="}";
}

void dfs(NodeTree *node) {
    cout << node->getKey() << " " ; // print the current node's key and value
    if (node->getValue() != "") cout<< ": " << node->getValue().substr(1);
    cout << "\n";
    for (NodeTree *child : node->getChildren()) {
        dfs(child); // recursively call dfs on each child
    }
}

int main()
{
    //string xml = "<root><row><id>1</id><name>Johnson, Smith, and Jones Co.</name><amount>345.33</amount><Remark>Pays on time</Remark></row><row><id>2</id><name>Sam &quot;Mad Dog&quot; Smith</name><amount>993.44</amount><Remark>ssssss</Remark></row><row><id>3</id><name>Barney &amp; Company</name><amount>0</amount><Remark>Great to work with and always pays with cash.</Remark></row><row><id>4</id><name>Johnson&#x27;s Automotive</name><amount>2344</amount><Remark>sss</Remark></row></root>";
    string xml = "<root><items><item><name>Item 1</name><description>This is the first item</description></item><item><name>Item 2</name><description>This is the second item</description></item></items></root>";

    // Convert XML to Tree
    NodeTree root = convertxml(xml);

    cout << "Traverse Tree\n";
    dfs(&root);
    cout << "___________________________________\n\n\n";
    cout << "JSON\n\n";
    // Convert Tree to JSON
    treeToJson(&root);
    cout << json;
    cout << "\n\n\n";
//    NodeTree* ptr = root.getChildren()[0];

}
