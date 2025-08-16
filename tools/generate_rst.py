import ast
import os
import re
import textwrap

def camel_to_snake_case(name):
    """
    Convert camel case to snake case.

    For example: VirtualWidget -> virtual_widget
    :param name: camel case name
    :return: lower snake case
    """
    return re.sub(r'(?<!^)(?=[A-Z])', '_', name).lower()

def format_function_signature(func: ast.FunctionDef) -> str:
    """
    Formats function signature of the given function definition.

    :param func: function definition
    :return: formatted function signature
    """
    args = []
    for arg in func.args.args:
        if arg.arg != "self":
            args.append(arg.arg)
    arglist = ", ".join(args)
    returns = ""
    if func.returns and hasattr(ast, 'unparse'):
        returns = f" -> {ast.unparse(func.returns)}"
    return f".. method:: {func.name}({arglist}){returns}"

def extract_docstring(node: ast.AsyncFunctionDef | ast.FunctionDef | ast.Module | ast.ClassDef) -> str:
    """
    Extracts docstrings from the given AST node.

    :param node: an AST node of Async Function, Function Definition, Module, or a Class Definition.
    :return: doc string
    """
    docstring = ast.get_docstring(node)
    if docstring:
        return textwrap.indent(docstring.strip(), "   ")
    return ""

def process_class(cls: ast.ClassDef, output_dir: str):
    class_name = cls.name
    filename = camel_to_snake_case(class_name) + ".rst"
    filepath = os.path.join(output_dir, filename)

    lines = [f".. class:: {class_name}", ""]

    # Class docstring
    class_doc = extract_docstring(cls)
    if class_doc:
        lines.append(class_doc)
        lines.append("")

    # Inheritance information
    if cls.bases:
        base_names = []
        for base in cls.bases:
            if isinstance(base, ast.Name):
                base_names.append(base.id)
            elif isinstance(base, ast.Attribute):
                base_names.append(ast.unparse(base) if hasattr(ast, 'unparse') else "<unknown>")
        if base_names:
            lines.append(f"   Inherited from {', '.join(base_names)}")
            lines.append("")

    for item in cls.body:
        if isinstance(item, ast.FunctionDef):
            lines.append("   " + format_function_signature(item))
            doc = extract_docstring(item)
            if doc:
                lines.append("")
                lines.append(doc)
                lines.append("")

    with open(filepath, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"Wrote: {filepath}")

def generate_rst_from_pyi(pyi_file: str, output_dir: str):
    with open(pyi_file, "r", encoding="utf-8") as f:
        source = f.read()

    tree = ast.parse(source, pyi_file)

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    for node in tree.body:
        if isinstance(node, ast.ClassDef):
            process_class(node, output_dir)

# Example usage:
# generate_rst_from_pyi("virtual_widgets.pyi", "rst_output")
if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Usage: python generate_rst_from_pyi.py <input.pyi> <output_dir>")
    else:
        generate_rst_from_pyi(sys.argv[1], sys.argv[2])
