import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static HashMap<String, Integer> dogam = new HashMap<>();
    public static String[] arr = new String[100005];
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i=1; i<=n; i++){
            arr[i] = br.readLine();
            dogam.put(arr[i], i);
        }

        find(m);
    }

    public static void find(int m) throws IOException {
        while(m-- > 0){
            String query = br.readLine();
            if(Character.isDigit(query.charAt(0))) System.out.println(arr[Integer.parseInt(query)]);
            else System.out.println(dogam.get(query));
        }
    }

}
