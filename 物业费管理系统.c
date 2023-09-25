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

void menu();                    // �˵�
void add(person **head);        // ����û�
void output(person *phead);     // ��ӡ��Ϣ
void change(person **head);     // �޸���Ϣ
void delete(person **head);     // ɾ����Ϣ
void save(person *head);        // ���浽�ļ�
void dread(person **head);      // ���ļ��ж�ȡ���ݵ�����
void sort(person *head);        // ����󣬴�ӡ����������
void auto_money(person **head); // ��ȡϵͳʱ�䣬ÿ��1���Զ�����
void stat(person *head);        // ͳ��¥����Ȼ���ӡ
void pay(person **head);
void password(char *userpassword); // ��������

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
    printf("����������û���>: ");
    gets(user);

    if (!strcmp(user, "baby"))
    {
        printf("�������������>: ");
        password(userpassword);

        printf("��¼�ɹ�\n");
        Sleep(1000);
        system("cls");
        printf("���ڵ�¼�����Ժ�...........\n");
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
                printf("ÿ��ͳ�ƽ�����£�\n");
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
                printf("�˳��ɹ�����ӭ�´�����Ӵ~~");
                exit(0);
                break;
            default:
                printf("����������������룡");
                Sleep(1000);
                break;
            }
        }
    }
    else
    {
        printf("�û�������!");
        exit(0);
    }

    return 0;
}

