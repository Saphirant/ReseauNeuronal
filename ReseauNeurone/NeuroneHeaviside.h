#pragma once
#include "Neurone.h"
namespace Neurone
{
	class NeuroneHeaviside : public Neurone
	{
	private:
		double fctActivation(double sommePonderee);

	public:
		NeuroneHeaviside(int nEntree, double apprentissage);
		~NeuroneHeaviside();
	};
}

