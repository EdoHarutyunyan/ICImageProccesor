#pragma once
#include <iostream>

namespace parser
{

class IParser
{
public:
	virtual void Start() = 0;
};

using ParserSharedPtr = std::shared_ptr<IParser>;

} // namespace parser
