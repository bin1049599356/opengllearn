#ifndef ASSERT_H
#define ASSERT_H

#include <string>

#define ASSERT(strName) Assert(strName, __FILE__)

class Assert
{
public:
	Assert(std::string strName) : _strName(strName) { _AssertDir = getAssertDir(); }
	Assert(std::string strName, std::string strAssertDir) : _strName(strName), _AssertDir(strAssertDir){
		std::string strCurDif = _AssertDir;
		strCurDif = strCurDif.substr(0, strCurDif.rfind("\\"));
		strCurDif += "\\";
		_AssertDir = strCurDif;
	}
	~Assert() {}

	operator std::string const& () const { return _AssertDir + _strName; }

	static std::string getAssertDir() {
		std::string strCurDif = __FILE__;
		strCurDif = strCurDif.substr(0, strCurDif.rfind("\\"));
		strCurDif += "\\img\\";
		return strCurDif;
	}
private:
	std::string _strName;
	std::string _AssertDir;
};

#endif // !ASSERT_H
