#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
namespace Ask {


class Helper {

public:

//parameter is a constant ref. so that dev knows he is not allowed to edit it
static vector<string> ReadFileLines(const string &path) const;

static void WriteFileLines(const string &path, const vector<string> &lines, bool append = true) const ;


static vector<string> SplitString(const string &str, const string &delimiter = ",") const;

static int ToInt(const string &str) const ;

static int ReadInt(int low,int high) const ;

static int ShowReadMenu(const vector<string> &choices) const ;


};
}
#endif // HELPER_H_INCLUDED
