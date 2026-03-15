#include <stdio.h>
#include <string.h>

#define MAX_SCHEDULES 100

typedef struct {
    char title[50];
    char date[20];
    char time[10];
    char desc[100];
} Schedule;

Schedule list[MAX_SCHEDULES];
int count = 0;

// 일정 추가
void addSchedule() {
    if (count >= MAX_SCHEDULES) {
        printf("\n[오류] 저장 공간이 가득 찼습니다.\n");
        return;
    }
    printf("\n--- 일정 추가 ---\n");
    printf("제목: "); scanf(" %[^\n]s", list[count].title);
    printf("날짜(YYYY-MM-DD): "); scanf("%s", list[count].date);
    printf("시간(HH:MM): "); scanf("%s", list[count].time);
    printf("설명: "); scanf(" %[^\n]s", list[count].desc);
    count++;
    printf("일정이 성공적으로 추가되었습니다!\n");
}

// 일정 조회
void showSchedules() {
    printf("\n--- 일정 목록 ---\n");
    if (count == 0) {
        printf("저장된 일정이 없습니다.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("[%d] 제목: %s | 날짜: %s | 시간: %s\n", i + 1, list[i].title, list[i].date, list[i].time);
        printf("    설명: %s\n", list[i].desc);
    }
}

// 일정 수정
void updateSchedule() {
    int index;
    showSchedules();
    if (count == 0) return;
    
    printf("\n수정할 일정 번호를 선택하세요: ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("잘못된 번호입니다.\n");
        return;
    }
    
    index--; // 배열 인덱스 맞춤
    printf("새 제목: "); scanf(" %[^\n]s", list[index].title);
    printf("새 날짜(YYYY-MM-DD): "); scanf("%s", list[index].date);
    printf("새 시간(HH:MM): "); scanf("%s", list[index].time);
    printf("새 설명: "); scanf(" %[^\n]s", list[index].desc);
    printf("수정이 완료되었습니다!\n");
}

// 일정 삭제
void deleteSchedule() {
    int index;
    showSchedules();
    if (count == 0) return;
    
    printf("\n삭제할 일정 번호를 선택하세요: ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("잘못된 번호입니다.\n");
        return;
    }
    
    for (int i = index - 1; i < count - 1; i++) {
        list[i] = list[i + 1];
    }
    count--;
    printf("일정이 삭제되었습니다.\n");
}

int main() {
    int menu;
    while (1) {
        printf("\n[일정 관리 프로그램]");
        printf("\n1.추가 2.조회 3.수정 4.삭제 0.종료\n메뉴 선택: ");
        scanf("%d", &menu);
        
        if (menu == 1) addSchedule();
        else if (menu == 2) showSchedules();
        else if (menu == 3) updateSchedule();
        else if (menu == 4) deleteSchedule();
        else if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}