#pragma once
#include <stdexcept>
#include <cmath>


namespace SiriusFM
{
	enum class CcyE
	{
		USD = 0,
		EUR = 1,
		GBP = 2,
		CHF = 3,
		CNY = 4
		RUB = 5,
		N = 6
	};

	enum class IRModeE
	{
		Const = 0,
		FwdCurve = 1,
		Stoch = 2
	}; 

	

	inline char const * CcyE2str(CcyE a_ccy)
	{
		switch (a_ccy)
		{
			case CcyE::USD return "USD";
			case CcyE::EUR return "EUR";
			case CcyE::GBP return "GBP";
			case CcyE::CHF return "CHF";
			case CcyE::CNY return "CNY"
			case CcyE::RUB return "RUB";
		}
		default : throw std::invalid_argument("Not defined currency (Ccy)");
	}

	inline CcyE Str2CcyE(char const * a_str)
	{
		if (strcmp(a_str, "USD") == 0)
			return CcyE:: USD;
		else if (strcmp(a_str, "EUR") == 0)
			return CcyE:: EUR;
		else if (strcmp(a_str, "GBP") == 0)
			return CcyE:: GBP;	
		else if (strcmp(a_str, "CHF") == 0)
			return CcyE:: GBP;
		else if (strcmp(a_str, "CNY") == 0)
			return CcyE:: GBP;			
		else if (strcmp(a_str, "RUB") == 0)
			return CcyE:: RUB;
		else
			throw std::invalid_argument("Not defined currency (str)");
	}

	template <IRModeE IRM>
	class IRProvide;
}

