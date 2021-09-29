//Pseudo-Random Number Generator - Ewan Burnett 2021
//This Random Number Generator is seeded to time. 
//So based on the time the user runs the app, they will recieve different random events.

#pragma once

struct RNG {
    void Seed(float time);
    int RandInt(int max = 100);
};

inline void RNG::Seed(float time)
{
    //Seed the RNG to the input time. 
    srand(time);
}

inline int RNG::RandInt(int max)
{
    return (rand() % max);
}