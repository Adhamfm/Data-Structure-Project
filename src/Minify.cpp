
#include"minify.h"

string minify(string in) {
    string out = "";
    for (int i = 0; i < in.size(); i++) {
        if (in.at(i) != '\n' && in.at(i) != ' ' && in.at(i) != '\t') {
            out += in.at(i);
        }
    }
    return out;
}
