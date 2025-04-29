import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    int[][] student = new int[7][2];

    for(int i=0; i<n; i++){
      st = new StringTokenizer(br.readLine());
      int gender = Integer.parseInt(st.nextToken());
      int grade = Integer.parseInt(st.nextToken());

      student[grade][gender]++;
    }
    int count = 0;
    for(int i=1; i<=6; i++){
      count += student[i][0] / k;
      if(student[i][0] % k != 0) count++;

      count += student[i][1] / k;
      if(student[i][1] % k != 0) count++;
    }

    System.out.println(count);
  }
}
