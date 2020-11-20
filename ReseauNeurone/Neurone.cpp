#include "Neurone.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

namespace Neurone
{
	using namespace std;



	Neurone::Neurone(int nEntree, double apprentissage) :  m_apprentissage(apprentissage)
	{

		m_n = nEntree + 1;


		//On initialise les poids de notre neuronne aléatoirement
		srand((unsigned int)time(NULL));


		for (size_t i = 0; i < m_n; i++)
		{
			//pour chaque input, on met un poids aléatoire
			m_poids.push_back(((double)rand() / (RAND_MAX)));
		}

	} 


	Neurone::~Neurone()
	{
	}

	double Neurone::sommePondere(std::vector<double> input, std::vector<double> poids)
	{
		double sommePondere = 0;
		for (size_t i = 0; i < input.size(); i++)
		{
			sommePondere += input[i] * poids[i];
		}
		return sommePondere;
	}


	/// <summary>
	/// Evalue la sortie du neuronne en passant la somme pondérée dans la fonction d'activation
	/// </summary>
	double Neurone::evaluer(std::vector<double> input)
	{
		input.insert(input.begin(), -1);

		m_sommePondere = sommePondere(input, m_poids);

		m_sortie = fctActivation(m_sommePondere);

		return m_sortie;
	}

	/// <summary>
	/// Entraine le neuronne en lui passant une liste d'exemple (Widrow-Hoff)
	/// </summary>
	/// <param name="listExemple">Liste des exemple</param>
	/// <param name="showDebug">Est-ce que le neuronne doit affiché son état entre chaque exemple</param>

	void Neurone::entrainer(std::vector<Test::Exemple> *listExemple)
	{
		for (Test::Exemple e : *listExemple)
		{
			double sortie = evaluer(e.getInput());
			for (size_t i = 1; i < m_n; i++)
			{
				m_poids[i] = m_poids[i] + m_apprentissage * (e.getSortie() - sortie) * e.getInput()[i];
			}
				
		}
	}

	/// <summary>
	/// Renvoie les valeurs des inputs du neuronne, sa somme pondérée et sa sortie
	/// </summary>
	/// <returns>Renvoie les valeurs des inputs du neuronne, sa somme pondérée et sa sortie</returns>
	string Neurone::toString()
	{
		string res = "[";
		for (size_t i = 1; i < m_n; i++)
		{
			res += std::to_string(m_poids[i]) + " ";
		}
		res += "]";

		return res;
	}

	std::string Neurone::toString(std::vector<double> input)
	{
		return toString() + "= " + std::to_string(evaluer(input));
	}

	double Neurone::getSortie()
	{
		if (m_sortie != NULL)
			return m_sortie;
		else
			throw exception("Le neurone n'a jamais eu d'entrée");
	}
	
}
