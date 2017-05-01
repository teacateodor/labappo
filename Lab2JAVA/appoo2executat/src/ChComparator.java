import java.util.Comparator;

public class ChComparator implements Comparator<character> {

    @Override
    public int compare(character o1, character o2) {
        return o1.compareTo(o2);
    }
}
