import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static int n;
  public static int[] arr;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;

    n = Integer.parseInt(br.readLine());
    st = new StringTokenizer(br.readLine());

    arr = new int[n];
    for(int i=0; i<n; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }
    Arrays.sort(arr);

    int m = Integer.parseInt(br.readLine());
    st = new StringTokenizer(br.readLine());
    while(m-- > 0){
      int num = Integer.parseInt(st.nextToken());

      System.out.println(binarySearch(num));
    }
  }

  public static int binarySearch(int target){
    int st = 0;
    int en = n-1;
    while(st <= en){
      int mid = (st+en)/2;
      if(arr[mid] < target)
        st = mid+1;
      else if(arr[mid] > target)
        en = mid-1;
      else
        return 1;
    }
    return 0;
  }
}
