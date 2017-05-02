import sun.misc.*;

import java.util.*;
import java.util.Queue;

public class Lab {
    public static void main(String[] args) {


        Set<character> set = new HashSet<character>();
        for(char c='A'; c<'E'; c++)
        {
            set.add(new character(c));
        }
        for(char c='!'; c<'%'; c++)
        {
            set.add(new character(c));
        }

        character[] arr = set.toArray(new character[set.size()]);
        Arrays.sort(arr, new reChComparator());
        System.out.println("Setul sortat descrescator:\n\t" + Arrays.toString(arr));

        character ch1 = new character('B');
        boolean found = Arrays.stream(arr).anyMatch(x -> ch1.equals(x));
        System.out.println("\nElementul "+ ch1 + (found?"":" nu") + " a fost gasit.");

        character ch2 = new character('Z');
        found = Arrays.stream(arr).anyMatch(x -> ch2.equals(x));
        System.out.println("Elementul "+ ch2 + (found?"":" nu") + " a fost gasit.");

        character zero = new character('!');
        character nine = new character('%');
        Queue queue = new LinkedList();
        for (character ch : set){

            if((ch.compareTo(zero)>=0) && (ch.compareTo(nine)<=0))
            {
                queue.add(ch);
            }
        }
        System.out.println("\nCoada:\n\t" + queue);

        Arrays.sort(arr, new ChComparator());
        System.out.println("\nSetul sortat crescator:\n\t" + Arrays.toString(arr));

        arr = (character[]) queue.toArray(new character[queue.size()]);// .toArray(new character[queue.size()]);//newqueue.toArray()..(new ChComparator());
        Arrays.sort(arr, new ChComparator());

        System.out.println("\nCoada sortata crescator:\n\t" + Arrays.toString(arr));

        while (!queue.isEmpty())
        {
            set.add((character) queue.element());
        }
        System.out.println("\nSetul combinat cu coada:\n\t" + set);

        int count = 0;
        for(character ch : set)
        {
            if((ch.compareTo(zero)>=0) && (ch.compareTo(nine)<=0))
            {
                count++;
            }
        }
        System.out.println("\nAu fost gasite "+ count +" caractere cifre.");

        arr = set.toArray(new character[set.size()]);
        character ch3 = new character('@');
        found = Arrays.stream(arr).anyMatch(x -> ch3.equals(x));
        System.out.println("\nElementul "+ ch3 + (found?"":" nu") + " a fost gasit.");
    }
}
