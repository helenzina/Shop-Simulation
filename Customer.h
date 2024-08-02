#ifndef CUSTOMER_H
#define CUSTOMER_H
#define M 21

class Customer
{
   protected:
      int custNo;  //kwdikos pelath
      char custName[M];  //onomatepwnymo pelath
      char custEmail[M];  //email pelath
   public:
      Customer();
      Customer(int custNo1, char custName1[], char custEmail1[]);
      void readData();
      void setData(int custNo1, char custName1[], char custEmail1[]);
      void printData();
      int getCustNo();
      char* getCustName();
      char* getCustEmail();
};

#endif
