import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static int[] dp = new int[1000002];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());

    dp[1] = 0; dp[2] = 1;
    for(int i=3; i<=n; i++){
      dp[i] = dp[i-1]+1;
      if(i%2 == 0) dp[i] = Math.min(dp[i], dp[i/2]+1);
      if(i%3 == 0) dp[i] = Math.min(dp[i], dp[i/3]+1);
    }

    System.out.println(dp[n]);
  }
}
