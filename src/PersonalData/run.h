#ifndef RUN_H
#define RUN_H
#include <algorithm>
#include <vector>
#include <random>       // std::default_random_engine

#include "trial.h"

/* GameLogic := creates alle possible 96 trials for a run and shuffel them
 * Run := in a run you see all 96 trials (all posible combinations of arrow_image and star_image)
 * Trial := a combination of star and arrow images*/

class Run
{

public:
    Run() {generator.seed(rd());} // init the random generator
    // methods for the run_vector
    void initRun(int);          // fills all possible trials in the run_vector
    void shuffelRun();          // shuffels the run_vector (used bevor every run)
    Trial readRun(bool&);       // read an element of run_vector - bool& checks if the iterator stay in the range between vector::begin and vector::end
    // methods for the measured reaction_time (saved in Trial)
    void saveReactionTime(int);     // saves the measured reaction time in a Trial
    void deleteReactionValues();    // deletes the reaction times(=0) of all trials and the right_reaction(=false) in run_vector
private:
    void possibleCombinations();                // create all possible arrow and star combinations
    std::vector<Trial> run_vector {};           // saves alle Trials for a Run - empty vector = start value of run_vector
    std::vector<Trial>::iterator it_run_vector; // the vector::iterator to iterate over the run_vector           // pseudo random generator - if shuffelRun every time use a new generator i get every time the same shuffel
    // for shuffelRun
    std::random_device rd;  // the generator values aren't reproducable
    std::mt19937 generator; // random_generator for shuffelRun
};

#endif // RUN_H
