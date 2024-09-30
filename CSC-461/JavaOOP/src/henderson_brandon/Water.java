package henderson_brandon;

public class Water extends Tile
{
    public void accept(IVisitor visitor)
    {
        visitor.accept(this);
    }
}
