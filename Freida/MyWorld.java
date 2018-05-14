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
    NewYork nyc = new NewYork();
    London ldn = new London();
    Bangladesh bng = new Bangladesh();
    Mexico mex = new Mexico();
    Canada cda = new Canada();
    SaintLouis stl = new SaintLouis();
    Chicago cgo = new Chicago();
    DominicanRepublic drc = new DominicanRepublic(); 
    France frc = new France();
    Japan jpn = new Japan();
    China chn = new China();
    Italy itl = new Italy();
    Colombia cba = new Colombia();
    Ethiopia etp = new Ethiopia();
    /**
     * Constructor for objects of class MyWorld.
     * 
     */
    public MyWorld()
    {    
        super(4500, 2234, 1);
        setBackground(bg);
        addObject(nyc, 914, 613);
        addObject(ldn, 1852, 450);
        addObject(bng, 3051, 897);
        addObject(mex, 504, 972);
        addObject(cda, 911, 533);
        addObject(stl, 731, 659);
        addObject(cgo, 738, 603); 
        addObject(drc, 881, 957);
        addObject(frc, 1870, 492);
        addObject(jpn, 3638, 699); 
        addObject(chn, 3350, 581);
        addObject(itl, 2019, 605);
        addObject(cba, 796, 1164);
        addObject(etp, 2371, 1127);
        // Create a new world with 600x400 cells with a cell size of 1x1 pixels.
         
    }
}
