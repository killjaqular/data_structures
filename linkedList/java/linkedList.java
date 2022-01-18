/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
linkedList.java

@description
Java implementation of a linked list structure.

Example:
CLI
user@host#>java linkedList 10 4 2 6 5
10[10]
4[10, 4]
2[10, 4, 2]
6[10, 4, 2, 6]
5[10, 4, 2, 6, 5]
5[10, 4, 2, 6]
6[10, 4, 2]
2[10, 4]
4[10]
10[]

STDIN
user@host#>java linkedList < someFile
10[10]
4[10, 4]
2[10, 4, 2]
6[10, 4, 2, 6]
5[10, 4, 2, 6, 5]
5[10, 4, 2, 6]
6[10, 4, 2]
2[10, 4]
4[10]
10[]
*/

// STANDARD LIBRARIES
import java.util.LinkedList;
import java.util.Scanner;

// NON-STANDARD LIBRARIES
// NONE

class linkedList{
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<Integer>();
        Integer value = 0;

//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARGS//ARG
        if(args.length > 0){
            for(String cli : args){
                value = Integer.parseInt(cli);
                System.out.print(value);
                list.add(value);
                System.out.println(list);
            }

            for(Integer counter = 0; counter < args.length; counter++){
                value = list.remove(list.size() - 1);
                System.out.print(value);
                System.out.println(list);
            }

//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STD
        }else{
            Integer total  = 0;
            Scanner reader = new Scanner(System.in);

            while(reader.hasNextInt()){
                value = reader.nextInt();
                System.out.print(value);
                list.add(value);
                System.out.println(list);
                total++;
            }

            for(Integer counter = 0; counter < total; counter++){
                value = list.remove(list.size() - 1);
                System.out.print(value);
                System.out.println(list);
            }
        }
        return;
    }
// METHODS
// NONE
}
