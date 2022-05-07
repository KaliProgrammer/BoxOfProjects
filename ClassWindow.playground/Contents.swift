import UIKit

class Window {
    var x = 0.0, y = 0.0
    var width = 100.0, height = 100.0
    
    var center: (Double, Double) {
        get {
            return (width/2, height/2)
        }
        set(newVal) {
            x = newVal.0 - (width/2)
            y = newVal.1 - (height/2)
        }
    }
}
var win = Window()
print(win.center)
win.center = (0.0, 10.0)
print(win.x)
print(win.y)
