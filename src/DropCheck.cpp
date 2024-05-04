#include "DropCheck.h"
#include <random>
using namespace std ;

DropCheck::DropCheck()
{
    //ctor
}

DropCheck::~DropCheck()
{
    //dtor
}

bool DropCheck::productReleased(){
    // Bernoulli avec une probabilité de 90%
    bernoulli_distribution dis(0.9);
    //produces non-deterministic random numbers
    random_device rd;
    default_random_engine  gen(rd());

    bool result = dis(gen);

    return result ;

}
