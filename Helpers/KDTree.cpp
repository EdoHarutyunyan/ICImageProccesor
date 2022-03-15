#include "KDTree.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <vector>


KDNode::KDNode() = default;

KDNode::KDNode(const point_t& pt,
    const size_t& idx_,
    const KDNodePtr& left_,
    const KDNodePtr& right_)
{
    x = pt;
    index = idx_;
    left = left_;
    right = right_;
}

KDNode::KDNode(const pointIndex & pi, const KDNodePtr & left_,
    const KDNodePtr & right_)
{
    x = std::get<0>(pi);
    index = std::get<1>(pi);
    id = std::get<2>(pi);
    left = left_;
    right = right_;
}

KDNode::~KDNode() = default;

double KDNode::coord(const size_t & idx) { return x.at(idx); }
KDNode::operator bool() { return (!x.empty()); }
KDNode::operator point_t() { return x; }
KDNode::operator size_t() { return index; }
KDNode::operator pointIndex() { return pointIndex(x, index, id); }

KDNodePtr NewKDNodePtr() {
    KDNodePtr mynode = std::make_shared< KDNode >();
    return mynode;
}

inline double dist2(const point_t & a, const point_t & b) {
    double distc = 0;
    for (size_t i = 0; i < a.size(); i++) {
        double di = a.at(i) - b.at(i);
        distc += di * di;
    }
    return distc;
}

inline double dist2(const KDNodePtr & a, const KDNodePtr & b) {
    return dist2(a->x, b->x);
}

inline double dist(const point_t & a, const point_t & b) {
    return std::sqrt(dist2(a, b));
}

inline double dist(const KDNodePtr & a, const KDNodePtr & b) {
    return std::sqrt(dist2(a, b));
}

comparer::comparer(size_t idx_) : idx{ idx_ } {};

inline bool comparer::compare_idx(const pointIndex & a,  //
    const pointIndex & b)
{
    return (std::get<0>(a).at(idx) < std::get<0>(b).at(idx));  //
}

inline void sort_on_idx(const pointIndexArr::iterator & begin,  //
    const pointIndexArr::iterator & end,    //
    size_t idx) {
    comparer comp(idx);
    comp.idx = idx;

    using std::placeholders::_1;
    using std::placeholders::_2;

    std::nth_element(begin, begin + std::distance(begin, end) / 2,
        end, std::bind(&comparer::compare_idx, comp, _1, _2));
}

KDNodePtr KDTree::make_tree(const pointIndexArr::iterator & begin,  //
    const pointIndexArr::iterator & end,    //
    const size_t & length,                  //
    const size_t & level                    //
) {
    if (begin == end) {
        return NewKDNodePtr();  // empty tree
    }

    size_t dim = std::get<0>(*begin).size();

    if (length > 1) {
        sort_on_idx(begin, end, level);
    }

    auto middle = begin + (length / 2);

    auto l_begin = begin;
    auto l_end = middle;
    auto r_begin = middle + 1;
    auto r_end = end;

    size_t l_len = length / 2;
    size_t r_len = length - l_len - 1;

    KDNodePtr left;
    if (l_len > 0 && dim > 0) {
        left = make_tree(l_begin, l_end, l_len, (level + 1) % dim);
    }
    else {
        left = leaf;
    }
    KDNodePtr right;
    if (r_len > 0 && dim > 0) {
        right = make_tree(r_begin, r_end, r_len, (level + 1) % dim);
    }
    else {
        right = leaf;
    }

    // KDNode result = KDNode();
    return std::make_shared<KDNode>(*middle, left, right);
}

KDTree::KDTree(pointVec point_array)
{
    // iterators
    pointIndexArr arr;
    for (size_t i = 0; i < point_array.size(); i++) {
        arr.push_back(pointIndex(point_array.at(i).second, i, point_array.at(i).first));
    }

    auto begin = arr.begin();
    auto end = arr.end();

    size_t length = arr.size();
    size_t level = 0;  // starting

    root = KDTree::make_tree(begin, end, length, level);
}

KDNodePtr KDTree::nearest_(   //
    const KDNodePtr & branch,  //
    const point_t & pt,        //
    const size_t & level,      //
    const KDNodePtr & best,    //
    const double& best_dist   //
) {
    double d, dx, dx2;

    if (!bool(*branch)) {
        return NewKDNodePtr();  // basically, null
    }

    point_t branch_pt(*branch);
    size_t dim = branch_pt.size();

    d = dist2(branch_pt, pt);
    dx = branch_pt.at(level) - pt.at(level);
    dx2 = dx * dx;

    KDNodePtr best_l = best;
    double best_dist_l = best_dist;

    if (d < best_dist) {
        best_dist_l = d;
        best_l = branch;
    }

    size_t next_lv = (level + 1) % dim;
    KDNodePtr section;
    KDNodePtr other;

    // select which branch makes sense to check
    if (dx > 0) {
        section = branch->left;
        other = branch->right;
    }
    else {
        section = branch->right;
        other = branch->left;
    }

    // keep nearest neighbor from further down the tree
    KDNodePtr further = nearest_(section, pt, next_lv, best_l, best_dist_l);
    if (!further->x.empty()) {
        double dl = dist2(further->x, pt);
        if (dl < best_dist_l) {
            best_dist_l = dl;
            best_l = further;
        }
    }
    // only check the other branch if it makes sense to do so
    if (dx2 < best_dist_l) {
        further = nearest_(other, pt, next_lv, best_l, best_dist_l);
        if (!further->x.empty()) {
            double dl = dist2(further->x, pt);
            if (dl < best_dist_l) {
                best_dist_l = dl;
                best_l = further;
            }
        }
    }

    return best_l;
};

// default caller
KDNodePtr KDTree::nearest_(const point_t & pt) {
    size_t level = 0;
    // KDNodePtr best = branch;
    double branch_dist = dist2(point_t(*root), pt);
    return nearest_(root,          // beginning of tree
        pt,            // point we are querying
        level,         // start from level 0
        root,          // best is the root
        branch_dist);  // best_dist = branch_dist
};

point_t KDTree::nearest_point(const point_t & pt) {
    return point_t(*nearest_(pt));
}

size_t KDTree::nearest_id(const point_t& pt)
{
    return nearest_(pt)->id;
}

size_t KDTree::nearest_index(const point_t & pt) {
    return size_t(*nearest_(pt));
};

pointIndex KDTree::nearest_pointIndex(const point_t & pt) {
    KDNodePtr Nearest = nearest_(pt);
    return pointIndex(point_t(*Nearest), size_t(*Nearest), Nearest->id);
}
