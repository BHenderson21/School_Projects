package henderson_brandon;

import java.text.DecimalFormat;

/**
 * @author Dr. Lisa Rebenitsch
 */
public class LightRailTests {

    private static final String ERROR_MARK = ">>>>>>>>>>>>>>";
    //monitor for error
    private static Boolean haveError = false;

    /**
     * Main test method: calls other tests.
     *
     * @param args Ignored command-line arguments
     */
    public static void main(String[] args) {
        tier01_SmallLine();
        checkForEarlyStop();

        tier02_ComingAndGoing();
        checkForEarlyStop();

        tier03_FeeCalculation();
        checkForEarlyStop();

        tier04_CheckForGlitches();
        checkForEarlyStop();

        tier05_FreeSmallLine();
        checkForEarlyStop();

        tier06_FreeComingAndGoing();
        checkForEarlyStop();

        tier07_FeeCalculation();
        checkForEarlyStop();

        tier08_CheckForGlitches();
        checkForEarlyStop();

        tier09_testTinyFreeCity();
        checkForEarlyStop();

        tier10_testPaidCity();
        checkForEarlyStop();

        tier11_testMixedAndGlitchyCity();
        checkForEarlyStop();

        System.out.println("All tests finished.");
    }


    private static void checkForLineGlitches(LightRail line) {
        int id1 = line.markEntry(50);
        if ( line.getTicketsInLine() != 1 )
            printError(" Error: expecting 1 ticket at distance 50.");

        // try to enter, exit in past
        int id2 = line.markEntry(49);
        if ( id2 != -1 )
            printError(" Error: entry should have failed.");
        if ( line.getTicketsInLine() != 1 )
            printError(" Error: expecting 1 ticket at distance -1A. Got: " + line.getTicketsInLine());
        line.markExit(49, id1);
        if ( line.getTicketsInLine() != 1 )
            printError(" Error: expecting 1 ticket at distance -1B. Got: " + line.getTicketsInLine());

        // enter, exit all at once
        int id3 = line.markEntry(51);
        int id4 = line.markEntry(51);
        int id5 = line.markEntry(51);
        if ( line.getTicketsInLine() != 4 )
            printError(" Error: expecting 4 tickets at distance 51. Got: " + line.getTicketsInLine());
        if ( line.isFull() )
            printError(" Error: line should not be full at distance 51. Got: " + line.getTicketsInLine());
        int id6 = line.markEntry(51);
        int id7 = line.markEntry(51);
        if ( line.getTicketsInLine() != 6 )
            printError(" Error: expecting 5 tickets at distance 51b. Got: " + line.getTicketsInLine());
        if ( !line.isFull() )
            printError(" Error: line should be full at distance 51b. Got: " + line.getTicketsInLine());

        //overfill
        int id8 = line.markEntry(52);
        if ( line.getTicketsInLine() != 6 )
            printError(" Error: expecting 6 tickets at distance 52. Got: " + line.getTicketsInLine());
        if ( id8 != -1 )
            printError(" Error: car should have been denied.");

        //remove everything
        line.markExit(53, id1);
        line.markExit(53, id3);
        line.markExit(53, id4);
        line.markExit(53, id5);
        line.markExit(53, id6);
        line.markExit(53, id7);
        if ( line.getTicketsInLine() != 0 )
            printError(" Error: expecting 0 tickets at distance 53. Still had: " + line.getTicketsInLine());

        //try a double removal
        line.markExit(53, id6);
        if ( line.getTicketsInLine() != 0 )
            printError(" Error: expecting 0 tickets at distance 53.");

        if ( line.getIsFullDistance() != 2 )
            printError(" Error: expecting 2 minutes full at distance 51c. Got: " + line.getIsFullDistance());
    }

