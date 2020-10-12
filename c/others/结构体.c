#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct Sutdent {
  char id[5];
  char name[10];
  int grade[3];
} Student;

void input(Student *student, int n) {
  for (int i = 0; i < n; ++i) {
    scanf("%s", student[i].id);
    scanf("%s", student[i].name);
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &student[i].grade[j]);
    }
  }
}

void average(Student *student, int n) {
  double ave[3], ave_max = -1;
  int sum1, sum2, index;
  //
  for (int i = 0; i < 3; ++i) {
    sum1 = 0;
    for (int j = 0; j < n; ++j) {
      sum1 += student[j].grade[i];
    }
    ave[i] = (double)(sum1 / n);
  }
  int k;
  for (k = 0; k < 2; ++k) {
    printf("%.0lf ", ave[k]);
  }
  printf("%.0lf\n", ave[k]);
  //
  for (int i = 0; i < n; ++i) {
    sum2 = 0;
    for (int j = 0; j < 3; ++j) {
      sum2 += student[i].grade[j];
    }
    if (sum2 > ave_max) {
      ave_max = sum2;
      index = i;
    }
  }
  //
  printf("%s %s", student[index].id, student[index].name);
  for (int i = 0; i < 3; ++i) {
    printf(" %d", student[index].grade[i]);
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  Student *stu = (Student *)malloc(sizeof(Student) * n);
  input(stu, n);
  average(stu, n);
  return 0;
}

// 3
// abc i 100 90 80
// def y 90 80 70
// ghi l 70 60 50