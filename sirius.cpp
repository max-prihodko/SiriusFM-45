#pragma once
#include <stdexcept>
#include <cmath>

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
	};

	class DiffusionCEV
	{
		double const m_mu;
		double const m_beta;
		double const m_sigma;
	public:

		double mu(double a_s, double a_t, double a_beta) const
		{
			return m_mu * a_s;
		}	

		double sigma (double a_s, double a_t, double a_beta) const
		{
			if a_s < 0
				return 0;
			return m_sigma*pow(a_s, m_beta);
		}

		DiffusionCEV(double a_mu, double a_sigma)
		: m_mu(a_mu),
		m_sigma(a_sigma)
		{
			if (m_sigma <= 0)
				throw std::invalid_argument("wrong! sigma < 0")
			if (m_beta < 0)
				throw std::invalid_argument("wrong! beta < 0")
		}
	};

	class DiffusionLipton
	{
		double const m_mu;
		double const m_sigma_0;
		double const m_sigma_1;
		double const m_sigma_2;

	public:

		double mu(double a_s, double a_t, double a_beta) const
		{
			return m_mu * a_s;
		}	

		double sigma (double a_s, double a_t, double a_beta) const
		{
			if a_s < 0
				return 0;
			return m_sigma_0 + sigma_1*a_s + sigma_2*a_s*a_s;
		}


		DiffusionLipton(double a_mu, double a_sigma_0, double a_sigma_1, double a_sigma_2)
		: m_mu(a_mu),
		m_sigma_0(a_sigma_0),
		m_sigma_1(a_sigma_1),
		m_sigma_2(a_sigma_2)
		{
			if (m_sigma_0 < 0)
				throw std::invalid_argument("wrong! sigma_0 < 0")
			if (m_sigma_2 < 0)
				throw std::invalid_argument("wrong! sigma_2 < 0")
			if (sigma_1 * sigma_1 - 4 * sigma_0 * sigma_2 >= 0)
				throw std::invalid_argument("wrong! sigma_1^2 - 4*sigma_0*sigma_2 >= 0")
		}
	};

	class DiffusionOU
	{
		double const m_s;
		double const m_teta;
		double const m_kappa;
		double const m_sigma;

	public:
		double mu(double a_kappa, double a_teta, double a_s) const
		{
			if (a_kappa <= 0) 
				return 0;
			return m_kappa * (a_teta - a_s);
		}	

		double sigma (double a_s, double a_t) const
		{
			if a_s < 0
				return 0;
			return m_sigma;
		}

		DiffusionOU(double a_mu, double a_sigma, double a_teta, double a_s)
		: m_mu(a_mu),
		m_sigma(a_sigma),
		m_teta(a_teta),
		m_s(a_s)
		{	
			if (m_kappa <= 0)
				throw std::invalid_argument("wrong! kappa <= 0");
		}
	};

	class DiffusionCIR
	{
		double const m_s;
		double const m_teta;
		double const m_kappa;
		double const m_sigma;

	public:
		double mu(double a_kappa, double a_teta, double a_s) const
		{
			if (a_kappa <= 0) 
				return 0;
			return m_kappa * (a_teta - a_s);
		}	

		double sigma (double a_s, double a_t) const
		{
			if a_s < 0
				return 0;
			return m_sigma*sqrt(a_s);
		}

		DiffusionCIR(double a_mu, double a_sigma, double a_teta, double a_s)
		: m_mu(a_mu),
		m_sigma(a_sigma),
		m_teta(a_teta),
		m_s(a_s)
		{
			if (m_kappa <= 0)
				throw std::invalid_argument("wrong! kappa <= 0");
			if (m_teta <= 0)
				throw std::invalid_argument("wrong! teta <= 0")
		}
	};


}


