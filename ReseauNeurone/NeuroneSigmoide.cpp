#include "NeuroneSigmoide.h"
#include <math.h>   


namespace Neurone
{
	NeuroneSigmoide::NeuroneSigmoide(int nEntree, double apprentissage) : Neurone(nEntree, apprentissage)
	{
	}


	NeuroneSigmoide::~NeuroneSigmoide()
	{
	}


	double NeuroneSigmoide::fctActivation(double sommePonderee)
	{
		return 1/(1+exp(-sommePonderee));
	}
}
