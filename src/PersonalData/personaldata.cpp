#include "personaldata.h"

// Private Mehtods

// sorts the int vectors
void PersonalData::sortVectors(std::vector<unsigned int>& unsorted){
    std::sort(unsorted.begin(), unsorted.end());    // sorts the unsorted vector - search if there is something more effectiv
}

// calculates the median of the reaction time vector - needs a sorted vector
float PersonalData::medianReactionTime(std::vector<unsigned int> right_reaction_times){
    float median_reaction_times = calcMedian(right_reaction_times);
    return median_reaction_times;
}

// Public Methods

// calculates average reaction time of alle right trials
unsigned int PersonalData::averageReactionTime(std::vector<unsigned int> right_reaction_times){
    unsigned int sum_reaction_times = 0;    // saves the sum of all reaction times in right_reaction_times
    // adds all reaction times in right_reaction_times
    for(auto i : right_reaction_times){
        sum_reaction_times = sum_reaction_times + i;
    }
    // calculate the average reaction time
    unsigned int average_reaction_time = sum_reaction_times / right_reaction_times.size();

    return average_reaction_time;
}

/* calculates the percentage of all right_reaction = true
 * sort_out_vector_size: size of a Trial-vector, which only includes Trials with reaction_right = true
 * run_vector_size: includes all Trials of an Run */
float PersonalData::rightPercentage(int sort_out_vector_size, int run_vector_size){
    float percentage = (sort_out_vector_size*100)/run_vector_size;
    return percentage;
}

/* Median(congruentReactionTime) - Median(incongruentReactionTime)
 * n_c: number of all congruent conditions
 * n_i: number of all incongruent conditions
 * x_vector: list of all reaction times in ascending order
 * x_i: an element of x_list
 * n_* = even: 0.5[x_(n/2) + x_(n/2+1)]
 * n_* = uneven: x_((n+1)/2) */
float PersonalData::calcMedian(std::vector<unsigned int> x_vector){      // calcMedian needs an vector in ascending order
    float median;   // saves the calculated median

    // test if the x_vector vector have an even size or an odd size
    if(x_vector.size() % 2){                                    // calcualtes the median for an odd vector size
        unsigned int median_pos = (x_vector.size() + 1) / 2;    // calculates the position of the median value in congruent_reactiontimes
        median = x_vector[median_pos];                          // saves the median for an odd vector size
    }else {                                                     // calculates the median for an even vector size
        unsigned int pos_n2 = x_vector.size() / 2;              // calculates the position for the first value of the median
        unsigned int pos_n2_1 = pos_n2 + 1;                     // calculates the position for the second value of the median
        median = (x_vector[pos_n2] + x_vector[pos_n2_1])*(1/2); // calculates the median for an even vector size
    }

    return median;
}

 /* calcEffects calculate the conflict/orientation/alertness effect
  * reactiontimes1 is the first SORTED vector for the median calculation
  * reactiontimes2 is the seconded SORTED vector for the median calculation */
float PersonalData::calcEffects(std::vector<unsigned int> reactionstimes1, std::vector<unsigned int> reactiontimes2){
    float effect, median1, median2;

    // calculates the median values
    median1 = calcMedian(reactionstimes1);
    median2 = calcMedian(reactiontimes2);

    // calculates the conflict-effect
    effect = median1 - median2;

    return effect;
}