    private static void TestComingAndGoing(LightRail busy) {
        int id0 = busy.markEntry(5);
        int id1 = busy.markEntry(10);
        int id2 = busy.markEntry(12);

        //check ids
        if ( id0 != 0 )
            printError(" IDs should start at 0.");
        if ( id1 != 1 )
            printError(" The next ID must be 1.");
        if ( id2 != 2 )
            printError(" The next ID must be 2.");
        if ( busy.isFull() )
            printError(" Error: Busy line should not be full at distance 12");


        //fill line
        int id3 = busy.markEntry(15);
        int id4 = busy.markEntry(15);
        int id5 = busy.markEntry(15);
        int id6 = busy.markEntry(15);
        int id7 = busy.markEntry(15);
        int id8 = busy.markEntry(15);
        if ( !busy.isFull() )
            printError(" Error: Busy line should be full at distance 15");
        if ( busy.getIsFullDistance() != 0 )
            printError(" Error: no distance update yet, so total full minutes is still 0");
        if ( busy.getTicketsInLine() != 9 )
            printError(" Error: Busy line should have 9 tickets at distance 15");

        //push to max capacity
        int id9 = busy.markEntry(20);
        if ( busy.getTicketsInLine() != 10 )
            printError(" Error: Busy line should have 10 tickets at distance 20");
        if ( busy.getIsFullDistance() != 5 )
            printError(" Error: New entry, so total distance full updates to 5");

        //test incrementing of is full distance
        busy.markExit(23, id0);
        if ( busy.getTicketsInLine() != 9 )
            printError(" Error: Busy line should have 9 tickets at distance 23");
        if ( busy.getIsFullDistance() != 8 )
            printError(" Error: New exit, so total distance full updates to 8. Got: " + busy.getIsFullDistance());

        //reopen line
        busy.markExit(25, id1);
        if ( busy.getIsFullDistance() != 10 )
            printError(" Error: busy line should have been full for 10 minutes at distance 30");

        //refill
        int id10 = busy.markEntry(33);
        int id11 = busy.markEntry(35);
        if ( !busy.isFull() )
            printError(" Error: Busy line should be full at distance 35");
        if ( busy.getIsFullDistance() != 12 )
            printError(" Error: Line full again, so total distance full updates to 12. Got: " + busy.getIsFullDistance());
        if ( busy.getTicketsInLine() != 10 )
            printError(" Error: Busy line should have 10 tickets at distance 35");

        //empty line
        busy.markExit(45, id3);
        if ( busy.getTicketsInLine() != 9 )
            printError(" Error: Busy line should have 9 tickets at distance 45");
        busy.markExit(50, id9);
        busy.markExit(54, id10);
        busy.markExit(60, id11);
        busy.markExit(60, id2);
        busy.markExit(60, id4);
        busy.markExit(60, id5);
        busy.markExit(60, id6);
        busy.markExit(60, id7);
        busy.markExit(60, id8);
        if ( busy.getIsFullDistance() != 27 )
            printError(" Error: busy line should have been full for 27 miles");
        if ( busy.getTicketsInLine() != 0 )
            printError(" Error: Busy line should be empty at end");
    }

    private static void TestEntryStrings(LightRail busy, String[] results) {
        //test strings
        busy.markEntry(1);
        busy.markEntry(1);
        busy.markEntry(1);
        if ( !busy.toString().equals(results[0]) ) {
            printError(" Incorrect open string result ");
            showBeforeAfter(busy.toString(), results[0]);
        }
        busy.markEntry(1);
        if ( !busy.toString().equals(results[1]) ) {
            printError(" Incorrect second open string result ");
            showBeforeAfter(busy.toString(), results[1]);
        }
        busy.markEntry(1);

        busy.markEntry(1);
        if ( !busy.toString().equals(results[2]) ) {
            printError(" Incorrect full result ");
            showBeforeAfter(busy.toString(), results[2]);
        }
    }


    ///////////////////////////////////////////////////////////
    // district tests

    private static void TestSmallLost(LightRail singleSeatLine, String targetOutput) {

        //check variables
        if ( Math.abs(FreeLightRail.FULL_THRESHOLD - 90) > 0.01 )
            printError("Incorrect threshold for full line.");
        if ( singleSeatLine.isFull() )
            printError("Empty paid seat is full.");

        //check entry status
        int id = singleSeatLine.markEntry(5);
        if ( id != 0 )
            printError(" IDs should start at 0.");
        if ( !singleSeatLine.isFull() )
            printError(" Paid seat with something in it is full.");
        if ( !singleSeatLine.toString().equals(targetOutput) ) {
            printError(" Incorrect string result ");
            showBeforeAfter(singleSeatLine.toString(), targetOutput);
        }

        //check ticket exited and full count
        singleSeatLine.markExit(400, id);
        if ( singleSeatLine.getTicketsInLine() != 0 )
            printError(" Empty singleSeatLine should have no tickets in it.");
        if ( singleSeatLine.getIsFullDistance() != 395 )
            printError(" Wrong number of minutes while sleeping overnight.");
    }

