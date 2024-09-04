package henderson_brandon;

public class LightRail
{
    // Constructor
    public LightRail(String name, int capacity, double fee)
    {
        this.name = name;
        this.capacity = capacity;
        this.fee = fee;
        this.tickets = new Ticket[capacity];
    }

    public LightRail()
    {

    }

    public LightRail(int capacity)
    {
        this.capacity = capacity;
    }

    public LightRail(int capacity, double fee)
    {
        this.capacity = capacity;
        this.fee = fee;
        this.tickets = new Ticket[capacity];
    }

    public LightRail(String name, int capacity)
    {
        this.name = name;
        this.capacity = capacity;
        this.tickets = new Ticket[capacity];
    }

    // Properties - PUBLIC
    public String name = "test";
    public int id;
    public int capacity;
    public double fee = 1.5;
    public Ticket[] tickets;

    // Properties - PRIVATE
    private int currentDistance = 0;
    private int nextID = 0;

    // Methods
    public String getName()
    {
        return this.name;
    }

    public int getTicketsInLine()
    {
        return tickets.length;
    }

    public int markEntry(int distance)
    {
        if(this.getTicketsInLine() > this.capacity || distance < currentDistance)
            return -1;
        else
        {
            Ticket ticket = new Ticket(nextID, distance);
            nextID++;
            return 1;
        }
    }

    public void markExit(int distance, int id)
    {

    }

    public boolean isFull()
    {
        return true;
    }

    public int getIsFullDistance()
    {
        return 1;
    }

    public int getCapacity()
    {
        return this.capacity;
    }

    public double getFee()
    {
        return this.fee;
    }

    public double getProfit()
    {
        return 0;
    }
}
