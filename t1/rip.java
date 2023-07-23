import java.util.*;

public class rip {
    private static void printMedian(ArrayList<Integer> arrayList) {
        double median = arrayList.get(0);
        PriorityQueue<Integer> smallerThan = new PriorityQueue<>
                (Collections.reverseOrder());
        PriorityQueue<Integer> greaterThan = new PriorityQueue<>();
        smallerThan.add(arrayList.get(0));
        System.out.println(median);
        for (int i = 1; i < arrayList.size(); i++) {
            int x = arrayList.get(i);
            if (smallerThan.size() > greaterThan.size()) {
                if (x < median) {
                    greaterThan.add(smallerThan.remove());
                    smallerThan.add(x);
                } else
                    greaterThan.add(x);
                median = (double) (smallerThan.peek() + greaterThan.peek()) / 2;
            }
            else if (smallerThan.size() == greaterThan.size()) {
                if (x < median) {
                    smallerThan.add(x);
                    median = (double) smallerThan.peek();
                } else {
                    greaterThan.add(x);
                    median = (double) greaterThan.peek();
                }
            } else {
                if (x > median) {
                    smallerThan.add(greaterThan.remove());
                    greaterThan.add(x);
                } else
                    smallerThan.add(x);
                median = (double) (smallerThan.peek() + greaterThan.peek()) / 2;

            }
            System.out.println(median);
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        ArrayList<Integer> arrayList = new ArrayList<>();
        while (true){
            int num = input.nextInt();
            if (num!=-1)
            arrayList.add(num);
            else break;
        }
        printMedian(arrayList);
    }
}