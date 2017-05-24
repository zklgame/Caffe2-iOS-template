//
//  ViewController.swift
//  caffe2-iOS-template
//
//  Created by zklgame on 2017/5/24.
//  Copyright © 2017年 Kaili Zhu. All rights reserved.
//

import UIKit
import MobileCoreServices

class ViewController: UIViewController {

    @IBOutlet weak var imageView: UIImageView!
    @IBOutlet weak var predictionView: UITextView!
    
    let caffe = Caffe2(initNetName: "squeezeNetInit", predictNetName: "squeezeNetPredict")
    let image = UIImage(named: "cat.jpeg")
    
    let imagePicker = UIImagePickerController()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        imagePicker.sourceType = .photoLibrary
        imagePicker.mediaTypes = [kUTTypeImage as String]
        imagePicker.delegate = self
        
        predict(with: image!)
    }
    
    @IBAction func selectImage(_ sender: UIButton) {
        present(imagePicker, animated: true, completion: nil)
    }
    
    func predict(with image: UIImage) {
        imageView.image = image
        
        let results = caffe.predict(from: image)
        let topFiveResults = results.prefix(5)
        var text = "Top Five Predictions:\n"
        for result in topFiveResults {
            let confidence = String(format: "%.4f", result.confidence)
            text += "\(confidence) \(result.itemName)\n"
        }
        
        predictionView.text = text
    }

}

extension ViewController: UINavigationControllerDelegate, UIImagePickerControllerDelegate {
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        let image = info[UIImagePickerControllerOriginalImage] as! UIImage
        picker.dismiss(animated: true, completion: nil)
        predict(with: image)
    }
}

