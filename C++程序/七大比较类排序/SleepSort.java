import java.util.Arrays;
import java.util.ArrayList;

public class SleepSort {
  public static ArrayList<Integer> sorted = new ArrayList<Integer>();
  public static void main(String [] args) {
    int [] arr = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    System.out.println("sort before: " + Arrays.toString(arr));
    SortThread[] threads = new SortThread[arr.length];
    for (int i = 0; i < threads.length; ++i) {
      threads[i] = new SortThread(arr[i], i);
    }
    for (int i = 0; i < threads.length; ++i) {
      threads[i].start();
    }
    while (true) {
      if (SleepSort.sorted.size() == arr.length) {
        System.out.println("sort after: " + SleepSort.sorted.toString());
        break;
      } else {
        try {
          Thread.sleep(500);
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
    }
  }
  public static class SortThread extends Thread {
    int number = 0;
    int index = 0;
    public SortThread(int number, int index) {
      this.number = number;
      this.index = index;
    }
    public void run() {
      try {
        sleep(this.number * 10);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      SleepSort.sorted.add(this.number);
      System.out.println("第" + (this.index + 1) + "人醒了, \t他分配的数字是: [" + this.number + "]");
    }
  }
}
