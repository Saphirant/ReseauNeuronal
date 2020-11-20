#pragma once
#include "Neurone.h"
namespace Neurone
{
	class NeuroneSigmoide : public Neurone
	{
	private:
		double fctActivation(double sommePonderee);

	public:
		NeuroneSigmoide(int nEntree, double apprentissage);
		~NeuroneSigmoide();
	};

}
