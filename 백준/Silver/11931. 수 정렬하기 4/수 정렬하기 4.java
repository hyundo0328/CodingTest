import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<Integer> list = new ArrayList<>();
        while(n-- > 0){
            int tmp = Integer.parseInt(br.readLine());
            list.add(tmp);
        }
        list.sort(Collections.reverseOrder());

        StringBuilder sb = new StringBuilder();
        for(int num:list) sb.append(num).append('\n');
        System.out.println(sb);
    }

}
