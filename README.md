의도는 C++ 라이브러리로 핵심 기능 구현하고 블루프린트로 호출해서 구현

C++ 라이브러리 구현 내용

1. GenerateRandomNumber()
1~9 사이의 숫자 3개를 중복 없이 생성

게임 시작 시 정답 숫자 설정에 사용

3. ExtractValidNumber(Input)
사용자 입력을 필터링 및 유효성 검사
숫자 3자리(1~9) 중복 없이 구성되어야 유효

4. EvaluateGuess(Secret, Guess, AttemptCount, Result, OutCount)
정답과 사용자 입력을 비교하여 Strike / Ball / Out 판정
시도 횟수 및 아웃 카운트에 따라 승패 결정 ("Win!", "Lose!", 혹은 진행 중인 결과 텍스트 반환)

5. HandleMessageFromClient(Input, Secret, AttemptCount, OutCount, Result, bShouldReset)
채팅 입력 처리 핵심 함수
유효성 검사 → 판정 → 결과 문자열 구성

게임이 리셋되어야 하는지 여부(bShouldReset)를 판단

5. ResetGame
게임 상태 초기화 (정답 숫자 재생성, 시도 횟수 초기화 등)

블루프린트 구현 내용
1.SecretNumber 저장	
C++에서 생성한 정답 숫자를 저장하고 유지

2.AttemptCount / OutCount 관리	
시도 횟수 및 아웃 횟수를 변수로 저장

3.채팅 입력 처리
플레이어가 입력한 메시지를 C++로 전달

4.HandleMessageFromClient 호출
채팅 입력을 분석하여 C++ 라이브러리 함수 호출

5.Result 출력
C++에서 반환된 결과 문자열을 UI(채팅창 등)에 출력

다 되어간다고 생각 될 쯤에 뭐 하나 고쳐보려다 갈아 엎기만 하고
결과적으로 잘 안되어서 블루프린트 찌꺼기만 남은 사진
![Image](https://github.com/user-attachments/assets/60ffccf7-1e48-4e85-bf8f-c4757fc44c31)

포기하고 튜터님 강의를 따라서 천천히 이해하면서 해보니,  혼자 했던 과정들도 잘 되어가다 망친게 아니라 큰 그림부터 잘못 그리고 시작했다는 생각이 든다.
