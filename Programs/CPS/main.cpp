//#include <stdio.h>
//#include <climits>
////int main()
////{
////    int a[10], sum = 0, i, m=0;
//////    printf("%d", sizeof(int));
////    printf("Enter no of elements: ");
////    scanf("%d", &m);
////    printf("Enter %d elements:\n", m);
////    for(i=0; i<m; i++)
////    {
////        scanf("%d", &a[i]);
////        sum += a[i];
////    }
////    printf("Sum of elements is %d\n", sum);
//
////char a[4] = "abc";
////char b[4];
////b = a;
////printf("%s\n%s",&a, &b);
//
//void my_srtrcpy(char de[], char src[])
//{
//    int i = 0;
//    while(src[i] != '\0')
//    {
//        de[i] = src[i];
//        i++;
//    }
//    de [i] = '\0';
//}
//int world(int a, int b)
//{
//    return a - b;
//    return a + b;
//}
//int main()
//{
//    char src[20], dest[20];
//    printf("Enter string: ");
////    gets(src);
//    scanf("%s", src);
//    my_srtrcpy(dest, src);
//    puts(dest);
//    
//    char a[05]{'1', '2', '3', '4', '5'};
//    for(auto v: a)
//    {
//        v = '8';
//        printf("%c\t", v);
//    }printf("\n");
//    for(auto v: a)
//        printf("%c\t", v);
//    
//    printf("\n%d\n", world(20, 20));
//
//    //int x;
//    //100 = x;
//}
////}



//#include <stdio.h>
//void display(struct book *b1);
//struct book
//{
//char bname[15];
//int bno;
//};
//int main ()
//{
//struct book b;
//printf("Enter bookname and number: ");
//scanf ("%s %d", b.bname,&b.bno);
//display(&b);
//
//}
//void display (struct book *b1)
//{
//
//printf ("Name = %s\n", b1->bname);
//printf("Number = %d\n",b1->bno);
//}




#include <stdio.h>
void swap(int *x, int *y)
{
int temp;
temp = *x; 
*x = *y;
*y = temp; 
}
int main()
{
int m = 10, n = 20;
printf("Before executing swap m=%d n=%d\n", m, n);
swap(&m, &n);
printf("After executing swap m=%d n=%d\n", m, n);
}