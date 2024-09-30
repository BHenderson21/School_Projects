package henderson_brandon;

public abstract class Tile
{
    char symbol;
    ColorText.Color color;
    int x;
    int y;

    abstract void accept(IVisitor visitor);
}
