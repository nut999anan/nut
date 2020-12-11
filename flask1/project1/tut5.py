from flask import Flask,redirect,url_for,render_template
from flask import request,session

app = Flask(__name__)

@app.route("/")#where to find this function
def home():
    return "<h1>Home<h1>"

@app.route("/login",methods = ["POST","GET"])
def login():
    if request.method == "POST":
        user = request.form["nm"]
        session["user"] = user
        return redirect(url_for("user",usr = user))
    else:
        return render_template("login.html")

@app.route("/user")
def user():
    if "user" in session:
        user = session["user"]
        return f"<h1>{user}</h1>"

    return f"<h1></h1>"



if __name__ == "__main__":
    app.run(debug=True)   