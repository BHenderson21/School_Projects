package henderson_brandon;

public class FreeLightRail extends LightRail
{
    public FreeLightRail(String name, int capacity, double fee)
    {
        this.name = name;
        this.capacity = capacity;
        this.fee = fee;
        this.tickets = new Ticket[capacity];
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
        this.tickets = new Ticket[capacity];
    }

    public FreeLightRail(String name, int capacity)
    {
        this.name = name;
        this.capacity = capacity;
        this.tickets = new Ticket[capacity];
    }


    public static int FULL_THRESHOLD;


    public void markExit(int id)
    {

    }
}
