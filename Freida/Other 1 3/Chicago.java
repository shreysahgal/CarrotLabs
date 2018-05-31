import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Chicago here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Chicago extends Actor
{
    /**
     * Act - do whatever the SaintLouis wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    GreenfootSound chicago = new GreenfootSound("Chicago.wav");
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
            setImage("button.png");  
            mouseOver = false;  
       } 
       if(Greenfoot.mouseClicked(this)){
            setImage("buttonPressed.png");
            chicago.play();
       }
        // Add your action code here.
    }    
}
