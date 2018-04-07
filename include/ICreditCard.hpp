#pragma once

#include <cstddef>
#include <string>

class ICreditCard
{
public:
	/**
	 * \brief Widthdraws money for the account.
	 */
	virtual void Widthdraw(uint64_t amount) = 0;

	/**
	 * \brief Deposits money to the account.
	 */
	virtual void Deposit(uint64_t amount) = 0;

	/**
	 * \brief Queries for account balance.
	 */
	virtual uint64_t Query() = 0;
};
