/*
 * CS 1511 Project 1
 * Created by Kobi Jones on January 12, 2022
 *
 * This program calculates expected revenue per 1000 impressions
 * of a Google advertisement given total estimated earnings and
 * total impressions (page views).
 * */

#include <iostream>
#include <stdexcept>
#include <string>

int main() {
	std::string estEarningsIn = "";
	std::string pageViewsIn = "";

	double estEarnings = 0;
	unsigned int pageViews = 0;

	// Prompt user for est earnings
	std::cout << "Estimated earnings: ";
	std::cin >> estEarningsIn;

	// Validate input
	try {
		estEarnings = std::stod(estEarningsIn);
	} catch (const std::invalid_argument&) {
		std::cerr << "Estimated earnings must be a number" << std::endl;
		return -1;
	}
	if (estEarnings < 0) {
		std::cerr << "Estimated earnings must be greater than or equal to 0" << std::endl;
		return -1;
	}

	// Prompt user for page views
	std::cout << "Page views: ";
	std::cin >> pageViewsIn;
	try {
		int pageViewsSigned = std::stoi(pageViewsIn);
		if (pageViewsSigned < 0) {
			std::cerr << "Page views must be greater than or equal to 0" << std::endl;
			return -1;
		}
		pageViews = static_cast<unsigned int>(pageViewsSigned);
	} catch (const std::invalid_argument&) {
		std::cerr << "Page views must be an integer" << std::endl;
		return -1;
	}

	// Calculate and print rpm
	double rpm = estEarnings / pageViews * 1000;
	std::cout << "RPM: " << rpm << std::endl;

	return 0;
}
