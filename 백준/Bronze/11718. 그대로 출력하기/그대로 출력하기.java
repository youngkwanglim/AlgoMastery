import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String st;

        while ((st = br.readLine()) != null) {
            bw.write(st);
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}