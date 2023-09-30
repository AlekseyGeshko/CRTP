#include "writeData.h"

#include <fstream>
#include <vector>
#include <variant>

#include "readData.h"
#include "groupBy.h"
#include "groupByDistance.h"
#include "groupByTime.h"
#include "groupByType.h"
#include "groupByName.h"

using namespace group;
using namespace std;

namespace{
    using Grouping = variant<groupByType, groupByName, groupByTime, groupByDistance>;
}

writeData::writeData(const string& output_file): output(output_file){}

void writeData::writeIntoFile(const std::vector<object>& elements, int need_count) {
    vector<Grouping> groups = {groupByType{need_count}, groupByName{}, groupByTime{}, groupByDistance{}};
    for (auto &elem: groups) {
        std::visit([&](auto& elem){
            groupElements(elem, elements);
        }, elem);
        std::visit([&](auto& elem){
            printInFileElements(elem, output);
        }, elem);
    }
}

writeData::~writeData() {
    output.close();
}
