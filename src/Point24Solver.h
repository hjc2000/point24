#pragma once
#include <array>
#include <stdint.h>
#include <string>
#include <vector>

class Point24Solver
{
	static std::string OperatorToString(uint8_t op);
	static std::string GetExpression(
		std::array<uint8_t, 4> const &nums,
		std::vector<uint8_t> const &operators);
	static std::string TryAllOperatorCombinations(std::array<uint8_t, 4> const &nums);
	static double CalculateExpression(std::string const &expr);

public:
	/// <summary>
	///
	/// </summary>
	/// <param name="nums"></param>
	/// <returns></returns>
	static std::string Solve(std::array<uint8_t, 4> const &nums);
};
