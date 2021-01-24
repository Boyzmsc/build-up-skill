#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <deque>

using namespace std;

class Person
{
public:
    int index;
    string name;
    Person(int i, string n)
    {
        index = i;
        name = n;
    }
};

bool cmp(const Person &p1, const Person &p2)
{
    if (p1.index < p2.index){
        return true;
    }else{
        return false;
    }
}

void sortPeople(int n)
{
    vector<Person> people;
    while (n--)
    {
        int num;
        string name;
        cin >> num >> name;
        Person p(num, name);
        people.push_back(p);
    }

    // sort 함수 세번째 인자에 비교 함수를 넣어줌으로써
    // 해당 함수의 정의된 조건을 기준으로 정렬
    stable_sort(people.begin(), people.end(), cmp);

    for (int i = 0; i < people.size(); i++)
    {
        cout << people[i].index << " " << people[i].name << '\n';
    }
}

int main()
{
    int n;
    cin >> n;
    sortPeople(n);
}