#pragma once

#pragma once
#include <ClayPOT/ClayPOT.h>
#include <ClayPOT/EntryPoint.h>

namespace cp
{
	class CPUser : public CPCreator
	{
	public:

		CPUser() = default;
		~CPUser() = default;

	};

}

cp::CPCreator* cp::CreateApplication()
{
	return new CPUser();
}
