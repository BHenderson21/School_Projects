package henderson_brandon;

import java.util.ArrayList;

//Additional OOP  requirements
//    toString properly extended				        complete
//    Constructors properly handled			            complete
//    Access properly handled (code style requirement)	complete
//
//Last tier completed: ALL (11)

public class City
{
    private ArrayList<LightRail> lines = new ArrayList<LightRail>();

    private int allFullDistance = 0;
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
        int id = this.lines.get(line).markEntry(distance);
        if(id == -1)
            return id;
        if(this.isCurrentlyFull)
        {
            this.allFullDistance += (distance - startFullDistance);
            this.startFullDistance = distance;
        }
        else if(this.isFull())
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

    public void markExit(int line, int distance, int id)
    {
        this.lines.get(line).markExit(distance, id);
        if(this.isCurrentlyFull)
        {
            this.allFullDistance += (distance - startFullDistance);
            if(this.isFull())
                this.startFullDistance = distance;
            else
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
