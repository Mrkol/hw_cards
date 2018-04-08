#pragma once

#include <cstddef>
#include <string>


/**
 * \brief Gives limited access to a cards' crediting functionality.
 */
class ICreditCardAccess
{
public:
	/**
	 * \brief Accesses the cardholder's name.
	 */
	virtual std::string GetHolderName() = 0;

	/**
	 * \brief Queries for account balance.
	 */
	virtual uint64_t QueryBalance() = 0;
};
