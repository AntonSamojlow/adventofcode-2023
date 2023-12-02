#include "day1.h"

#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


namespace day1 {

namespace {
auto read_lines(const std::string& file_path) -> std::vector<std::string> {
	std::vector<std::string> lines{};
	{
		std::fstream fstream{file_path, fstream.in};
		std::string line;
		while (std::getline(fstream, line)) {
			lines.emplace_back(line);
		}
		fstream.close();
	}
	return lines;
}

auto first_digit(const std::string& line) -> int {
	for (auto it = line.cbegin(); it != line.cend(); ++it) {
		if (std::isdigit(*it))
			return std::atoi(&*it);
	}
}

auto last_digit(const std::string& line) -> int {
	for (auto it = line.crbegin(); it != line.crend(); ++it) {
		if (std::isdigit(*it))
			return std::atoi(&*it);
	}
}

auto get_number(const std::string& line) -> int {
	return 10 * first_digit(line) + last_digit(line);
}

}  // namespace

auto print_solution() -> void {
	const std::string file_path = "D:/repos/adventofcode-2023/assets/day1.txt";

	auto lines = read_lines(file_path);
	int result = std::transform_reduce(lines.cbegin(), lines.cend(), 0, std::plus<>(), get_number);
	std::cout << "Solution Day 1:" << std::endl << result << std::endl; 
}

}  // namespace day1