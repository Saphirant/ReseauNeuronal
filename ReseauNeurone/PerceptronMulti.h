#pragma once
#include "Perceptron.h"
#include <iostream>
#include <vector>

namespace NeuralNetwork
{
	class PerceptronMulti
	{
	private:

		/// <summary>
		/// Représente toutes les couches du perceptron (chaque couche étant un réseau mono couche)
		/// </summary>
		std::vector<Perceptron*> m_couche = std::vector<Perceptron*>();


		/// <summary>
		/// Représente la derniere couche du réseau, celle qui sert de sortie
		/// </summary>
		Perceptron * m_sortieCouche;

		/// <summary>
		/// Les données rentrées en entrées du perceptron
		/// </summary>
		std::vector<double> m_input = std::vector<double>();

		/// <summary>
		/// La sortie du perceptron
		/// </summary>
		std::vector<double> m_sortie = std::vector<double>();

		/// <summary>
		/// Le nombre de couche du reseau (couche d'entrée exclu et couche de sortie inclus) >= 1
		/// </summary>
		int m_nCouche;

		/// <summary>
		/// Représente le nombre de neurone par couche
		/// </summary>
		std::vector<int> m_nParCouche = std::vector<int>();

		/// <summary>
		/// Représente le nombre de sortie du perceptron
		/// </summary>
		int m_nSortie;



	public:		
		/// <summary>
		/// Initializes a new instance of the <see cref="PerceptronMulti" /> class.
		/// </summary>
		/// <param name="input">Données en entré du réseau neuronal</param>
		/// <param name="couche">Description de chaque couche (sauf la couche de sortie) ==> Nombre de neurone pas couche, type de neurone, coefficient d'apprentissage pour la couche</param>
		/// <param name="nSortie">Nombre de sortie attendu</param>
		PerceptronMulti(std::vector<double> input, std::vector<std::tuple<int, Neurone::NeuroneType, double>> couche, int nSortie);


		/// <summary>
		/// Evalue la sortie du réseau de neurone selon son entrée
		/// </summary>
		/// <returns> la sortie du réseau </returns>
		std::vector<double> evaluer(std::vector<double>  input);


		/// <summary>
		/// Entraine tous les neurones du réseau
		/// </summary>
		/// <param name="listExemple">La liste d'exemple</param>
		void entrainer(std::vector<Test::Exemple> * listExemple);


		~PerceptronMulti();

		/// <summary>
		/// Renvoie les valeurs de chaque couche de neurone
		/// </summary>
		/// <returns>les valeurs de chaque couche de neurone</returns>
		std::string toString();

		/// <summary>
		/// Renvoie les couches du réseau
		/// </summary>
		/// <param name="input">Entrée du réseau</param>
		/// <returns>valeurs des couches</returns>
		std::string toString(std::vector<double> input);
	};


}