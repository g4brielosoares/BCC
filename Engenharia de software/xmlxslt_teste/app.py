from flask import Flask, Response
from lxml import etree

app = Flask(__name__)

@app.route('/')
def transform_xml():
    xml = etree.parse("alunos.xml")
    xslt = etree.parse("alunos.xsl")
    transform = etree.XSLT(xslt)
    html = transform(xml)
    return Response(str(html), mimetype='text/html')

if __name__ == "__main__":
    app.run(debug=True)
