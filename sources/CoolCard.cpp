#include "CoolCard.hpp"
#include <cstring>

CoolCard::CoolCard(size_t dataSize)
	: 
	size_(dataSize),
	dataStart_(new uint8_t[dataSize]),
	data_(dataStart_)
{
	std::memset(data_, 0, dataSize*sizeof(uint8_t));
}

size_t CoolCard::GetFreeSpace()
{
	return size_ - (data_ - dataStart_);
}

uint8_t* CoolCard::AddDataSection(const std::string& flag, size_t size)
{
	//TODO: proper error handling
	if (GetFreeSpace() < size)
		throw -1;

	sections_.insert({flag, data_});
	data_ += size;

	return data_ - size;
}

uint8_t* CoolCard::GetDataSection(const std::string& flag)
{
	auto iter = sections_.find(flag);
	if (iter == sections_.end())
		return nullptr;
	return iter->second;
}

CoolCard::~CoolCard()
{
	delete[] dataStart_;
}
