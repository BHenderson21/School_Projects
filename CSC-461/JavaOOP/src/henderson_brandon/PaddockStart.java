package henderson_brandon;

import java.util.Scanner;

public class PaddockStart {
    public static Scanner cin;
    public static void main(String[] args) {

        Paddock c = new Paddock();
        cin = new Scanner(System.in);
        String menu =
                """
                1) Set Tile
                2) Make Default Paddock
                3) Count Zones
                4) Set Tile Color
                5) Grass Health
                6) Time Step
                0) Quit
                """;

        int input = -1;
        while(input != 0) {
            System.out.println(c);
            System.out.println(menu);
            System.out.print("Choice:> ");

            input = cin.nextInt();
        }


    }

}
