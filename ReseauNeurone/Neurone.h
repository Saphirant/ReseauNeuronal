#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Exemple.h"


namespace Neurone
{
	enum class NeuroneType
	{
		NEURONE_HEAVISIDE,
		NEURONE_SIGMOIDE,
		NEURONE_END
	};

	class Neurone
	{
	private:

		/// <summary>
		/// poids de chaque input
		/// </summary>
		std::vector<double> m_poids = std::vector<double>();

		/// <summary>
		/// Représente la somme pondérée des entrées
		/// </summary>
		double m_sommePondere;

		/// <summary>
		/// Représente la sortie du neuronne (nombre entre 0 et 1)
		/// </summary>
		double m_sortie = NULL;

		/// <summary>
		/// Nombre d'entrées du neuronne
		/// </summary>
		size_t m_n;

		/// <summary>
		/// Coefficient d'apprentissage du neuronne
		/// </summary>
		double m_apprentissage;


		/// <summary>
		/// Calcul la somme pondérée des entrées
		/// </summary>
		double sommePondere(std::vector<double> input, std::vector<double> poids);

		/// <summary>
		/// Fonction d'activation du neuronne 
		/// </summary>
		virtual double fctActivation(double sommePonderee) = 0;

	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Neurone" /> class.
		/// </summary>
		/// <param name="nEntree">Nombre d'entrée du neuronne (pour préparer ses poids)</param>
		/// <param name="apprentissage">Coefficient d'apprentissage du neurone</param>
		Neurone(int nEntree, double apprentissage);


		virtual ~Neurone();

		

		/// <summary>
		/// Evalue la sortie du neuronne en passant la somme pondérée dans la fonction d'activation
		/// </summary>
		double evaluer(std::vector<double> input);

		/// <summary>
		/// Entraine le neuronne en lui passant une liste d'exemple (Widrow-Hoff)
		/// </summary>
		/// <param name="listExemple">Liste des exemple</param>
		void entrainer(std::vector<Test::Exemple> *listExemple);

		/// <summary>
		/// Renvoie les valeurs des poids du neuronne
		/// </summary>
		/// <returns>Renvoie les valeurs des poids du neuronne</returns>
		std::string toString();

		/// <summary>
		/// Renvoie les podis du neuronne avec sa sortie
		/// </summary>
		/// <param name="input">Entrée du neurone (pour calculer sa sortie)</param>
		/// <returns>Renvoie les podis du neuronne avec sa sortie</returns>
		std::string toString(std::vector<double> input);


		double getSortie();


	};

}
