#include "Exemple.h"



namespace Test
{
	Exemple::Exemple(std::vector<double> input, std::vector<double> sortie) : m_input(input), m_sortie(sortie)
	{
		m_input.insert(m_input.begin(), -1);
	}

	Exemple::~Exemple()
	{
	}

	std::vector<double> Exemple::getInput()
	{
		return std::vector<double>(m_input);
	}

	std::vector<double> Exemple::getSortie()
	{
		return m_sortie;
	}


}