#pragma once

#include "IUniversalChip.hpp"
#include <unordered_map>
#include <string>

class CoolCard : public IUniversalChip
{
public:
	CoolCard(size_t dataSize = 4096);

	virtual size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(const std::string& flag, size_t size) override;
	virtual uint8_t* GetDataSection(const std::string& flag) override;

	~CoolCard();
	
private:
	size_t size_;
	uint8_t* dataStart_;
	uint8_t* data_;

	std::unordered_map<std::string, uint8_t*> sections_;
};
