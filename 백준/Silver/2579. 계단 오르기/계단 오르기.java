import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int t = Integer.parseInt(br.readLine());

    int[] stair = new int[302];
    int[][] dp = new int[302][2];

    for(int i=1; i<=t; i++){
      stair[i] = Integer.parseInt(br.readLine());
    }

    dp[1][0] = stair[1]; dp[2][0] = stair[2]; dp[2][1] = stair[1] + stair[2];
    for(int i=3;i<=t;i++){
      dp[i][0] = Math.max(dp[i-2][0], dp[i-2][1]) + stair[i];
      dp[i][1] = dp[i-1][0] + stair[i];
    }

    System.out.println(Math.max(dp[t][0], dp[t][1]));
  }
}
