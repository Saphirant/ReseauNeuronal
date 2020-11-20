#pragma once
#include <iostream>
#include <vector>
#include "Neurone.h"


namespace NeuralNetwork
{
	/// <summary>
	/// Définit un perceptron = reseau de neurone monocouche
	/// </summary>
	class Perceptron
	{
	private:

		/// <summary>
		/// La sortie du perceptron
		/// </summary>
		std::vector<double> m_sortie = std::vector<double>();

		/// <summary>
		/// La couche de neurone du perceptron
		/// </summary>
		std::vector<Neurone::Neurone*> m_couche = std::vector<Neurone::Neurone*>();


		/// <summary>
		/// Type de neurone composant la couche (elles diffèrent selon leur fonction d'activation)
		/// </summary>
		Neurone::NeuroneType m_type;

		/// <summary>
		/// Le nombre de neurone de la couche
		/// </summary>
		int m_nNeurone;

		/// <summary>
		/// Coefficient d'apprentissage du neurone
		/// </summary>
		double m_apprentissage;

	public:

		/// <summary>
		/// Initialise un perceptron "entré" (qui prends des valeurs données ar l'utilisateur)
		/// </summary>
		/// <param name="nNeurone">Nombre de neurone</param>
		/// <param name="apprentissage">Coefficient d'apprentissage des neurones</param>
		/// <param name="type">Type du neurone</param>
		Perceptron(int mNPrec, int nNeurone, double apprentissage, Neurone::NeuroneType type);


		/// <summary>
		/// Evalue la sortie de chaque neurone
		/// </summary>
		/// <returns>la sortie de chaque neurone</returns>
		std::vector<double> evaluer(std::vector<double> input);

		/// <summary>
		/// renvoie le nombre de neurone d'une couche
		/// </summary>
		/// <returns>Nombre de neurone de la couche</returns>
		int getnbNeurone();

		/// <summary>
		/// Entraine tous les neurones de la couches
		/// </summary>
		/// <param name="listExemple">La liste d'exemple</param>
		void entrainer(std::vector<Test::Exemple> * listExemple);

		/// <summary>
		/// Envoie toutes les poids des neurones de la couche
		/// </summary>
		/// <returns>les poids des neurones de la couche</returns>
		std::string toString();

		/// <summary>
		/// Renvoie toutes les valeurs de la couche
		/// </summary>
		/// <param name="input">Entrée des neurones</param>
		/// <returns>les valeurs de la couche</returns>
		std::string toString(std::vector<double> input);

		std::vector<Neurone::Neurone *> getNeurone();

		~Perceptron();
	};

}
