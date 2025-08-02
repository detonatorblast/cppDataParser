#include "../parserInterface/parser.h"

#include <gtest/gtest.h>

// Mock parser class for testing
class MockParser : public IParser {
public:
	// Override the parse method
	std::unique_ptr<parsedData> parse(const std::string& input) override;
	// Override the validate method
	bool validate(const std::string& input) const override;
	// Override the getName method
	std::string getName() const override;
};

std::unique_ptr<parsedData>
MockParser::parse(const std::string& input) {
	auto data = std::make_unique<parsedData>();
	// Mock parsing logic
	if (input == "valid") {
		data->addData("key1", {"value1", "value2"});
	}
	return data;
}

bool MockParser::validate(const std::string& input) const {
	// Mock validation logic
	return input == "valid";
}

std::string MockParser::getName() const {
	return "MockParser";
}

TEST(ParserTest, testgetname)
{
	MockParser parser;
	EXPECT_EQ(parser.getName(), "MockParser");
}