class DiffusionCIR
	{
		double const m_s;
		double const m_teta;
		double const m_cappa;
		double const m_sigma;

	public:
		double mu(double a_cappa, double a_teta, double a_s) const
		{
			if (a_cappa <= 0) 
				return 0;
			return m_cappa * (a_teta - a_s);
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
			if (m_cappa <= 0)
				throw std::invalid_argument("wrong! cappa <= 0");
			if (m_teta <= 0)
				throw std::invalid_argument("wrong! teta <= 0")
		}
	};