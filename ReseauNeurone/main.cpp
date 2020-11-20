#include <iostream>
#include "PerceptronMulti.h"
#include "Neurone.h"


using namespace std;

int main(int argc, char *argv[]) 
{ 

	cout << "Debut --------------------------------------------" << endl;

	vector<double> input = vector<double>({0.1,0.8 });
	double apprentissage = 0.3;

	vector<double> res = vector<double>();

	NeuralNetwork::PerceptronMulti reseau = NeuralNetwork::PerceptronMulti(input, vector<std::tuple<int, Neurone::NeuroneType, double>>({
																std::make_tuple(2, Neurone::NeuroneType::NEURONE_HEAVISIDE, apprentissage),
																std::make_tuple(1, Neurone::NeuroneType::NEURONE_HEAVISIDE, apprentissage)
																}), 1);


	cout << "Neurone avant entrainement -------------------" << endl;
	/*res = reseau.evaluer();
	for (const auto rep : res)
	{
		cout << rep << endl;
	}*/
	cout << reseau.toString() << endl;
	cout << reseau.toString(input) << endl;


	cout << "Entrainement -------------------" << endl;
	vector<Test::Exemple> listExemple = vector<Test::Exemple>();
	listExemple.push_back(Test::Exemple(vector<double>({ 0.1,0.8 }), vector<double>({ 1 })));
	listExemple.push_back(Test::Exemple(vector<double>({0,0 }), vector<double>({ 0 })));
	listExemple.push_back(Test::Exemple(vector<double>({1,1 }), vector<double>({ 1 })));
	listExemple.push_back(Test::Exemple(vector<double>({0.25, 0.25 }), vector<double>({ 1 })));
	listExemple.push_back(Test::Exemple(vector<double>({0.1, 0.2 }), vector<double>({ 0 })));
	
	//reseau.entrainer(&listExemple, true);

	cout << "Neurone apres entrainement -------------------" << endl;
	cout << reseau.toString() << endl;
	cout << reseau.toString(input) << endl;

	cout << "Fin --------------------------------------------" << endl;
	system("pause");
}