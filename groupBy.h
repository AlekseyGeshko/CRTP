#pragma once
#include <algorithm>
#include "readData.h"

namespace group {
    template<class ChildOption>
    class groupBy {
    public:
        void group(const std::vector<object> &data);

        void printInFile(std::ofstream &out) const;
    };

    inline void printGroup(const std::vector<const object *> &elements, std::ofstream &out) {
        for (const object *elem: elements) {
            out << *elem;
        }
        out << std::endl;
    }

    template<class ChildOption>
    void groupBy<ChildOption>::group(const std::vector<object> &data) {
        static_cast<ChildOption*>(this)->group(data);
    }

    template<class ChildOption>
    void groupBy<ChildOption>::printInFile(std::ofstream &out) const {
        static_cast<const ChildOption*>(this)->printInFile(out);
    }

    template<class T>
    void groupElements(groupBy<T>& groupByObj, const std::vector<object>& elements){
        groupByObj.group(elements);
    }

    template<class T>
    void printInFileElements(const groupBy<T>& groupByObj, std::ofstream& output){
        groupByObj.printInFile(output);
    }
}
