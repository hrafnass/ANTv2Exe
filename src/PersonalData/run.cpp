#include "run.h"

// Private Methods
void Run::possibleCombinations(){
    // iterate over all possible arrow combination
    for(auto it_arrow : ArrowImage::arrow_image){
        // iterate over all posible arrow positions (above/under the plus image)
        for(auto it_pos : ImagePos::it_image_pos) {
            // iterate over all star image positions
            for(auto it_star : StarImage::it_star_image){
                run_vector.push_back(Trial(it_arrow, it_star, it_pos));
            }
        }
    }
}

// Public Methods
// create 48 possible Trials
// number_of_reruns: is the number how often possibleCombinations as to used - standard is 2
void Run::initRun(int number_of_reruns=2){
    // fills the run_vector
    for(int i = 0; i < number_of_reruns; i++){
        possibleCombinations();
    }
    // set the run_vector iterator to the start
    it_run_vector = run_vector.begin();
}

// shuffels the run_vector
void Run::shuffelRun(){
    // using the mt19937 random number generator - maybe use another
    std::shuffle(run_vector.begin(), run_vector.end(), generator);
}

// reads every time a new trial of the run_vector
Trial Run::readRun(bool& inRange){
    // checks if the iterator is equal run_vector.end()
    // if it's true the vector end is reached -> the run is finished and readRun has to start again (next run) -> run_vector has to bee shuffel
    if(it_run_vector == run_vector.end())
        inRange = false;    // is the sign to shuffle the run_vector again - the Run has ended
    else
        inRange = true;     // the run_vector isn't finished yet:

    // if the iterator (it_run_vector) is equal run_vector.end(), the run starts again
    if(inRange == false){
        it_run_vector = run_vector.begin(); // set the iterator at the vector begin and return the Trial
        return *it_run_vector;
    }

    // the Run hasn't ended yet.
    Trial retTrial = *it_run_vector;    // saves the Trial of the run_vector
    ++it_run_vector;                    // iterator to the next Trial in the vector

    return retTrial;                    // return the Trial
}

// set all trial reaction times to 0 and right_reactio to false
void Run::deleteReactionValues(){
    // iterate over the run_vector and set all reaction_time of the trials 0
    // this is the c++11 way - maybe there is another way for c++17
    for(auto &i : run_vector){
        i.setReactionTime(0);
        i.setRightReaction(false);
    }
}
