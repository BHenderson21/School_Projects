package henderson_brandon;

public class Grass extends Tile
{
    public void accept(IVisitor visitor)
    {
        visitor.accept(this);
    }
}
