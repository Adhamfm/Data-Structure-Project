#include "minify.h"
using namespace std;

void minify(string inputFile, string outputFile) {
    ifstream indata(inputFile);
    ofstream outdata(outputFile);
    string sentence;
    while (getline(indata, sentence)) {		//Reading file
        string res = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence.at(i) != '\t' && sentence.at(i) != '\n' && sentence.at(i) != ' ')
                res += sentence.at(i);
        }
        outdata << res;
    }
    indata.close();
}

