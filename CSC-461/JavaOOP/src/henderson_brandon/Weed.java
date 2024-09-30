package henderson_brandon;

public class Weed extends Tile
{
    public void accept(IVisitor visitor)
    {
        visitor.accept(this);
    }
}
