package henderson_brandon;

public interface IVisitor
{
    void accept(Empty empty);
    void accept(Horse horse);
    void accept(Grass grass);
    void accept(Weed weed);
    void accept(Water water);
}
