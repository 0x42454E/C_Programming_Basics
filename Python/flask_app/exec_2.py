"""
Simple Flask app that renders an HTML form to input a city.

Author: Ben
Date: 2024-10
"""

from flask import render_template, Flask, request
import requests

app = Flask(__name__)

#Route establishment
@app.route('/', methods=['POST', 'GET'])
def input_city():
    return render_template('simple_html.html')
    
    
    
if __name__ == '__main__':
    app.run(debug=True)

