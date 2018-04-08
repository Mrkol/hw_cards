#pragma once

#include <cstddef>
#include <string>

/**
 * \brief Describes the functionality of a digital passport.
 *        Provided by another company. 
 */
class IPassportAccess
{
public:
	/**
	 * \brief Queries for passport holer's name.
	 */
	virtual std::string GetHolderName() = 0;

	/**
	 * \brief Queries for passport holer's surname.
	 */
	virtual std::string GetHolderSurname() = 0;

	/**
	 * \brief Queries for passport holder's government-assigned ID.
	 */
	virtual uint64_t GetHolderUUID() = 0;
};
