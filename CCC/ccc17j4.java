import java.util.*;

public class Main {
  public static void main (String[] args) {
    Scanner cin = new Scanner (System.in);
    int [] dp = new int[60*12+1];
    int m = 1, h = 0;
    //while loop simulates all the different times within a 12 hour cycle;
    while (h != 0 || m != 0) {
      m++;
      if (m % 60 == 0) {
        m = 0;
        h++;
      }
      if (h > 12) {
        h -= 12;
      }
      dp[h*60+m] += dp[h*60+m - 1];
      //0 is the same as 12 hours, but for the sequence and outofbound's sake I have to convert
      if (h == 0) {
        h = 12;
      }
      
      //check if sequence is arithmetic
      String temp;
      //if minutes is less than 9, then we have to add a '0' in the tens minute digit
      if (m > 9) {
        temp = Integer.toString(h) + Integer.toString(m);
      } else {
        temp = Integer.toString(h) + "0" + Integer.toString(m);
      }
      int firstDiff = (int)temp.charAt(1) - (int)temp.charAt(0);
      boolean arithmetic = true; //assume it is a valid sequence to start off
      for (int x = 2; x < temp.length(); x++) {
        if ((int)temp.charAt(x) - (int)temp.charAt(x - 1) != firstDiff) {
          arithmetic = false; //first difference is not consistant
          break;
        }
      }
      //convert back to 0, if I converted to 12 earlier
      if (h == 12) {
        h = 0;
      }
      if (arithmetic) {
        dp[h*60+m]++;
      }
    }
    int n = cin.nextInt();
    if (n <= 60*12) {
      System.out.println(dp[n]);
    } else {
      System.out.println((dp[720]*((n-n%720)/720) + dp[n%720]));
    }
  }
}
