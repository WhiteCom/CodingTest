package StackSequence;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class StackSequence {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int arraySize = Integer.parseInt(br.readLine());
		
		Integer[] stackSequence = new Integer[arraySize];
		for(int i = 0; i < stackSequence.length; i++) {
			stackSequence[i] = Integer.parseInt(br.readLine());
		}
		
		List<String> pushpopList = new ArrayList<String>();
		String success = "YES";
		
		int number = 1;
		int i = 0;
		
		Stack<Integer> stack = new Stack<Integer>();
		
		while(i < stackSequence.length) {
			if(stack.isEmpty()) {
				stack.push(number++);
				pushpopList.add("+");
			}
			else if(!stack.peek().equals(stackSequence[i])) {
				stack.push(number++);
				pushpopList.add("+");
				if(stackSequence.length + 1 < number) {
					success = "NO";
					break;
				}
			}
			else {
				stack.pop();
				pushpopList.add("-");
				i++;
			}
		}
		
		if(success == "YES") {
			for(String pushpop : pushpopList) {
				System.out.println(pushpop);
			}
		} else {
			System.out.println(success);
		}
	}
}
