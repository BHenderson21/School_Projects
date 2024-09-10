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

    public void markExit(int distance)
    {
        if(distance < this.currentDistance || this.tickets.isEmpty())
            return;
        if(this.isFull())
            this.isFullDistance += (distance - this.currentDistance);
        this.tickets.removeFirst();
        this.currentDistance = distance;
    }

    public void markExit(int distance, int id)
    {
        if(distance < this.currentDistance || this.tickets.isEmpty())
            return;
        if(this.isFull())
            this.isFullDistance += (distance - this.currentDistance);

        this.tickets.removeFirst();
        this.currentDistance = distance;
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
        return "Status for " + this.getName() + " line: " + this.tickets.size() + " tickets " + currentCapacity + " FREE";
    }
}
