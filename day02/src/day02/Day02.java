package day02;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Day02 {

	public static void main(String[] args) throws IOException 
	{
		//java standard io
		File f = new File("input.txt");
		
		//collection in memory to save input data in
		ArrayList<String> input = new ArrayList<String>();
		
		//read from file to memoy
		BufferedReader br = new BufferedReader(new FileReader(f));
		String line = null;
		while((line = br.readLine()) != null)
		{
			input.add(line);
		}
		
		//close to prevent memory leak
		br.close();
		
		//variables to count occurrences
		int twos = 0;
		int threes = 0;
		
		//loop through each string
		for(String val : input)
		{
			//to count the occurrences, a map is used to simply increment value (occurrence) for each character (key) 
			HashMap<Character, Integer> map = new HashMap<Character, Integer>();
			
			//loop through the string ( a string is a character array)
			for(Character c: val.toCharArray())
			{
				// check if character is already in map (as key)
				if(map.containsKey(c)) 
				{
					//if yes, get the value and overwrite it with its increment
					int oldVal = map.get(c);
					map.put(c, ++oldVal);
				}
				
				// otherwise create a map entry for this character (NOTE: c is used as variable for Character)
				else
				{
					map.put(c, 1);
				}
			}
		
			// now we increment 'twos' and 'threes' for each occurrence
			if(map.containsValue(2))
			{
				twos+=1;
			}
			if(map.containsValue(3))
			{
				threes+=1;
			}
		}
		
		//there you go
		System.out.println("twos: " + twos);
		System.out.println("threes: " + threes);
		System.out.println("Result: " + (twos * threes));
	}

}
