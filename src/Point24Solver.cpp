#include "Point24Solver.h"
#include "base/math/number_base.h"
#include "base/math/tinyexpr.h"
#include <algorithm>
#include <cmath>
#include <format>

std::string Point24Solver::OperatorToString(uint8_t op)
{
	switch (op)
	{
	case 0:
		{
			return "+";
		}
	case 1:
		{
			return "-";
		}
	case 2:
		{
			return "*";
		}
	case 3:
		{
			return "/";
		}
	}

	throw std::invalid_argument("未知的运算符");
}

std::string Point24Solver::GetExpression(
	std::array<uint8_t, 4> const &nums,
	std::vector<uint8_t> const &operators)
{
	return std::format(
		"{} {} {} {} {} {} {}",
		nums[0],
		OperatorToString(operators[0]),
		nums[1],
		OperatorToString(operators[1]),
		nums[2],
		OperatorToString(operators[2]),
		nums[3]);
}

std::string Point24Solver::TryAllOperatorCombinations(std::array<uint8_t, 4> const &nums)
{
	// 遍历运算符的全部组合
	// 4 则运算符就像是 4 进制数。3 个运算符就像是 3 位 4 进制数
	for (uint8_t i = 0; i < std::pow(4, 3); i++)
	{
		std::vector<uint8_t> operators = base::number_base::ConvertBase(i, 4);

		// 把 operators 补全到长度为 3
		int remain = 3 - operators.size();
		for (int j = 0; j < remain; j++)
		{
			operators.push_back(0);
		}

		std::string expr = GetExpression(nums, operators);
		if (CalculateExpression(expr) == 24)
		{
			return expr;
		}
	}

	return std::string();
}

double Point24Solver::CalculateExpression(std::string const &expr)
{
	int error = 0;
	double result = te_interp(expr.c_str(), &error);
	if (error)
	{
		throw std::invalid_argument("非法表达式：" + expr);
	}

	return result;
}

std::string Point24Solver::Solve(std::array<uint8_t, 4> const &nums)
{
	std::array<uint8_t, 4> copyed_nums = nums;
	std::sort(copyed_nums.begin(), copyed_nums.end());

	while (true)
	{
		std::string expr = TryAllOperatorCombinations(copyed_nums);
		if (expr != "")
		{
			return expr;
		}

		bool have_next = std::next_permutation(copyed_nums.begin(), copyed_nums.end());
		if (!have_next)
		{
			return std::string("找不到解");
		}
	}
}
