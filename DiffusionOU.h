#pragma once
#include <stdexcept>

namespace SiriusFM
{
	class DiffusionOU
	{
		double const m_teta;
		double const m_kappa;
		double const m_sigma;

	public:
		double mu(double a_s) const
		{
			return m_kappa * (m_teta - a_s);
		}	

		double sigma (double a_s) const
		{
			if a_s < 0
				return 0;
			return m_sigma;
		}

		DiffusionOU(double a_mu, double a_sigma, double a_teta)
		: m_mu(a_mu),
		m_sigma(a_sigma),
		m_teta(a_teta)
		{	
			if (m_kappa <= 0)
				throw std::invalid_argument("wrong! kappa <= 0");
		}
	};
}	