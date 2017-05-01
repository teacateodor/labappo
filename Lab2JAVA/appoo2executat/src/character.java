
class character implements Comparable<character> {
    private char ch;
    private char n;

    character(char C) {
        ch = C;
        n = (""+C).toLowerCase().charAt(0);
    }

    public character() {
        ch = '\0';
        n='\0';
    }

    @Override
    public String toString() {
        return "<" + this.ch + ":" + this.n + ">";
    }

    @Override
    public int compareTo(character o) {
        if (ch < o.ch)
            return -1;
        if (ch == o.ch)
            return 0;
        return 1;
    }

    @Override
    public boolean equals(Object obj) {
        return ch == ((character) obj).ch;
    }
}