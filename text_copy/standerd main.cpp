//copy txt files with line numbers in the copy version
//ver 0.2
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
//string object's
string input_file;
string output_file;
string output_file_loc;
string output_file_name;
//fstream object's
ofstream out_file;
ifstream in_file;

bool safety_check(const ifstream& in_file); // check if input file opened and ready 
bool safety_check(const ofstream& out_file); // to check if the output path is fine and the appliction where able to create new txt file 
string nameing_the_output(string& outfileloc, string& output_file_name);
void copying(ifstream& in_file, ofstream& out_file);

int main() {
	//get the user input
	cout << "please enter the address for the file you want to change\n(ex: C:\\Mytxt.txt): ";
	cin >> input_file; //storing the address to astring
	cout << endl; //clearing the buffer 
	//connecting  the input file to fstream
	in_file.open(input_file);
	//safe checking
	if (safety_check(in_file)) return 1;
	//now the output
	cout << "please enter the output file path you want (ex:C:\\Users\\name\\Documents):";
	cin >> output_file_loc; //storing the output address to a string
	cout << endl;
	cout << "please enter the output file name you want (without \\ ) :";
	cin >> output_file_name;
	cout << endl;
	//setting the name and the location for the output file
	output_file = nameing_the_output(output_file_loc, output_file_name);
	//connecting the output file to fstream
	out_file.open(output_file);
	//checking if all is good
	if (safety_check(out_file)) return 1;
	//if all is good we start copying
	copying(in_file, out_file);
	cout << "new modified copy created" << endl;
	cout << "the address is :" << output_file_loc << endl;
	out_file.close();
	in_file.close();
	return  0;
}

bool safety_check(const ifstream& in_file) {
	if (!in_file) {
		std::cerr << "problem opening the orignal file check the address " << std::endl;
		return true;
	}
}

bool safety_check(const ofstream& out_file) {
	if (!out_file) {
		std::cerr << "problem creating the output file check address or name" << std::endl;
		return true;
	}
}

string nameing_the_output(string& outfileloc, string& output_file_name) {
	return output_file_loc += "\\" + output_file_name + ".txt"; //adding our output file name to the giving address
}

void copying(ifstream& in_file, ofstream& out_file)
{
	string line;
	int num{ 0 };
	while (getline(in_file, line)) //the copying statment
	{
		if (!line.empty()) {
			out_file << num << ". " << line << endl;
			++num;
		}
		else
		{
			out_file << line << endl;
		}
	}
}