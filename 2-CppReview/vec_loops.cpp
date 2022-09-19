// 3 different ways of looping through a vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> my_vec = {"first", "second", "last"};

    //  1)  Loop by making a copy of each element in vector.
    //      Copy made is by value.
    //      Changes to the copy do not change the original element. 
    for (std::string s: my_vec)
    {
        s = s + "_copy";
        cout << s << endl;
    }

    //  2)  Loop by making s read-only using keyword const.
    //      s is still a copy of the elements in my_vec.
    for (const std::string s : my_vec)
    {
        s = s + "_copy";
        cout << s << endl;
    }

    // 3)   Pass by reference.
    //      Keyword 'auto' allows compiler to deduce the type of s
    //      References are FASTER and allow modification to the values stored
    //      in the container. Modification may or may not be desired.
    for (auto & s: my_vec)
    {
        s = "new string";
        cout << s << endl;
    }

    // 4)   Pass by constant reference
    //      Values of container cannot be modified
    //      Ideal implementation because it is SAFE and FAST
    for (const auto & s : my_vec)
        cout << s << endl;

    // std::unordered_map<std::vector<std::pair<int, std::string>>> myMap;
}