#ifndef PERSONALDATA_H
#define PERSONALDATA_H
#include <vector>
#include <algorithm>

// uses the measured values to calculate average values
class PersonalData
{

public:
    float medianReactionTime(std::vector<unsigned int>);            // calculates the median of the reaction times - needs a sorted vector
    unsigned int averageReactionTime(std::vector<unsigned int>);    // calculates the average reaction time of all trials with right_reaction = true
    float rightPercentage(int, int);                                // calculates the percentage of all right_reactions = true
    float calcEffects(std::vector<unsigned int>, std::vector<unsigned int>);          // calculates the calculates all needed effects - needs sorted vectors
private:
    float calcMedian(std::vector<unsigned int>);                              // calculates the median of an int vector
    void sortVectors(std::vector<unsigned int>&);                             // sorts an int vector in ascending order
};

#endif // PERSONALDATA_H
