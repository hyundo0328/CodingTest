import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine());
    int x = Integer.parseInt(br.readLine());

    int[] arr = new int[n];
    for(int i=0; i<n; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }
    Arrays.sort(arr);

    int count = 0;
    int frontIndex = 0;
    int behindIndex = n-1;
    while(frontIndex < behindIndex){
      int sum = arr[frontIndex] + arr[behindIndex];
      if(sum == x){
        count ++;
        behindIndex--;
      } else if (sum < x){
        frontIndex++;
      } else if (sum > x){
        behindIndex--;
      }
    }

    System.out.println(count);
  }
}
