import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static HashMap<String, String> hash = new HashMap<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        while(n-- > 0){
            st = new StringTokenizer(br.readLine());
            String link = st.nextToken();
            String password = st.nextToken();

            hash.put(link, password);
        }

        while(m-- > 0){
            String password = br.readLine();
            System.out.println(hash.get(password));
        }
    }

}