void menu()
{
    printf("**************************��ӭ����С����ҵ����ϵͳ***************************\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("* * * * * * * * * * * * * * * * * *��ѡ��* * * * * * * * * * * * * * * * * * * *\n");
    printf("*                                                                              *\n");
    printf("*                             (1)  ��ӡ��Ϣ                                    *\n");
    printf("*                                                                              *\n");
    printf("*                             (2�������û�                                     *\n");
    printf("*                                                                              *\n");
    printf("*                             (3��ɾ���û�                                     *\n");
    printf("*                                                                              *\n");
    printf("*                            ��4���޸��û���Ϣ                                 *\n");
    printf("*                                                                              *\n");
    printf("*                            ��5��ͳ��ÿ��δ��������                           *\n");
    printf("*                                                                              *\n");
    printf("*                            ��6������Ƿ��ҵ��������                           *\n");
    printf("*                                                                              *\n");
    printf("*                            ��7���ɷ�                                         *\n");
    printf("*                                                                              *\n");
    printf("*                            ��8�������ļ�, ���˳�                             *\n");
    printf("*                                                                              *\n");
    printf("* * * * * * * * * * * * * * * * * *��ѡ��* * * * * * * * * * * * * * * * * * * *\n");
    printf("��������ѡ��:");
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
        printf("�������");
        exit(0);
    }
}
void add(person **head)
{
    int a;
    person *cur = NULL;
    printf("��ֱ����뻧���������Ա����֤�š���ϵ�绰��¥�š���Ԫ�š����š�ס�������ÿƽ������ҵ�ѡ�Ӧ������ҵ�ѡ���ע\n");
    printf("����Ҫ��Ӽ��ˣ�\n>>:");
    scanf("%d", &a);
    getchar();
    for (int i = 0; i < a; i++)
    {
        cur = (person *)malloc(sizeof(person));
        printf("����������: ");
        scanf("%s", cur->name);
        printf("�������Ա�: ");
        scanf("%s", cur->sex);
        printf("���������֤: ");
        scanf("%s", cur->idcard);
        printf("������ҵ���绰: ");
        scanf("%s", cur->phnum);
        printf("������¥��: ");
        scanf("%d", &cur->num_build);
        printf("�����뵥Ԫ��: ");
        scanf("%d", &cur->num_d);
        printf("�����뷿�� ");
        scanf("%d", &cur->num_room);
        printf("������ס�����: ");
        scanf("%f", &cur->area);
        printf("�����뵥λ��ҵ��: ");
        scanf("%f", &cur->area_money);
        printf("�����뱸ע�� ");
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
    printf("������ɣ������˳������Ժ�.........");
    Sleep(1000);
    system("cls");
}
void output(person *phead)
{
    person *cur;
    char n[10];
    cur = phead;
    printf("����\t�Ա�\t���֤��\t\t�绰����\t¥��\t��Ԫ��\t����\tƽ������\tÿƽ������ҵ�۸�\tӦ����ҵ��\t��ע\n");
    while (cur != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%0.2f\t\t%0.2f\t\t\t%0.2f\t\t%s\n", cur->name, cur->sex, cur->idcard, cur->phnum, cur->num_build, cur->num_d, cur->num_room, cur->area, cur->area_money, cur->all_money, cur->b);
        cur = cur->next;
    }
    printf("\n");

    while (1)
    {
        printf("\n\n\n\n");
        printf("������exit�˳�: \n");
        scanf("%s", n);

        if (!strcmp(n, "exit"))
            return;
    }
}

void change(person **head)
{
    char name[10];
    printf("����������Ҫ�޸ĵ��˵�����>: ");
    scanf("%s", name);
    person *cur;
    cur = *head;

    printf("��ѯ���������ݣ�\n");
    printf("����\t�Ա�\t���֤��\t\t�绰����\t¥��\t��Ԫ��\t����\tƽ������\tÿƽ������ҵ�۸�\tӦ����ҵ��\t��ע\n");
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
    printf("\n\n\n�������������Ҫɾ������ĵ�Ԫ�źͷ��ţ�");
    scanf("%d %d", &a, &b);

    system("cls");
    while (cur != NULL)
    {
        if ((!strcmp(cur->name, name)) && a == cur->num_d && cur->num_room == b)
        {
            printf("������Ҫ���ĵ���Ϣ\n");
            printf("����������: ");
            scanf("%s", cur->name);
            printf("�������Ա�: ");
            scanf("%s", cur->sex);
            printf("���������֤: ");
            scanf("%s", cur->idcard);
            printf("������ҵ���绰: ");
            scanf("%s", cur->phnum);
            printf("������¥��: ");
            scanf("%d", &cur->num_build);
            printf("�����뵥Ԫ��: ");
            scanf("%d", &cur->num_d);
            printf("�����뷿�� ");
            scanf("%d", &cur->num_room);
            printf("������ס�����: ");
            scanf("%f", &cur->area);
            printf("�����뵥λ��ҵ��: ");
            scanf("%f", &cur->area_money);
            printf("�����뱸ע�� ");
            scanf("%s", cur->b);
            printf("\n");
            cur->all_money = cur->area * cur->area_money;

            break;
        }

        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("δ��ѯ������");
        Sleep(2000);
        system("cls");
        return;
    }
    printf("�޸���ɣ������˳������Ժ�.........");
    Sleep(1000);
    system("cls");
}

void delete(person **head)
{
    char name[10];

    person *cur, *p;
    cur = *head;
    printf("����������Ҫɾ���Ķ��������: ");
    scanf("%s", name);

    printf("��ѯ���������ݣ�\n");
    printf("����\t�Ա�\t���֤��\t\t�绰����\t¥��\t��Ԫ��\t����\tƽ������\tÿƽ������ҵ�۸�\tӦ����ҵ��\t��ע\n");
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
    printf("\n\n\n�������������Ҫɾ������ĵ�Ԫ�źͷ��ţ�");
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

            printf("ɾ���ɹ��������˳������Ժ�.........");
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
        printf("δ��ѯ������");
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
        printf("Ŷż�����ǵ��ļ���ʧ���ˣ���������������´򿪡�");
        Sleep(2000);
        system("cls");
        return;
    }

    fprintf(pf, "%s\n", "����\t�Ա�\t���֤��\t\t�绰����\t¥��\t��Ԫ��\t����\t\tƽ������\tÿƽ������ҵ�۸�\tӦ����ҵ��\t��ע");

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

    printf("����ɹ��������˳������Ժ�.........\n");
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
        printf("Ŷż�����ǵ��ļ���ʧ���ˣ���������������´򿪡�");
        Sleep(2000);
        system("cls");
        return 0;
    }
    fseek(pf, 90, 0); // ������ͷ
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
// ��ӡ����������
void sort(person *head)
{
    printf("��������Ϊ��\n");
    printf("����\t�Ա�\t���֤��\t\t�绰����\t¥��\t��Ԫ��\t����\tƽ������\tÿƽ������ҵ�۸�\tӦ����ҵ��\t��ע\n");
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

        printf("������exit����: \n");
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
        printf("%d��\t", i + 1);
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
        printf("������exit����: \n");
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
    printf("���������ڵ�����:> ");
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
    printf("������ɷ�ס����������");
    scanf("%s", name);

    printf("��ѯ���������ݣ�\n");
    printf("����\t�Ա�\t���֤��\t\t�绰����\t¥��\t��Ԫ��\t����\tƽ������\tÿƽ������ҵ�۸�\tӦ����ҵ��\t��ע\n");
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
    printf("\n\n\n�������������Ҫɾ������ĵ�Ԫ�źͷ��ţ�");
    scanf("%d %d", &a, &b);

    system("cls");
    while (cur != NULL)
    {
        if ((!strcmp(cur->name, name)) && a == cur->num_d && cur->num_room == b)
        {
            printf("\n���û��������ҵ�� %0.2f Ԫ\n\n\n", cur->all_money);
            printf("��������ɵķ��ã�");
            scanf("%f", &money);
            cur->all_money -= money;
            printf("�ɷѳɹ���");
            Sleep(2000);
            return;
        }

        cur = cur->next;
    }

    printf("�ɷ�ʧ�ܣ���鿴�����Ƿ�����");
    Sleep(2000);
}
