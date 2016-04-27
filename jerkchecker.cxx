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

jerk_t::jerk_t() : jerklist(0) {
    addJerk(PREDEFINED_JERK);
}
void jerk_t::addJerk(int userid) {
    if(isJerk(userid) == 0) jerklist.push_back(userid);
    return;
}
std::vector<int> jerk_t::getJerkList() {
    return jerklist;
}
int jerk_t::isJerk(int userid) {
    size_t jerkcount = jerklist.size();
    for(size_t i = 0; i<jerkcount; i++) {
        if(userid == jerklist[i]) return 1; //jerk is already in the list
    }
    return 0;
}
}
int main (int argc, char **argv) {
    if(argc == 3) {
        std::cout<<argv[1]<<std::endl;
        jerkchecker::jerk_t obj;
        if(obj.isJerk(std::stoi(argv[2])) )std::cout<<"Yep."<<std::endl;
        else std::cout<<"No."<<std::endl;
    return 0;
    }
}
/* output:
 *
 * $ ./jerkchecker 278846 22445
 * Yep.
 */