    /**
     * Watches for a error call, and ends cleanly
     */
    private static void checkForEarlyStop() {
        System.out.println();
        if ( !haveError )
            return;

        System.err.println("\n\nA tier was not passed. Later teirs not tested");
        System.exit(0);
    }

    private static void glitchyCityRetest(City town){
        DecimalFormat format = new DecimalFormat("#.##");

        if ( town.getTicketsInCity() != 8 )
            printError(" Expected 8 tickets in town. Got: " + town.getTicketsInCity());

        if ( town.getIsFullDistance() != 4 )
            printError(" At end of day, all lines should be full 4 minutes. They were full "
                    + town.getIsFullDistance() + " min.");

        if ( Math.abs(town.getTotalMoneyCollected() - 70) > 0.01 )
            printError(" At end of day, $70 should have been collected. $"
                    + format.format(town.getTotalMoneyCollected()) + " was collected.");

    }


    //helper function to both set a flag and output a error in easy to catch format
    private static void printError(String str) {
        haveError = true;
        System.err.println(ERROR_MARK + str);
    }

    /**
     * Helper function when the check is a long string
     *
     * @param actual   the target string of the show
     * @param expected what was actually returned
     */
    private static void showBeforeAfter(String actual, String expected) {

        String indent = "    ";
        printError(" Got this (indented added for readability):");
        printError(indent + actual.replace("\n", "\n" + indent));
        printError(" Needed this:");
        printError(indent + expected.replace("\n", "\n" + indent));
        printError("");

    }

    /**
     * Test creating a line with a single space.
     */
    public static void tier01_SmallLine() {
        System.out.println("Tier 1: Testing a line with one seat (no fee calculation needed)..................................");

        String targetOutput = "Status for Single Seat line: 1 tickets (FULL) Money Collected: $0.00";

        //check default constructors
        LightRail defaultLine = new LightRail(1);
        if ( defaultLine.getName().equals("Test") )
            printError(" Default name should not be capitalized.");
        if ( !defaultLine.getName().equals("test") )
            printError(" Default name is not working with constructor with one parameter.");
        if ( defaultLine.getCapacity() != 1 )
            printError(" Default constructor did not accept capacity.");
        if ( Math.abs(defaultLine.getFee()-1.5) > 0.01 )
            printError(" Default constructor does not have correct default fee.");

        //check capacity and fee constructor
        defaultLine = new LightRail(2, 2.25);
        if ( defaultLine.getName().equals("Test") )
            printError(" Default name should not be capitalized.");
        if ( !defaultLine.getName().equals("test") )
            printError(" Default name is not working  with two parameters.");
        if ( defaultLine.getCapacity() != 2 )
            printError("Capacity and fee constructor did not accept capacity.");
        if ( Math.abs(defaultLine.getFee()-2.25) > 0.01 )
            printError(" Capacity and fee did not accept a custom fee.");


        //check name and capacity constructor
        defaultLine = new LightRail("Single Seat", 1);
        if ( !defaultLine.getName().equals("Single Seat") )
            printError(".getName() not working");
        if ( defaultLine.getCapacity() != 1 )
            printError("Capacity and name constructor did not accept capacity.");
        if ( Math.abs(defaultLine.getFee()-1.5) > 0.01 )
            printError(" Capcity and name does not have correct default fee.");

        TestSmallLost(defaultLine, targetOutput);
    }

    /**
     * Test what happens when line fills, empties, then refills. No fee check
     */
    public static void tier02_ComingAndGoing() {
        System.out.println("Tier 2: Testing line coming and going cars (no fee check)............................");

        //test strings
        LightRail busy = new LightRail(6);
        String[] results = { "Status for test line: 3 tickets (50%) Money Collected: $0.00",
                "Status for test line: 4 tickets (66.7%) Money Collected: $0.00",
                "Status for test line: 6 tickets (FULL) Money Collected: $0.00" };
        TestEntryStrings(busy, results);

        //test events
        busy = new LightRail(10);
        TestComingAndGoing(busy);


    }

