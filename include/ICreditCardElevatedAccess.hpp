#pragma once

#include <cstddef>
#include <string>
#include "ICreditCardAccess.hpp"


/**
 * \brief Gives full access to a cards' crediting functionality
 */
class ICreditCardElevatedAccess : public ICreditCardAccess
{
public:
	/*
	 * TODO: implement
	 */
	//virtual void MakeAPayment(IBill bill) = 0;

	/**
	 * \brief Widthdraws money from the account.
	 */
	virtual void Widthdraw(uint64_t amount) = 0;

	/**
	 * \brief Deposits money to the account.
	 */
	virtual void Deposit(uint64_t amount) = 0;

	/**
	 * \brief Accesses the cardholder's name.
	 */
	virtual std::string GetHolderName() override = 0;


	/**
	 * \brief Queries for account balance.
	 */
	virtual uint64_t QueryBalance() override = 0;
};