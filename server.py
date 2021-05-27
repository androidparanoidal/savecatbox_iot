from flask import Flask
from datetime import datetime

app = Flask(__name__)
motions = []

@app.route('/')
def index():
    str_response = "Motions:<br/>"
    for time in motions:
        str_response += time.strftime("%H:%M:%S") + "<br/>"
    return str_response
    
    
@app.route('/motion')
def motion():
    now = datetime.now()
    motions.append(now)
    return 'OK'


if __name__ == "__main__":
    app.run(host='', port=5000) 
