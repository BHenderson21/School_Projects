package henderson_brandon;

public class Horse extends Tile
{
    public void accept(IVisitor visitor)
    {
        visitor.accept(this);
    }
}
