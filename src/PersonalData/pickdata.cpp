/*#include "pickdata.h"

PickData::PickData(std::vector<Trial> run_vector)
{
    // fills the sort_out vector with all Trial with the right anwser
    for(auto it : run_vector){
        if(it.getRightReaction())
            sort_out_vector.push_back(it);
    }
}

// add all reaction times in the right_reaction_times vector -  - only for run_vector, which used sortOut
void PickData::readReactionTimes(std::vector<unsigned int>& save_reactiontimes){
    eraseVector(save_reactiontimes);
    for(auto i : sort_out_vector){
        save_reactiontimes.push_back(i.getReactionTime());
    }
}

// read the reactions time for the effect calculation - only for run_vector, which used sortOut
void PickData::readReactionTimes(std::vector<unsigned int>& react_time1, std::vector<unsigned int>& react_time2, effect effect_calc){
    // erase the reaction time vectors
    eraseVector(react_time1);
    eraseVector(react_time2);

    // saves the needed reaction_times
    for(auto i : sort_out_vector){
        // searche for a better way to solve this problem - maybe a switch or something else
        if(effect_calc == effect::in_congruent){
            // saves the reaction times of all congruent arrows in react_time1
            if(i.getArrowImage() == ArrowImage::lllll || i.getArrowImage() == ArrowImage::rrrrr)
                react_time1.push_back(i.getReactionTime());
            // saves the reaction times of all incongruent arrows in react_time2
            if(i.getArrowImage() == ArrowImage::llrll || i.getArrowImage() == ArrowImage::rrlrr)
                react_time2.push_back(i.getReactionTime());
        } else if (effect_calc == effect::double_no_cue) {
            // saves the reaction time of alle double cues
            if(i.getTrialStar() == StarImage::both)
                react_time1.push_back(i.getReactionTime());
            // savesthe reaction times of all no cues
            if(i.getTrialStar() == StarImage::no)
                react_time2.push_back(i.getReactionTime());
        } else {
            // saves the up or down image reaction times in react_times1
            if(i.getTrialStar() == StarImage::up_or_down)
                react_time1.push_back(i.getReactionTime());
            if(i.getTrialStar() == StarImage::mid)
                react_time2.push_back(i.getReactionTime());
        }
    }
}
*/
