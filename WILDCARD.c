#include <stdio.h>
#pragma warning(disable:4996)
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>


void SetPatternEnd(); // 패턴을 patternEnd에 반대로 저장한다.
bool CompareBasicPattern(int point); // 패턴과 문자열을 비교한다. 문자, ?, * 비교


char pattern[30] = { '\0', }; // 와일드 카드 값 (즉, 검색할 패턴)
char patternEnd[30] = { '\0', }; // 반대로 저장된 패턴
char data[100][30] = { '\0', }; // 비교할 문자열들
char dataCopy[30] = { '\0', }; // 임시로 복사해둔 문자열, data에서 비교된 문자가 패턴에 적합하면 result에 복사된다. data배열은 비교중에 데이터가 변경되므로, 변경되지 않은 원본을 따로 저장하는 역할을 한다.

char result[100][30] = { '\0', }; // 결과 문자열들

int patternCounter = 0; // 패턴의 카운터
int patternEndCounter = 0; // 패턴의 뒤쪽부터의 카운터
int dataEndCounter = 0; // 문자열의 뒤쪽부터의 카운터
int N = 0; // 파일로 부터 입력받은 파일의 개수
int resultCounter = 0; // 결과 문자열의 개수

int main()
{
	bool flagEnd = true, onStarSearch = false;
	int patternPointer = 0;
	int dataPointer = 0;
	int tempPattern = -1;
	int C;
	scanf("%d", &C);

	for (int i = 0; i < C; i++)
	{

		scanf("%s", &pattern);

		scanf("%d", &N);
		for (int i = 0; i < N; i++) {

			scanf("%s", &pattern);
			strcpy(data, dataCopy[i]);
			dataEndCounter = strlen(data[i]) - 1;

			flagEnd = CompareBasicPattern(i); // 패턴과 문자열 비교

			while (flagEnd == true)
			{
				if (pattern[patternPointer] != '*' && pattern[patternPointer] != '?' && pattern[patternPointer] != 0) // patter이 *,? 이 아니라면
				{

					if (onStarSearch == false) //'*'가 앞에 없을 경우
					{
						if (pattern[patternPointer] == data[i][dataPointer]) // 패턴과 문자열의 문자가 같다면
						{

							dataPointer++; // 문자열의 다음 문자로 이동
							patternPointer++;// 패턴의 다음 문자로 이동

						}
						else // 같지 않다면
						{

							if (data[i][dataPointer] == '\0') // 문자열이 끝났다면 종료
								break;

							dataPointer++; // 문자열의 다음 포인터로 이동

							if (tempPattern >= 0)
								patternPointer = tempPattern;
							else
								break;

						}
					}
					else // '*' 가 앞에 있을 경우
					{
						while (pattern[patternPointer] != data[i][dataPointer]) // 패턴과 문자열의 데이터가 같지 않다면
						{

							dataPointer++; // 문자열의 데이터만 포인터를 중가시킨다.

							if (data[i][dataPointer] == '\0') // 문자열이 끝났다면 종료
								break;
						}

						if (data[i][dataPointer] == '\0') // 문자열이 끝났다면 종료
							break;

						dataPointer++; // 문자열의 데이터와 패턴의 포인터를 모두 증가시킨다. 
						patternPointer++;
						onStarSearch = false; // * 탐색 종료
					}
				}
				else if (pattern[patternPointer] == '?') // 패턴에 ?가 있다면
				{

					if (data[i][dataPointer] == '\0') // 문자열이 끝났다면 종료
						break;
					else // 그렇지 않다면 문자열의 데이터와 패턴의 포인터를 모두 증가시킨다.
					{
						dataPointer++;
						patternPointer++;
					}

				}
				else if (pattern[patternPointer] == '*') // 패턴에 *가 있다면
				{
					onStarSearch = true; // * 검색모드를 true
					tempPattern = patternPointer;
					patternPointer++;
				}
				else if (pattern[patternPointer] == 0) // 패턴의 비교가 모두 끝났다면, 더이상 비교할 패턴의 문자가 없다면
				{

					if (onStarSearch != true) // * 검색중이 아니었다면, 패턴에 적합한 문자열 처리
					{
						if (data[i][dataPointer] == 0) // 데이터(data)의 문자열의 문자가 모두 소진되었다면
						{

							strcpy(result[resultCounter++], dataCopy); // 결과 리스트에 포함
							break;

						}
						else // 결과 리스트에 포함시키지 않는다.
							break;

					}
					else // * 검색 중이었다면
					{
						strcpy(result[resultCounter++], dataCopy); // 결과 리스트에 포함
						break;
					}
				}
			}
			// 데이터 초기화
			patternPointer = dataPointer = 0;
			tempPattern = -1;
			flagEnd = true;
			onStarSearch = false;
		}
		for (int i = 0; i < resultCounter; i++)
			printf("%s\n", result[i]); // 화면에 출력

	}

void SetPatternEnd() // 패턴을 반대로 저장
{

	while (pattern[patternCounter] != '*') // 패턴의 문자중에서 '*'가 나올때까지 (pattern의 뒤에서부터 문자를 읽는다.)
	{

		patternEnd[patternEndCounter] = pattern[patternCounter]; // pattern의 뒤에서부터 읽은 문자를 patternEnd의 앞쪽부터 쓴다.
		pattern[patternCounter] = '\0'; // pattern에서 읽은 데이터는 지운다.

		patternCounter--; // 배열의 이동
		patternEndCounter++;

	}

}

bool CompareBasicPattern(int point) // 기본적인 패턴 비교
{
	while (patternEnd[patternEndCounter] != '\0') // 패턴(반대로 저장된)에 문자가 남아있다면
	{

		if (data[point][dataEndCounter] == patternEnd[patternEndCounter]) // 패턴(반대로 저장된)과 문자열의 문자가 같다면, 뒤에서부터 비교
		{

			dataEndCounter--;
			patternEndCounter++;

		}
		else if (patternEnd[patternEndCounter] == '?') // 패턴(반대로 저장된)에 ?가 나왔다면 
		{

			dataEndCounter--;
			patternEndCounter++;

		}
		else
			return false;

	}

	return true;

}
