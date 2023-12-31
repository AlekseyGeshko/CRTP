#pragma once
#include <memory>
#include <vector>
#include <cmath>

#include "groupBy.h"

namespace group {

    class groupByDistance final : public groupBy<groupByDistance> {
    private:
        double returnDistanceObj(const object &obj) const;
        void sortGroups();
    public:
        void group(const std::vector<object> &data);

        void printInFile(std::ofstream &out) const;

    private:
        //рассматриваем расстояние от т. (0,0)
        std::vector<const object *> one_hundred;
        std::vector<const object *> two_hundred;
        std::vector<const object *> far_away;
    };
}
