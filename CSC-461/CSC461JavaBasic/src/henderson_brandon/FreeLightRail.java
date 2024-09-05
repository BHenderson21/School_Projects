package henderson_brandon;

public class FreeLightRail extends LightRail
{
    public FreeLightRail(String name, int capacity, double fee)
    {
        this.name = name;
        this.capacity = capacity;
        this.fee = fee;
    }

    public FreeLightRail()
    {

    }

    public FreeLightRail(int capacity)
    {
        this.capacity = capacity;
    }

    public FreeLightRail(int capacity, double fee)
    {
        this.capacity = capacity;
        this.fee = fee;
    }

    public FreeLightRail(String name, int capacity)
    {
        this.name = name;
        this.capacity = capacity;
    }


    public static int FULL_THRESHOLD = 90;


    public void markExit(int id)
    {

    }
}
