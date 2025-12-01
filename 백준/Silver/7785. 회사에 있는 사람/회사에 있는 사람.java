import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        HashSet<String> hash = new HashSet<>();
        while(n-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String log = st.nextToken();

            if(log.equals("enter")) hash.add(name);
            else hash.remove(name);
        }

        List<String> list = new ArrayList<>(hash);
        list.sort(Collections.reverseOrder());

        for(String name:list) System.out.println(name);
    }

}
