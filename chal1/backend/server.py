from flask import Flask, request, jsonify
from flask_cors import CORS
KEY = "258109"
app = Flask(__name__)
CORS(app)
@app.route("/code", methods=["POST"])
def submit_code():
    try:
        data = request.get_json()
        code = data.get("code")
        if not code:
            code = request.data.decode("utf-8")
        import io, contextlib
        f = io.StringIO()
        with contextlib.redirect_stdout(f):
            exec(code, {"KEY" : KEY})
        xero = "000000"
        return jsonify({"success": True, "out": xero})
    
    except Exception as e:
        return jsonify({"success": False, "error": str(e)}), 400


# Route for receiving key
@app.route("/key", methods=["POST"])
def submit_key():
    try:
        data = request.get_json()
        inkey = data.get("key")
        if not inkey:
            inkey = request.data.decode("utf-8")
        flag = "FLAG{CTF_FLAG}"
        if (inkey == "000000"):
            flag = "Don't tell me you tried this"
        if (inkey == "258109"):
            flag = "FLAG{n3v3r_g0nna_g1v3_y0u_up}"
            return jsonify({"success": True, "out": flag})
        return jsonify({"success": True, "out": flag})
    
    except Exception as e:
        return jsonify({"success": False, "error": str(e)}), 400


if __name__ == "__main__":
    app.run(debug=True, port=5000)
