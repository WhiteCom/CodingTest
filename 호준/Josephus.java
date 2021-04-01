package Josephus;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Josephus {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String command[] = br.readLine().split(" ");
		List<Integer> circleList = new ArrayList<Integer>();
		
		int value = 1;
		int size = Integer.parseInt(command[0]);
		for(int i = 0; i < size; i++) {
			circleList.add(value++);
		}
		
		System.out.print("<");
		int idx = Integer.parseInt(command[1])-1;
		int idxFix = Integer.parseInt(command[1])-1;
		while(!circleList.isEmpty()) {
			if(circleList.size() == 1) {
				System.out.print(circleList.remove(idx) + ">");
				break; // 하단의 while 문에서 무한루프에 걸리지 않기 위해 break 로 반복문 탈출
			} else
				System.out.print(circleList.remove(idx) + ", ");
			idx += idxFix;
			while(idx >= circleList.size()) idx = idx - circleList.size();
		}
		
		br.close();
	}
}
