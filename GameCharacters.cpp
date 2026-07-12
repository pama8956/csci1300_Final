#include "GameCharacters.h"

NPC Phil(){
    Item tradeItem("Plane ticket", 250, "Trade Item", false);
    Item clueItem("Photo booth pictures", 0, "Clue", true);

    NPC phil("Phil", "Casino", //name location
        "Psst, buddy. You look like you're missing something. I might be able to help... for a price.", //dialouge
             "NONE", 100, tradeItem, clueItem); //set 

    return phil;
}

NPC Alan(){
    Item tradeItem("Comb", 150, "Trade Item", false );
    Item clueItem("Man Purse", 0, "Clue", true);

    NPC alan("Alan", "Thailand", 
        "*Flips Hair* Hey, heard youre looking for something. \n Ive got this sweet comb, i just need a ticket out of here. Or if you have some cash... ",
        "Plane ticket", 100, tradeItem, clueItem);
        return alan;
    }

NPC Stu(){
    Item tradeItem("Missing ID", 200, "Trade Item", false );
    Item clueItem("Mike Tyson tattoo recipt", 0, "Clue", true);

    NPC stu("Stu", "The Club", 
        "Oh god what now?? Look im a doctor i really dont have time for this, i look like a wreck and need to get ready for work. \n I think I have your friends ID. Do you have anything that could help me?",
        "Comb", 150, tradeItem, clueItem);
        return stu;
    }

NPC Doug(){

    Item tradeItem("Car Keys", 250, "Trade Item", false );
    Item clueItem("Telephone", 0, "Clue", true);

    NPC doug("Doug", "The Club", 
        "Hey! My wife is pissed... \n We have a date in 30 minutes and I was out all night. \n You got a mint or something? I found your friends phone last night, its got a bunch of pictures at a park...",
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