 // Writing data randomly to a random-access file
    #include <stdio.h>

    // clientData structure definition
    struct employeeData {
    unsigned int empID; // account number
    char Name[ 15 ]; // account last name
    char Address[ 10 ]; // account first name
    int number; // account balance
    }; // end structure clientData

    int main( void )  {
    FILE *fp; // credit.dat file pointer
    int i,record;

    // create clientData with default information
    struct employeeData employee = { 0, "", "", 0 };
    fp=fopen("employee.dat","w");


    // fopen opens the file; exits if file cannot be opened
    if ( ( fp = fopen( "employee.dat", "rb+" ) ) == NULL ) {
      puts( "File could not be opened." );
    } // end if
    else {

    // require user to specify account number
      printf( "%s"," Enter how many records you want to make ?\n " );
      scanf( "%d", &record );
    printf("Enter employee details\n");
    // user enters information, which is copied into file
    for( i=0; i<record; i++ )
        {

    // user enters last name, first name and balance
    printf( "%s", "Enter Name, Address, number\n " );

    // set record lastName, firstName and balance value
    fscanf( stdin, "%14s%9s%lf", employee.Name,
              employee.Name, &employee.number );
    // seek position in file to user-specified record
      fseek( fp, (employee.empID - 1 ) *
            sizeof( struct employeeData ), SEEK_SET );

    // write user-specified information in file
      fwrite( &employee, sizeof( struct employeeData ), 1, fp );

    // enable user to input another account number
      printf( "%s", "Enter employee ID\n " );
      scanf( "%d", &employee.empID );
      } // end while
      fclose( fp); // fclose closes the file
      } // end else
    } // end main
