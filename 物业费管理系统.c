#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode
{
    char name[10];
    char sex[5];
    char idcard[20];
    char phnum[15];
    int num_build;
    int num_d;
    int num_room;
    float area;
    float area_money;
    float all_money;
    char b[1000];

    struct LNode *next;
} person;

void menu();                    // 菜单
void add(person **head);        // 添加用户
void output(person *phead);     // 打印信息
void change(person **head);     // 修改信息
void delete(person **head);     // 删除信息
void save(person *head);        // 保存到文件
void dread(person **head);      // 从文件中读取数据到链表
void sort(person *head);        // 排序后，打印排序后的内容
void auto_money(person **head); // 读取系统时间，每月1号自动叠加
void stat(person *head);        // 统计楼栋，然后打印
void pay(person **head);
void password(char *userpassword); // 输入隐化

int main()
{
    int i, n, flag;
    char user[20];
    char userpassword[20];
    person *list;
    list = NULL;
    dread(&list);
    auto_money(&list);
    getchar();
    printf("请输入你的用户名>: ");
    gets(user);

    if (!strcmp(user, "baby"))
    {
        printf("请输入你的密码>: ");
        password(userpassword);

        printf("登录成功\n");
        Sleep(1000);
        system("cls");
        printf("正在登录，请稍后...........\n");
        for (i = 3; i > 0; i--)
        {
            printf("%d\n", i);
            Sleep(1000);
        }

        while (1)
        {
            system("cls");
            menu();
            scanf("%d", &flag);
            system("cls");
            switch (flag)
            {
            case 1:
                output(list);
                break;
            case 2:
                add(&list);
                break;
            case 3:
                delete (&list);
                break;
            case 4:
                change(&list);
                break;
            case 5:
                printf("每栋统计结果如下：\n");
                stat(list);
                break;
            case 6:
                sort(list);
                break;
            case 7:
                pay(&list);

                break;
            case 8:
                save(list);
                printf("退出成功，欢迎下次再来哟~~");
                exit(0);
                break;
            default:
                printf("输入错误！请重新输入！");
                Sleep(1000);
                break;
            }
        }
    }
    else
    {
        printf("用户名错误!");
        exit(0);
    }

    return 0;
}

