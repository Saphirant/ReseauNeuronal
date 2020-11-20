#include "NeuroneHeaviside.h"


namespace Neurone
{
	double NeuroneHeaviside::fctActivation(double sommePonderee)
	{
		return sommePonderee >= 0 ? 1 : 0;
	}
	NeuroneHeaviside::NeuroneHeaviside(int nEntree, double apprentissage) : Neurone(nEntree,apprentissage)
	{
	}


	NeuroneHeaviside::~NeuroneHeaviside()
	{
	}

}