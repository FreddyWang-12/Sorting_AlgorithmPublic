#include "catch.hpp"

#include <cstring>
#include "DSString.h"
#include <iostream>
using namespace std;


TEST_CASE("DSString class", "[dsstring]"){

    DSString s[12];
    s[0] = DSString("testString");
    s[1] = DSString("a test string");
    s[2] = DSString("");
    s[3] = DSString("THIS IS AN UPPERCASE STRING");
    s[4] = DSString("this is an uppercase string");
    s[5] = DSString("\n");
    s[6] = DSString("");
    s[7] = DSString("  split  split  split  ");
    s[8] = DSString("                          ");
    s[9] = DSString("testString");
    s[10] = DSString("Hi ");
    s[11] = DSString("Hi.");

    SECTION("Equality operators") {
        REQUIRE(s[0] == DSString("testString"));
        REQUIRE(s[0] == "testString");
        REQUIRE(s[0] == s[9]);
        REQUIRE(s[2] == "");
        REQUIRE(s[1] == DSString("a test string"));
        REQUIRE(!(s[3] == s[4]));
    }

    SECTION("Assignment operators"){
        DSString str;
        str = "a test string";
        REQUIRE(str == s[1]);
        str = DSString("testString");
        REQUIRE(str == s[0]);
        str = "";
        REQUIRE(str == s[6]);
        str = DSString("\n");
        REQUIRE(str == s[5]);
    }

    SECTION("Addition operator"){
        REQUIRE(DSString("testStringtestString") == s[0]+s[9]);
        REQUIRE(s[6] + s[6] == "");
        REQUIRE(s[5] + s[6] == DSString("\n"));
        REQUIRE(s[0] + s[1] + s[2] == DSString("testStringa test string"));
        s[0] += s[1];
        REQUIRE(s[0] == DSString("testStringa test string"));
    }

    SECTION("Greater than operator"){
        REQUIRE((s[0] > s[1]));
        REQUIRE(s[4] > s[3]);
        REQUIRE(s[9] > s[6]);
        REQUIRE(s[7] > s[6]);
        REQUIRE(DSString("7") > DSString("2"));
        REQUIRE(s[1] < s[0]);
    }

    SECTION("[] Operator"){
        REQUIRE(s[0][1] == 'e');
        REQUIRE(s[4][4] == ' ');
        REQUIRE(s[6][0] == 0);
    }

    SECTION("getLength function"){
        REQUIRE(s[9].getLength() == 10);
        REQUIRE(s[2].getLength() == 0);
        REQUIRE(s[8].getLength() == 26);
        REQUIRE(s[3].getLength() == 27);
    }

    SECTION("Substring function"){
        REQUIRE(s[0].substring(0, 5) == DSString("testS"));
        REQUIRE(s[4].substring(0, 4) == DSString("this"));
        REQUIRE(s[4].substring(1, 3) == DSString("his"));
    }


    SECTION("c_str function"){
        REQUIRE(strcmp(s[0].c_str(), "testString") == 0);
        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
        REQUIRE(strcmp(s[2].c_str(), "") == 0);
    }

    SECTION("To Lower-case"){
        s[3].toLowercase();
        REQUIRE(s[3] == s[4]);
        s[0].toLowercase();
        s[9].toLowercase();
        REQUIRE(s[0] == s[9]);
    }

    SECTION("Remove Punctuation"){
        s[11].removePunctuation();
        REQUIRE(s[11] == "Hi ");
        REQUIRE(s[10] == s[11]);
    }
}
