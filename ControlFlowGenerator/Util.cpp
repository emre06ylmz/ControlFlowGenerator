#include "stdafx.h"
#include "Util.h"
#include <string>
#include <locale>

using namespace std;

Util::Util()
{
}

string Util::trim(const string& str)
{
	std::locale loc;
	std::string str_no_ws;
	for (char c : str) if (!std::isspace(c, loc)) str_no_ws += c;
	return str_no_ws;
}

Util::~Util()
{
}