    /**
     * Checks fee calculation
     */
    public static void tier03_FeeCalculation() {
        System.out.println("Tier 3: Test Fees in a Light Rail line....................................................");

        DecimalFormat format = new DecimalFormat("#.##");
        String targetOutput = "Status for Reserved line: 1 tickets (FULL) Money Collected: $0.00";
        String targetOutput1 = "Status for Reserved line: 0 tickets (0%) Money Collected: $0.00";
        String targetOutput2 = "Status for Reserved line: 0 tickets (0%) Money Collected: $3.00";
        String targetOutput3 = "Status for Reserved Line line: 0 tickets (0%) Money Collected: $60.58";

        //default default amount
        LightRail singleSeater = new LightRail("Reserved", 1);
        int id = singleSeater.markEntry(0);
        if ( Math.abs(singleSeater.getProfit()) > 0.01 )
            printError(" Wrong profit. It should be $0.00");
        if ( !singleSeater.toString().equals(targetOutput) ) {
            printError(" Incorrect full single seat string result.");
            showBeforeAfter(singleSeater.toString(), targetOutput);
        }

        //check threshold for no pay
        singleSeater.markExit(3, id);
        if ( Math.abs(singleSeater.getProfit()) > 0.01 )
            printError(" Wrong profit. It should be $0.00 since it is 3 miles or less since the start.");
        if ( !singleSeater.toString().equals(targetOutput1) ) {
            printError(" Incorrect empty seat string result.");
            showBeforeAfter(singleSeater.toString(), targetOutput1);
        }

        //check pay calculation with default
        id = singleSeater.markEntry(25);
        singleSeater.markExit(33, id);
        if ( Math.abs(singleSeater.getProfit() - 3) > 0.01 )
            printError(" Wrong profit. It should be $3.00. Got $" + singleSeater.getProfit());
        if ( !singleSeater.toString().equals(targetOutput2) ) {
            printError(" Incorrect paid amount with 1 seat string result.");
            showBeforeAfter(singleSeater.toString(), targetOutput2);
        }

        //reset with new fee
        singleSeater = new LightRail("Reserved", 1, 2.75);
        id = singleSeater.markEntry(5);
        singleSeater.markExit(400, id);
        if ( Math.abs(singleSeater.getProfit() - 269.5) > 0.01 )
            printError(" Wrong profit. It should be $269.50. Got " + format.format(singleSeater.getProfit()));

        //confirm still correct with multiple cars
        singleSeater = new LightRail("Reserved Line", 5, 2.33);
        id = singleSeater.markEntry(5);
        int id2 = singleSeater.markEntry(5);
        int id3 = singleSeater.markEntry(10);
        int id4 = singleSeater.markEntry(15);
        int id5 = singleSeater.markEntry(15);
        singleSeater.markExit(15, id);
        singleSeater.markExit(20, id2);
        singleSeater.markExit(26, id4);
        singleSeater.markExit(45, id5);
        singleSeater.markExit(60, id3);
        if ( Math.abs(singleSeater.getProfit() - 60.58) > 0.01 )
            printError(" Wrong profit. It should be $60.58. Got " + format.format(singleSeater.getProfit()));
        if ( !singleSeater.toString().equals(targetOutput3) ) {
            printError(" Incorrect paid line string result.");
            showBeforeAfter(singleSeater.toString(), targetOutput3);
        }
    }

    /**
     * Test entry/exit where the distance is in the past, bad ids, double removal, etc.
     */
    public static void tier04_CheckForGlitches() {
        System.out.println("Tier 4: Testing a Light Rail with invalid distances.............................................");

        LightRail line = new LightRail(6);
        checkForLineGlitches(line);

        //nonexistant id
        line = new LightRail(3);
        line.markEntry(2);
        line.markExit(50, -1);
        if ( line.getTicketsInLine() != 1 )
            printError(" Error: expecting 1 ticket at distance 50.  Got: " + line.getTicketsInLine());
    }

