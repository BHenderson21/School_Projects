package henderson_brandon;

import java.util.ArrayList;

public class City
{
    private ArrayList<LightRail> lines;
    private int nextID = 0;

    public int getTicketsInCity()
    {
        int tickets = 0;
        for(int i = 0; i < lines.size(); i++)
            tickets += lines.get(i).getTicketsInLine();
        return tickets;
    }

    public int getIsFullDistance()
    {
        return -1;
    }

    public double getTotalMoneyCollected()
    {
        return 0;
    }

    public int add(LightRail rail)
    {
        this.lines.add(rail);
    }

    public int markEntry(int line, int distance)
    {
        return -1;
    }

    public boolean isFull()
    {
        return false;
    }

    public void markExit(int line, int id, int distance)
    {

    }

    public LightRail getLine(int id)
    {
        return null;
    }


    public String toString()
    {
        System.out.println("City status:");
    }
}
