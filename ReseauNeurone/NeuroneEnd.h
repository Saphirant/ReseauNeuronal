#pragma once
#include "Neurone.h"
namespace Neurone
{
	class NeuroneEnd : public Neurone
	{
	private:
		double fctActivation(double sommePonderee);
	public:
		NeuroneEnd(int nEntree, double apprentissage);
		~NeuroneEnd();
	};


}