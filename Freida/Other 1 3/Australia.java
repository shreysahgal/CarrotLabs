import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Australia here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Australia extends Actor
{
    /**
     * Act - do whatever the Austrlaia wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    GreenfootSound australia = new GreenfootSound("Australia.wav");
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
           australia.play();
       }
        // Add your action code here.
    }    
}
