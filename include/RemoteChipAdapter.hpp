#pragma once

#include "IUniversalChip.hpp"


/**
 * \brief Adapts a virtual remote chip to the universal chip interface.
 * \details Each method call is forwarded to a server for further processing.
 *          This is just an example for this API's usage, 
 *          so no implementation is provided.
 */
class RemoteChipAdapter : public IUniversalChip
{
public:
	virtual size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(const std::string& flag, size_t size) override;
	virtual uint8_t* GetData(const std::string& flag) override;

private:
	//std::shared_ptr<ServerConnection> connection_;
};
