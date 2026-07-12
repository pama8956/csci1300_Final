#include "GameCharacters.h"

NPC Phil(){
    Item tradeItem("Poker Chip", 250, "Trade Item", false);
    Item clueItem("Photo booth pictures", 0, "Clue", true);

    NPC phil("Phil", "Casino", //name location
        "Psst, buddy. You look like you're missing something. I might be able to help... for a price.", //dialouge
             "NONE", 250, tradeItem, clueItem); //set 

    return phil;
}

NPC Alan(){
    Item tradeItem("Comb", 100, "Trade Item", false );
    Item clueItem("Man Purse", 0, "Clue", true);

    NPC alan("Alan", "Thailand", 
        "*Flips Hair* Hey, heard youre looking for something. ",
        "Poker Chip", 100, tradeItem, clueItem);
        return alan;
    }

NPC Stu(){
    Item tradeItem("Missing ID", 150, "Trade Item", false );
    Item clueItem("Mike Tyson tattoo recipt", 0, "Clue", true);

    NPC stu("Stu", "The Club", 
        "Oh god what now?? Look im a doctor i really dont have time for this, i look like a wreck and need to get ready for work. Do you have anything that could help?",
        "Comb", 150, tradeItem, clueItem);
        return stu;
    }

NPC Doug(){

    Item tradeItem("Car Keys", 200, "Trade Item", false );
    Item clueItem("Telephone", 0, "Clue", true);

    NPC doug("Doug", "The Club", 
        "Hello! My breath stinks, i was out late last night... \n Anways, you got a mint or something, I phone this random phone last night that might be of use to you.",
        "Missing ID", 200, tradeItem, clueItem);
        return doug;
}

NPC Chow(){
    Item nothing1("N/A", 0, "None", false);
    Item nothing2("N/A", 0, "None", false);

    NPC chow("Chow", "Thailand",
        "Well well well its YOU. Wanna have a fun time?? Ride with me and ill cover your travel costs, you might be a littttle more tired though. HAHAHAHA",
        "NONE", 0, nothing1, nothing2);

    return chow;
}