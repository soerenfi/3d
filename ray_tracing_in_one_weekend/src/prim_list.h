#ifndef PRIM_LIST_H
#define PRIM_LIST_H

#include "prim.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class prim_list : public prim {
    public:
        prim_list() {}
        prim_list(shared_ptr<prim> object) { add(object); }

        void clear() { objects.clear(); }
        void add(shared_ptr<prim> object) { objects.push_back(object); }

        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;

    public:
        std::vector<shared_ptr<prim>> objects;
};

bool prim_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) {
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif