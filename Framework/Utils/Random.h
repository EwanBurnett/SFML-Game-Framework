//Pseudo-Random Number Generator - Ewan Burnett 2021
//This Random Number Generator is seeded to time. 
//So based on the time the user runs the app, they will recieve different random events.

#pragma once
#include <random>

struct RNG {

    void Seed(float time);
    int RandInt(int max = 100);

private:
    std::mt19937 mt;    //Mersenne Twister RNG
};


inline void RNG::Seed(float time)
{
    //Seed the RNG to the input time. 
    mt.seed(static_cast<unsigned int>(time));
}

inline int RNG::RandInt(int max)
{
    return (mt() % max);
}
