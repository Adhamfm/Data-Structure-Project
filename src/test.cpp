/*
 * test.cpp
 *
 *  Created on: Dec 11, 2022
 *      Author: pc
 */
#include <iostream>
#include "validatexml.h"
#include <stack>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>



using namespace std;






int main(){
	validatexml xml1;

string str="sample.xml";

	xml1.check_xml(str);














/*
	stack<char> input;
	std::stack<std::string> str;
	std::ifstream myfile ("sample.xml");
	std::string myline;
	int i=0;
	char chars[]=" ";
	char chars2[]="/<> ";
	char mychar;
	int lineNum=0;


	while ( myfile ) {
	mychar = myfile.get();
	if(mychar=='<'){
	input.push(mychar);
	}
	if(mychar=='>'){
		input.pop();
	}
	}
	myfile.close();
	if(input.empty()==1){
		std::cout << "there are no error"<<endl;
	}
	else {std::cout << " error found";

	}
	myfile.close();



/*
	myfile.open("sample.xml");
	while ( myfile ) {
	std::getline (myfile, myline);
	std::cout << myline << '\n';
	}
	myfile.close();



	myfile.open("sample.xml");
	if( myfile.is_open() ) {     while ( myfile.good() ) {
		std::getline (myfile, myline);
		for(i=0;i<strlen(chars);i++){

					    myline.erase (std::remove(myline.begin(), myline.end(), chars[i]), myline.end());
				}
		lineNum++;
		if(myline[0] =='<'){
				i=0;

				for(i=0;i<myline.length(); i++){
					if(myline[i]=='>')
					myline.erase(i);

				}

			}
		else{
			myline.erase(0);
		}
		for(i=0;i<strlen(chars);i++){

		 myline.erase (std::remove(myline.begin(), myline.end(), chars[i]), myline.end());
				}

		if(myline.front()=='<'){

			if( myline[1]=='/'){

			for(i=0;i<(strlen(chars2));i++){

						  myline.erase (std::remove(myline.begin(), myline.end(),chars2[i]), myline.end());
						    				 }
			if(myline==str.top()){
				str.pop();
			}
			else{
				std:: cout<<" there are error in the line "<<lineNum<< "for the tag name: "<< myline<<endl;
			}

			}
			else{for(i=0;i<strlen(chars2);i++){
					 myline.erase (std::remove(myline.begin(), myline.end(),chars2[i]), myline.end());
									     }
			str.push(myline);
			}
		}
	 }
}

	if(str.empty()){

		cout<< "empty"<<endl;
	}
*/
	cout <<"finish";




}



