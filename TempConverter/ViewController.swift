//
//  ViewController.swift
//  TempConverter
//
//  Created by MacBook Air on 08.05.2022.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    
    var degreesValue: Double = 0.0
    var fahrenheitValue: Double = 0.0
    
    
    @IBOutlet weak var textFieldCelToFahr: UITextField!
    
    @IBOutlet weak var textFieldFahrToCel: UITextField!
    
    
    @IBOutlet weak var convertedValue: UILabel!
    
    @IBAction func celToFahr(_ sender: UIButton) {
                let textFieldCelsiusDouble: Double? = Double(textFieldCelToFahr.text!)
                if textFieldCelsiusDouble != nil {
                fahrenheitValue = (textFieldCelsiusDouble! * 9/5) + 32
                }
                convertedValue.text = String(fahrenheitValue)
        view.backgroundColor = .yellow
    }
    
    @IBAction func fahrToCel(_ sender: UIButton) {
        let textFieldFahrDouble: Double? = Double(textFieldFahrToCel.text!)
        if textFieldFahrDouble != nil {
            degreesValue = (fahrenheitValue - 32) * 5/9
        }
        convertedValue.text = String(degreesValue)
        view.backgroundColor = .orange
    }
    
    

    

    


}

