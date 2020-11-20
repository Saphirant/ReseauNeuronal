#include "NeuroneEnd.h"


namespace Neurone
{
	double NeuroneEnd::fctActivation(double sommePonderee)
	{
		return sommePonderee;
	}
	NeuroneEnd::NeuroneEnd(int nEntree, double apprentissage) : Neurone(nEntree, apprentissage)
	{
	}


	NeuroneEnd::~NeuroneEnd()
	{
	}

}