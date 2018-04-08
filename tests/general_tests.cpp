#include <memory>
#include <cstddef>
#include <cstring>
#include "gtest/gtest.h"
#include "CoolCard.hpp"
#include "UniversalChipPassportAccessDecorator.hpp"
#include "UniversalChipCreditCardAccessDecorator.hpp"
#include "UniversalChipCreditCardElevatedAccessGranter.hpp"
#include "UniversalChipCreditCardElevatedAccessDecorator.hpp"

TEST(GeneralTests, DirectCardAccessTest)
{
	const size_t SIZE = 4096;

	std::shared_ptr<IUniversalChip> card = std::make_shared<CoolCard>(SIZE);

	ASSERT_EQ(card->GetFreeSpace(), SIZE);

	uint8_t* rawData = card->AddDataSection("data", sizeof(uint64_t));

	ASSERT_EQ(card->GetFreeSpace(), SIZE - sizeof(uint64_t));
	ASSERT_EQ(card->GetDataSection("data"), rawData);

	uint64_t* data = reinterpret_cast<uint64_t*>(rawData);
	*data = 0;

	ASSERT_EQ(*data, 0);
}

TEST(GeneralTests, PassportAccessTest)
{
	const size_t SIZE = 4096;
	const char* NAME_FLAG = "passport::holderName";
	const char* SURNAME_FLAG = "passport::holderSurname";
	const char* UUID_FLAG = "passport::holderUUID";

	std::shared_ptr<IUniversalChip> card = std::make_shared<CoolCard>(SIZE);
	std::shared_ptr<UniversalChipPassportAccessDecorator> decorated =
		std::make_shared<UniversalChipPassportAccessDecorator>(card);

	char* cstrName = 
		reinterpret_cast<char*>(card->GetDataSection(NAME_FLAG));
	char* cstrSurname = 
		reinterpret_cast<char*>(card->GetDataSection(SURNAME_FLAG));
	uint64_t* UUID = 
		reinterpret_cast<uint64_t*>(card->GetDataSection(UUID_FLAG));

	strcpy(cstrName, "John");
	strcpy(cstrSurname, "Smith");
	*UUID = 0xDEADBEEFFACEFEEDull;


	ASSERT_EQ(std::string(cstrName), decorated->GetHolderName());
	ASSERT_EQ(std::string(cstrSurname), decorated->GetHolderSurname());
	ASSERT_EQ(*UUID, decorated->GetHolderUUID());
}

TEST(GeneralTests, CreditCardAccessTest)
{
	const size_t SIZE = 4096;
	const char* NAME_FLAG = "creditcard::holderName";
	const char* BALANCE_FLAG = "creditcard::holderBalance";

	std::shared_ptr<IUniversalChip> card = std::make_shared<CoolCard>(SIZE);
	std::shared_ptr<UniversalChipCreditCardAccessDecorator> decorated =
		std::make_shared<UniversalChipCreditCardAccessDecorator>(card);

	char* cstrName = 
		reinterpret_cast<char*>(card->GetDataSection(NAME_FLAG));
	uint64_t* balance = 
		reinterpret_cast<uint64_t*>(card->GetDataSection(BALANCE_FLAG));

	strcpy(cstrName, "John Smith Mr.");
	*balance = 100500;


	ASSERT_EQ(std::string(cstrName), decorated->GetHolderName());
	ASSERT_EQ(*balance, decorated->QueryBalance());
}

TEST(GeneralTests, CreditCardElevatedAccessTest)
{
	const size_t SIZE = 4096;
	const char* NAME_FLAG = "creditcard::holderName";
	const char* BALANCE_FLAG = "creditcard::holderBalance";

	std::shared_ptr<IUniversalChip> card = std::make_shared<CoolCard>(SIZE);

	UniversalChipCreditCardElevatedAccessGranter granter("TOP SECRET INFO");
	std::shared_ptr<UniversalChipCreditCardElevatedAccessDecorator> decorated =
		granter.GrantElevatedAccess(card);

	char* cstrName = 
		reinterpret_cast<char*>(card->GetDataSection(NAME_FLAG));
	uint64_t* balance = 
		reinterpret_cast<uint64_t*>(card->GetDataSection(BALANCE_FLAG));

	strcpy(cstrName, "John Smith Mr.");
	*balance = 0;

	ASSERT_EQ(std::string(cstrName), decorated->GetHolderName());
	ASSERT_EQ(*balance, decorated->QueryBalance());

	decorated->Deposit(100500);
	ASSERT_EQ(decorated->QueryBalance(), 100500);
	decorated->Widthdraw(500);
	ASSERT_EQ(decorated->QueryBalance(), 100000);
	decorated->Deposit(69);
	ASSERT_EQ(decorated->QueryBalance(), 100069);
}
