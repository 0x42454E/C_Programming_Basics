import io
import mimetypes
import subprocess
import yagmail

subject = "Test Email with Attachment"
from_addr = "your_email@example.com"
to_addr = "recipiet_email@example.com"
body_text = "This is a test email with an attachment"

attachment_file = "example_file.txt"
with open(attachment_file, "rb") as f:
    attachment_data = f.read()
attachment_mimetype = mimetypes.guess_type(attachment_file)[0]
attachment_part = io.BytesIO(attachment_data)
attachment_part.name = attachment_file
attachment_part.type = attachment_mimetype

msg = yagmail.SMTPMessage()
msg.subject = subject
msg.from_addr = from_addr
msg.to_addr = to_addr
msg.body = body_text
msg.attachment = [attachment_part]

yagmail.send(msg, smtp_host='localhost', smtp_port=25)

command = "sudo postfix start"
completed_process =  subprocess.run(command, shell=True, capture_output=True, text=True)
output = completed_process.stdout
print(output)


if completed_process.returncode != 0:
    print(f"Command failed with return code {completed_process.returncode}")

command = "sudo postfix status"
completed_process =  subprocess.run(command, shell=True, capture_output=True, text=True)
output = completed_process.stdout
print(output)

if completed_process.returncode != 0:
    print(f"Command failed with return code {completed_process.returncode}")


print("Input email body")
email_body = input()
print("Input recipient hostname")
hostname = input()
print("Input ip address:")
ip = input()
command = "echo "f"{email_body}"" | mail -s ""Subject"" "f"{hostname}@"f"[{ip}]"
completed_process =  subprocess.run(command, shell=True, capture_output=True, text=True)
output = completed_process.stdout
print(output)

if completed_process.returncode != 0:
    print(f"Command failed with return code {completed_process.returncode}")


command = "sudo postfix stop"
completed_process =  subprocess.run(command, shell=True, capture_output=True, text=True)
output = completed_process.stdout
print(output)