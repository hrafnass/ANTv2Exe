#ifndef PICKDATA_H
#define PICKDATA_H
#include <vector>

#include "trial.h"

// search for a better way - used to define, which values should searche
enum effect { in_congruent,     // defines the conflict-effect (median of (in-)congruent arrows
              spatial_center,   // defines the orientation-effect (median of spatial/center-cue
              double_no_cue     // defines the alertness-effect  (median of double/no-cue
            };

// saves all values, which needed for the calculation - the PickData methods has to run after every Run
class PickData
{
public:
    PickData(std::vector<Trial>);
    void readReactionTimes(std::vector<unsigned int>&); // read all reaction times with right_reaction = true
    void readReactionTimes(std::vector<unsigned int>&, std::vector<unsigned int>&, effect); // searches the reaction times for the effect calculation
    // Getter for sort_out_size
    unsigned int getSortOutSize() { return sort_out_vector.size();} // size of a vector, which only includes Trials with reaction_right = true
private:
    // delete all elements of the reaction time vectors - look for an template for bool and int
    void eraseVector(std::vector<unsigned int>& erase_vector) { erase_vector.erase(erase_vector.begin(), erase_vector.end());}
    void eraseVector(std::vector<bool>& erase_vector){ erase_vector.erase(erase_vector.begin(), erase_vector.end());}

    std::vector<Trial> sort_out_vector {}; // vector, which saves only the reaction_right = true Trials - start value = empty vector
};

#endif // PICKDATA_H
