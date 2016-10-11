#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class solution {
  public:
    int combSum(const vector<int> & nums, int target) {
        vector<vector<int>> combs = buildFrom(nums, target);
        for (auto comb : combs) {
            std::for_each(comb.begin(), comb.end(), [](int i){std::cout << i << " ";});
            std::cout << std::endl;
        }

        return combs.size();
    }

  private:
    vector<vector<int>> buildFrom(const vector<int> & nums, int target) {
        // std::cout << "target = " << target << std::endl;
        vector<vector<int>> result;
        if (target == 0)
            result.push_back(vector<int>());
        else {
            vector<int> next;
            for(auto n : nums)
                if (n <= target)
                    next.push_back(n);
            if (next.empty())
                return result;
            else {
                for (auto nx : next) {
                    auto temp = buildFrom(nums, target-nx);
                    for (auto tmp : temp) {
                        tmp.insert(tmp.begin(), nx);
                        result.push_back(tmp);
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{1,2,3};
    int target = 4;

    solution soln;
    int combs = soln.combSum(nums, target);
    std::cout << "The total number of combinations is:" << std::endl;
    std::cout << combs << std::endl;
}