    public static void tier05_FreeSmallLine() {
        System.out.println("Tier 5: Testing a free line with one seat..................................");

        String targetOutput = "Status for Free Seat line: 1 tickets (FULL) FREE";

        //check default constructor
        FreeLightRail defaultLine = new FreeLightRail(1);
        if ( defaultLine.getName().equals("Test") )
            printError(" Default name is not working.");

        //check constructor
        defaultLine = new FreeLightRail("Free Seat", 1);

        if ( !defaultLine.getName().equals("Free Seat") )
            printError(".getName() not working");

        TestSmallLost(defaultLine, targetOutput);
    }

    /**
     * Test what happens when line fills, empties, then refills. No fee check
     */
    public static void tier06_FreeComingAndGoing() {
        System.out.println("Tier 6: Testing free Light Rail line multiple coming and going cars............................");

        //test strings
        FreeLightRail busy = new FreeLightRail(6);
        String[] results = { "Status for test line: 3 tickets (50%) FREE",
                "Status for test line: 4 tickets (66.7%) FREE",
                "Status for test line: 6 tickets (FULL) FREE" };
        TestEntryStrings(busy, results);

        //test events
        busy = new FreeLightRail(10);
        TestComingAndGoing(busy);
    }

    /**
     * Checks fee calculation (or lack thereof)
     */
    public static void tier07_FeeCalculation() {
        System.out.println("Tier 7: Test Fees in a Free Light Rail line (should always be 0)..............................................");

        //default default amount
        FreeLightRail driveway = new FreeLightRail("Reserved", 1);
        driveway.markEntry(5);
        if ( Math.abs(driveway.getProfit()) > 0.01 )
            printError(" Wrong profit. It should be $0.00");

        //check pay calculation with default
        driveway.markExit(10);
        if ( Math.abs(driveway.getProfit()) > 0.01 )
            printError(" Wrong profit. It should be $0.");

        driveway.markEntry(25);
        driveway.markExit(400);
        if ( Math.abs(driveway.getProfit()) > 0.01 )
            printError(" Wrong profit. It should be $0.");

        //confirm still correct with multiple cars
        driveway = new FreeLightRail("Reserved Line", 5);
        driveway.markEntry(5);
        driveway.markEntry(5);
        driveway.markEntry(10);
        driveway.markEntry(15);
        driveway.markEntry(15);
        driveway.markExit(15);
        driveway.markExit(20);
        driveway.markExit(26);
        driveway.markExit(45);
        driveway.markExit(60);
        if ( Math.abs(driveway.getProfit()) > 0.01 )
            printError(" Wrong profit. It should be $0. ");

    }

    /**
     * Test entry/exit where the distance is in the past, bad ids, double removal, etc.
     */
    public static void tier08_CheckForGlitches() {
        System.out.println("Tier 8: Testing Free Light Rail with invalid distances.............................................");


        FreeLightRail line = new FreeLightRail(6);

        checkForLineGlitches(line);

        //nonexistant id
        line = new FreeLightRail(3);
        line.markEntry(2);
        line.markExit(50, -1);
        if ( line.getTicketsInLine() != 0 )
            printError(" Error: expecting 0 ticket at distance 50.  Since ids should be ignored. Got: " + line.getTicketsInLine());
    }

