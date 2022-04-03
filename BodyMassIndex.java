
import javax.swing.JOptionPane;

public class BodyMassIndex {
    public static void main(String[] args)
    {
        double weight,
                height,
                BMI;
        String input;

        //JOptionPane.showMessageDialog(null,"Hello! What is your weight?");
        input = JOptionPane.showInputDialog("Hello! What is your weight?");
        weight= Double.parseDouble(input);
        input = JOptionPane.showInputDialog("What is your height?");
        height = Double.parseDouble(input);
        BMI = weight * 703 / (height * height);
        if (BMI >= 18.5 && BMI <= 25)
        {
            JOptionPane.showMessageDialog(null, "Your weight is optimal! ");
        }
        else if (BMI < 18.5)
        {
            JOptionPane.showMessageDialog(null, "You are underweight!");
        }
        else if (BMI > 25)
        {
            JOptionPane.showMessageDialog(null, "You are overweight!");
        }
    }
}
