#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Person{
public:
    int weight,tall;
    Person(int w, int t){
        weight = w;
        tall = t;
    }
};

void compareBig(int t)
{
    vector<Person> people;
    for (int x = 0; x < t; x++)
    {
        int weight, tall;
        cin >> weight >> tall;
        Person p(weight,tall);
        people.push_back(p);
    }
    
    for(int i = 0; i< people.size(); i++){
        int rank = 1;
        for(int j = 0; j < people.size();j++){
            if((people[j].tall > people[i].tall) && (people[j].weight > people[i].weight)){
                rank++;
            }
        }
        cout << rank << " ";
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    compareBig(t);
}