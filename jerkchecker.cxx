/** Copyright (C) 2016 duelistgamer
 * Licensed under GPLv2. Re-licensing under the terms of later revisions of
 * the GPL is expressly forbidden under all circumstances.
 *
 * Full text of the GPLv2 can be found here:
 * https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html
 */

#include<iostream>
#include<vector>
#define PREDEFINED_JERK 22445

namespace jerkchecker {
/* contains:
 * vector<int> jerklist that stores the list of jerks
 * void addJerk() add a jerk
 * int isJerk() check if someone is a jerk
 * vector<int> getJerkList() get a copy of the current
 * list of jerks
 */
typedef struct jerk_t jerk_t;
struct jerk_t {
    jerk_t();
private:
    std::vector<int> jerklist;
public:
    void addJerk(int userid);
    int isJerk(int userid);
    std::vector<int> getJerkList();
};

/* constructor, initializes the list of jerks as empty
 * and then adds predefined jerks during run time
 * If you need to add more jerks, change the definition of
 * PREDEFINED_JERK to be an array of jerks, and overload
 * addJerk() to one that works with a collection of userids
 */
jerk_t::jerk_t(): jerklist(0) {
    addJerk(PREDEFINED_JERK);
}

/* void jerk_t::addJerk(int userid): adds a jerk to the list if that jerk does
 * not already exist in the list
 * int userid: the id# of the jerk
 *
 * this function does not return any value
 */
void jerk_t::addJerk(int userid) {
    if(isJerk(userid) == 0) jerklist.push_back(userid);
    return;
}

/* std::vector<int> jerk_t::getJerkList(): when called, returns a copy
 * of the list of jerks
 * this function takes no arguments
 * this function returns a value of type vector<int>
 */
std::vector<int> jerk_t::getJerkList() {
    return jerklist;
}

/* int jerk_t::isJerk(int userid): Checks if a user is a jerk
 * int userid: the id# of the person you suspect to be a jerk
 * the function returns 1 if the jerk is in the list,
 * and 0 if not
 */
int jerk_t::isJerk(int userid) {
    for(const auto& i: jerklist) if(userid == i) return 1; 
    // jerk is already in the list  ^^^^^^^^^
    return 0;
}
}

/** WARNING: Please only use valid arguments. Invalid input is
 * untested.
 *
 * main function to check if the program works correctly. prints
 * the first number you enter as an argument, checks if the second
 * one is in the list and adds three more jerks to the list before
 * printing the list.
 * argc: the number of arguments. it has to be exactly 3
 * for the program to work, provided your arguments are not
 * invalid.
 * argv[0] is the name of the executable
 * argv[1] is a string that is not the id# of a jerk
 * argv[2] contains the id# of the jerk you want to add
 * to your list
 * 
 * returns 0 on successful use, -1 on erroneous input
 */
int main (int argc, char **argv) {
    if(argc == 3) {
        std::cout<<argv[1]<<std::endl;
        jerkchecker::jerk_t obj;
        if(obj.isJerk(std::stoi(argv[2]))) std::cout<<"Yep."<<std::endl;
        else std::cout<<"No."<<std::endl;
        obj.addJerk(50);
        obj.addJerk(70);
        obj.addJerk(99);
        std::vector<int> jerklistcpy = obj.getJerkList();
        std::cout<<"jerklist:"<<std::endl;
        for(const auto& i: jerklistcpy) std::cout<<i<<std::endl;
        return 0;
    }
    //invalid number of arguments
    return -1;
}
/* output:
 *
 * $ ./jerkchecker 278846 22445
 * 278846
 * Yep.
 * jerklist:
 * 22445
 * 50
 * 70
 * 99
 */
