#include "catch.hpp"

#include <cstring>
#include "DSVector.h"
#include <iostream>
using namespace std;
//
// Created by Frederick Wang on 2/13/20.
//

TEST_CASE("DSVector class", "[dsvector]"){
    DSVector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    x.push_back(6);
    x.push_back(7);
    x.push_back(1);

    SECTION("Inside vector"){
        REQUIRE(x.front() == 1);
        x.pop_back();
        REQUIRE(x.front() == 2);
        x.pop_back();
        REQUIRE(x.front() == 3);
        x.pop_back();
        REQUIRE(x.front() == 4);
        x.pop_back();
        REQUIRE(x.front() == 5);
        x.pop_back();
        REQUIRE(x.front() == 6);
        x.pop_back();
        REQUIRE(x.front() == 7);
    }

    SECTION("Clear and Length Functions"){
        REQUIRE(x.size() == 8);
        x.clear();
        REQUIRE(x.size() == 0);
    }

    SECTION("Index Brackets"){
        REQUIRE(x[0] == 1);
        REQUIRE(x[1] == 2);
        REQUIRE(x[2] == 3);
    }

    SECTION("Copy Assigner"){
        DSVector<int> y = x;
        REQUIRE(y.front() == 1);
        REQUIRE(y[1] == 2);
        DSVector<int> z;
        z = x;
        REQUIRE(z.front() == 1);
        REQUIRE(z[1] == 2);
    }

    SECTION("Sort"){
        x.sort();
        REQUIRE(x[0] == 1);
        REQUIRE(x[1] == 1);
    }

    SECTION("Remove Duplicates"){
        REQUIRE(x.size() == 8);
        int a = 0;
        for(int i = 0; i < x.size(); i++){
            if(x[i] == 1){
                a++;
            }
        }
        REQUIRE(a == 2);

        x.removeDuplicates();
        REQUIRE(x.size() == 7);
        int z = 0;
        for(int j = 0; j < x.size(); j++){
            if(x[j] == 1){
                z++;
            }
        }
        REQUIRE(z == 1);
    }
}