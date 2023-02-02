/*
 * validatexml.h
 *
 *  Created on: Dec 11, 2022
 *      Author: pc
 */

#ifndef VALIDATEXML_H_
#define VALIDATEXML_H_

#include <string>
#include <fstream>


using namespace std;

#define missing_close 0
#define missing_open  1
#define Error_found	  1
#define No_Error	  0








class validatexml {


public:

    int line_number;
    string  tag;
    int  status;
    fstream read_file;
    ofstream write_file;
    int file_status = 1;

    validatexml();


    void check_xml(string string);

    void correct_xml(string input_file,string output_file);

    void intergration(string input , string output);


    virtual ~validatexml();
};

#endif /* VALIDATEXML_H_ */
