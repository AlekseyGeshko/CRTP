#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "groupBy.h"
#include "readData.h"

namespace group {

    class groupByType final : public groupBy<groupByType> {
    private:
        using type_groups = std::unordered_map<std::string_view,
                std::pair<int, std::vector<const object *>>>;

        void createGroups(const std::vector<object>& data);

        void addElements(std::vector<const object *>& objects);

        void sortGroup(std::vector<const object *>& elements);
    public:
        explicit groupByType(int _need_objects);

        void group(const std::vector<object>& data);

        void printInFile(std::ofstream& out) const;

    private:
        type_groups my_groups;
        std::vector<const object *> difference_elements;
        int need_objects;
    };
}

