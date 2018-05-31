import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class MyWorld here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class MyWorld extends World
{
    GreenfootImage bg = new GreenfootImage("world.jpg");
  
    England eng = new England();
    Mexico mex = new Mexico();
    SaintLouis stl = new SaintLouis();
    Chicago cgo = new Chicago();
    Italy itl = new Italy();
    Southkorea skr = new Southkorea();
    Ethiopia etp = new Ethiopia();
    Lebanon lbn = new Lebanon();
    Peru per = new Peru();
    Australia aus = new Australia();
    Fiji fij = new Fiji();
    Kenya ken = new Kenya();
    Switzerland swi = new Switzerland();
    Greece gre= new Greece();
    Taiwan tai= new Taiwan();
    Newyork nwy = new Newyork();
    France frc = new France();
    Indonesia idn = new Indonesia();
    /**
     * Constructor for objects of class MyWorld.
     * 
     */
    public MyWorld()
    {    
        super(4500, 2234, 1);
        setBackground(bg);
        addObject(eng, 1852, 450);
        addObject(frc, 1876, 543);
        addObject(mex, 504, 972);
        addObject(stl, 731, 659);
        addObject(cgo, 738, 603); 
        addObject(itl, 2019, 605);
        addObject(nwy, 880, 595);
        addObject(idn, 3398, 1272);
        addObject(skr, 3493, 695);
        addObject(etp, 2372, 1125);
        addObject(lbn, 2306, 730);
        addObject(per, 802, 1414);
        addObject(aus, 3645, 1642);
        addObject(fij, 4245, 1534);
        addObject(ken, 2359, 1252);
        addObject(swi, 1946, 528);
        addObject(gre, 2124, 671);
        addObject(tai, 3454, 885);
        
        // Create a new world with 600x400 cells with a cell size of 1x1 pixels.
         
    }
}
