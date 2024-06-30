import tensorflow as tf
import os
from email.message import EmailMessage
import smtplib
import ssl
from datetime import datetime

# Load model for disease detection
loaded_model = tf.keras.models.load_model(r"/home/superpotatorpi/Desktop/machine_learning_files/health_assessment_model.hdf5")
# Find latest folder for plants 
images_path = r"/home/superpotatorpi/Desktop/images_captured/"
list_files = os.listdir(images_path)
list_files.sort()

folder_1 = os.path.join(images_path, list_files[-1])
folder_1_list_files = os.listdir(folder_1)
folder_1_list_files.sort()
folder_2 = os.path.join(folder_1, folder_1_list_files[-1])
print(folder_2)

# Load the images
test_dataset = tf.keras.utils.image_dataset_from_directory(rf'{folder_2}', 
                                                           labels=None, shuffle=False, batch_size=1, image_size=(256,256))

pred = loaded_model.predict(test_dataset)
pred_adjusted = list(map(lambda x: 0 if x < 0.5 else 1, pred))
print(pred_adjusted)

# predicted list values
values = ['Healthy', 'Unhealthy']

# Email part 
email_sender = 'dpaulallan15@gmail.com'
email_password = 'shai majm tzag aybb'
email_receiver = 'dpaulallan14@gmail.com'
subject =  "Plant Health Assessment Results"
time_now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")


body = f"""
These are the results for the Plant Health Assessment on {time_now}.
Plant A - {values[pred_adjusted[0]]}
Plant B - {values[pred_adjusted[1]]}
Plant C - {values[pred_adjusted[2]]}
Plant D - {values[pred_adjusted[6]]}
Plant E - {values[pred_adjusted[5]]}
Plant F - {values[pred_adjusted[4]]}
Plant G - {values[pred_adjusted[3]]}
Plant H - {values[pred_adjusted[7]]}
Plant I - {values[pred_adjusted[8]]}
Plant J - {values[pred_adjusted[9]]}
"""

em = EmailMessage()
em['From'] = email_sender
em['To'] = email_receiver
em['Subject'] = subject
em.set_content(body)
context = ssl.create_default_context()

with smtplib.SMTP_SSL('smtp.gmail.com', 465, context=context) as smtp:
    smtp.login(email_sender, email_password)
    smtp.sendmail(email_sender, email_receiver, em.as_string())