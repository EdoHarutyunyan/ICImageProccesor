#pragma once
#include <iostream>
#include <functional>

#include "../Helpers/KDTree.h"
#include "../LogicalGates/Gate.h"

namespace parser
{

class IParser
{
public:
	using Callback = std::function<void()>;

	virtual void Start(Callback cb) = 0;
	virtual std::vector<std::shared_ptr<gate::Gate>> GetGates() const = 0;
	virtual std::vector<std::pair<point_t, point_t>> GetWires() const = 0;
};

using ParserSharedPtr = std::shared_ptr<IParser>;

} // namespace parser
