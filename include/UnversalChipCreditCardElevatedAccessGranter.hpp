#pragma once

#include <string>


/**
 * \brief This factory class encapsulates a connection to a bank's server
 *        and grants elavated access a credit card's functionality.
 */
class UniversalChipCreditCardEleveatedAccessGranter final
{
public:
	explicit UniversalChipCreditCardEleveatedAccessGranter(
		std::string connectionInformation);

	std::unique_ptr<UniversalChipCreditCardEleveatedAccessGranter>
		GrantElevatedAccess(std::shared_ptr<IUniversalChip> controlled);
};
