//
// Created by Frederick Wang on 1/30/20.
// "A copy of the string class that takes an array of chars and makes a line of string from it"
// "that can then be modified and adjusted"
// CS2341 - Data Structures
// Professor Mark Fontenot
//

#ifndef S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
#define S20_PA01_SENTIMENTANALYSIS_DSSTRING_H


class DSString {
    private:
        int length; // Length of the string's contents
        char* data; // The string's contents of chars
    public:
        DSString(); // Default constructor of the DSString
        DSString(const char* stringIdentity); // Overloaded constructor of the DSString
                                              // @param stringIdentity: The char array that defines this DSString's contents
        DSString(const DSString &dopplerString); // Copy constructor of the DSString
                                                 // @param dopplerString: The DSString that the current string will copy from
        ~DSString(); // Overloaded destructor for the DSString
        DSString& operator = (const DSString &copy); // First Overloaded copy assigner operator for the DSString using another DSString
                                                     // @param copy: The DSString that the current string will copy from
        DSString& operator = (const char* copy); // Second Overloaded copy assigner operator for the DSString using a char array
                                                 // @param copy: The char array that defines this DSString's contents
        DSString operator + (const DSString &add); // Overloaded addition operator for the DSString
                                                   // @param add: The DSString whose contents will be added to the current DSString
        DSString operator += (const DSString &add); // Overloaded addition-assigner operator for the DSString
                                                    // @param add: The DSString whose contents will be added to the current DSString
        int getLength(); // Returns the length of the DSString
        bool operator == (const DSString &compare) const; // Overloaded equivalence operator for the DSString using another DSString
                                                          // @param compare: The DSString the current DSString will be compared to
        bool operator == (const char* &compare) const; // Overloaded equivalence operator for the DSString using a char array
                                                       // @param compare: The char array the current DSString will be compared to
        void print(); // Prints out the contents of the DSString's data
        DSString substring(int index, int strLength); // Creates a smaller DSString from the main DSString
                                                      // @param index: The first character of the new smaller DSString
                                                      // @param strLength: The length of the new smaller DSString
        char operator [] (const int index); // Returns the char found at a specific place in data
                                            // @param index: The place in data where the char will be found
        bool operator > (const DSString &other) const; // Overload "greater-than" operator for the DSString
                                                       // Returns whether or not the current DSString is bigger than the other
                                                       // @param other: The DSString the main DSString is being compared to
        bool operator < (const DSString &other) const; // Overload "greater-than" operator for the DSString
                                                       // Returns whether or not the current DSString is bigger than the other
                                                       // @param other: The DSString the main DSString is being compared to
        char* c_str(); // Returns the DSString's data as a separate char array
        void toLowercase(); // Turns all of the DSString's alphabetical chars into the lower-cased versions of themselves
        void removePunctuation(); // Removes all punctuations from the char array
};


#endif //S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
