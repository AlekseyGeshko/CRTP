#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>

#include "groupBy.h"

namespace group {

    class groupByName final : public groupBy<groupByName> {
    public:
        void group(const std::vector<object> &data);

        void printInFile(std::ofstream &out) const;

    private:
        void sortGroups();
        std::unordered_map<std::string, std::vector<const object *>> groups;
    };
}
