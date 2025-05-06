import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;

    st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    int[] dp = new int[100002];
    st = new StringTokenizer(br.readLine());
    for(int i=1; i<=n; i++){
      int num = Integer.parseInt(st.nextToken());
      dp[i] = num + dp[i-1];
    }

    while(m-- > 0){
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      System.out.println(dp[b] - dp[a-1]);
    }
  }
}
