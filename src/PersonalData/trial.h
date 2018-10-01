#ifndef TRIAL_H
#define TRIAL_H
#include <vector>
#include <string>

namespace ArrowImage {
    const std::vector<std::string> arrow_image {":/lllll.svg", ":/rrlrr.svg", ":/sslss.svg", ":/rrrrr.svg", ":/llrll.svg", ":/ssrss.svg"};    // arrow names
}

/*namespace StarImage {
    const std::vector<std::string> star {":/double.svg", ":/mid.svg", ":/up_or_down.svg"};
}*/

/*namespace ArrowImage {
     * Describes the arrow images
     * l = left arrow
     * r = right arrow
     * s = stroke
    enum arrow_image { lllll,
                       rrlrr,
                       sslss,
                       rrrrr,
                       llrll,
                       ssrss};
    // used to iterate over arrow_image - needed in GameLogic::initRun
    static const std::vector<arrow_image> it_arrow_image { lllll, rrlrr, sslss, rrrrr, llrll, ssrss};
}*/

namespace StarImage {
     /* star image position in relation to the plus image
     * up_or_down: the star image has the same position as the image_pos
     * mid: the star image has the same position as the plus image
     * both: the star image is above and under the plus image
     * no: no star image is shown*/
    enum star { up_or_down,
                mid,
                both,
                no};
    // used to iteratr over star - needed in GameLogic::initRun
    static const std::vector<star> it_star_image { up_or_down, mid, both, no};
}

namespace ImagePos {
     /* arrow image position in relation to the plus image
     * arrow_up: arrow image is above the plus image
     * arrow_down: arrow image is under the plus image*/
    enum image_pos { arrow_up,
                     arrow_down};
    // used to iterate over image_pos -  needed in GameLogic::initRun
    static const std::vector<image_pos> it_image_pos { arrow_up, arrow_down};
}

class Trial
{
public:
    Trial(std::string arrow_image, StarImage::star star_image, ImagePos::image_pos pos)
        : trial_image {arrow_image}, trial_star {star_image}, trial_image_pos {pos} {}

    // all Getter for the images
    std::string getArrowImage() { return trial_image;}
    StarImage::star getTrialStar() { return trial_star;}
    ImagePos::image_pos getTrialImagePos() { return trial_image_pos;}
    // Getter and Setter for the reaction_time
    void setReactionTime(unsigned int measured_time) { reaction_time = measured_time;}
    unsigned int getReactionTime() { return reaction_time;}
    // Getter and Setter for the right_reaction
    void setRightReaction(bool reaction) { right_reaction = reaction;}
    bool getRightReaction() { return right_reaction;}
private:
    std::string trial_image;    // saves the arrow image combination
    StarImage::star trial_star;             // saves the star image position
    ImagePos::image_pos trial_image_pos;    // saves the arrow_image position
    unsigned int reaction_time;             // saves the reactiontime
    bool right_reaction;                    // if the measured reaction is right right_reaction is true else false
};

#endif // TRIAL_H
