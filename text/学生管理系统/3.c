#include <stdio.h>
#include <conio.h> 
#include <string.h>
#include <stdlib.h>
struct student * list(); 
struct student * list3();
int student_number1 = 31;
FILE *fp;
int key;
int judge = 0;
struct student {
	char name[20];
	char xuehao[10];
	char class1[20];
	char math[20];
	char English[20];
	char chinese[20];
	struct student * next;
};
struct Users {
	char user[20];
	char code[20];
};
struct Teachers {
	char user[20];
	char code[20];
};
struct Users pe;
void zhuce() {
	char temp[20], cha;
	struct Users name;
	if (key == 0) {
		printf("�û�ע��");
		printf("\n\t�û�����");
		scanf("%s", name.user);
		fp = fopen("user.txt","r");
	}
	if (key == 1) {
		printf("��ʦע��");
		printf("\n\t�û�����");
		scanf("%s", name.user);
		fp = fopen("teacher.txt","r");
	}
	int flag = 1;
	while (!feof(fp)) { //�ж��û����Ƿ��ظ� fread(&pe, sizeof(struct Users), 1,fp);
		if (fscanf(fp,"%s %s\n", pe.user, pe.code)) {
			if (strcmp(pe.user, name.user) == 0) {
				printf("�û����Ѵ���");
				fclose(fp);
				flag--;
				printf("�Ƿ����ע�᣿(Y/N)");
				if (getch() == 'Y') {
					 zhuce();
				} else if (getch() == 'N') {
					main();
				}
			}
		}
	}
	if (flag == 1) {	
		do {
			printf("���룺");
			int i = 0;
			while ((name.code[i] = getch()) != '\r') {
				if (name.code[i] == '\b') {
					printf("\b \b");
					i--;
				} else {
					printf("*");
					i++;
				}
			} 
			printf("\n");
			name.code[i] = '\0';
			i = 0;
			printf("ȷ������:");
			while ((temp[i] = getch()) != '\r') {
				printf("*");
				i++;
			}
			temp[i] = '\0';
			if (strcmp(name.code, temp) != 0) {
				printf("�������벻һ������������");
			}
		} while (strcmp(name.code, temp) != 0);
		/*�û�����û���⣬�����ļ� */
		if (key == 0) {
			fp = fopen("user.txt","a+"); 
		} 
		if (key == 1) {
			fp = fopen("teacher.txt","a+"); 
		}
		if (fp == '\0') {
			printf("ע��ʧ��");
			exit(0);
		} else {
			system("cls");
			fprintf(fp,"%s %s\n", name.user, name.code);
			printf("д��ɹ�\n"); 
			fclose(fp);
			judge = 1;
			denglu(); 
		}
	}	
}
int  denglu() {
	char c[20], temp[20] = {0};
	struct Users name2;
	int flag = 0;
	if (key == 0) {
		printf("�û���½\n");
		printf("  �û���:");
		scanf("%s", name2.user);
		fp = fopen("user.txt", "r+");
	} 
	if (key == 1) {
		printf("��ʦ��½\n");
		printf("  ��ʦ�û�����"); 
		scanf("%s", name2.user);
		fp = fopen("teacher.txt", "r+");
	} 
	if (key == 2) {
		printf("����Ա��½\n");
		printf("�˺ţ�");
		scanf("%s", name2.user);
		fp = fopen("Admin.txt", "r+");
		flag = 1; 
	}
	
	temp[0] = '0';
	while (!feof(fp)) {
		fscanf(fp, "%s %s\n", pe.user, pe.code);
		if (strcmp(name2.user, pe.user) == 0) {
			flag++;
			break;
		}
	}
		int flag2 = 0;
		if (flag == 0) {
			printf("�û�������\n");
			printf("�Ƿ�ע��  yes/no\n");
			while (flag2 == 0) {
				scanf("%s", c);
				if (strcmp(c, "no") == 0) {
					welcome2();
					 flag2++;
				} else if (strcmp(c, "yes") == 0) {
					zhuce();
					flag2++;
				} else {
					printf("�������");
					printf("������yes/no\n");	
				}
			}
		} else if (flag == 1) {
			
		do {
			printf("����Ϊ ��"); 
			int i = 0;
			while ((name2.code[i] = getch()) != '\r') {
				if (name2.code[i] == '\b') {
					printf("\b \b");
					i--;
				} else {
					printf("*");
					i++;
				}
			}
			name2.code[i] = '\0';
			if (strcmp(pe.code, name2.code) != 0) {
				printf("�������\n");
				int flag3 = 0; 
					do {
						printf("1.�˳�  2.��������  3.�����һ�:");
						scanf("%s", temp);
						printf("\n");
						if (strcmp(temp, "1") == 0) {
							fclose(fp);
							flag3++;
							main();
						} else if (strcmp(temp, "3") == 0) {
							flag3++;
						} else if (strcmp(temp, "2") == 0) {
								flag3++;				
						} else {
							printf("������������ԣ�\n"); 
						}
					} while (flag3 == 0);
				} else {
					printf("\n");
					if (key == 1) {
						judge = 1; 
						printf("��ʦ��½�ɹ�\n");	
						strcpy(temp, "0");			
					} else if (strcmp(name2.code, "ADMIN") == 0 ) {
					    key = 2;
					    judge = 1;
					    strcpy(temp, "0");
					    printf("����Ա��½�ɹ�\n");
					} else {
					printf("��½�ɹ���\n");
					judge = 1; 
					strcpy(temp, "0");
					}
				}
			} while (strcmp(temp,"2") == 0);
		if (strcmp(temp, "3") == 0) {
			do {	
				printf("���������Ա����:");
				int j = 0;
			while ((temp[j] = getch()) != '\r') {
				if (temp[j] == '\b') {
					printf("\b \b");
					j--;
				} else {
					printf("*");
					j++;
				}
			}
			temp[j] = '\0';
				if (strcmp(temp,"ADMIN") == 0) {
					printf("��½�ɹ���\n");
					printf("�ɵ�����Ϊ��");
					printf("%s\n", pe.code); 
					denglu();
				}
			} while(strcmp(temp,"ADMIN") != 0);
		}
		return 0;
	}
}
void welcome() {     //��½����      
    printf("\n\n		````````````````````````````````````````````````````````````````````````````````");  
    printf("\n");  
    printf("\n");  
    printf("\n");  
    printf(" 		 ***********************  ��ӭ��¼ѧ����Ϣ����ƽ̨ *************************  \n");  
    printf("\n");  
    printf("\n");  
    printf("\n");  
    printf("		````````````````````````````````````````````````````````````````````````````````");  
}  
int welcome2() {
	char temp[100] = {0};
	int flag1 = 0;
	do {
		printf("\n1.��½\n2.ע��\n3.��ʦ��½\n4.����Ա��½\n\t \t \t ");
		scanf("%s", temp);
		system("cls");
		if (strcmp(temp, "1") == 0) {
			 flag1++;
			 key = 0;
			 denglu(); 
		} else if (strcmp(temp, "2") == 0) {
			 flag1++; 
			 zhuce();
		} else if (strcmp(temp, "3") == 0) {
			flag1++;
			key = 1;
			denglu();
		} else if (strcmp(temp, "4") == 0) {
			flag1++;
			key = 2;
			denglu();
		} 
		else {
			printf("����������������룡\n"); 
		}
	} while(flag1 == 0);
} 	
struct student *head, *head2;
void student_information() {
	int i;	
	struct student *information1, information,*end;
	fp = fopen("123.txt", "r+");
	head = end =(struct student *)malloc(sizeof(struct student));
	head->next = end;
	while(!feof(fp)) {
	    information1 = (struct student *)malloc(sizeof(struct student));
		fscanf(fp, "%s", information1->name);
		fgetc(fp);
		fscanf(fp, "%s", information1->xuehao);
		fgetc(fp);
		fscanf(fp, "%s", information1->class1);
		fgetc(fp);
		fscanf(fp, "%s", information1->chinese);
		fgetc(fp);
		fscanf(fp, "%s", information1->math);
		fgetc(fp);
		fscanf(fp, "%s", information1->English);
		end->next = information1;
		information1->next = '\0';
		end = information1;
	}
	fclose(fp);
}
int Student() {
   char temp[20];
   do { 
    printf("    |________________________________________________|\n");  
    printf("    |                                                |\n");  
    printf("    |                ѧ����½                        |\n");  
    printf("    |                                                |\n");  
    printf("    |               0���˳�ϵͳ                      |\n");  
    printf("    |               1���ɼ���ѯ                      |\n");  
    printf("    |               2����ѯ����ɼ�                  |\n");  
    printf("    |               3���ɼ�����                      |\n");  
    printf("    |               4���ɼ�����                      |\n");  
    printf("    |               5��������һ��                    |\n");   
    printf("    |________________________________________________|\n");  
		scanf("%s", temp);
		if (strcmp(temp, "5") == 0) {
			main();
		} else if (strcmp(temp, "0") ==0) {
			exit(0);
		} else if (strcmp(temp, "1") == 0) {
			Grade_query();
		} else if  (strcmp(temp, "2") == 0) {
			class_information_lookfor();
		} else if (strcmp(temp, "3") == 0) {
			personal_grade_analysis();	
		}else if (strcmp(temp, "4") == 0) {
			grade_appeal();
		} else {
			system("cls");
			printf("�������������\n");
		}
	} while ((strcmp(temp, "5") != 0) && (strcmp(temp, "0") != 0) && (strcmp(temp, "1") != 0) && (strcmp(temp, "2") != 0) && (strcmp(temp, "3") != 0) && (strcmp(temp, "4") != 0));
} 
int Grade_query() {
	char temp3[30];
	int key2 = 0, key3 = 0, key6 = 0;
	struct student *p;
	do {
		printf("������������ͣ�\n");
		printf("a.��ѧ�Ų���. b.���༶����. c.���Ҽ������ d. ���Ҳ��������"); 
		scanf("%s", temp3);
		if (strcmp(temp3, "a") == 0) {
			key2 = 1;
		} else if (strcmp(temp3, "b") == 0) {
			key2 = 2;
		} else if (strcmp(temp3, "c") == 0) {
			key2 = 3;
		} else if (strcmp(temp3, "d") == 0) {
			key2 = 4; 
		} else {
			printf("�������");
			getchar();
			getchar();
			system("cls");
		}
	} while ((strcmp(temp3, "a") != 0) && (strcmp(temp3, "b") != 0) && (strcmp(temp3, "c") != 0) && (strcmp(temp3, "d") != 0));
	if (key2 == 1) {
		char temp[20] = {0};
		int temp2 = 0;
		printf("������ѧ�ţ�");
		scanf("%s", temp);
		struct student *p;
		p = head->next;
		while (p->next) {
			if (strcmp(p->xuehao, temp) == 0) {
				temp2++;
				break;
			}
			p = p->next; 
		}
		int flag2 = 0;
		if (temp2 == 0) {
			printf("δ�ҵ���ѧ����\n");
			printf("1.���ؼ������� 2.������һ��"); 
			while (flag2 == 0) {
				scanf("%s", temp);
				if (strcmp(temp, "1") == 0) {
					Grade_query();
				} else if (strcmp(temp, "2") == 0) {
					if (key == 0) {
						system("cls");
						Student();
					}
					if (key == 1) {
						system("cls");
						Teacher();
					}
				} else {
					printf("������������ԣ�\n"); 
					printf("1.���ؼ������� 2.������һ��\n");
				}
			}
		} else {
			printf("%s\t%s\t%s\t%s\t%s\t%s\n", p->name, p->xuehao, p->class1, p->chinese, p->math, p->English);
			printf("���������������\n");
			getchar();
			getchar();
			system("cls"); 
			if (key == 0) {
				Student();
			} 
			if (key == 1) {
				Teacher();
			}
		}	
	} else if (key2 == 2) {
		class_information_lookfor(); 
	} else if (key2 == 4) {
	char temp4[20];
	do {
		printf("1. ��ȫ����Ա�в�ѯ 2.���༶��ѯ");
		
		scanf("%s", temp4);
		if (strcmp(temp4, "1") == 0) {
			key3 = 1;
		} else if (strcmp(temp4, "2") == 0) {
			key3 = 1;
		} else {
			printf("�������");
		}
	} while ((strcmp(temp4, "1") != 0) && (strcmp(temp4, "2") != 0));
	FILE *fp1;
		if (key3 == 1) {
			fp1 = fopen("123.txt", "r+");
			p = list3();
			
			while (p) {
				if (number_conversion(p->chinese) < 60 ) {
					printf("%s\n ���ĳɼ� ��%s\t", p->name, p->chinese); 
				}
				if (number_conversion(p->math) < 60 ) {
					printf("��ѧ�ɼ� ��%s\t", p->chinese); 
				} 
				if (number_conversion(p->English) < 60 ) {
					printf("Ӣ��ɼ� ��%s\t", p->chinese); 
				}
				printf("\n");
				p = p->next; 
			}
			fclose(fp1);
			printf("��ѯ��ϣ����������������");
			getchar();
			getchar();
			system("cls");
				if (key == 0) {
				Student();
			} 
			if (key == 1) {
				Teacher();
			}
		} else if (key3 == 2) {
			char temp[20];
			do {
				printf("\n�༶��\n");
				printf("1.����1�� 2.����2�� 3.����3�� 4.����4�� 5.����5��\n"); 
				scanf("%s", temp);
			} while ((strcmp(temp, "1") != 0) && (strcmp(temp, "2") != 0) && (strcmp(temp, "3") != 0) && (strcmp(temp, "4") != 0) && (strcmp(temp, "5") != 0));
			if (strcmp(temp, "1") == 0) {
				fp = fopen("class1.txt", "r+");
			}
			if (strcmp(temp, "2") == 0) {
				fp = fopen("class2.txt", "r+");
			}	
			if (strcmp(temp, "3") == 0) {
				fp = fopen("class3.txt", "r+");
			}
			if (strcmp(temp, "4") == 0) {
				fp = fopen("class4.txt", "r+");
			}
			if (strcmp(temp, "5") == 0) {
				fp = fopen("class5.txt", "r+");
			}
			p = list();
			while (p) {
			if (number_conversion(p->chinese) < 60 ) {
					printf("%s\n ���ĳɼ� ��%s\t", p->name, p->chinese); 
				}
				if (number_conversion(p->math) < 60 ) {
					printf("��ѧ�ɼ� ��%s\t", p->chinese); 
				} 
				if (number_conversion(p->English) < 60 ) {
					printf("Ӣ��ɼ� ��%s\t", p->chinese); 
				}
				printf("\n");
				p = p->next; 
			}
			printf("��ѯ��ϣ����������������");
			getchar();
			getchar();
			system("cls");
			if (key == 0) {
				Student();
			} 
			if (key == 1) {
				Teacher();
			}
		} else if (key2 == 3) {
			do {
				printf("1. ��ȫ����Ա�в�ѯ 2.���༶��ѯ");
				char temp4[20];
				scanf("%s", temp4);
				if (strcmp(temp4, "1") == 0) {
					key3 = 1;
				} else if (strcmp(temp4, "2") == 0) {
					key3 = 1;
				} else {
					printf("�������");
				}
			} while ((strcmp(temp4, "1") != 0) && (strcmp(temp4, "2") != 0));
			if (key3 == 1) {
				fp1 = fopen("123.txt", "r+");
				p = list();
				while (p) {
					if (number_conversion(p->chinese) > 60 ) {
						printf("%s\n ���ĳɼ� ��%s\t", p->name, p->chinese); 
					}
					if (number_conversion(p->math) > 60 ) {
						printf("��ѧ�ɼ� ��%s\t", p->chinese); 
					} 
					if (number_conversion(p->English) > 60 ) {
						printf("Ӣ��ɼ� ��%s\t", p->chinese); 
					}
					printf("\n");
					p = p->next; 
				}
				fclose(fp1);
				printf("��ѯ��ϣ����������������");
				getchar();
				getchar();
				system("cls");
				if (key == 0) {
					Student();
				} 
				if (key == 1) {
					Teacher();
				}
			} else if (key3 == 2) {
					;			
			}
		}
	} 
}
struct student * list() {
		int i;
		struct student *information, *end;
		head2 = end =(struct student *)malloc(sizeof(struct student));
		head2->next = end;
		while (!feof(fp)) {
		    information = (struct student *)malloc(sizeof(struct student));
			fscanf(fp, "%s", information->name);
			fgetc(fp);
			fscanf(fp, "%s", information->xuehao);
			fgetc(fp);
			fscanf(fp, "%s", information->class1);
			fgetc(fp);
			fscanf(fp, "%s", information->chinese);
			fgetc(fp);
			fscanf(fp, "%s", information->math);
			fgetc(fp);
			fscanf(fp, "%s\n", information->English);
			end->next = information;
			information->next = '\0';
			end = information;
	}
	fclose(fp);
	return head2->next; 
}
struct student * list2() {
		int i;
		struct student *information, *end;
		head2 = end =(struct student *)malloc(sizeof(struct student));
		head2->next = end;
		while (!feof(fp)) {
		    information = (struct student *)malloc(sizeof(struct student));
			fscanf(fp, "%s", information->name);
			fgetc(fp);
			fscanf(fp, "%s", information->xuehao);
			fgetc(fp);
			fscanf(fp, "%s", information->class1);
			fgetc(fp);
			fscanf(fp, "%s", information->chinese);
			fgetc(fp);
			fscanf(fp, "%s", information->math);
			fgetc(fp);
			fscanf(fp, "%s\n", information->English);
			end->next = information;
			information->next = '\0';
			end = information;
	}
	return head2; 
}
FILE *fp1;
struct student * list3() {
		int i;
		struct student *information, *end;
		head2 = end =(struct student *)malloc(sizeof(struct student));
		head2->next = end;
		while (!feof(fp1)) {
		    information = (struct student *)malloc(sizeof(struct student));
			fscanf(fp1, "%s", information->name);
			fgetc(fp1);
			fscanf(fp1, "%s", information->xuehao);
			fgetc(fp1);
			fscanf(fp1, "%s", information->class1);
			fgetc(fp1);
			fscanf(fp1, "%s", information->chinese);
			fgetc(fp1);
			fscanf(fp1, "%s", information->math);
			fgetc(fp1);
			fscanf(fp1, "%s\n", information->English);
			end->next = information;
			information->next = '\0';
			end = information;
	}
	return head2->next; 
}
int  personal_grade_analysis() {
	char temp[20], temp2[20];
	struct student abc[50], * p;
	printf("������༶ (���)��\n1.����һ�� 2. ������� 3.�������� 4. �����İ� 5.�������\n");
	scanf("%s", temp);
	fp = '\0';
	if (strcmp(temp, "1") == 0) {
		fp = fopen("class1.txt", "r+");
	} 
	if (strcmp(temp, "2") == 0) {
		fp = fopen("class2.txt", "r+");
	}
	if (strcmp(temp, "3") == 0) {
		fp = fopen("class3.txt", "r+");
	}
	if (strcmp(temp, "4") == 0) {
		fp = fopen("class4.txt", "r+");
	}
	if (strcmp(temp, "5") == 0) {
		fp = fopen("class5.txt", "r+");
	}
	if (fp == '\0') {
		printf("�༶������\n");
		do {
			printf("1.���� 2.�˳�");
			scanf("%s", temp2);
			if (strcmp(temp2, "1") == 0) {
				personal_grade_analysis();
			} else if (strcmp(temp2, "2") == 0) {
				system("cls"); 	
				Student();
			} else {
				printf("�������"); 
			}
		} while((strcmp(temp2, "1") != 0) && (strcmp(temp2, "2") != 0));
	} else {
		int i = 0, j = 0, k = 0;
		struct student *head3, *pre, *p, *t, *tail;
		head3 = list2();
		pre = head3;
		tail = '\0';
		while ((head3->next->next) != tail) {
			p = head3->next;
			pre = head3;
			while ((p->next) != tail) {
				if (number_conversion(p->chinese) > number_conversion(p->next->chinese)){ 
					pre->next = p->next;
					p->next = pre->next->next;
					pre->next->next = p;
					p = pre->next; 
				}
					pre = pre->next;
					p = p->next;
			}
			tail = p;
		}
			printf("���ĳɼ�����Ϊ��\n");
			t = head3->next;
			while(t) {
				printf("%s %d\n", t->name, number_conversion(t->chinese));
				t = t->next;
			}
		pre = head3;
		tail = '\0';
		while ((head3->next->next) != tail) {
			p = head3->next;
			pre = head3;
			while ((p->next) != tail) {
				if (number_conversion(p->math) > number_conversion(p->next->math)){ 
					pre->next = p->next;
					p->next = pre->next->next;
					pre->next->next = p;
					p = pre->next; 
				}
					pre = pre->next;
					p = p->next;
			}
			tail = p;
		} 
			printf("\n\n\n\n��ѧ����Ϊ��\n");
			t = head3->next;
			while(t) {
				printf("%s %d\n", t->name, number_conversion(t->math));
				t = t->next;
			}
			pre = head3;
			tail = '\0';
			while ((head3->next->next) != tail) {
				p = head3->next;
				pre = head3;
				while ((p->next) != tail) {
					if (number_conversion(p->English) > number_conversion(p->next->English)){ 
						pre->next = p->next;
						p->next = pre->next->next;
						pre->next->next = p;
						p = pre->next; 
					}
						pre = pre->next;
						p = p->next;
				}
				tail = p;
			}
			printf("\n\n\n\nӢ��ɼ�����Ϊ��\n");
			t = head3->next;
			while(t) {
				printf("%s %d\n", t->name, number_conversion(t->English));
				t = t->next;
			}
		}
		printf("�������������");
		getchar();
		getchar();
		system("cls");
		Student();
}
int number_conversion(char number[]) {
	int i, j = 1, sum = 0;
	for (i = 0; i < strlen(number); i++) {
		sum = sum * 10 + number[i] - '0';
	}
	return sum;
}
int grade_appeal() {
	char temp[20] = {0}, a[150] = {0};
	int temp2 = 0;
	char temp3[20];
	printf("������������");
	scanf("%s", temp);
	strcpy(temp3, temp);
	struct student *p;
	fp = fopen("123.txt", "r+");
	p = list();
	p = p->next;
	while (p) {
		if (strcmp(p->name, temp) == 0) {
			temp2++;
			break;
		}
		p = p->next; 
	}
	int flag2 = 0;
	if (temp2 == 0) {
		printf("δ�ҵ���ѧ����\n");
		printf("1.���ؼ������� 2.������һ��"); 
		while (flag2 == 0) {
			scanf("%s", temp);
			if (strcmp(temp, "1") == 0) {
				Student();
			} else if (strcmp(temp, "2") == 0) {
				if (key == 0) {
					system("cls");
					Student();
				}
				if (key == 1) {
					system("cls");
					Teacher();
				}
			} else {
				printf("������������ԣ�\n"); 
				printf("1.���ؼ������� 2.������һ��\n");
			}
		}
	} else {
		printf("������Ҫ���ߵ����ݣ�:\n");
		scanf("%s", a);
		fp = fopen("appeal.txt", "w+");
		fprintf(fp, "%s\n", temp3);
		fprintf(fp, "%s", a);
		fclose(fp);
		printf("������ϣ�");
		getchar();
		getchar();
		system("cls"); 
		Student();
	}
}
int class_information_lookfor() {
char temp[20] = {0};
	int temp2 = 0;
	int flag = 0; 
	printf("������༶��");
	scanf("%s", temp);
	struct student *p;
	fp = fopen("123.txt", "r+");
	p = list();
	p = p->next;
	while (p) {
		if (strcmp(p->class1, temp) == 0) {
			printf("%s\t%s\t%s\t%s\t%s\t%s\n", p->name, p->xuehao, p->class1, p->chinese, p->math, p->English);
		flag++; 
		}
		p = p->next; 
	}
	fclose(fp);
	if (flag == 0) {
		printf("δ�ҵ��ð༶\n");
		printf("�������������");
		getchar();
		getchar();
		system("cls"); 
		if (key == 0) {
			Student();
		} 
		if (key == 1) {
			Teacher();
		}
	} else {
		getchar();
		getchar();
		printf("���������������\n");
		system("cls");
		if (key == 0) {
			Student();
		} 
		if (key == 1) {
			Teacher();
		}
	}
}
int Teacher() {
	char temp[20] = {0}; 
	do{
    	printf("    |________________________________________________|\n");  
    	printf("    |                                                |\n");  
   		printf("    |                ��ʦ��½                        |\n");  
   		printf("    |                                                |\n");  
    	printf("    |               0���˳�ϵͳ                      |\n");  
    	printf("    |               1������ѧ����Ϣ                  |\n");  
    	printf("    |               2��ɾ��ѧ����Ϣ                  |\n");  
    	printf("    |               3���޸�ѧ����Ϣ                  |\n");  
    	printf("    |               4������ѧ������Ϣ                |\n");  
    	printf("    |               5���������ɼ�                  |\n");  
    	printf("    |               6�����ص��ļ���                  |\n");  
    	printf("    |               7���ɼ�����                      |\n");  
    	printf("    |               8�����ѹ���Ա�ɼ�����            |\n");
    	printf("    |               9��������һ��                    |\n");	
    	printf("    |                                                |\n");	  
    	printf("    |________________________________________________|\n");  

    	scanf("%s", temp);
		if (strcmp(temp, "9") == 0) {
			main();
		} else if (strcmp(temp, "0") == 0) {
			exit(0);
		} else if (strcmp(temp, "4") == 0) {
			Grade_query();
		} else if (strcmp(temp, "7") == 0) {
			all_grade_analysis();
		} else if (strcmp(temp, "1") == 0) {
			strcat_information();
		} else if (strcmp(temp, "2") == 0) {
			grade_delete();
		} else if (strcmp(temp, "4") == 0) {
			Grade_query();
		} else if (strcmp(temp, "3") == 0) {
			grade_modify();
		} else if (strcmp(temp, "5") == 0) {
			class_information_lookfor();
		} else if (strcmp(temp, "6") == 0) {
			download();
		} else if (strcmp(temp, "8") == 0) {
			printf("�ù���ûδд");
			getchar();
			getchar();
			system("cls");
			Teacher();
		} else {
			printf("������������ԣ�\n");
			getchar();
			getchar();
			system("cls");
		}
	} while ((strcmp(temp, "5") != 0) && (strcmp(temp, "0") != 0) && (strcmp(temp, "1") != 0) && (strcmp(temp, "2") != 0) && (strcmp(temp, "3") != 0) && (strcmp(temp, "4") != 0) && (strcmp(temp, "6") != 0) && (strcmp(temp, "7") != 0) && (strcmp(temp, "8") != 0) && (strcmp(temp, "9") != 0));
}
int strcat_information() {
	struct student Teacher_1;
	int i = 0, flag2 = 1;
	char temp[20], temp1 = 0;
	printf("������ѧ����Ϣ\n");
	printf("������");
	scanf("%s", temp); 
	strcpy(Teacher_1.name, temp);
	printf("\n");
	do {
		flag2 = 1;
		printf("ѧ�ţ�");
		scanf("%s", temp);
		for (i = 0; i < strlen(temp); i++) {
			if (temp[i] >='A' && temp[i] <= 'z') {
				printf("���벻�ð�����ĸ��������\n");
				flag2 = 0;
				break;
			}
		}
	} while (flag2 == 0); 
	FILE *ffp; 
	struct student temp5;
	ffp = fopen("123.txt", "r+");
	while(!feof(ffp)) {
		fscanf(ffp, "%s %s %s %s %s %s\n", temp5.name, temp5.xuehao, temp5.class1, temp5.chinese, temp5.math, temp5.English);
		if (strcmp(temp, temp5.xuehao) == 0) {
			printf("�Ѵ��ڴ��ˣ�\n");
			printf("�����������\n");
			getchar();
			getchar();
			Teacher();
		}
	} 
	strcpy(Teacher_1.xuehao, temp);
	do {
	printf("\n�༶��\n");
	printf("1.����1�� 2.����2�� 3.����3�� 4.����4�� 5.����5��\n"); 
	scanf("%s", temp);
	} while ((strcmp(temp, "1") != 0) && (strcmp(temp, "2") != 0) && (strcmp(temp, "3") != 0) && (strcmp(temp, "4") != 0) && (strcmp(temp, "5") != 0));
	if (strcmp(temp, "1") == 0) {
		fp = fopen("class1.txt", "a+");
		strcpy(temp, "����1��");
	}
	if (strcmp(temp, "2") == 0) {
		fp = fopen("class2.txt", "a+");
		strcpy(temp, "����2��");
	}
	if (strcmp(temp, "3") == 0) {
		fp = fopen("class3.txt", "a+");
		strcpy(temp, "��·3��");
	}
	if (strcmp(temp, "4") == 0) {
		fp = fopen("class4.txt", "a+");
		strcpy(temp, "����4��");
	}
	if (strcmp(temp, "5") == 0) {
		fp = fopen("class5.txt", "a+");
		strcpy(temp, "����5��"); 
	}
	strcpy(Teacher_1.class1, temp);
	printf("\n");
	do {
		flag2 = 1;
		printf("���ĳɼ���");
		scanf("%s", temp);
		for (i = 0; i < strlen(temp); i++) {
			if (temp[i] >='A' && temp[i] <= 'z') {
				printf("���벻�ð�����ĸ��������\n");
				flag2 = 0;
				break;
			}
		}
	} while (flag2 == 0);
	strcpy(Teacher_1.chinese, temp);
	printf("\n");
	do {
		flag2 = 1;
		printf("��ѧ�ɼ���");
		scanf("%s", temp);
		for (i = 0; i < strlen(temp); i++) {
			if (temp[i] >='A' && temp[i] <= 'z') {
				printf("���벻�ð�����ĸ��������\n");
				flag2 = 0;
				break;
			}
		}
	} while (flag2 == 0);
	strcpy(Teacher_1.math, temp);
	printf("\n");
	do {
		flag2 = 1;
		printf("Ӣ��ɼ���");
		scanf("%s", temp);
		for (i = 0; i < strlen(temp); i++) {
			if (temp[i] >='A' && temp[i] <= 'z') {
				printf("���벻�ð�����ĸ��������\n");
				flag2 = 0;
				break;
			}
		}
	} while (flag2 == 0);
	strcpy(Teacher_1.English, temp); 
	fprintf(fp, "%s %s %s %s %s %s\n", Teacher_1.name, Teacher_1.xuehao, Teacher_1.class1, Teacher_1.chinese, Teacher_1.math, Teacher_1.English);
	fclose(fp);
	printf("д��ɹ���\n");
	getchar();
	getchar();
	fp = fopen("123.txt", "a+");
	fprintf(fp, "%s %s %s %s %s %s\n", Teacher_1.name, Teacher_1.xuehao, Teacher_1.class1, Teacher_1.chinese, Teacher_1.math, Teacher_1.English);
	fclose(fp);
	student_information();
	printf("�������������һ�㣡");
	system("cls"); 
	Teacher();
}
int grade_delete() {
	FILE *ftp, *fp2;
	int flag2 = 1, i = 0;
	int flag5 = 0; 
	char temp[20];
	do {
		printf("\n�༶��\n");
		printf("1.����1�� 2.����2�� 3.����3�� 4.����4�� 5.����5��\n"); 
		scanf("%s", temp);
	} while ((strcmp(temp, "1") != 0) && (strcmp(temp, "2") != 0) && (strcmp(temp, "3") != 0) && (strcmp(temp, "4") != 0) && (strcmp(temp, "5") != 0));
	if (strcmp(temp, "1") == 0) {
			fp = fopen("class1.txt", "a+");
			strcpy(temp, "����1��");
			flag5 = 1;
	}
	if (strcmp(temp, "2") == 0) {
		fp = fopen("class2.txt", "a+");
		strcpy(temp, "����2��");
		flag5 = 2;
	}	
	if (strcmp(temp, "3") == 0) {
		fp = fopen("class3.txt", "a+");
		strcpy(temp, "��·3��");
		flag5 = 3;
	}
	if (strcmp(temp, "4") == 0) {
		fp = fopen("class4.txt", "a+");
		strcpy(temp, "����4��");
		flag5 = 4;
	}
	if (strcmp(temp, "5") == 0) {
		fp = fopen("class5.txt", "a+");
		strcpy(temp, "����5��"); 
		flag5 = 5;
	}
	do {
		flag2 = 1;
		printf("Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%s", temp);
		for (i = 0; i < strlen(temp); i++) {
			if (temp[i] >='A' && temp[i] <= 'z') {
				printf("���벻�ð�����ĸ��������\n");
				flag2 = 0;
				break;
			}
		}
	} while (flag2 == 0);
	struct student *t, *q, *p, *head6;
	head6 = list2();
	t = head6; 
	int flag0 = 1;
	while(t->next) {
		q = t->next;
		p = q->next;
		if (strcmp(q->xuehao, temp) == 0) {
			t->next = p;
			q->next = '\0';	
			printf("ɾ���ɹ�");
			flag0 = 0;
			break;	
		}
		t = t->next;
	}
	printf("!!!!!");
	if (flag0 == 1) {
		printf("δ�ҵ���ѧ��,�����ԣ�");
		grade_delete();
	} else {
		q = head6->next;
		ftp = fopen("temp.txt", "w+");
		if (ftp == '\0') {
			printf("��ʧ��"); 
		}
		while (q) {
			fprintf(ftp, "%s ", q->name);
			fprintf(ftp, "%s ", q->xuehao);
			fprintf(ftp, "%s ", q->class1);
			fprintf(ftp, "%s ", q->chinese);
			fprintf(ftp, "%s ", q->math);
			fprintf(ftp, "%s\n", q->English);
			q = q->next; 
		}
		fclose(ftp);
		fclose(fp);
		if (flag5 == 1) {
			remove("class1.txt");
			rename("temp.txt", "class1.txt");
		}
		if (flag5 == 2) {
			remove("class2.txt");
			rename("temp.txt", "class2.txt");
		}
		if (flag5 == 3) {
			remove("class3.txt");
			rename("temp.txt", "class3.txt");
		}
		if (flag5 == 4) {
			remove("class4.txt");
			rename("temp.txt", "class4.txt");
		}
		if (flag5 == 5) {
			remove("class5.txt");
			rename("temp.txt", "class5.txt");
		}
		fp = fopen("123.txt", "r+");
		head6 = list2();
	t = head6; 
	while(t) {
		q = t->next;
		p = q->next;
		if (strcmp(q->xuehao, temp) == 0) {
			t->next = p;
			q->next = '\0';	
			break;	
		}
		t = t->next;
	}
		q = head6;
		ftp = fopen("temp2.txt", "w+");
		if (ftp == '\0') {
			printf("��ʧ��"); 
		}
		while (q) {
			fprintf(ftp, "%s ", q->name);
			fprintf(ftp, "%s ", q->xuehao);
			fprintf(ftp, "%s ", q->class1);
			fprintf(ftp, "%s ", q->chinese);
			fprintf(ftp, "%s ", q->math);
			fprintf(ftp, "%s\n", q->English);
			q = q->next; 
		}
		getchar();
		getchar();
		fclose(ftp);
		fclose(fp);
		remove("123.txt");
		rename("temp2.txt","123.txt");
		system("cls");
		Teacher();
	}
}
int grade_modify() {
	int flag2 = 1, i = 0; 
	FILE *ftp, *ftp2;
	int flag3 = 0;
	char temp[20], a[20];
	printf("�����޸�ѧ����Ϣ"); 
	do {
		printf("\n�༶��\n");
		printf("1.����1�� 2.����2�� 3.����3�� 4.����4�� 5.����5��\n"); 
		scanf("%s", temp);
	} while ((strcmp(temp, "1") != 0) && (strcmp(temp, "2") != 0) && (strcmp(temp, "3") != 0) && (strcmp(temp, "4") != 0) && (strcmp(temp, "5") != 0));
	if (strcmp(temp, "1") == 0) {
			fp = fopen("class1.txt", "a+");
			strcpy(temp, "����1��");
			flag3 = 1;
	}
	if (strcmp(temp, "2") == 0) {
		fp = fopen("class2.txt", "a+");
		flag3 = 2;
		strcpy(temp, "����2��");
	}	
	if (strcmp(temp, "3") == 0) {
		fp = fopen("class3.txt", "a+");
		strcpy(temp, "��·3��");
		flag3 = 3; 
	}
	if (strcmp(temp, "4") == 0) {
		fp = fopen("class4.txt", "a+");
		strcpy(temp, "����4��");
		flag3 = 4;
	}
	if (strcmp(temp, "5") == 0) {
		fp = fopen("class5.txt", "a+");
		strcpy(temp, "����5��"); 
		flag3 = 5;
	}
	do {
		flag2 = 1;
		printf("Ҫ�޸ĵ�ѧ��ѧ�ţ�");
		scanf("%s", temp);
		for (i = 0; i < strlen(temp); i++) {
			if (!(temp[i] >='0' && temp[i] <= '9')) {
				printf("���������֣�������\n");
				flag2 = 0;
				break;
			}
		}
	} while (flag2 == 0);
	struct student *t, *q, *p, *head1, *head4, *t2, *q2;
	head1 = list();
	fp1 = fopen("123.txt", "r+");
	head4 = list3();
	t2 = head4;
	t = head1; 
	int flag1 = 1, flag9= 1;
	while(t) {
		if(strcmp(t->xuehao, temp) == 0) {
			flag1 = 0;
			break;
		}
		t = t->next;
	}
	while(t2) {
		if (strcmp(t->xuehao, temp) ==0) {
			flag9 = 0;
			break;
		}
	}
	if (flag1 == 1 && flag9 == 0) {
		printf("δ�ҵ���ѧ��,�����ԣ�");
		grade_modify();
	} else {
		char temp2[20], temp3[20];
		do {
			do {
				printf("�޸����ݣ�");
				printf("1.�޸����� 2.�޸�ѧ�� 3.�޸İ༶ 4.�޸����ĳɼ� 5.�޸���ѧ�ɼ� 6.�޸�Ӣ��ɼ�");
				printf("\n\t");
				scanf("%s", temp2);
				if ((strcmp(temp2, "1") != 0) && (strcmp(temp2, "2") != 0) && (strcmp(temp2, "3") != 0) && (strcmp(temp2, "4") != 0) && (strcmp(temp2, "5") != 0) && (strcmp(temp2, "6") != 0)) {
					printf("������������ԣ�\n");
				}
			} while ((strcmp(temp2, "1") != 0) && (strcmp(temp2, "2") != 0) && (strcmp(temp2, "3") != 0) && (strcmp(temp2, "4") != 0) && (strcmp(temp2, "5") != 0) && (strcmp(temp2, "6") != 0));	
			if (strcmp(temp2, "1") == 0) {
				printf("�����޸�Ϊ��");
				scanf("%s", t->name);
				strcpy(t2->name, t->name);
			} 
			if (strcmp(temp2, "2") == 0) {
				printf("ѧ���޸�Ϊ��");
				scanf("%s", t->xuehao); 
				strcpy(t2->xuehao, t->xuehao);
			}
			if (strcmp(temp2, "3") == 0) {
				printf("�༶�޸�Ϊ��");
				scanf("%s", t->class1); 
				strcpy(t2->class1, t->class1);
			}
			if (strcmp(temp2, "4") == 0) {
				printf("���ĳɼ��޸�Ϊ:");
				scanf("%s", t->chinese);
				strcpy(t2->chinese, t->chinese);
			}
			if (strcmp(temp2, "5") == 0) {
				printf("��ѧ�ɼ��޸�Ϊ��");
				scanf("%s", t->math);
				strcpy(t2->math, t->math);
			}
			if (strcmp(temp2, "6") == 0) {
				printf("Ӣ��ɼ��޸�Ϊ:");
				scanf("%s", t->English);
				strcpy(t2->English, t->English);
			}
			q = head1;
			q2 = head4;
			ftp = fopen("temp.txt", "w+");
			ftp2 = fopen("temp7.txt", "w+");
			if (ftp == '\0') {
				printf("��ʧ��"); 
			}
			while (q->next) {
				fprintf(ftp, "%s ", q->name);
				fprintf(ftp, "%s ", q->xuehao);
				fprintf(ftp, "%s ", q->class1);
				fprintf(ftp, "%s ", q->chinese);
				fprintf(ftp, "%s ", q->math);
				fprintf(ftp, "%s\n", q->English);
				q = q->next; 
			}
			while (q2->next) {
				fprintf(ftp2, "%s ", q2->name);
				fprintf(ftp2, "%s ", q2->xuehao);
				fprintf(ftp2, "%s ", q2->class1);
				fprintf(ftp2, "%s ", q2->chinese);
				fprintf(ftp2, "%s ", q2->math);
				fprintf(ftp2, "%s\n", q2->English);
				q2 = q2->next; 
			}
			do {
				printf("�Ƿ�����޸ģ�Yes/No");
				scanf("%s", a);
				if (strcmp(a,"Yes") != 0 && strcmp(a,"No") != 0) {
					printf("����������������룡"); 
				}
			} while (strcmp(a,"Yes") != 0 && strcmp(a,"No") != 0);
		} while(strcmp(a,"Yes") == 0); 
			fclose(ftp);
			fclose(fp);
			fclose(ftp2);
			fclose(fp1);
			if (flag3 == 1) {
				remove("class1.txt");
				rename("temp.txt", "class1.txt");
			}
			if (flag3 == 2) {
				remove("class2.txt");
				rename("temp.txt", "class2.txt");
			}
			if (flag3 == 3) {
				remove("class3.txt");
				rename("temp.txt", "class3.txt");
			}
			if (flag3 == 4) {
				remove("class4.txt");
				rename("temp.txt", "class4.txt");
			}
			if (flag3 == 5) {
				remove("class5.txt");
				rename("temp.txt", "class5.txt");
			}
			remove("123.txt");
			if (rename("temp7.txt", "123.txt") == 0) {
				printf("�޸���ϣ�\n");
			}
			getchar();
			getchar();
			system("cls");
			Teacher();
	}
} 
int download () {
	FILE *ftp;
	printf("��������Ҫ���صİ༶\n");
	char temp[20];
	do {
		printf("\n�༶��\n");
		printf("1.����1�� 2.����2�� 3.����3�� 4.����4�� 5.����5��\n"); 
		scanf("%s", temp);
	} while ((strcmp(temp, "1") != 0) && (strcmp(temp, "2") != 0) && (strcmp(temp, "3") != 0) && (strcmp(temp, "4") != 0) && (strcmp(temp, "5") != 0));
	if (strcmp(temp, "1") == 0) {
			fp = fopen("class1.txt", "a+");
			strcpy(temp, "����1��");
	}
	if (strcmp(temp, "2") == 0) {
		fp = fopen("class2.txt", "a+");
		strcpy(temp, "����2��");
	}	
	if (strcmp(temp, "3") == 0) {
		fp = fopen("class3.txt", "a+");
		strcpy(temp, "��·3��");
	}
	if (strcmp(temp, "4") == 0) {
		fp = fopen("class4.txt", "a+");
		strcpy(temp, "����4��");
	}
	if (strcmp(temp, "5") == 0) {
		fp = fopen("class5.txt", "a+");
		strcpy(temp, "����5��"); 
	}
	struct student  *p, *q;
	q = list();
	ftp = fopen("temp3.txt", "w+");
	if (ftp == '\0') {
		printf("��ʧ��"); 
	}
	while (q) {
		fprintf(ftp, "%s ", q->name);
		fprintf(ftp, "%s ", q->xuehao);
		fprintf(ftp, "%s ", q->class1);
		fprintf(ftp, "%s ", q->chinese);
		fprintf(ftp, "%s ", q->math);
		fprintf(ftp, "%s\n", q->English);
		q = q->next; 
	}
	printf("���سɹ���");
	printf("���������������\n");
	getchar();
	fclose(ftp);
	getchar();
	system("cls");
	Teacher(); 
}
int  all_grade_analysis() {
	struct student abc[200], t, q;
	char temp[20] = {0};
	int temp2 = 0;
	struct student *p;
	p = head->next;
	int i = 0, j = 0, k = 0, temp3 = 0;
	while (p) {
		strcpy(abc[i].name, p->name);
		strcpy(abc[i].xuehao, p->xuehao);
		strcpy(abc[i].class1, p->class1);
		strcpy(abc[i].chinese, p->chinese);
		strcpy(abc[i].math, p->math);
		strcpy(abc[i].English, p->English);
		p = p->next; 
		i++;
	}
	for (k = 0; k < i; k++) {
		for (j = 0; j < i; j++) {
			if (strcmp(abc[j].chinese, abc[k].chinese) < 0) {
				t = abc[j];
				abc[j] = abc[k];
				abc[k] = t;
			}
		}
	}
	printf("�����ĳɼ�����Ϊ \n");
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].chinese, "100") == 0) {
			continue;
		}
		printf("%s\t%s\t%s\n", abc[k].name, abc[k].class1, abc[k].chinese);
	}
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].chinese, "100") == 0) {
			printf("%s\t%s\t%s\n", abc[k].name, abc[k].class1, abc[k].chinese);
		}
	}
	for (k = 0; k < i; k++) {
		for (j = 0; j < i; j++) {
			if (strcmp(abc[j].math, abc[k].math) < 0) {
				t = abc[j];
				abc[j] = abc[k];
				abc[k] = t;
			}
		}
	}
	printf("����ѧ�ɼ�����Ϊ \n"); 
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].math, "100") == 0) {
			continue;
		}
		printf("%s\t%s\t%s\n", abc[k].name, abc[k].class1, abc[k].math);
	}
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].math, "100") == 0) {
			printf("%s\t%s\t%s\n", abc[k].name, abc[k].class1, abc[k].math);
		}
	}
	
	for (k = 0; k < i; k++) {
		for (j = 0; j < i; j++) {
			if (strcmp(abc[j].English, abc[k].English) < 0) {
				t = abc[j];
				abc[j] = abc[k];
				abc[k] = t;
			}
		}
	}
	printf("��Ӣ��ɼ�����Ϊ \n"); 
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].English, "100") == 0) {
			continue;
		}
		printf("%s\t%s\t%s\n", abc[k].name, abc[k].class1, abc[k].English);
	}
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].English, "100") == 0) {
			printf("%s\t%s\t%s\n", abc[k].name, abc[k].class1, abc[k].English);
		}
	}
	printf("���ĳɼ������������ ��\n");
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].chinese, "100") == 0) {
			continue;
		}
		if (strcmp(abc[k].chinese, "60") < 0) {
			printf("%s\t%s\t%s\t", abc[k].name, abc[k].class1, abc[k].chinese);
		}
	}
	printf("\n");
	printf("��ѧ�ɼ������������ ��\n");
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].math, "100") == 0) {
			continue;
		}
		if (strcmp(abc[k].math, "60") < 0) {
			printf("%s\t%s\t%s\t", abc[k].name, abc[k].class1, abc[k].math);
		}
	}
	printf("\n");
	printf("Ӣ��ɼ������������ ��\n");
	for (k = 0; k < i; k++) {
		if (strcmp(abc[k].English, "100") == 0) {
			continue;
		}
		if (strcmp(abc[k].English, "60") < 0) {
			printf("%s\t%s\t%s\t", abc[k].name, abc[k].class1, abc[k].English);
		}
	}
	getchar ();
	getchar ();
	Teacher();
}
void Admin() {
	int flagg = 0;  
	do {
		printf("\n\n");
		printf("		    |________________________________________________|\n");  
		printf("       		    |                                                |\n");  
    	printf("      		    |                ����Ա��½                      |\n");  
    	printf("    		    |                                                |\n");  
    	printf("		    |               0���˳�ϵͳ                      |\n");  
    	printf("		    |               1���鿴����ѡ��                  |\n");  
    	printf("		    |               2�������ʦ�˽�����Ϣ�޸�        |\n");  
    	printf("		    |               3�������˺ż�����                |\n");  
    	printf("		    |               4��ɾ���˺ż�����                |\n");  
    	printf("		    |               5���޸��˺ż�����                |\n");  
    	printf("		    |               6�������˺ż�����                |\n");  
   		printf("		    |               7��¼�������˺ż�����            |\n"); 
		printf("		    |               8����������˺ż�����            |\n");
		printf("		    |               9���ֶ�����¼�������˺ż�����    |\n"); 
    	printf("		    |               10��������һ��                   |\n"); 
    	printf("		    |                                                |\n");  
    	printf("		    |________________________________________________|\n");  
		char temp[20];
   		scanf("%s", temp);
		if (strcmp(temp, "10") == 0) {
			main();
			flagg++;
		}else if (strcmp(temp, "0") == 0) {
			exit(0);
			flagg++;
		} else if (strcmp(temp, "2") == 0) {
			getchar();
			flagg++;
			getchar();
			system("cls");
			key = 1;
			flagg++;
			Teacher(); 
		} else if (strcmp(temp, "3") == 0) {
			flagg++;
			add_acount();
		} else if (strcmp(temp, "4") == 0) {
			flagg++;
			delete_acount();
		} else if (strcmp(temp, "5") == 0) {
			flagg++;
			change_acount();
		} else if (strcmp(temp, "1") == 0) {
			to_do_things(); 
			flagg++;
		} else if (strcmp(temp, "6") == 0) {
			account_lookfor();
			flagg++;
		} else if (strcmp(temp, "8") == 0) {
			all_account();
			flagg++;
		} else if (strcmp(temp, "7") == 0 || strcmp(temp, "9") == 0) {
			printf("�ù���δд");
			getchar();
			getchar();
			flagg++;
			system("cls");
			Admin();
		} else {
			printf("�������������ԣ�\n"); 
		}
	} while (flagg == 0);
}
int all_account() {
	struct Users deletion;
	char temp[20];
	fp = fopen("user.txt", "r+"); 
	while (!feof(fp)) { 
		fscanf(fp, "%s %s\n", deletion.user, deletion.code);
		printf("�˺ţ�%s\t���룺%s\n", deletion.user, deletion.code);
	}
	printf("������");
	printf("\n�������������\n");
	getchar();
	getchar();
	system("cls");
	Admin();
}
int to_do_things(){
	char a[20], a2[150];
	printf("��������:\n");
	printf("������:"); 
	fp = fopen("appeal.txt", "r+");
	fscanf(fp, "%s\n%s", a, a2);
	printf("%s\n%s", a, a2);
	printf("\n�������������\n");
	getchar();
	getchar();
	system("cls");
	Admin();
}
int add_acount() {
	struct Users add;
	char temp[20];
	fp = fopen("user.txt", "a+");
	printf("������Ҫ���ӵ��˺ţ�"); 
	scanf("%s", add.user);
	printf("\n���������룺\n");
	scanf("%s", add.code); 
	fprintf(fp, "%s %s\n", add.user, add.code);
	fclose(fp);
	printf("�Ƿ���� yes/no\n");
	do {
		printf("�����룺"); 
		scanf("%s", temp);
		if (strcmp(temp, "yes") != 0 && strcmp(temp, "no") != 0) {
			printf("������������ԣ�\n");
		}
	} while (strcmp(temp, "yes") != 0 && strcmp(temp, "no") != 0);
	if (strcmp(temp, "yes") == 0) {
		add_acount();
	} else {
		system("cls");
		Admin();
	}
}
int delete_acount() {
	struct Users deletion;
	FILE *ftp;
	char temp[20];
	printf("������Ҫɾ�����˺ţ�");
	scanf("%s", temp);
	fp = fopen("user.txt", "r+"); 
	ftp = fopen("temp5.txt", "w+");
	int flag = 0;
	while (!feof(fp)) { 
		fscanf(fp, "%s %s\n", deletion.user, deletion.code);
		if (strcmp(temp, deletion.user) == 0) {
				printf("ɾ���ɹ���\n");
				flag++;
		} else {
			fprintf(ftp,"%s %s\n", deletion.user, deletion.code);
		}
	}
	if (flag == 0) {
		printf("ɾ��ʧ��");
	}
	fclose(fp);
	fclose(ftp);
	remove("user.txt");
	rename("temp5.txt", "user.txt"); 
	printf("�������������\n");
	getchar();
	getchar();
	system("cls");
	Admin();
}
int change_acount() {
	struct Users change;
	char temp [20];
	printf("������Ҫ�޸ĵ��˺� ��");
	scanf("%s", temp);
	fp = fopen("user.txt", "r+");
	int flag = 0;
	FILE *ftp;
	ftp = fopen("temp4.txt", "w+");
	while (!feof(fp)) { 
		fscanf(fp, "%s %s\n", change.user, change.code);
		if (strcmp(change.user, temp) == 0) {
			printf("\n�޸�����Ϊ��");
			scanf("%s", temp);
			strcpy(change.code, temp);
			flag++;		
		}
			fprintf(ftp, "%s %s\n", change.user, change.code); 
	}
	fclose(fp);
	fclose(ftp);
	if (flag == 0) {
		printf("δ�ҵ����˺�");
		getchar();
		getchar();
		system("cls");
		Admin(); 
	} else {
		remove("user.txt");
		rename("temp4.txt","user.txt");
		printf("�޸ĳɹ�\n");
		getchar();
		getchar();
		printf("�������������\n");
		system("cls");
		Admin();
	}
}
int account_lookfor() {
		struct Users change;
	char temp [20];
	printf("������Ҫ���ҵ��˺� ��");
	scanf("%s", temp);
	fp = fopen("user.txt", "r+");
	int flag = 0;
	while (!feof(fp)) { 
		fscanf(fp, "%s %s\n", change.user, change.code);
		if (strcmp(change.user, temp) == 0) {
			printf("���ҳɹ���\n");
			printf("���˺���ϢΪ:\n");
			printf("�˺ţ�%s\n����: %s\n", change.user, change.code);
			flag++;
		}
	}
	fclose(fp);
	if (flag == 0) {
		printf("δ�ҵ����˺�");
		getchar();
		getchar();
		system("cls");
		Admin(); 
	} else {
		printf("\n�������������\n");
		getchar();
		getchar();
		system("cls");
		Admin();
	}
}
int main(void) {
	system("cls"); 
	welcome();
	welcome2(); 
	student_information();
	if (judge == 1) {
		printf("�������������\n");
		system("cls"); 
		switch(key) {
			case 0: Student(); break;
			case 1: Teacher(); break;
			case 2: Admin(); break;
		}
	}
	return 0;
} 