    /**
     * Create district with small lines, fill them, then
     * ensure one is not full.
     */
    public static void tier09_testTinyFreeCity() {
        String initalOutput = """
                City status:
                Status for red line: 0 tickets (0%) FREE
                Status for green line: 0 tickets (0%) FREE
                Status for blue line: 0 tickets (0%) FREE
                """;
        String endingOutput = """
                City status:
                Status for red line: 0 tickets (0%) FREE
                Status for green line: 1 tickets (FULL) FREE
                Status for blue line: 2 tickets (FULL) FREE
                """;

        System.out.println("Tier 9: Testing a City with 3 tiny free lines......................................");
        City ourTown = new City();
        int redLine = ourTown.add(new FreeLightRail("red", 1));
        int greenLine = ourTown.add(new FreeLightRail("green", 1));
        int blueLine = ourTown.add(new FreeLightRail("blue", 2));

        if ( !ourTown.toString().equals(initalOutput) ) {
            printError(" incorrect district toString()");
            showBeforeAfter(ourTown.toString(), initalOutput);
        }
        if ( ourTown.getTicketsInCity() != 0 )
            printError(" Expected 0 tickets in tiny district");

        ourTown.markEntry(greenLine, 5);
        ourTown.markEntry(redLine, 7);
        ourTown.markEntry(blueLine, 10);
        ourTown.markEntry(blueLine, 12);
        if ( ourTown.getTicketsInCity() != 4 )
            printError(" Expected 4 tickets in tiny district");
        if ( !ourTown.isFull() )
            printError(" Error in tiny district at 12: should be full.");
        ourTown.markExit(greenLine, 15, 0);
        if ( ourTown.isFull() )
            printError(" Error in tiny district at 15: should be open.");
        if ( ourTown.getTicketsInCity() != 3 )
            printError(" Expected 3 tickets in tiny district at distance 15");

        ourTown.markExit(redLine, 17, 0);
        ourTown.markEntry(greenLine, 18);
        if ( ourTown.isFull() )
            printError(" Error in tiny district at 18: should be open.");

        if ( !ourTown.toString().equals(endingOutput) ) {
            printError(" incorrect ending district toString()");
            showBeforeAfter(ourTown.toString(), endingOutput);
        }
    }

    /**
     * Test City class with three lines.
     */
    public static void tier10_testPaidCity() {
        System.out.println("Tier 10: Testing a City with 3 normal lines (no fee check)..................");

        String targetTime7 = """
                City status:
                Status for brown line: 7 tickets (70%) Money Collected: $0.00
                Status for green line: 14 tickets (FULL) Money Collected: $0.00
                Status for black line: 7 tickets (58.3%) Money Collected: $0.00
                """;
        String targetTime8 = """
                City status:
                Status for brown line: 8 tickets (80%) Money Collected: $0.00
                Status for green line: 14 tickets (FULL) Money Collected: $0.00
                Status for black line: 7 tickets (58.3%) Money Collected: $0.00
                """;
        String targetTime10 = """
                City status:
                Status for brown line: 9 tickets (FULL) Money Collected: $0.00
                Status for green line: 14 tickets (FULL) Money Collected: $0.00
                Status for black line: 11 tickets (FULL) Money Collected: $0.00
                """;

        City airport = new City();
        int brown = airport.add(new LightRail("brown", 10));
        int green = airport.add(new LightRail("green", 15, 3.75));
        int black = airport.add(new LightRail("black", 12, 2));

        //fill city a bit
        for ( int i = 0; i < 7; i++ ) {
            airport.markEntry(brown, i);
            airport.markEntry(green, i);
            airport.markEntry(green, i);
            airport.markEntry(black, i);
            if ( airport.isFull() )
                printError(" Error: airport full at distance 7.");
        }
        if ( airport.getTicketsInCity() != 28 )
            printError(" Expected 28 tickets in airport");

        if ( !airport.toString().equals(targetTime7) ) {
            printError(" incorrect airport at distance 7 toString()");
            showBeforeAfter(airport.toString(), targetTime7);
        }


        //add one ticket
        airport.markEntry(brown, 8);
        if ( airport.isFull() )
            printError(" Error: airport should not be full at distance 8.");

        if ( !airport.toString().equals(targetTime8) ) {
            printError(" incorrect airport at distance 8 toString()");
            showBeforeAfter(airport.toString(), targetTime8);
        }

        //check lines within city
        LightRail blackLine = airport.getLine(black);
        if ( !blackLine.getName().equals("black") )
            printError(" Black line has the wrong name.");
        if ( blackLine.getTicketsInLine() != 7 )
            printError(" Expecting 7 tickets in black line at distance 8.");

        //fill city
        int id0 = airport.markEntry(black, 9);
        airport.markEntry(black, 10);
        airport.markEntry(black, 10);
        airport.markEntry(black, 10);
        int id1 = airport.markEntry(brown, 10);
        if ( blackLine.getTicketsInLine() != 11 )
            printError(" Expecting 10 tickets in black line at distance 10.");
        if ( !airport.isFull() )
            printError(" Error: airport not full at distance 10.");
        if ( airport.getTicketsInCity() != 34 )
            printError(" Expected 34 tickets in airport. Got: " + airport.getTicketsInCity());

        if ( !airport.toString().equals(targetTime10) ) {
            printError(" incorrect airport at distance 10 toString()");
            showBeforeAfter(airport.toString(), targetTime10);
        }

        //one more entry, and then exit to calculate fees
        int id2 = airport.markEntry(green, 10);
        airport.markExit(black, 13, id0);
        airport.markExit(brown, 14, id1);
        airport.markExit(green, 14, id2);
        if ( Math.abs(airport.getTotalMoneyCollected() - 7.25) >= 0.01 ) {
            printError("Airport should have collected $7.25. Got: "+airport.getTotalMoneyCollected() );
        }

        if ( airport.getIsFullDistance() != 3 ) {
            printError("Airport should have been full for 3 miles. Got: "+airport.getIsFullDistance());
        }

        //confirm closures and funds are still tallying with a few more enter/exits
        airport.markEntry(black, 15);
        int id3 = airport.markEntry(brown, 15);
        airport.markExit(brown, 20, id3);
        if ( Math.abs(airport.getTotalMoneyCollected() - 8.75) >= 0.01 ) {
            printError("Airport should have collected $8.75. Got: "+airport.getTotalMoneyCollected() );
        }

        if ( airport.getIsFullDistance() != 8 ) {
            printError("Airport should have been full for 8 miles. Got: "+airport.getIsFullDistance());
        }
    }

