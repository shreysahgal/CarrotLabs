import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class NewYork here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Switzerland extends Actor
{
    /**
     * Act - do whatever the Switzerland wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    GreenfootSound switzerland = new GreenfootSound("Switzerland.wav");
    MouseInfo mouse = Greenfoot.getMouseInfo();  
    boolean mouseOver = false;
    public void act() 
    {    
       if (!mouseOver && Greenfoot.mouseMoved(this))  
       {  
            setImage("buttonHover.png");  
            mouseOver = true;  
       }  
       if (mouseOver && Greenfoot.mouseMoved(null) && ! Greenfoot.mouseMoved(this))  
       {  
            setImage("blue-draught.png");  
            mouseOver = false;  
       } 
       if(Greenfoot.mouseClicked(this)){
            setImage("buttonPressed.png");
           switzerland.play();
       }
        // Add your action code here.
    }    
}
