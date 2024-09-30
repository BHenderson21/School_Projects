package henderson_brandon;

public class Empty extends Tile
{
    private final static String symbol = "⛞";
    public void accept(IVisitor visitor)
    {
        visitor.accept(this);
    }

    public String toString()
    {
        return this.symbol;
    }
}
