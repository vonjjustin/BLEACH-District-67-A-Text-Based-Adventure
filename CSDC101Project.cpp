#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int playerHP = 40;
    int playerATK = 12;
    int playerDEF = 5;
    
    int bossHP = 400;
    int bossATK = 21;
    int bossDEF = 20;

    int playerDMG; // raw damage calculation of player
    int bossDMG; // raw damage calculation of boss
    int choice; // used for choosing among safe, mid, or risky in scenes 2 to 10
    int turn = 0; // increment for each turn
    int useItem; // used for choosing a special item in a turn
    int action; // used for choosing an action
    int itemNum = 1; // counter for numbering special items
    int actionNum = 1; // counter for numbering actions

    int rapierItem = 0;
    int netItem = 0;
    int sunglassesItem = 0;
    int rustbiteItem = 0;
    int attack = 0;

    bool hasRapier = false;
    bool hasNet = false;
    bool hasSunglasses = false;
    bool hasAmulet = false;
    bool hasRustbite = false;
    bool skipBossAttack = false;

    // Scene 0 - Introduction
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\tBLEACH: District 67 - A Text-Based Adventure" << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Disclaimer: This is a fan-made educational project. Bleach is created by Tite Kubo." << endl;
    cout << "All rights belong to their respective owners. For classroom use only." << endl << endl;
    cout << "You are Jun Arashi, a soul living in District 67 of Rukongai." << endl;
    cout << "One night, a terrible presence descends - a rogue Hollow stalks the district." << endl;
    cout << "You must prepare yourself for the coming battle." << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to begin your journey...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');   

    // Scene 1 - Prologue (District 67)
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "District 67, outskirts of Rukongai." << endl << endl;
    cout << "Jun stands in a dark alley as screams echo through the streets." << endl;
    cout << "The night sky trembles as a Hollow\'s roar shakes the rooftops." << endl;
    cout << "Jun clenches his fists - there is no running now." << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');   

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl << endl;
    cout << "Current Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << "\n";
    cout << "\t- 🗡️ Attack Power: " << playerATK << "\n";
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');   

    // Scene 2 - The Saint (Hanae)
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Hanae, the district\'s wandering saint, approaches you." << endl;
    cout << "Hanae: \"You look pale, Jun. The night is cruel... let me bless you with light.\"" << endl;
    cout << "Choose:" << endl; 
    cout << "\t1. Safe - \"Just a little strength will do.\" (+4 ATK)" << endl;
    cout << "\t2. Mid - \"I\'ll take whatever you can give.\" (+1 ATK, +1 DEF, +7 HP)" << endl;
    cout << "\t3. Risky - \"Give me everything you have!\" (+11 ATK, +3 DEF, -5 HP)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerATK += 4;
            break;
        case 2: // Mid
            playerATK += 1; playerDEF += 1; playerHP += 7;
            break;
        case 3: // Risky
            playerATK += 11; playerDEF += 3; playerHP -= 5;
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerATK += 4;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;

    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Scene 3 - The Tinkerer (Riku)
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "You find Riku, a tinkerer surrounded by scraps of strange metal." << endl << endl;
    cout << "Riku: \"You\'ll need more than fists against a Hollow. I can forge something quick.\"" << endl;
    cout << "Choose:" << endl;
    cout << "\t1. Safe - \"Just give me something simple.\" (+4 ATK)" << endl;
    cout << "\t2. Mid - \"Make me sturdier.\" (+1 DEF, -2 HP)" << endl;
    cout << "\t3. Risky - \"Push the limits!\" (+5 ATK, +3 DEF, -5 HP, gain Rustbite: -6 Boss DEF)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerATK += 4;
            break;
        case 2: // Mid
            playerDEF += 1; playerHP -= 2;
            break;
        case 3: // Risky
            playerATK += 5; playerDEF += 3; playerHP -= 5; hasRustbite = true; // rustbite obtained (-6 boss DEF)
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerATK += 4;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;

    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Scene 4 - Sister Midori (Shrine)
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "You pass a ruined shrine. Sister Midori kneels in prayer." << endl << endl;
    cout << "Midori: \"Child... I can offer a charm. But the gods ask for something in return.\"" << endl;
    cout << "Choose:" << endl;
    cout << "\t1. Safe - \"A small blessing, please.\" (+4 ATK)" << endl;
    cout << "\t2. Mid - \"I\'ll take the charm.\" (Gain Net, -2 HP)" << endl;
    cout << "\t3. Risky - \"I want true power!\" (+9 ATK, -4 HP)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerATK += 4;
            break;
        case 2: // Mid
            playerHP -= 2; hasNet = true; // net obtained (free skip 1 boss attack)
            break;
        case 3: // Risky
            playerATK += 9; playerHP -= 4;
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerATK += 4;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;

    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Scene 5 - Yumi the Smuggler
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "A shadow in the corner alley beckons you. Yumi, the smuggler, grins." << endl << endl;
    cout << "Yumi: \"Dangerous times, dangerous goods. I can sell you power, if you're willing to pay the price.\"" << endl;
    cout << "Choose:" << endl;
    cout << "\t1. Safe - \"Something reliable.\" (+11 ATK)" << endl;
    cout << "\t2. Mid - \"The Armlet of Mordiggan...\" (+15 ATK, -1 DEF, -2 HP)" << endl;
    cout << "\t3. Risky - \"What's your strongest weapon?\" (Gain Divine Rapier, -10 HP, -3 DEF, -3 ATK)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerATK += 11;
            break;
        case 2: // Mid
            playerATK += 15; playerDEF -= 1; playerHP -= 2;
            break;
        case 3: // Risky
            playerATK -= 3; playerDEF -= 3; playerHP -= 10; hasRapier = true; // divine rapier obtained (deals 275 true damage ignoring boss DEF)
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerATK += 11;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;

    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Scene 6 - Kaji the Peddler
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "An old peddler, Kaji, rattles his cart of bottles and charms." << endl << endl;
    cout << "Kaji: \"Spare change for power? Every blessing has a price.\"" << endl;
    cout << "Choose:" << endl;
    cout << "\t1. Safe - \"A minor boost.\" (+4 ATK)" << endl;
    cout << "\t2. Mid - \"Something stronger.\" (+8 ATK, -2 HP)" << endl;
    cout << "\t3. Risky - \"Everything you've got!\" (+15 ATK, -2 DEF, -5 HP)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerATK += 4;
            break;
        case 2: // Mid
            playerATK += 8; playerHP -= 2;
            break;
        case 3: // Risky
            playerATK += 15; playerDEF -= 2; playerHP -= 5;
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerATK += 4;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;

    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Scene 7 - Aiko the Child
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Aiko, a small child, tugs at your sleeve with pleading eyes." << endl << endl;
    cout << "Aiko: \"Please... help us. You're the only one who can stand against the Hollow.\"" << endl;
    cout << "Choose:" << endl;
    cout << "\t1. Safe - \"I'll do my best.\" (+2 ATK)" << endl;
    cout << "\t2. Mid - \"I'll push myself harder.\" (+1 ATK, +1 DEF, -1 HP)" << endl;
    cout << "\t3. Risky - \"I'll protect everyone at any cost!\" (+8 ATK, +3 DEF, -5 HP)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerATK += 2;
            break;
        case 2: // Mid
            playerATK += 1; playerDEF += 1; playerHP -= 1;
            break;
        case 3: // Risky
            playerATK += 8; playerDEF += 3; playerHP -= 5;
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerATK += 2;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;

    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Scene 8 - Master Renga
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Your old mentor, Renga, leans on his cane and lowers his sunglasses." << endl << endl;
    cout << "Renga: \"Jun... take these. You'll need sharp eyes more than a sharp blade.\"" << endl;
    cout << "Choose:" << endl;
    cout << "\t1. Safe - \"A steady path will do.\" (+5 ATK)" << endl;
    cout << "\t2. Mid - \"I'll endure the strain.\" (+7 ATK, -2 HP)" << endl;
    cout << "\t3. Risky - \"I'll fight with your spirit!\" (Gain Sunglasses, +2 DEF, -5 HP)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerATK += 5;
            break;
        case 2: // Mid
            playerATK += 7; playerHP -= 2;
            break;
        case 3: // Risky
            playerDEF += 2; playerHP -= 5; hasSunglasses = true; // sunglasses obtained (free skip 1 boss attack)
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerATK += 5;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;

    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Scene 9 - Mika the Charm-Sel
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Mika holds a tray of strange charms." << endl << endl;
    cout << "Mika: \"These trinkets are cursed and blessed alike. What will you take?\"" << endl;
    cout << "Choose:" << endl;
    cout << "\t1. Safe - \"A small charm.\" (+2 ATK)" << endl;
    cout << "\t2. Mid - \"That one... it glows faintly.\" (Gain Schala's Amulet, -3 HP)" << endl;
    cout << "\t3. Risky - \"I want the strongest one!\" (+11 ATK, +2 DEF, -7 HP)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerATK += 2;
            break;
        case 2: // Mid
            playerHP -= 3; hasAmulet = true; // schala's amulet obtained (survive 1 lethal blow)
            break;
        case 3: // Risky
            playerATK += 11; playerDEF += 2; playerHP -= 7;
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerATK += 2;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;

    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

   // Scene 10 - Supply Cache
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "You find a hidden cache of supplies - medicine, weapons, armor." << endl << endl;
    cout << "Choose:" << endl;
    cout << "\t1. Safe - \"Patch me up completely.\" (Set HP to 50)" << endl;
    cout << "\t2. Mid - \"I'll take the sharper blades.\" (+12 ATK, -3 HP)" << endl;
    cout << "\t3. Risky - \"Load me with everything!\" (+23 ATK, +2 HP)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    switch(choice){
        case 1: // Safe
            playerHP = 50;
            break;
        case 2: // Mid
            playerATK += 12; playerHP -= 3;
            break;
        case 3: // Risky
            playerATK += 23; playerHP += 2;
            break;
        default:
            cout << "\t❌ Invalid Choice! Defaulting to the safe choice." << endl;
            playerHP = 50;
            cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
            break;
    }
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl << endl;
    cout << "Special Items:\n";
    cout << "\t" << (hasRapier ? "✅ " : "❌ ") << "⚔️ Divine Rapier" << endl;
    cout << "\t" << (hasNet ? "✅ " : "❌ ") << "🕸️ 90-Caliber Net" << endl;
    cout << "\t" << (hasSunglasses ? "✅ " : "❌ ") << "😎 Sunglasses" << endl;
    cout << "\t" << (hasAmulet ? "✅ " : "❌ ") << "💠 Schala's Amulet" << endl;
    cout << "\t" << (hasRustbite ? "✅ " : "❌ ") << "⚡ Rustbite Charge" << endl;
    cout << "\n══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Scene 11 - Boss Fight: Bjorne the Rogue Hollow
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║ 🕷️🩸 BOSS FIGHT:BJORNE THE ROGUE HOLLOW 🩸🕷️ ║" << endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "The ground trembles violently as a monstrous shadow rises, eclipsing the moonlight." << endl;
    cout << "A chilling roar echoes through District 67, sending shivers down your spine." << endl;
    cout << "Bjorne, the Rogue Hollow, emerges—towering, mask cracked, claws dripping with cursed energy." << endl << endl;
    cout << "Bjorne: \"Foolish soul... your resistance amuses me.\"" << endl;
    cout << "Bjorne: \"Tonight, you face oblivion. Show me your strength, if you dare!\"" << endl << endl;
    cout << "🔥 The air crackles with tension. The crowd watches from shattered windows, holding their breath." << endl;
    cout << "🎮 [GAME TIP] Use your special items wisely—one wrong move could mean defeat!" << endl;
    cout << "💀 The battle for District 67 begins. Only legends survive the night..." << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to start the fight...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  1 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  2 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  3 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  4 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  5 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  6 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  7 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  8 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  9 ⚔️☠️            ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;

    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  10 ⚔️☠️           ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;


    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  11 ⚔️☠️           ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;


    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  12 ⚔️☠️           ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;


    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  13 ⚔️☠️           ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;


    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  14 ⚔️☠️           ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;


    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "\t\t\t\t\t\t╔═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t\t║             ☠️⚔️ T U R N  15 ⚔️☠️           ║"<<  endl;
    cout << "\t\t\t\t\t\t╚═══════════════════════════════════════╝" << endl;


    turn += 1; // increments turn to monitor number of turns for fatigue ending
    skipBossAttack = false; // reset boss attack skip at start of each turn
    itemNum = actionNum = 1; // reset to 1 every turn
    rapierItem = netItem = sunglassesItem = rustbiteItem = attack = 0; // reset the value of items and attackto 0 in every turn
    cout << "Turn: " << turn << endl;

    // Display current stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl;
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose a special item:" << endl;
    if (hasNet) {
        cout << "\t" << itemNum << ". 🕸️ 90-Caliber Net (Skips the next boss attack)" << endl;
        netItem = itemNum++;
    }
    if (hasSunglasses) {
        cout << "\t" << itemNum << ". 😎 Sunglasses (Skips the next boss attack)" << endl;
        sunglassesItem = itemNum++;
    }
    if (hasRustbite) {
        cout << "\t" << itemNum << ". ⚡ Rustbite Charge (Permanently reduces Bjorne\'s DEF by 6)" << endl;
        rustbiteItem = itemNum++;
    }
    if (hasAmulet) {
        cout << "\t Note: 💠 Schala's Amulet will automatically activate if your HP drops to 0 or below." << endl;
    }

    // if no special items were obtained
    if (itemNum == 1) {
        cout << "\t❌ No special items obtained." << endl;
    } else {
        cout << "Enter your choice: ";
        cin >> useItem;
        cin.clear(); // clear error flag or fail state on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

        if (useItem == netItem && hasNet) {
            skipBossAttack = true;
            hasNet = false;
            cout << "\t✅ You used the 90-Caliber Net! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == sunglassesItem && hasSunglasses) {
            skipBossAttack = true;
            hasSunglasses = false;
            cout << "\t✅ You wore the Sunglasses! The boss attack will be skipped this turn!" << endl;
        }else if (useItem == rustbiteItem && hasRustbite) {
            bossDEF -= 6;
            hasRustbite = false;
            cout << "\t✅ You used the Rustbite Charge! Boss DEF permanently reduced by 6! Boss DEF: " << bossDEF << endl;
        }else {
            cout << "\t❌ Invalid choice. You did not use any special item this turn." << endl;
        }
    }
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
    cout << "Press any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;

    cout << "Choose an action: " << endl;
    // Player attacks boss (only if player is alive)
    if(playerHP > 0 && bossHP > 0) {
        cout << "\t" << actionNum << ". 🗡️ Attack" << endl;
        attack = actionNum++;
    }
    if (hasRapier) {
        cout << "\t" << actionNum << ". ⚔️ Divine Rapier (Deals 275 true damage (ignores DEF))" << endl;
        rapierItem = actionNum++;
    }

    cout << "Enter your action: ";
    cin >> action;
    cin.clear(); // clear error flag or fail state on cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from input buffer

    if(action == attack) {
        playerDMG = max(1, playerATK - bossDEF);
        bossHP -= playerDMG;
        cout << "\t🗡️ You strike Bjorne, dealing " << playerDMG << " damage!" << endl;
    }else if (action == rapierItem && hasRapier) {
        bossHP -= 275;
        hasRapier = false;
        cout << "\t✅ You used the Divine Rapier! You dealt 275 true damage! Boss HP: " << bossHP << endl;
    }else {
        cout << "\t❌ Invalid choice. You did not choose any action this turn." << endl;
    }

    // Boss attacks player (only if boss is alive and not skipped)
    if(bossHP > 0 && playerHP > 0) {
        if(skipBossAttack == false){
            bossDMG = max(1, bossATK - playerDEF);
            playerHP -= bossDMG;
            cout << "\n☠️ Bjorne lunges at you, claws flashing!" << endl;
            cout << "🩸 You take " << bossDMG << " damage!" << endl;

            // Check for Amulet
            if(hasAmulet && playerHP <= 0){
                playerHP = 1; // restores to 1 HP
                hasAmulet = false;
                cout << "\n💠 Schala's Amulet glows! You cheat death and revive with 1 HP!" << endl;
                cout << "✨ The charm shatters in your hand." << endl;
            }
        } else {
            cout << "\n🕸️ You dodge as your item activates — Bjorne's attack is completely negated!" << endl;
        }
    }

    // Update Stats
    cout << "\nCurrent Player Stats:\n";
    cout << "\t- ❤️ Health Points: " << playerHP << endl;
    cout << "\t- 🗡️ Attack Power: " << playerATK << endl;
    cout << "\t- 🛡️ Defense Power: " << playerDEF << endl;
    cout << "\nCurrent Boss Stats:\n";
    cout << "\t- ❤️ Health Points: " << bossHP << endl;
    cout << "\t- 🗡️ Attack Power: " << bossATK << endl;
    cout << "\t- 🛡️ Defense Power: " << bossDEF << endl << endl;

    // Boss dialogue based on HP
    if(bossHP > 300){
        cout << "Boss: Tiny spark. I will crush you slowly." << endl;
    }else if(bossHP > 200){
        cout << "Boss: You sting… nothing more." << endl;
    }else if(bossHP > 100){
        cout << "Boss: Impossible… you persist?!" << endl;
    }else{
        cout << "Boss: I will DEVOUR YOU!" << endl;
    }

    // Ending check
    if(bossHP <= 0){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "🏆 VICTORY 🏆" << endl;
        cout << "\tJun stands over Bjorne's fallen form, the Hollow's mask shattered." << endl;
        cout << "\tAs dawn breaks, shinigami flash-step into the ruined street." << endl;
        cout << "\tA captain nods: \"You fought bravely, Jun. The Academy awaits you.\"" << endl;
        cout << "\tThe district cheers. Jun's legend begins." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(playerHP <= 0 ){ 
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "💀 DEFEAT 💀" << endl;
        cout << "\tJun collapses, bloodied but defiant. Bjorne roars in frustration." << endl;
        cout << "\tShinigami arrive in a blaze of light, finishing the Hollow." << endl;
        cout << "\tJun's sacrifice echoes through District 67. He is remembered as a hero." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }else if(turn >= 15){
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        cout << "⏳ FATIGUE ENDING ⏳" << endl;
        cout << "\tAfter a grueling battle, Jun collapses from exhaustion." << endl;
        cout << "\tBjorne prepares to strike, but shinigami flash in, saving the district." << endl;
        cout << "\tJun's courage becomes legend, his name whispered with respect for generations." << endl;
        cout << "══════════════════════════════════════════════════════════════════════════════════" << endl;
        return 0;
    }
    
    return 0;
}
