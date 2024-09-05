package henderson_brandon;

import java.text.DecimalFormat;
import java.util.ArrayList;

public class LightRail
{
    // Constructor
    public LightRail(String name, int capacity, double fee)
    {
        this.name = name;
        this.capacity = capacity;
        this.fee = fee;
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
    }

    public LightRail(String name, int capacity)
    {
        this.name = name;
        this.capacity = capacity;
    }

    // Properties - PUBLIC
    public String name = "test";
    public int id;
    public int capacity;
    public double fee = 1.5;
    public ArrayList<Ticket> tickets = new ArrayList<Ticket>();

    // Properties - PRIVATE
    private int currentDistance = 0;
    private int nextID = 0;
    private double currentProfit = 0;
    private int isFullDistance = 0;

    // Methods
    public String getName()
    {
        return this.name;
    }

    public int getTicketsInLine()
    {
        return tickets.size();
    }

    public int markEntry(int distance)
    {
        if(this.getTicketsInLine() >= this.capacity || distance < this.currentDistance)
            return -1;
        else
        {
            Ticket ticket = new Ticket(nextID, distance);
            this.tickets.add(ticket);
            this.currentDistance = distance;
            if(this.isFull())
                this.isFullDistance += distance;
            this.nextID++;
            return ticket.id;
        }
    }

    public void markExit(int distance, int id)
    {
        if(distance < this.currentDistance)
            return;
        else
        {
            for(int i = 0; i < this.tickets.size(); i++)
            {
                if(this.tickets.get(i).id == id)
                {
                    this.currentDistance = distance;
                    double profit = ((double) (this.currentDistance - this.tickets.get(i).entryDistance) / 4) * this.fee;
                    this.currentProfit += profit;
                    this.tickets.remove(i);
                    return;
                }
            }
        }
    }

    public boolean isFull()
    {
        if(((double)this.tickets.size() / this.capacity) >= 0.9)
            return true;
        return false;
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
        return this.currentProfit;
    }

    public String toString()
    {
        String currentCapacity;
        if(this.isFull())
            currentCapacity = "(FULL)";
        else
            currentCapacity = "(" + ((double)this.tickets.size()/this.capacity) + ")";
        DecimalFormat df = new DecimalFormat("#.##");
        return "Status for " + this.getName() + " line: " + this.tickets.size() + " tickets " + currentCapacity + " Money Collected: $" + String.format("%.2f", this.getProfit());
    }
}
