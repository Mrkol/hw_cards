#include "UniversalChipDecorator.hpp"


UniversalChipDecorator::UniversalChipDecorator(
	std::shared_ptr<IUniversalChip> controlled)
	:
	controlled_(controlled)
{

}

std::size_t UniversalChipDecorator::GetFreeSpace()
{
	return controlled_->GetFreeSpace();
}

uint8_t* UniversalChipDecorator::AddDataSection(
	const std::string& flag, std::size_t size)
{
	return controlled_->AddDataSection(flag, size);
}

uint8_t* UniversalChipDecorator::GetDataSection(
	const std::string& flag)
{
	return controlled_->GetDataSection(flag);
}
