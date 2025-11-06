import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        long total = a*b*c;
        String total_st = String.valueOf(total);

        int[] cnt = new int[10];

        for(int i=0; i<total_st.length(); i++) cnt[total_st.charAt(i) - '0']++;
        for(int count:cnt) System.out.println(count);
    }

}