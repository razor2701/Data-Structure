#include<stdio.h>
 int size,i,n,fkey,temp=0;
 int q=0;
 int a[100],b[100];
 int search(int key2);
 int deleteElement(int key3);
 int genrateQuddraticKey(int key);
 int genrateLinearKey(int key);
 int genrateLinearKeyForDeleteAndSearch(int key);
 int genrateQuadraticKeyForDeleteAndSearch(int key);
int main()
{
    /* ----------------------------------------------------------------------------------*/
   printf("\nEnter size of Table: ");
   scanf("%d",&size);
     for(i=0; i<size; i++)
   {
     a[i]=-1;
   }
   /*------------------------------------------------------------------------------------*/
   printf("\nEnter number of elements: ");
   printf("\nNote: Number of elements should be less than number of keys\n");
   scanf("%d",&n);
   /*----------------------------------------------------------------------------------*/
   int j;
   printf("Enter the elements:\n");
    printf("\nNote(elements can be any integers except '-1' )\n");
   for(j=0; j<n; j++)
   {
       scanf("%d",&b[j]);
   }
   /*-----------------------------------------------------------------------------------*/
   printf("\nEnter the probing method for collision resolution");
   printf("Note: Enter (1) for Linear and (2)for Quadratic: ");
   int selector;
   scanf("%d",&selector);
   if(selector == 1)
   {
     int linearkey;
     for(j=0; j<n; j++)
     {
       linearkey = genrateLinearKey(b[j]);
       a[linearkey] = b[j];
     }
       printf("\nNumbers Stored using Linear probing method!");
       printf("\n The Elements:");
     for(i=0; i<size; i++)
        printf("\n%d",a[i]);
   }
   if(selector == 2)
   {
    int quadratickey;
   for(j=0; j<n; j++)
   {
     quadratickey = genrateQuddraticKey(b[j]);
     a[quadratickey] = b[j];
   }
     printf("\nNumbers Stored using Quadratic Probing method!");
     printf("\nThe Elements:");
     for(i=0; i<size; i++)
        printf("\n%d",a[i]);
   }
   if(selector != 1 && selector != 2)
   {
       printf("Wrong Choice!");
       return 0;
   }
   /*------------------------------------------------------------------------------------*/
    printf("\n\nEnter element to search: ");
    int elekey;
    scanf("%d",&elekey);
    int searchkey;
    if(selector == 1)
      searchkey = genrateLinearKeyForDeleteAndSearch(elekey);
     else
      searchkey = genrateQuadraticKeyForDeleteAndSearch(elekey);
    int resultelement;
    resultelement = search(searchkey);
    if(resultelement == -1)
    {
        printf("Not found");
    }
    else
       {
         printf("Result Element %d",resultelement);
       }
 /*-------------------------------------------------------------------------------------*/
    printf("\n\nEnter element to Delete: ");
    int delkey;
    scanf("%d",&delkey);
    int deletekey;
    if(selector == 1)
      deletekey = genrateLinearKeyForDeleteAndSearch(delkey);
     else
     {
      q=1;
      deletekey = genrateQuadraticKeyForDeleteAndSearch(delkey);
     }
    if(deletekey>size)
    {
        printf("\nElement not found!");
    }
    else if(deletekey<size && deletekey>=0)
    {
     int temp = deleteElement(deletekey);
       if(temp == 1)
       {
        printf("\nElement Deleted");
        printf("\nNew List");
        for(i=0; i<size; i++)
        {
          printf("\n%d",a[i]);
        }
       }

        else
           printf("Slot Empty");
    }
   return 0;
}
/*---------------------------------    Linear Key    -------------------------------------------------------*/
int genrateLinearKey(int key)
 {

     key = key%size;
     if(a[key]!=-1)
     {
      key++;
      return genrateLinearKey(key);
     }
     else if(a[key]==-1)
     {
       return key;
     }
     else
     {
         printf("No Space");

     }
 }
 /*------------------------  Quadratic Key  ------------------------------------------*/
 int genrateQuddraticKey(int key)
 {
     key = key%size;
     if(a[key]!=-1)
     {
      key+=(q*q);
      q++;
      return genrateQuddraticKey(key);

     }
     else if(a[key]==-1)
     {
       return key;
     }
     else
     {
         printf("No Space");

     }
 }
 /*----------------------------  Search   -----------------------------------------*/
 int search(int key2)
  {
    if(a[key2]!= -1)
     {
       return a[key2];
     }
    else
      return -1;

  }
  /*-----------------------------  Delete  ----------------------------------------*/
  int deleteElement(int key3)
  {
     if(a[key3] != -1)
     {
      a[key3]=-1;
      return 1;
     }
     else
        return -1;

  }
/*--------------------------------Linear Key for search and Delete -------------------*/
 int genrateLinearKeyForDeleteAndSearch(int key4)
 {
     temp = key4%size;
     if(a[temp] == key4)
     return temp;
     else
        return genrateLinearKeyForDeleteAndSearch(temp++);
 }
 int genrateQuadraticKeyForDeleteAndSearch(int key5)
 {
     q++;
     temp = key5%size;
     if(a[temp] == key5)
        return temp;
     else
     {
        q*=q;
        return genrateQuadraticKeyForDeleteAndSearch(temp+q);
     }

 }
