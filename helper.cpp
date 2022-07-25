#include "helper.h"
#include <iostream>

#include<fstream>
#include <string>
#include <sstream>
using std::fstream;
using std::endl;
using std::cout;
using std::cin;
using std::ostringstream;
using std::istringstream;


using std::ios;
namespace Ask {

vector<string> Helper::ReadFileLines(const string &path) {
	vector<string> lines;

	fstream file_handler(path.c_str());

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return lines;
	}
	string line;

	while (getline(file_handler, line)) {
		if (line.size() == 0)
			continue;
		lines.push_back(line);
	}

	file_handler.close();
	return lines;
}

 void Helper::WriteFileLines(const string &path, const vector<string> &lines, bool append )  {
auto status=ios::in | ios::out | ios::app;

if(!append){
    status=ios::in | ios::out | ios::trunc;
}

fstream file_handler(path.c_str(),status);
if(file_handler.fail()){
    cout<<"\n\nError Opening the required file...\n\n"<<endl;
    return;
}
for(auto line: lines){
    file_handler << line<<endl;
}
file_handler.close();
}


vector<string> Helper::SplitString(const string &str,const string &delimiter) {
string s = str;
	vector<string> strs;

	int pos = 0;
	string substr;
	while ((pos = (int) s.find(delimiter)) != -1) {
		substr = s.substr(0, pos);
		strs.push_back(substr);
		s.erase(0, pos + delimiter.length());
	}
	strs.push_back(s);
	return strs;


}


int Helper::ToInt(const string &str)  {
istringstream iss (str);

int num;

iss >>num;

return num;
}

int Helper::ReadInt(int low, int high) {
	cout << "\nEnter number in range " << low << " - " << high << ": ";
	int value;

	cin >> value;

	if (low <= value && value <= high)
		return value;

	cout << "ERROR: invalid number...Try again\n";
	return ReadInt(low, high);
}


int Helper::ShowReadMenu(const vector<string> &choices) {
	cout << "\nMenu:\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
	return ReadInt(1, choices.size());
}

}


