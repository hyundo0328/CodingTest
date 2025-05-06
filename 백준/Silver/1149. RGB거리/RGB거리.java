import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;

    int t = Integer.parseInt(br.readLine());

    int[][] house = new int[1002][3];
    int[][] dp = new int[1002][3];

    for(int i=1; i<=t; i++){
      st = new StringTokenizer(br.readLine());
      house[i][0] = Integer.parseInt(st.nextToken());
      house[i][1] = Integer.parseInt(st.nextToken());
      house[i][2] = Integer.parseInt(st.nextToken());
    }
    dp[1][0] = house[1][0]; dp[1][1] = house[1][1]; dp[1][2] = house[1][2];

    for(int i=2; i<=t; i++){
      dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + house[i][0];
      dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + house[i][1];
      dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + house[i][2];
    }

    System.out.println(Math.min(dp[t][0], Math.min(dp[t][1], dp[t][2])));
  }
}
