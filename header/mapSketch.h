#ifndef MAPS_H
#define MAPS_H

#include <array>
#include <array>
#include <vector>
#include <string>

const int MAP_HEIGHT1 = 21;
const int MAP_WIDTH1 = 21;
const int square_size = 21.0f;

   std::vector<std::vector<std::string>> map1 = {
        {" TJJJJJJJJWJJJJJJJJA "},
        {" V........V........V "},
        {" VoER.EJR.M.EJR.ERoV "},
        {" V.................V "},
        {" V.ER.B.EJWJR.B.ER.V "},
        {" V....V...V...V....V "},
        {" LJJA.DJR M EJS.TJJK "},
        {"    V.V   0   V.V    "},
        {"JJJJK.M TR=EA M.LJJJJ"},
        {"     .  V123V  .     "},
        {"JJJJA.B LJJJK B.TJJJJ"},
        {"    V.V       V.V    "},
        {" TJJK.M EJWJR M.LJJA "},
        {" V........V........V "},
        {" V.EA.EJR.M.EJR.TR.V "},
        {" Vo.V.....P.....V.oV "},
        {" DR.M.B.EJWJR.B.M.ES "},
        {" V....V...V...V....V "},
        {" V.EJJQJR.M.EJQJJR.V "},
        {" V.................V "},
        {" LJJJJJJJJJJJJJJJJJK "}
        // letters used: E A L B J R T S M V W K D Q
    };

       std::vector<std::vector<std::string>> map2 = {
        {" ################### "},
        {" #........#........# "},
        {" #o##.###.#.###.##o# "},
        {" #.................# "},
        {" #.##.#.     .#.##.# "},
        {" #....#...#...#....# "},
        {" ####.### # ###.#### "},
        {"    #.#   0   #.#    "},
        {"#####.# ##### #.#####"},
        {"     .  #123=  .     "},
        {"#####.# ##### #.#####"},
        {"    #.#       #.#    "},
        {" ####.# ##### #.#### "},
        {" #........#........# "},
        {" #.##.###.#.###.##.# "},
        {" #o.#.....P.....#.o# "},
        {" ##.#.#.#####.#.#.## "},
        {" #....#...#...#....# "},
        {" #.               .# "},
        {" #.................# "},
        {" ################### "}
    };


    std::vector<std::vector<std::string>> completedMap = {
        {" TJJJJJJJJWJJJJJJJJA "},
        {" V        V        V "},
        {" V ER EJR M EJR ER V "},
        {" V                 V "},
        {" V ER B EJWJR B ER V "},
        {" V    V   V   V    V "},
        {" LJJA DJR M EJS TJJK "},
        {"    V V   0   V V    "},
        {"JJJJK M TR=EA M LJJJJ"},
        {"        V123V        "},
        {"JJJJA B LJJJK B TJJJJ"},
        {"    V V       V V    "},
        {" TJJK M EJWJR M LJJA "},
        {" V        V        V "},
        {" V EA EJR M EJR TR V "},
        {" V  V     P     V  V "},
        {" DR M B EJWJR B M ES "},
        {" V    V   V   V    V "},
        {" V EJJQJR M EJQJJR V "},
        {" V                 V "},
        {" LJJJJJJJJJJJJJJJJJK "}
    };

#endif