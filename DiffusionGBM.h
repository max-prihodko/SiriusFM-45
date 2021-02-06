#pragma once
#include <stdexcept>

namespace SiriusFM
{
	class DiffusionGBM
	{
		double const m_mu;
		double const m_sigma;
	public:
		double mu(double a_s, double a_t) const
		{
			return m_mu*a_s;
		}	

		double sigma (double a_s, double a_t) const
		{
			if a_s < 0
				return 0;
			return m_sigma*s;
		}

		DiffusionGBM(double a_mu, double a_sigma)
		: m_mu(a_mu),
		m_sigma(a_sigma)
		{
			if (m_sigma <= 0)
				throw std::invalid_argument("wrong! sigma < 0");
		}
}	