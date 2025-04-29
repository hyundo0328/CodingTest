import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    Long num = 0L;
    Long a, b, c;
    int[] numList = new int[10];

    a = Long.valueOf(br.readLine());
    b = Long.valueOf(br.readLine());
    c = Long.valueOf(br.readLine());

    num = a*b*c;

    while(num > 0){
      numList[(int) (num%10)]++;

      num /= 10;
    }

    for(int i:numList){
      System.out.println(i);
    }
  }
}
