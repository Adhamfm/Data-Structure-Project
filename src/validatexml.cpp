#include "validatexml.h"
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;


//reversing string recursively
string reversestringrec(string str) {
    while (str.length() >= 0 && str.length() <= 20) {
        if (str.length() == 1) {
        	return str;
        }
        else {
            return reversestringrec(str.substr(1, str.length())) + str.at(0);
        }
    }
    return "invalid input string";
}


//changing filexml content



std::stack<std::string> str;
std::string myline;
//stack of char named input
stack<char> input;
stack <int> input2;
int i=0;
char chars[]=" ";
char chars2[]="/<> ";
char mychar,mychar2;
int lineNum=1;
//to avoid the initial value of false
bool mark = true;
string opentag, closetag;
int openN=0 , closeN=0;
bool flag = false;
//file correcting variables
string filename;
string text;
int line_number;
vector<string> lines;
string line;

validatexml::validatexml() {

	// TODO Auto-generated constructor stub
}


void copyFile(string sourceFileName, string destinationFileName) {
    std::ifstream sourceFile(sourceFileName);
    std::ofstream destinationFile(destinationFileName);

    destinationFile << sourceFile.rdbuf();

    sourceFile.close();
    destinationFile.close();


}

void validatexml::  check_xml(string string){


		std::fstream myfile (string);
		std::ofstream filexml("corrected.txt");

		copyFile("sample.xml","corrected.xml");



		//check tag number and shape
		while ( myfile ) {
			//read char from the file stream
			mychar = myfile.get();
			if(mychar=='<'){
				input.push(mychar);
			}
			if(mychar=='>'){
				input.pop();
			}
		}

		myfile.close();
		//check the empty of the stack
		if(input.empty()==1){
			cout << "there are no error"<<endl;
		}
		else {
			//numbers of tags are equal and same shape <
			cout << "error found"<< endl;
		}
		myfile.close();

		//check tag name
		//open file identified by file name as an argument
		myfile.open("sample.xml");
			//return true if the file is opened
			if( myfile.is_open() ) {
				//.good() return true if the file has no errors
                    while (myfile.good()){
					//read line from myfile in myline
					getline (myfile, myline);
                    int linelen = myline.length();
					for(int j = 0; j <linelen; j++){
						opentag = "";
						closetag="";
						int counter = 0;
						mychar2 = myline[j];
						//open tag
						if (mychar2 == '<' && myline[j+1] != '/'){
							openN++;
							for(int k = j+1 ; myline[k] != '>' ; k++){
								input.push(myline[k]);
								counter += 1 ;
							}
							//counter in stack for the current length of the tag
							input2.push(counter);
						}
						//close tag
						else if(mychar2 == '/' && myline[j-1] == '<' && !input2.empty()) {
							closeN++;
							int cnt = input2.top();
							input2.pop();
							//forming the close tag name
							for (int v = j+1 ; myline[v] != '>' ; v++){
								closetag += myline[v];
							}
							cout << closetag<<endl;
							for (int m = j+1,n=2 ;n < cnt + 2;m++,n++){
								if( myline[linelen-n] == input.top() ){
									//forming the open tag name in variable tag
									opentag += input.top();
									input.pop();
									//all results must be true to obtain a true output
									mark &= true;
								}

						//&= for cumulative error checking if one time is false then the result is false
								else
								{
									opentag += input.top();
									input.pop();
									mark &= false;
									cout << "error in line: " << lineNum << endl;
									//missing tag
									cout << closetag << endl;

								}
							}
						//cout the name of the tag
						cout << reversestringrec(opentag) << endl;
					}
					}
					lineNum += 1 ;
                    }
                    if (openN>closeN){
                    	cout << "missing closetag"<<endl;

                    }
                    else{
                    	cout << "missing opentag" <<endl;

                    }
                    /*if (reversestringrec(opentag) == reversestringrec(closetag)){
                    	cout << "no tag errors"<<endl;
                    }
                    else {
                    	cout<< "error in line:" << lineNum<<endl;
                    }*/

					if (mark == true){
						cout << "tags are consistent"<< endl;
					}
					else cout << "tags are inconsistent" << endl;

					if (input.empty()==true){
						cout << "empty stack"<<endl;
					}
					else cout << "error in stack"<< endl;

					//printing the total number of lines in the file
					//cout << lineNum<<endl;
//return "Tree";
}
	
	getline(cin,filename);

	getline(cin, text);

	cin >> line_number;

	fstream read_file;
	read_file.open(filename);

	if(read_file.fail()){
		cout<<"error in opening file to read"<< endl;
	}


	while(getline(read_file,line)){
		lines.push_back(line);
	}

	read_file.close();

	if (line_number > lines.size())
	{
		 cout << "Line " << line_number;
		 cout << " not in file." << endl;

		 // Inform user how many lines ARE in the file as part of the error message
		 cout << "File has " << lines.size();
		 cout << " lines." << endl;

	 }


	ofstream write_file;
	write_file.open(filename);

	if(write_file.fail()){
	cout << "error in corrected.xml"<<endl;
	}


	line_number --;

	for (int x = 0; x < lines.size(); x++)
	 {
	  // If the current index is not the line number we wish to replace, write
	// the line back to the file, OTHERWISE if it IS the line we want to
	// replace write the replacement text back to the file instead.
	if (x != line_number)
	write_file << lines[x] << endl;
	else
	write_file << text << endl;
	}
	write_file.close();
}


validatexml::~validatexml() {
	// TODO Auto-generated destructor stub
}
