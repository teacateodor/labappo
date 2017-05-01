import java.util.Comparator;

public class reChComparator implements Comparator<character> {

    @Override
    public int compare(character o1, character o2) {
        return o2.compareTo(o1);
    }
}

