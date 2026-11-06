import java.util.Scanner;

abstract class Flight {
    abstract int getMile();

    int getPrice(boolean peak) {
        int price;
        if (getMile() <= 500)
            price = 100;
        else if (getMile() <= 800)
            price = 150;
        else
            price = 200;
        if (peak)
            price += 50;
        return price;
    }
}

class NewYorkFlight extends Flight {
    @Override int getMile() {
        return 700;
    }
} class ManilaFlight extends Flight {
    @Override int getMile() {
        return 400;
    }
} class LondonFlight extends Flight {
    @Override int getMile() {
        return 1200;
    }
}

public class Main {
  public
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(">> 출발일을 입력하세요");
        String date = sc.nextLine();
        boolean peak = date.contains("May") || date.contains("Jun") || date.contains("Jul");

        System.out.println(">> 몇장의 티켓을 구매하겠습니까?");
        int count = Integer.parseInt(sc.nextLine());
        while (count > 2) {
            System.out.println(">> 티켓이 없습니다. 2명이하로 다시입력하세요");
            count = Integer.parseInt(sc.nextLine());
        }

        System.out.println(">> 도착지를 입력하세요");
        String city = sc.nextLine();
        Flight f;
        if (city.equals("London"))
            f = new LondonFlight();
        else if (city.equals("Manila"))
            f = new ManilaFlight();
        else if (city.equals("New York"))
            f = new NewYorkFlight();
        else {
            System.out.println(">> 취항하지 않는 도시입니다.");
            return;
        }

        System.out.println(">> 성공적으로 티켓을 구매하셨습니다. 가격은 " +
                           (f.getPrice(peak) * count) + "만원 입니다.");
    }
}
