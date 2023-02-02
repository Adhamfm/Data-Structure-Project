
#include <string>
#include <fstream>
#include<iostream>
#include <string>
//#include <algorithm>
//#include <cstring>
#include <vector>
//#include <algorithm>
#include <locale>
#include <functional>

using namespace std;

	fstream read_file;
	ofstream write_file;


	char chars[]=" ";
	char chars2[]="/<> ";
	char mychar,mychar2;
	string myline;
	int openN=0,closeN=0,j;
	static int tabs_num=0;


void prettify(string input_file, string output_file){


	  read_file.open(input_file,ios::in);

		  // If file failed to open, exit with an error message and error exit status
		  if (read_file.fail())
		  {
		    cout << "Error opening file." << endl;

		    // returning 1 instead of 0 is a signal to the shell that something went
		    // wrong in the execution of the program

		  }

		  // Create a vector to store all the file lines, and a string line to store
		  // each line that we read
		  vector<string> lines;
		  string line;

		  // Read each line of the file and store it as the next element of the vector,
		  // the loop will stop when there are no more lines to read
		  while (getline(read_file, line))
		    lines.push_back(line);

		  // Close our access to the file since we are done reading with it
		 // read_file.close();


		  //read_file.flush();	  // Create ofstream object for writing to the file
		  write_file.open(output_file,ios::out);

		  // If the file failed to open, exit with an error message and exit status
		  if (write_file.fail())
		  {
		    cout << "Error opening file." << endl;

		  }

		  for (int counter = 0; counter < int(lines.size()); counter++){

			  int num=0;

			  					//read line from myfile in myline

			  					line=lines[counter];
			  					line.erase(std::remove_if(line.begin(), line.end(), std::bind(std::isspace < char > ,
			  					            std::placeholders::_1,
			  					            std::locale::classic())),
			  							line.end());

			  						//open tag
			  					for(int cnt=0;cnt<line.size();cnt++){
			  						if(line[cnt]=='<'){
			  							num++;
			  						}

			  					}

			  					if(num==2){
			  						tabs_num--;
			  					}

			  						if (line[0] == '<' && line[1] != '/' ){


			  						for(int i=0;i<tabs_num;i++){
			  							write_file <<"\t";
			  						}
			  						tabs_num++;

			  							write_file << line << endl;



			  							//openN++;

			  						}


			  						//close tag
			  						else if(line[1] == '/' && line[0] == '<' ) {
			  							tabs_num--;

			  							for(int i=0;i<tabs_num;i++){
			  										 write_file <<"\t";
			  										  				}

			  							write_file <<line << endl;



			  							//closeN++;
			  						}

			  						else{

			  							for(int i=0;i<tabs_num-1;i++){
			  										  		write_file <<"\t";
			  										  					}

			  									write_file <<line << endl;
			  						}
		  }

			  							//forming the close tag name



		 // file_status=No_Error;

		  // Close our access to the file since we are done working with it

		//  write_file.flush();
		  write_file.close();




			  					}
