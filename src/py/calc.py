class Calc():
    #   0               1           2               3     4         5       6           7
    # trial number,reaction time,right desicion,birthday,cue,combinations,position,position mid arrow,comment
    # all needed lists
    # list all possible cues            - 5th(nr. 4) entrie in the table
    def __init__(self):
        self.cue_list = ["non cue", "center cue", "double cue", "spatial cue up", "spatial cue down"]
        # all possible arrow combinations   - 6th(nr. 5) entrie in the table
        self.comb_list= ["neutral", "congruent", "incongruent"]
        # all possible arrow positions      - 7th(nr. 6) entrie in the table
        self.arrow_pos_list = ["up", "down"]
        # direction mid arrow               - 8th(nr. 7) entrie in the table
        self.dir_mid_arrow_list = ["left", "right"]
        # list of all errors - nr 4 til 7
        self.error_list = ["cue error", "error_combinations", "error position", "error_mid_arrow"]
        # dictionary which saves all combinations with a list as value
        self.dict = {}

    # fills the dict with keys and as start value a free list
    # value: [sum of reaction times, nr right desicion, nr. false desicion]
    def fill_dict(self):
        # a combi over cue, combination and arrow_position
        for cue in self.cue_list:
            for combi in self.comb_list:
                for arrow in self.arrow_pos_list:
                    self.dict.update({cue+" "+combi+" "+arrow: [0,0,0]})
        print("Init Dict: ", self.dict)

    # reads a csv file and  calc all values
    def read_file(self, name):
        # open fd and create readline
        file = open(name, "r")
        line = file.readline()
        print("fist line: ", line)
        # iterate over all lines
        while file:
            # readline
            line = file.readline()
            # split the line (string)
            splitted = line.split(',')
            # create a key
            key = splitted[4]+" "+splitted[5]+" "+splitted[6]
            # quit endless loop at the file end
            if line == "" or key == '  ':
                break
            print("key: ", key)
            # get the value of the key and removes it from the dict
            val = self.dict.get(key)
            self.dict.pop(key)
            # calcs the new values
            new_sum_react_times = val[0]+int(splitted[1])
            # iterate the false and the right number
            if splitted[2] == "0":      # false
                self.dict.update({key: [new_sum_react_times, val[1], val[2]+1]})
            elif splitted[2] == "1":    # right
                self.dict.update({key: [new_sum_react_times, val[1]+1, val[2]]})

        file.close()

    def getDict(self):
        print("key  sum_reaction_time    number_of_right_reactions      number_of_wrong_reactions")
        print(self.dict)
        return self.dict


# main
if __name__ == "__main__":
    filename = input("Bitte geben Sie den Dateinamen an: ")
    calc = Calc()
    calc.fill_dict()
    calc.read_file(filename)
    calc.getDict()