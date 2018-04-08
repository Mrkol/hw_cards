#include "UniversalChipPassportAccessDecorator.hpp"


const std::string UniversalChipPassportAccessDecorator::NAME_FLAG = 
	"passport::holderName";
const std::string UniversalChipPassportAccessDecorator::SURNAME_FLAG = 
	"passport::holderSurname";
const std::string UniversalChipPassportAccessDecorator::UUID_FLAG = 
	"passport::holderUUID";

UniversalChipPassportAccessDecorator::UniversalChipPassportAccessDecorator(
	std::shared_ptr<IUniversalChip> controlled)
	:
	UniversalChipDecorator(controlled)
{
	if (controlled->GetDataSection(NAME_FLAG) == nullptr)
		controlled->AddDataSection(NAME_FLAG, 32);
	
	if (controlled->GetDataSection(SURNAME_FLAG) == nullptr)
		controlled->AddDataSection(SURNAME_FLAG, 32);

	if (controlled->GetDataSection(UUID_FLAG) == nullptr)
		controlled->AddDataSection(UUID_FLAG, sizeof(uint64_t));
}

std::string UniversalChipPassportAccessDecorator::GetHolderName()
{
	return std::string(reinterpret_cast<char*>(
		GetDataSection(NAME_FLAG)));
}

std::string UniversalChipPassportAccessDecorator::GetHolderSurname()
{
	return std::string(reinterpret_cast<char*>(
		GetDataSection(SURNAME_FLAG)));
}

uint64_t UniversalChipPassportAccessDecorator::GetHolderUUID()
{
	return *reinterpret_cast<uint64_t*>(GetDataSection(UUID_FLAG));
}
