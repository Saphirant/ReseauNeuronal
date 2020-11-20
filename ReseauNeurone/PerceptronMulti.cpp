#include "PerceptronMulti.h"


namespace NeuralNetwork
{

	PerceptronMulti::PerceptronMulti(std::vector<double> input, std::vector<std::tuple<int, Neurone::NeuroneType, double>> couche, int nSortie) : m_input(input), m_nSortie(nSortie), m_nCouche((int)couche.size() + 1)
	{


		//tuple = Nombre de neurone par couche, type de neurone, coefficient d'apprentissage pour la couche
		m_nParCouche.push_back(std::get<0>(couche[0]));



		m_couche.push_back(new Perceptron((int)m_input.size(), std::get<0>(couche[0]), std::get<2>(couche[0]), std::get<1>(couche[0])));


		//On initialise chaque couche du réseau
		for (size_t i = 1; i < couche.size() ; i++)
		{
			m_nParCouche.push_back(std::get<0>(couche[i]));



			m_couche.push_back(new Perceptron(std::get<0>(couche[i - 1]), std::get<0>(couche[i]), std::get<2>(couche[i]), std::get<1>(couche[i])));
		}

		m_nParCouche.push_back(m_nSortie);

		m_sortieCouche = new Perceptron(std::get<0>(couche[couche.size() - 1]), m_nSortie, 0, Neurone::NeuroneType::NEURONE_HEAVISIDE);
			
		m_couche.push_back(m_sortieCouche);
	}


	std::vector<double> PerceptronMulti::evaluer(std::vector<double>  input)
	{
		m_sortie = m_couche[0]->evaluer(input);
		for (size_t i = 1; i < m_couche.size(); i++)
		{
			m_sortie = m_couche[i]->evaluer(m_sortie);
		}
		return m_sortie;
	}

	void PerceptronMulti::entrainer(std::vector<Test::Exemple>* listExemple)
	{
		std::vector<std::vector<double>> courant = std::vector<std::vector<double>>();

		for (auto& i : m_couche)
		{
			courant.push_back(std::vector<double>());
		}

		for (auto& exemple : *listExemple)
		{
			std::vector<double> sortie = evaluer(exemple.getInput());

			for (size_t i = 0; i < m_sortieCouche->getnbNeurone(); i++)
			{
				courant[m_couche.size() - 1].push_back(sortie[i] *(1-sortie[i])*(exemple.getSortie()[i]-sortie[i]));
			}
			


			for (int i = m_couche.size() - 1 - 1; i >= 0; i--)
			{
				std::vector<Neurone::Neurone*> listeNeurone = m_couche[i]->getNeurone();
				for (size_t j = 0; j < m_couche[i]->getnbNeurone(); j++)
				{
					double somme;
					for()
					courant[i].push_back(listeNeurone[j]->getSortie()*(1 - listeNeurone[j]->getSortie()) * );
				}
			}
		}


	}

	PerceptronMulti::~PerceptronMulti()
	{
		delete m_sortieCouche;
		m_sortieCouche = nullptr;

		for (size_t i = 0; i < m_couche.size() - 1; i++)
		{
			delete m_couche[i];
			m_couche[i] = nullptr;
		}
	}

	std::string PerceptronMulti::toString()
	{
		std::string res = "Entree: ";

		for (auto& i : m_input)
		{
			res += std::to_string(i) + " ";
		}
		res += "\n";
		
		for (size_t i = 0; i < m_couche.size()-1; i++)
		{
			res += "Couche " + std::to_string(i) + ": " + m_couche[i]->toString() + "\n";
		}

		return res;
	}

	std::string PerceptronMulti::toString(std::vector<double> input)
	{
		std::string res = "Entree: ";

		for (auto& i : input)
		{
			res += std::to_string(i) + " ";
		}
		res += "\n";
		for (size_t i = 0; i < m_couche.size()-1; i++)
		{
			res += "Couche " + std::to_string(i) + ": " + m_couche[i]->toString(input) + "\n";
		}

		res += "Sortie: ";
		for (auto& s : evaluer(input))
		{
			res += std::to_string(s) + " ";
		}

		return res;
	}

}