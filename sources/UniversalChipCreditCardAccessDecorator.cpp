#include "UniversalChipCreditCardAccessDecorator.hpp"


const std::string UniversalChipCreditCardAccessDecorator::NAME_FLAG = 
	"creditcard::holderName";
const std::string UniversalChipCreditCardAccessDecorator::BALANCE_FLAG = 
	"creditcard::holderBalance";

UniversalChipCreditCardAccessDecorator::UniversalChipCreditCardAccessDecorator(
	std::shared_ptr<IUniversalChip> controlled)
	:
	UniversalChipDecorator(controlled)
{
	if (controlled->GetDataSection(NAME_FLAG) == nullptr)
		controlled->AddDataSection(NAME_FLAG, 32);
	
	if (controlled->GetDataSection(BALANCE_FLAG) == nullptr)
		controlled->AddDataSection(BALANCE_FLAG, sizeof(uint64_t));
}

std::string UniversalChipCreditCardAccessDecorator::GetHolderName()
{
	return std::string(reinterpret_cast<char*>(GetDataSection(NAME_FLAG)));
}

uint64_t UniversalChipCreditCardAccessDecorator::QueryBalance()
{
	return *reinterpret_cast<uint64_t*>(GetDataSection(BALANCE_FLAG));
}
