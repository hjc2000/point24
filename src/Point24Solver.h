#pragma once
#include <array>
#include <cstdint>
#include <string>
#include <vector>

class Point24Solver
{
private:
	static std::string OperatorToString(uint8_t op);

	static std::string GetExpression(std::array<uint8_t, 4> const &nums,
									 std::vector<uint8_t> const &operators);

	static std::string TryAllOperatorCombinations(std::array<uint8_t, 4> const &nums);
	static double CalculateExpression(std::string const &expr);

public:
	static std::string Solve(std::array<uint8_t, 4> const &nums);
};
