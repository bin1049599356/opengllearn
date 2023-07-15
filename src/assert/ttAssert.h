#ifndef ASSERT_H
#define ASSERT_H

#include <string>

#define ASSERT_OF_CURPATH(strName) Assert(strName, __FILE__)

class Assert
{
public:
	Assert(std::string strName) 
		: _strName(strName) 
	{ 
		_AssertDir = getAssertDir(); 
	}
	Assert(std::string strName, std::string strAssertDir) : _strName(strName), _AssertDir(strAssertDir){
		std::string strCurDif = _AssertDir;
		strCurDif = strCurDif.substr(0, strCurDif.rfind("\\"));
		strCurDif += "\\";
		_AssertDir = strCurDif;
	}
	virtual ~Assert() {}

	operator std::string () { 
		std::string strFile(_AssertDir + _strName);
		findAndReplaceAll(strFile, "\\", "/");
		return strFile;
	}

	virtual std::string getAssertDir() {
		std::string strCurDif = __FILE__;
		strCurDif = strCurDif.substr(0, strCurDif.rfind("\\"));
		strCurDif += "\\img\\";
		return strCurDif;
	}

	void findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr)
	{
		size_t pos = data.find(toSearch);
		while (pos != std::string::npos)
		{
			data.replace(pos, toSearch.size(), replaceStr);
			pos = data.find(toSearch, pos + replaceStr.size());
		}
	}
protected:
	std::string _strName;
	std::string _AssertDir;
};

class ImageAssert : public Assert
{
public:
	ImageAssert(std::string strName) : Assert(strName) { _AssertDir = getAssertDir(); }
	ImageAssert(std::string strName, std::string strAssertDir) : Assert(strName, strAssertDir) {
	}
	virtual ~ImageAssert() {}

	virtual std::string getAssertDir() {
		std::string strCurDif = __FILE__;
		strCurDif = strCurDif.substr(0, strCurDif.rfind("\\"));
		strCurDif += "\\img\\";
		return strCurDif;
	}
};

class ModelAssert : public Assert
{
public:
	ModelAssert(std::string strName) : Assert(strName) { _AssertDir = getAssertDir(); }
	ModelAssert(std::string strName, std::string strAssertDir) : Assert(strName, strAssertDir) {
	}
	virtual ~ModelAssert() {}

	std::string getAssertDir() override {
		std::string strCurDif = __FILE__;
		strCurDif = strCurDif.substr(0, strCurDif.rfind("\\"));
		strCurDif += "\\model\\";
		return strCurDif;
	}
};

#endif // !ASSERT_H
