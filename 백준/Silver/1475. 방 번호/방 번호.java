import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n; n = Integer.parseInt(br.readLine());

    int[] num = new int[10];
    int count = 0;
    while(n > 0){
      if(n%10 == 6 || n%10 == 9){
        if(num[6] > num[9]) num[9]++;
        else num[6]++;
      } else {
        num[n%10]++;
      }

      n /= 10;
    }

    System.out.println(Arrays.stream(num).max().getAsInt());
  }
}
