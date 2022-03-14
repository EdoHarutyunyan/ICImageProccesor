#pragma once
#include <iostream>
#include <functional>

#include "../LogicalGates/Gate.h"

namespace parser
{

class IParser
{
public:
	using Callback = std::function<void()>;

	virtual void Start(Callback cb) = 0;
	virtual std::vector<std::shared_ptr<gate::Gate>> GetGates() const = 0;
	virtual std::vector<std::vector<bool>> GetAdjacencyMatrix() const = 0;
};

using ParserSharedPtr = std::shared_ptr<IParser>;

} // namespace parser
