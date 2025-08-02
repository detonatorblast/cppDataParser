// parsingFramework.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

// TODO: Reference additional headers your program requires here.

// a class to hold parsed data
class parsedData {
public:
	// Constructor
	parsedData() = default;
	// Method to add data
	void addData(const std::string& key, const std::vector<std::string>& values) {
		dataMap[key] = values;
	}
	// Method to get data
	const std::vector<std::string>& getData(const std::string& key) const {
		return dataMap.at(key);
	}
	// Method to check if key exists
	bool hasKey(const std::string& key) const {
		return dataMap.find(key) != dataMap.end();
	}
private:
	std::unordered_map<std::string, std::vector<std::string>> dataMap;
};

// Parser class declaration
class IParser {
public:
	virtual ~IParser() = default;
	// Method to parse input data
	virtual std::unique_ptr<parsedData> parse(const std::string& input) = 0;
	// Method to validate the input data
	virtual bool validate(const std::string& input) const = 0;
	// Method to get the parser name
	virtual std::string getName() const = 0;
};