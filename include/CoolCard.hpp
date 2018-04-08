#pragma once

#include "IUniversalChip.hpp"

class CoolCard : public IUniversalChip
{
public:
	CoolCard(size_t dataSize = 4096);

	virtual size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(std::string flag, size_t size) override;
	virtual uint8_t* GetData(std::string flag) override;

	~CoolCard();
private:
	uint8_t* data_;
};
