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