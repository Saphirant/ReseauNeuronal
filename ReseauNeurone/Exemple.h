#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace Test
{
	class Exemple
	{
	private:

		/// <summary>
		/// Corresponds � l'input du neuronne
		/// </summary>
		std::vector<double> m_input = std::vector<double>();


		/// <summary>
		/// Corresponds � la sortie attendu pour l'exemple
		/// </summary>
		std::vector<double> m_sortie;

	public:
		Exemple(std::vector<double> input, std::vector<double> sortie);
		~Exemple();

		/// <summary>
		/// Renvoie l'input pass� � l'exemple
		/// </summary>
		/// <returns>input de l'exemple</returns>
		std::vector<double> getInput();


		/// <summary>
		/// Renvoie la sortie th�orique de l'exemple
		/// </summary>
		/// <returns>Sortie de l'exemple</returns>
		std::vector<double> getSortie();
	};
}

