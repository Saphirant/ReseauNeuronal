#include "Perceptron.h"
#include "NeuroneHeaviside.h"
#include "NeuroneSigmoide.h"
#include "NeuroneEnd.h"


namespace NeuralNetwork
{

	Perceptron::Perceptron(int mNPrec, int nNeurone, double apprentissage, Neurone::NeuroneType type) : m_nNeurone(nNeurone), m_apprentissage(apprentissage), m_type(type)
	{

		//On initialise les neurones
		for (size_t i = 0; i < m_nNeurone; i++)
		{
			switch (m_type)		
			{
			case Neurone::NeuroneType::NEURONE_HEAVISIDE:
				m_couche.push_back(new Neurone::NeuroneHeaviside(mNPrec, m_apprentissage));
				break;
			case Neurone::NeuroneType::NEURONE_SIGMOIDE:
				m_couche.push_back(new Neurone::NeuroneSigmoide(mNPrec, m_apprentissage));
				break;
			case Neurone::NeuroneType::NEURONE_END:
				m_couche.push_back(new Neurone::NeuroneEnd(mNPrec, m_apprentissage));
				break;
			default:
				m_couche.push_back(new Neurone::NeuroneHeaviside(mNPrec, m_apprentissage));
				break;
			}

			//On initialise la sortie
			m_sortie.push_back(0);
		}
	}


	std::vector<double> Perceptron::evaluer(std::vector<double> input)
	{

		for (size_t i = 0; i < m_couche.size(); i++)
		{
			m_sortie[i] = m_couche[i]->evaluer(input);
		}

		return m_sortie;
	}

	int Perceptron::getnbNeurone()
	{
		return m_nNeurone;
	}


	void Perceptron::entrainer(std::vector<Test::Exemple> * listExemple)
	{
		for (auto& neurone : m_couche)
		{
			neurone->entrainer(listExemple);
		}

	}

	std::string Perceptron::toString()
	{
		std::string res;
		for (size_t i = 0; i < m_couche.size(); i++)
		{
			res += "{" + std::to_string(i)+ "}" + m_couche[i]->toString() + "	 ";
		}

		return res;
	}

	std::string Perceptron::toString(std::vector<double> input)
	{
		std::string res;
		for (size_t i = 0; i < m_couche.size(); i++)
		{
			res += "{" + std::to_string(i) + "}" + m_couche[i]->toString(input) + "		";
		}

		return res;
	}

	std::vector<Neurone::Neurone*> Perceptron::getNeurone()
	{
		return m_couche;
	}

	Perceptron::~Perceptron()
	{
		for (size_t i = 0; i < m_couche.size(); i++)
		{
			delete m_couche[i];
			m_couche[i] = nullptr;
		}
	}

}