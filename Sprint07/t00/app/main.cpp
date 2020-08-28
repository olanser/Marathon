#include <vector>

#include "check.h"
#include "Vector.h"
using namespace CBL;


template <typename T>
void cycles(std::vector<T> &std_v, Vector<T> &our_v) {
    ASSERT_EQUAL(std_v.size(), our_v.size());
    for (size_t i = 0; i < std_v.size(); i++) {
        ASSERT_EQUAL(std_v[i], our_v[i]);
    }
}

int main() {

    /// int
    {

        std::vector<int> std_v = {1, 2, 3, 4, 5};
        Vector<int> our_v = {1, 2, 3, 4, 5};
        Vector<int> our_v2;
        std::vector<int> std_v2;
        std_v2 = std_v;
        our_v2 = our_v;

        cycles(std_v2, our_v2);
        ASSERT_EQUAL(std_v2[std_v2.size() - 1], our_v2[our_v2.size() - 1]);
        ASSERT_EQUAL(std_v2.size(), our_v2.size());
        ASSERT_EQUAL(std_v2.capacity(), our_v2.capacity());
        {
            ASSERT_EQUAL(std_v.size(), our_v.size());
            ASSERT_EQUAL(std_v.capacity(), our_v.capacity());
            ASSERT_EQUAL(std_v[0], our_v[0]);
            std_v.push_back(1);
            our_v.push_back(1);
            ASSERT_EQUAL(std_v[std_v.size() - 1], our_v[our_v.size() - 1]);
            std_v.pop_back();
            our_v.pop_back();
            ASSERT_EQUAL(std_v[std_v.size() - 1], our_v[our_v.size() - 1]);
            cycles(std_v, our_v);
            ASSERT_EQUAL(std_v.size(), our_v.size());
            ASSERT_EQUAL(std_v.capacity(), our_v.capacity());
        }

        {
            std::vector<int> std_v1(10);
            Vector<int> our_v1(10);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());

        }

        {
            std::vector<int> std_v1(10, 10);
            Vector<int> our_v1(10, 10);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
             ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<int> std_v1{std_v.begin(), std_v.begin() + 2};
            Vector<int> our_v1{our_v.begin(), our_v.begin() + 2};
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<int> std_v1 = std_v;
            Vector<int> our_v1 = our_v;
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            ASSERT_EQUAL(std_v.capacity(), our_v.capacity());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }
        {
            std::vector<int> std_v1;
            Vector<int> our_v1;
            ASSERT_EQUAL(our_v.isEmpty(), std_v.empty());
            ASSERT_EQUAL(our_v1.isEmpty(), std_v1.empty());
            cycles(std_v1, our_v1);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
        }

        {
            std::vector<int> std_v1 = std_v;
            Vector<int> our_v1 = our_v;
            std_v1.reserve(100);
            our_v1.reserve(100);
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            cycles(std_v1, our_v1);
        }

        {
            std::vector<int> std_v1 = std_v;
            Vector<int> our_v1 = our_v;
            std_v1.resize(100, 10);
            our_v1.resize(100, 10);
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<int> std_v1 = std_v;
            Vector<int> our_v1 = our_v;
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            std_v1.insert(std_v1.begin() + 3, 8);
            our_v1.insert(our_v1.begin() + 3, 8);
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[3], our_v1[3]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<int> std_v1 = std_v;
            Vector<int> our_v1 = our_v;
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            std_v1.erase(std_v1.begin() + 3, std_v1.begin() + 4);
            our_v1.erase(our_v1.begin() + 3, our_v1.begin() + 4);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[3], our_v1[3]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<int> std_v1 = std_v;
            Vector<int> our_v1 = our_v;
            std_v1.erase(std_v1.begin() + 3);
            our_v1.erase(our_v1.begin() + 3);
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[3], our_v1[3]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }
        {
            std::vector<int> std_v1 = std_v;
            Vector<int> our_v1 = our_v;
            std_v1.clear();
            our_v1.clear();
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1.empty(), our_v1.isEmpty());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }
    }

    // //////string

    {
        std::vector<std::string> std_v = {"1", "2", "3", "4", "5"};
        Vector<std::string> our_v = {"1", "2", "3", "4", "5"};

        {
            ASSERT_EQUAL(std_v.size(), our_v.size());
            ASSERT_EQUAL(std_v[0], our_v[0]);
            ASSERT_EQUAL(std_v.capacity(), our_v.capacity());
            std_v.push_back("1");
            our_v.push_back("1");
            ASSERT_EQUAL(std_v.capacity(), our_v.capacity());
            ASSERT_EQUAL(std_v[std_v.size() - 1], our_v[our_v.size() - 1]);
            std_v.pop_back();
            our_v.pop_back();
            ASSERT_EQUAL(std_v.capacity(), our_v.capacity());
            ASSERT_EQUAL(std_v[std_v.size() - 1], our_v[our_v.size() - 1]);
            cycles(std_v, our_v);
        }

        {
            std::vector<std::string> std_v1(10);
            Vector<std::string> our_v1(10);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
        }

        {
            std::vector<std::string> std_v1(10, "10");
            Vector<std::string> our_v1(10, "10");
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<std::string> std_v1{std_v.begin(), std_v.begin() + 2};
            Vector<std::string> our_v1{our_v.begin(), our_v.begin() + 2};
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<std::string> std_v1 = std_v;
            Vector<std::string> our_v1 = our_v;
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }
        {
            std::vector<std::string> std_v1;
            Vector<std::string> our_v1;
            ASSERT_EQUAL(our_v.isEmpty(), std_v.empty());
            ASSERT_EQUAL(our_v1.isEmpty(), std_v1.empty());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<std::string> std_v1 = std_v;
            Vector<std::string> our_v1 = our_v;
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            std_v1.reserve(100);
            our_v1.reserve(100);
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<std::string> std_v1 = std_v;
            Vector<std::string> our_v1 = our_v;
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            std_v1.resize(100, "10");
            our_v1.resize(100, "10");
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[0], our_v1[0]);
            cycles(std_v1, our_v1);
        }

        {
            std::vector<std::string> std_v1 = std_v;
            Vector<std::string> our_v1 = our_v;
            std_v1.insert(std_v1.begin() + 3, "8");
            our_v1.insert(our_v1.begin() + 3, "8");
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            ASSERT_EQUAL(std_v1[3], our_v1[3]);
            cycles(std_v1, our_v1);
        }

        {
            std::vector<std::string> std_v1 = std_v;
            Vector<std::string> our_v1 = our_v;
            std_v1.erase(std_v1.begin() + 3, std_v1.begin() + 4);
            our_v1.erase(our_v1.begin() + 3, our_v1.begin() + 4);
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[3], our_v1[3]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }

        {
            std::vector<std::string> std_v1 = std_v;
            Vector<std::string> our_v1 = our_v;
            std_v1.erase(std_v1.begin() + 3);
            our_v1.erase(our_v1.begin() + 3);
            ASSERT_EQUAL(std_v1[std_v1.size() - 1], our_v1[our_v1.size() - 1]);
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1[3], our_v1[3]);
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }
        {
            std::vector<std::string> std_v1 = std_v;
            Vector<std::string> our_v1 = our_v;
            std_v1.clear();
            our_v1.clear();
            ASSERT_EQUAL(std_v1.size(), our_v1.size());
            ASSERT_EQUAL(std_v1.empty(), our_v1.isEmpty());
            ASSERT_EQUAL(std_v1.capacity(), our_v1.capacity());
            cycles(std_v1, our_v1);
        }
    }
}