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
		/// Corresponds à l'input du neuronne
		/// </summary>
		std::vector<double> m_input = std::vector<double>();


		/// <summary>
		/// Corresponds à la sortie attendu pour l'exemple
		/// </summary>
		std::vector<double> m_sortie;

	public:
		Exemple(std::vector<double> input, std::vector<double> sortie);
		~Exemple();

		/// <summary>
		/// Renvoie l'input passé à l'exemple
		/// </summary>
		/// <returns>input de l'exemple</returns>
		std::vector<double> getInput();


		/// <summary>
		/// Renvoie la sortie théorique de l'exemple
		/// </summary>
		/// <returns>Sortie de l'exemple</returns>
		std::vector<double> getSortie();
	};
}

