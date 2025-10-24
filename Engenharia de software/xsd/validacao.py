from lxml import etree

# Carrega os arquivos
xml_file = 'alunos.xml'
xsd_file = 'alunos.xsd'

# Parse do esquema XSD
with open(xsd_file, 'rb') as f:
    schema_doc = etree.XML(f.read())
    schema = etree.XMLSchema(schema_doc)

# Parse do XML
with open(xml_file, 'rb') as f:
    xml_doc = etree.parse(f)

# Validação
is_valid = schema.validate(xml_doc)
print("Arquivo XML válido?" , is_valid)

# Exibir erros, se houver
if not is_valid:
    for error in schema.error_log:
        print(error.message)