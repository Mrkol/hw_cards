#pragma once

#include <string>
#include <memory>
#include "UniversalChipCreditCardElevatedAccessDecorator.hpp"


/**
 * \brief This factory class encapsulates a connection to a bank's server
 *        and grants elavated access a credit card's functionality.
 */
class UniversalChipCreditCardElevatedAccessGranter final
{
public:
	explicit UniversalChipCreditCardElevatedAccessGranter(
		const std::string& connectionInformation);

	std::unique_ptr<UniversalChipCreditCardElevatedAccessDecorator>
		GrantElevatedAccess(std::shared_ptr<IUniversalChip> controlled);
};
