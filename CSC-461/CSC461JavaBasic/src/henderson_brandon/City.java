package henderson_brandon;

import java.util.ArrayList;

public class City
{
    private ArrayList<LightRail> lines = new ArrayList<LightRail>();
    private int allFullDistance = 0;
    private int currentDistance = 0;
    private Boolean isCurrentlyFull = false;
    private int startFullDistance = 0;

    public int getTicketsInCity()
    {
        int tickets = 0;
        for(int i = 0; i < lines.size(); i++)
            tickets += lines.get(i).getTicketsInLine();
        return tickets;
    }

    public int getIsFullDistance()
    {
        return this.allFullDistance;
    }

    public double getTotalMoneyCollected()
    {
        double profit = 0;
        for(int i = 0; i < this.lines.size(); i++)
            profit += this.lines.get(i).getProfit();
        return profit;
    }

    public int add(LightRail rail)
    {
        this.lines.add(rail);
        return this.lines.size()-1;
    }

    public int markEntry(int line, int distance)
    {
        this.currentDistance = distance;
        int id = this.lines.get(line).markEntry(distance);
        if(!this.isCurrentlyFull && this.isFull())
        {
            this.isCurrentlyFull = true;
            this.startFullDistance = distance;
        }
        return id;
    }

    public boolean isFull()
    {
        for(int i = 0; i < this.lines.size(); i++)
        {
            if(!this.lines.get(i).isFull())
                return false;
        }
        return true;
    }

    public void markExit(int line, int id, int distance)
    {
        this.lines.get(line).markExit(id, distance);
        if(this.isCurrentlyFull && !this.isFull())
        {
            System.out.println("Add to full distance: " + (this.startFullDistance - distance));
            this.isCurrentlyFull = false;
        }
    }

    public LightRail getLine(int id)
    {
        return this.lines.get(id);
    }


    public String toString()
    {
        String output = "";
        output += "City status:\n";
        for(int i = 0; i < this.lines.size(); i++)
            output += this.lines.get(i).toString() + "\n";
        return output;
    }
}
