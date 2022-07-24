#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#include <cmath>
#include <cassert>
#include <algorithm>

#include <memory>
#include <vector>
using std::vector;
using std::string;


namespace Ask {


class Helper {

public:

//parameter is a constant ref. so that dev knows he is not allowed to edit it
static vector<string> ReadFileLines(const string &path);

static void WriteFileLines(const string &path, const vector<string> &lines, bool append) ;


static vector<string> SplitString(const string &str ) ;

static int ToInt(const string &str)  ;

static int ReadInt(int low,int high);

static int ShowReadMenu(const vector<string> &choices) ;


};
}
#endif // HELPER_H_INCLUDED
