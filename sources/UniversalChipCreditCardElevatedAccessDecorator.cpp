#include "UniversalChipCreditCardElevatedAccessDecorator.hpp"


const std::string UniversalChipCreditCardElevatedAccessDecorator::NAME_FLAG = 
	"creditcard::holderName";
const std::string UniversalChipCreditCardElevatedAccessDecorator::BALANCE_FLAG = 
	"creditcard::holderBalance";

UniversalChipCreditCardElevatedAccessDecorator::
	UniversalChipCreditCardElevatedAccessDecorator(
		std::shared_ptr<IUniversalChip> controlled)
	:
	UniversalChipDecorator(controlled)
{
	if (controlled->GetDataSection(NAME_FLAG) == nullptr)
		controlled->AddDataSection(NAME_FLAG, 32);
	
	if (controlled->GetDataSection(BALANCE_FLAG) == nullptr)
		controlled->AddDataSection(BALANCE_FLAG, sizeof(uint64_t));
}

size_t UniversalChipCreditCardElevatedAccessDecorator::GetFreeSpace()
{
	//if (unaothrized)
	//    throw;
	return UniversalChipDecorator::GetFreeSpace();
}

uint8_t* UniversalChipCreditCardElevatedAccessDecorator::AddDataSection(
	const std::string& flag, size_t size)
{
	//if (unaothrized)
	//    throw;
	return UniversalChipDecorator::AddDataSection(flag, size);
}

uint8_t* UniversalChipCreditCardElevatedAccessDecorator::GetDataSection(
	const std::string& flag)
{
	//if (unaothrized)
	//    throw;
	return UniversalChipDecorator::GetDataSection(flag);
}

void UniversalChipCreditCardElevatedAccessDecorator::Widthdraw(
	uint64_t amount)
{
	*reinterpret_cast<uint64_t*>(GetDataSection(BALANCE_FLAG)) -= amount;
}

void UniversalChipCreditCardElevatedAccessDecorator::Deposit(
	uint64_t amount)
{
	*reinterpret_cast<uint64_t*>(
		GetDataSection(BALANCE_FLAG)) += amount;
}

std::string UniversalChipCreditCardElevatedAccessDecorator::GetHolderName()
{
	return std::string(reinterpret_cast<char*>(
		GetDataSection(NAME_FLAG)));
}

uint64_t UniversalChipCreditCardElevatedAccessDecorator::QueryBalance()
{
	return *reinterpret_cast<uint64_t*>(GetDataSection(BALANCE_FLAG));
}
