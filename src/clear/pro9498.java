package clear;

import java.util.Scanner;

public class pro9498 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int score = scanner.nextInt();

        switch (score/10){
            case 10:
            case 9:
                System.out.print("A");
                break;

            case 8:
                System.out.print("B");
                break;

            case 7:
                System.out.print("C");
                break;

            case 6:
                System.out.print("D");
                break;

            default :
                System.out.print("F");
        }

    }
}
