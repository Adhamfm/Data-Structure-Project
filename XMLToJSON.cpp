#include "NodeTree.h"
#include <iostream>
#include <stack>
#include <queue>
#include "TreetoJSON.h"
using namespace std;


int main()
{
    //string xml = "<root><row><id>1</id><name>Johnson, Smith, and Jones Co.</name><amount>345.33</amount><Remark>Pays on time</Remark></row><row><id>2</id><name>Sam &quot;Mad Dog&quot; Smith</name><amount>993.44</amount><Remark>ssssss</Remark></row><row><id>3</id><name>Barney &amp; Company</name><amount>0</amount><Remark>Great to work with and always pays with cash.</Remark></row><row><id>4</id><name>Johnson&#x27;s Automotive</name><amount>2344</amount><Remark>sss</Remark></row></root>";
    //string xml = "<root><items><item><name>Item 1</name><description>This is the first item</description></item><item><name>Item 2</name><description>This is the second item</description></item></items></root>";
    string xml = "<users><user><id>1</id><name>Ahmed Ali</name><posts><post><body>sit</body><topics><topic>economy</topic></topics></post><post><body>Lrttry5</body><topics><topic>solar_energy</topic></topics></post></posts><followers><follower><id>2</id></follower><follower><id>3</id></follower></followers></user><user><id>2</id><name>Yasser Ahmed</name><posts><post><body>Lorem</body><topics><topic>education</topic></topics></post></posts><followers><follower><id>1</id></follower></followers></user><user><id>3</id><name>Mohamed Sherif</name><posts><post><body>uopeer</body><topics><topic>sports</topic></topics></post></posts><followers><follower><id>1</id></follower></followers></user></users>";

    TreetoJSON x;

// Convert XML to Tree
    NodeTree root = x.convertxml(xml);

    cout << "Traverse Tree\n";
    x.dfs(&root);
    cout << "___________________________________\n\n\n";
    cout << "JSON\n\n";
    x.mostFollower(&root);
    cout<< "most followers with: " << x.influencer.substr(1) << " has "<< x.followers << " followers \n";
    x.mostActive(&root);
    cout<< "most active with: " << x.active.substr(1) << " has "<< x.posts << " posts \n";
    // Convert Tree to JSON
    x.treeToJson(&root);
    cout << x.getJSON();
    cout << "\n\n\n";
//    NodeTree* ptr = root.getChildren()[0];

}
