## Tips

* 연산이 int의 범위를 벗어날 수 있음으로 1LL를 곱해 long long으로 타입캐스팅 후 연산을 수행

* cin, cout보다 scanf, printf가 입출력이 더 빠름
* sort() 함수 세번째 파라미터에 비교 함수를 넣어줌으로써 해당 함수의 정의된 조건을 기준으로 정렬

* stable_sort()를 이용함으로써 기존 배열에서의 순서 유지
* 비교 연산자를 재정의하면 sort() 함수가 재정의된 조건으로 정렬함
* 공백을 의미하는 아스키 코드 == 32
* 공백을 포함한 입력 받기 -> cin.getline()
* 'cout << fixed;', 'cout.precision(n);'을 통해 소수점 아래 자릿수 설정
* 'cin.tie(0);', 'cout.tie(0);', 'ios::sync_with_stdio(0);'을 통해 입출력 버퍼 최소화
* '\#include <bits/stdc++.h>'을 통해 웬만한 라이브러리 import
* char 타입의 숫자를 int 타입의 숫자로 변환 -> c - '0'
* *max_element()를 통해 컨테이너에 있는 원소들 중 가장 큰 원소 반환
* typedef를 통해 코드 내에서 타입의 이름을 정의 -> 코드 작성의 편리성 증가
* upper_bound(), lower_bound() 함수는 배열을 정렬한 뒤 사용
* upper_bound() -> 찾으려는 값을 처음으로 초과하는 위치를 반환
* lower_bound() -> 찾으려는 값 이상이 처음 나타나는 위치를 반환
* lower_bound() -> 찾으려는 값이 없으면 해당 값보다 큰 원소들 중 가장 작은 원소의 위치를 반환
* 벡터에서 *_bound() 함수를 통해 index를 받아오는 법 -> 'int idx = *_bound(v.begin(), v.end(), toFind) - v.begin();'
* LLONG_MIN / LLONG_MAX -> long long 타입에서의 최솟값/최댓값
* pair<type, type>을 사용하여 한 원소에 두개의 정보를 담을 수 있음
