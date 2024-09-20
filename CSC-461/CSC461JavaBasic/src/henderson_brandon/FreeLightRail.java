package henderson_brandon;

public class FreeLightRail extends LightRail
{
    public FreeLightRail(int capacity)
    {
        super(capacity);
    }

    public FreeLightRail(String name, int capacity)
    {
        super(name, capacity);
    }

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
        return super.toString();
    }

    @Override
    public String getMoney()
    {
        return " FREE";
    }
}
