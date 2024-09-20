package henderson_brandon;

import java.text.DecimalFormat;
import java.util.ArrayList;

public class LightRail
{
    // GRADING: CONSTRUCTION
    public LightRail(String name, int capacity, double fee)
    {
        this.name = name;
        this.capacity = capacity;
        this.fee = fee;
    }

    public LightRail(int capacity)
    {
        this("test", capacity, 1.5);
    }

    public LightRail(int capacity, double fee)
    {
        this("test", capacity, fee);
    }

    public LightRail(String name, int capacity)
    {
        this(name, capacity, 1.5);
    }

    // Properties - PUBLIC
    public int currentDistance = 0;
    public int isFullDistance = 0;
    public ArrayList<Ticket> tickets = new ArrayList<Ticket>();
    public static int FULL_THRESHOLD = 90;

    // Properties - PRIVATE
    private int nextID = 0;
    private double currentProfit = 0;
    private String name = "test";
    private int capacity;
    private double fee = 1.5;

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
            if(this.isFull())
                this.isFullDistance += (distance - this.currentDistance);
            Ticket ticket = new Ticket(nextID, distance);
            this.tickets.add(ticket);
            this.currentDistance = distance;
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
            if(this.isFull())
                this.isFullDistance += (distance - this.currentDistance);
            for(int i = 0; i < this.tickets.size(); i++)
            {
                if(this.tickets.get(i).id == id)
                {
                    double profit = (Math.floor((double) (distance - this.tickets.get(i).entryDistance) / 4)) * this.fee;
                    this.currentProfit += profit;
                    this.currentDistance = distance;
                    this.tickets.remove(i);
                    return;
                }
            }
        }
    }

    public boolean isFull()
    {
        if(((double)this.tickets.size() / this.capacity) >= FULL_THRESHOLD*0.01)
            return true;
        return false;
    }

    public int getIsFullDistance()
    {
        return this.isFullDistance;
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
        {
            double result = ((double)this.tickets.size()/this.capacity) * 100;
            if(result % 1 == 0)
                currentCapacity =   "(" + String.format("%d", (int) result) + "%)";
            else
                currentCapacity = "(" + String.format("%.1f", result) + "%)";
        }
        return "Status for " + this.getName() + " line: " + this.tickets.size() + " tickets " + currentCapacity + this.getMoney();
    }

    public String getMoney()
    {
        return " Money Collected: $" + String.format("%.2f", this.getProfit());
    }
}