void menu()
{
    printf("**************************欢迎进入小区物业管理系统***************************\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("* * * * * * * * * * * * * * * * * *请选择* * * * * * * * * * * * * * * * * * * *\n");
    printf("*                                                                              *\n");
    printf("*                             (1)  打印信息                                    *\n");
    printf("*                                                                              *\n");
    printf("*                             (2）增添用户                                     *\n");
    printf("*                                                                              *\n");
    printf("*                             (3）删除用户                                     *\n");
    printf("*                                                                              *\n");
    printf("*                            （4）修改用户信息                                 *\n");
    printf("*                                                                              *\n");
    printf("*                            （5）统计每栋未交清人数                           *\n");
    printf("*                                                                              *\n");
    printf("*                            （6）以拖欠物业多少排序                           *\n");
    printf("*                                                                              *\n");
    printf("*                            （7）缴费                                         *\n");
    printf("*                                                                              *\n");
    printf("*                            （8）保存文件, 并退出                             *\n");
    printf("*                                                                              *\n");
    printf("* * * * * * * * * * * * * * * * * *请选择* * * * * * * * * * * * * * * * * * * *\n");
    printf("请您输入选项:");
}

void password(char *userpassword)
{
    int i = 0;
    while (1)
    {
        userpassword[i] = getch();
        if (userpassword[i] == '\r')
            break;
        else if (userpassword[i] == '\b')
        {
            if (i == 0)
                continue;
            printf("\b");
            printf(" ");
            printf("\b");
            i--;
        }
        else
        {
            printf("*");
            i++;
        }
    }
    userpassword[i] = '\0';
    printf("\n");
    if (strcmp(userpassword, "123456789"))
    {
        printf("密码错误！");
        exit(0);
    }
}
void add(person **head)
{
    int a;
    person *cur = NULL;
    printf("请分别输入户主姓名、性别、身份证号、联系电话、楼号、单元号、房号、住房面积，每平方米物业费、应缴纳物业费、备注\n");
    printf("您想要添加几人？\n>>:");
    scanf("%d", &a);
    getchar();
    for (int i = 0; i < a; i++)
    {
        cur = (person *)malloc(sizeof(person));
        printf("请输入姓名: ");
        scanf("%s", cur->name);
        printf("请输入性别: ");
        scanf("%s", cur->sex);
        printf("请输入身份证: ");
        scanf("%s", cur->idcard);
        printf("请输入业主电话: ");
        scanf("%s", cur->phnum);
        printf("请输入楼号: ");
        scanf("%d", &cur->num_build);
        printf("请输入单元号: ");
        scanf("%d", &cur->num_d);
        printf("请输入房号 ");
        scanf("%d", &cur->num_room);
        printf("请输入住房面积: ");
        scanf("%f", &cur->area);
        printf("请输入单位物业费: ");
        scanf("%f", &cur->area_money);
        printf("请输入备注： ");
        scanf("%s", cur->b);
        cur->all_money = (cur->area * cur->area_money);
        cur->next = NULL;
        printf("\n");

        if (*head == NULL)
        {
            *head = cur;
        }
        else
        {
            cur->next = *head;
            *head = cur;
        }
    }
    printf("输入完成，正在退出，请稍后.........");
    Sleep(1000);
    system("cls");
}
void output(person *phead)
{
    person *cur;
    char n[10];
    cur = phead;
    printf("姓名\t性别\t身份证号\t\t电话号码\t楼号\t单元号\t房号\t平方米数\t每平方米物业价格\t应缴物业费\t备注\n");
    while (cur != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%0.2f\t\t%0.2f\t\t\t%0.2f\t\t%s\n", cur->name, cur->sex, cur->idcard, cur->phnum, cur->num_build, cur->num_d, cur->num_room, cur->area, cur->area_money, cur->all_money, cur->b);
        cur = cur->next;
    }
    printf("\n");

    while (1)
    {
        printf("\n\n\n\n");
        printf("请输入exit退出: \n");
        scanf("%s", n);

        if (!strcmp(n, "exit"))
            return;
    }
}

void change(person **head)
{
    char name[10];
    printf("请输入你想要修改的人的姓名>: ");
    scanf("%s", name);
    person *cur;
    cur = *head;

    printf("查询到以下数据：\n");
    printf("姓名\t性别\t身份证号\t\t电话号码\t楼号\t单元号\t房号\t平方米数\t每平方米物业价格\t应缴物业费\t备注\n");
    int a, b;
    while (cur != NULL)
    {
        if (!strcmp(cur->name, name))
        {
            printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%0.2f\t\t%0.2f\t\t\t%0.2f\t\t%s\n", cur->name, cur->sex, cur->idcard, cur->phnum, cur->num_build, cur->num_d, cur->num_room, cur->area, cur->area_money, cur->all_money, cur->b);
        }
        cur = cur->next;
    }
    cur = *head;
    printf("\n\n\n请具体输入你想要删除对象的单元号和房号：");
    scanf("%d %d", &a, &b);

    system("cls");
    while (cur != NULL)
    {
        if ((!strcmp(cur->name, name)) && a == cur->num_d && cur->num_room == b)
        {
            printf("请输入要更改的信息\n");
            printf("请输入姓名: ");
            scanf("%s", cur->name);
            printf("请输入性别: ");
            scanf("%s", cur->sex);
            printf("请输入身份证: ");
            scanf("%s", cur->idcard);
            printf("请输入业主电话: ");
            scanf("%s", cur->phnum);
            printf("请输入楼号: ");
            scanf("%d", &cur->num_build);
            printf("请输入单元号: ");
            scanf("%d", &cur->num_d);
            printf("请输入房号 ");
            scanf("%d", &cur->num_room);
            printf("请输入住房面积: ");
            scanf("%f", &cur->area);
            printf("请输入单位物业费: ");
            scanf("%f", &cur->area_money);
            printf("请输入备注： ");
            scanf("%s", cur->b);
            printf("\n");
            cur->all_money = cur->area * cur->area_money;

            break;
        }

        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("未查询到此人");
        Sleep(2000);
        system("cls");
        return;
    }
    printf("修改完成，正在退出，请稍后.........");
    Sleep(1000);
    system("cls");
}

void delete(person **head)
{
    char name[10];

    person *cur, *p;
    cur = *head;
    printf("请输入你想要删除的对象的姓名: ");
    scanf("%s", name);

    printf("查询到以下数据：\n");
    printf("姓名\t性别\t身份证号\t\t电话号码\t楼号\t单元号\t房号\t平方米数\t每平方米物业价格\t应缴物业费\t备注\n");
    int a, b;
    while (cur != NULL)
    {
        if (!strcmp(cur->name, name))
        {
            printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%0.2f\t\t%0.2f\t\t\t%0.2f\t\t%s\n", cur->name, cur->sex, cur->idcard, cur->phnum, cur->num_build, cur->num_d, cur->num_room, cur->area, cur->area_money, cur->all_money, cur->b);
        }
        cur = cur->next;
    }
    cur = *head;
    printf("\n\n\n请具体输入你想要删除对象的单元号和房号：");
    scanf("%d %d", &a, &b);

    while (cur != NULL)
    {
        if ((!strcmp(cur->name, name)) && a == cur->num_d && cur->num_room == b)
        {
            if (cur == *head)
            {
                *head = cur->next;
                free(cur);
                cur = *head;
            }
            else
            {
                p->next = cur->next;
                free(cur);
                cur = p->next;
            }

            printf("删除成功，正在退出，请稍后.........");
            Sleep(1000);
            system("cls");
            return;
        }
        else
        {
            p = cur;
            cur = cur->next;
        }
    }
    if (cur == NULL)
    {
        printf("未查询到此人");
        Sleep(2000);
        system("cls");
        return;
    }
}

void save(person *head)
{
    person *cur;
    cur = head;
    FILE *pf;
    pf = fopen("data.txt", "w+");

    if (pf == NULL)
    {
        printf("哦偶，我们的文件打开失败了，请修正错误后，重新打开。");
        Sleep(2000);
        system("cls");
        return;
    }

    fprintf(pf, "%s\n", "姓名\t性别\t身份证号\t\t电话号码\t楼号\t单元号\t房号\t\t平方米数\t每平方米物业价格\t应缴物业费\t备注");

    while (cur != NULL)
    {
        fprintf(pf, "%s\t", cur->name);
        fprintf(pf, "%s\t", cur->sex);
        fprintf(pf, "%s\t", cur->idcard);
        fprintf(pf, "%s\t", cur->phnum);
        fprintf(pf, "%d\t", cur->num_build);
        fprintf(pf, "%d\t", cur->num_d);
        fprintf(pf, "%d\t", cur->num_room);
        fprintf(pf, "%0.2f\t", cur->area);
        fprintf(pf, "%0.2f\t", cur->area_money);
        fprintf(pf, "%0.2f\n", cur->all_money);
        fprintf(pf, "%s\n", cur->b);
        cur = cur->next;
    }

    fclose(pf);

    printf("保存成功，正在退出，请稍后.........\n");
    Sleep(1000);
    system("cls");
}

void dread(person **head)
{
    FILE *pf;
    person *cur, *tail = *head;
    pf = fopen("data.txt", "w+");

    if (pf == NULL)
    {
        printf("哦偶，我们的文件打开失败了，请修正错误后，重新打开。");
        Sleep(2000);
        system("cls");
        return 0;
    }
    fseek(pf, 90, 0); // 跳过开头
    getc(pf);

    if (feof(pf))
    {
        *head = NULL;
        return;
    }
    fseek(pf, 90, 0);

    while (!feof(pf))
    {
        cur = (person *)malloc(sizeof(person));
        fscanf(pf, "%s\t", cur->name);
        fscanf(pf, "%s\t", cur->sex);
        fscanf(pf, "%s\t", cur->idcard);
        fscanf(pf, "%s\t", cur->phnum);
        fscanf(pf, "%d\t", &cur->num_build);
        fscanf(pf, "%d\t", &cur->num_d);
        fscanf(pf, "%d\t", &cur->num_room);
        fscanf(pf, "%f\t", &cur->area);
        fscanf(pf, "%f\t", &cur->area_money);
        fscanf(pf, "%f\t", &cur->all_money);
        fscanf(pf, "%s\n", cur->b);

        if (*head == NULL)
            *head = cur;
        else
            tail->next = cur;

        tail = cur;
    }
}
// 打印排序后的数据
void sort(person *head)
{
    printf("排序数据为：\n");
    printf("姓名\t性别\t身份证号\t\t电话号码\t楼号\t单元号\t房号\t平方米数\t每平方米物业价格\t应缴物业费\t备注\n");
    person *a[100];
    char n[20];
    int len = 0;
    for (; head != NULL; len++)
    {
        a[len] = head;
        head = head->next;
    }
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (a[j]->all_money < a[j + 1]->all_money)
            {
                person *tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }

    for (int i = 0; i < len; i++)
    {
        printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%0.2f\t\t%0.2f\t\t\t%0.2f\t\t%s\n", a[i]->name, a[i]->sex, a[i]->idcard, a[i]->phnum, a[i]->num_build, a[i]->num_d, a[i]->num_room, a[i]->area, a[i]->area_money, a[i]->all_money, a[i]->b);
    }

    while (1)
    {
        printf("\n\n\n\n");

        printf("请输入exit返回: \n");
        scanf("%s", n);

        if (!strcmp(n, "exit"))
            return;
    }
}
void stat(person *head)
{
    person *p;
    int num[20] = {0};
    char n[20];

    p = head;

    while (p != NULL)
    {
        if (p->all_money > 0)
        {
            num[p->num_build]++;
        }

        p = p->next;
    }
    for (int i = 0; i < 15; i++)
    {
        printf("%d号\t", i + 1);
    }
    printf("\n");
    for (int i = 1; i <= 15; i++)
    {
        printf("%d\t", num[i]);
    }
    printf("\n");

    while (1)
    {
        printf("\n\n\n\n");
        printf("请输入exit返回: \n");
        scanf("%s", n);

        if (!strcmp(n, "exit"))
            return;
    }
}

void auto_money(person **head)
{
    person *cur;
    cur = *head;
    float temp;
    time_t timep;
    time(&timep);
    struct tm *p;
    p = gmtime(&timep);
    printf("请输入现在的日期:> ");
    scanf("%d", &p->tm_mday);
    if (p->tm_mday == 1)
    {
        while (cur != NULL)
        {
            temp = 0;
            temp = cur->area * cur->area_money;
            cur->all_money += temp;
            cur = cur->next;
        }
    }
}
void pay(person **head)
{
    person *cur;
    cur = *head;
    char name[20];
    float money;
    printf("请输入缴费住户的姓名：");
    scanf("%s", name);

    printf("查询到以下数据：\n");
    printf("姓名\t性别\t身份证号\t\t电话号码\t楼号\t单元号\t房号\t平方米数\t每平方米物业价格\t应缴物业费\t备注\n");
    int a, b;
    while (cur != NULL)
    {
        if (!strcmp(cur->name, name))
        {
            printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%0.2f\t\t%0.2f\t\t\t%0.2f\t\t%s\n", cur->name, cur->sex, cur->idcard, cur->phnum, cur->num_build, cur->num_d, cur->num_room, cur->area, cur->area_money, cur->all_money, cur->b);
        }
        cur = cur->next;
    }
    cur = *head;
    printf("\n\n\n请具体输入你想要删除对象的单元号和房号：");
    scanf("%d %d", &a, &b);

    system("cls");
    while (cur != NULL)
    {
        if ((!strcmp(cur->name, name)) && a == cur->num_d && cur->num_room == b)
        {
            printf("\n该用户需缴纳物业费 %0.2f 元\n\n\n", cur->all_money);
            printf("请输入缴纳的费用：");
            scanf("%f", &money);
            cur->all_money -= money;
            printf("缴费成功！");
            Sleep(2000);
            return;
        }

        cur = cur->next;
    }

    printf("缴费失败，请查看姓名是否有误");
    Sleep(2000);
}
