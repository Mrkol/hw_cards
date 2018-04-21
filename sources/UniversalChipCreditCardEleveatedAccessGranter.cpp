#include "UniversalChipCreditCardElevatedAccessGranter.hpp"


UniversalChipCreditCardElevatedAccessGranter::
	UniversalChipCreditCardElevatedAccessGranter(
		const std::string& connectionInformation)
{
	//Connect and authorize	
}

std::unique_ptr<UniversalChipCreditCardElevatedAccessDecorator>
	UniversalChipCreditCardElevatedAccessGranter::GrantElevatedAccess(
		std::shared_ptr<IUniversalChip> controlled)
{
	return std::move(
		std::unique_ptr<UniversalChipCreditCardElevatedAccessDecorator>
			(new UniversalChipCreditCardElevatedAccessDecorator(controlled)));
}