    public static void tier11_testMixedAndGlitchyCity() {
        System.out.println("Tier 11: Testing a City with 2 normal, and 3 paid lines.......................");

        String result = """
                City status:
                Status for pink line: 1 tickets (50%) FREE
                Status for blue line: 2 tickets (66.7%) FREE
                Status for red paid line: 1 tickets (50%) Money Collected: $20.00
                Status for gray paid line: 2 tickets (66.7%) Money Collected: $35.00
                Status for green paid line: 2 tickets (50%) Money Collected: $15.00
                """;


        City town = new City();
        town.add(new FreeLightRail("pink", 2));
        town.add(new FreeLightRail("blue", 3));
        town.add(new LightRail("red paid", 2, 5));
        town.add(new LightRail("gray paid", 3, 7));
        town.add(new LightRail("green paid", 4));

        //many entries
        town.markEntry(0, 1);
        town.markEntry(1, 2);
        int car1 = town.markEntry(2, 3);
        int car2 = town.markEntry(3, 4);
        int car3 = town.markEntry(4, 5);
        town.markEntry(1, 6);
        town.markEntry(1, 7);
        town.markEntry(0, 8);
        town.markEntry(2, 9);
        town.markEntry(2, 10);
        town.markEntry(3, 11);
        town.markEntry(3, 11);
        town.markEntry(4, 11);
        int car4 =town.markEntry(4, 11);
        int car5 = town.markEntry(4, 11);

        town.markExit(0, 15, 0);
        town.markExit(1, 16, 0);
        town.markExit(2, 20, car1);
        town.markExit(3, 26, car2);
        town.markExit(4, 30, car3);
        town.markExit(4, 30, car4);

        //check value status
        glitchyCityRetest(town);

        if ( !town.toString().equals(result) ) {
            printError(" incorrect final paid district toString()");
            showBeforeAfter(town.toString(), result);
        }

        //test glitches----------
        //backward exits
        town.markExit(4, 20, car4);
        glitchyCityRetest(town);

        //backward entry
        int id4 = town.markEntry(3, 20);
        if ( id4 != -1 )
            printError("Add should have failed due to going backwards in distance.");
        glitchyCityRetest(town);

        //double removal
        town.markExit(4, 30, car4);
        glitchyCityRetest(town);

        //overfill
        town.markEntry(3, 30);
        int id5 = town.markEntry(3, 30);
        if ( id5 != -1 )
            printError("Add should have failed due no space left.");
        if ( town.getTicketsInCity() != 9 )
            printError(" Expected 9 tickets in town. Got: " + town.getTicketsInCity());
    }


}
