//
//  CircleImage.swift
//  LandMarks
//
//  Created by MacBook Air on 22.05.2022.
//

import SwiftUI

struct CircleImage: View {
    var body: some View {
        Image("Turtle Rock")
            .clipShape(Circle())
            .overlay(Circle().stroke(Color.white,
                                    lineWidth: 4))
            .shadow(radius: 10)
    }
}

struct CircleImage_Previews: PreviewProvider {
    static var previews: some View {
        CircleImage()
    }
}
