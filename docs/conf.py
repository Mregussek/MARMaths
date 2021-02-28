# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys
import subprocess
sys.path.insert(0, os.path.abspath('.'))
from sphinx.builders.html import StandaloneHTMLBuilder


# Doxygen
subprocess.call('doxygen Doxyfile', shell=True)


# -- Project information -----------------------------------------------------

project = 'MARMaths-docs'
copyright = '2021, Mateusz Rzeczyca'
author = 'Mateusz Rzeczyca'

# The full version, including alpha/beta/rc tags
release = '0.0.1'


# -- General configuration ---------------------------------------------------

master_doc = 'index'

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
	'sphinx.ext.autodoc',
    'sphinx.ext.intersphinx',
    'sphinx.ext.autosectionlabel',
    'sphinx.ext.todo',
    'sphinx.ext.coverage',
    'sphinx.ext.mathjax',
    'sphinx.ext.ifconfig',
    'sphinx.ext.viewcode',
    'sphinx_sitemap',
    'sphinx.ext.inheritance_diagram',
    'breathe'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

highlight_language = 'c++'


# -- Options for HTML output -------------------------------------------------

import sphinx_rtd_theme


# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'
html_theme_options = {
    'canonical_url': '',
    'analytics_id': '',  #  Provided by Google in your dashboard
    'display_version': True,
    'prev_next_buttons_location': 'bottom',
    'style_external_links': False,
    
    'logo_only': False,

    # Toc options
    'collapse_navigation': True,
    'sticky_navigation': True,
    'navigation_depth': 4,
    'includehidden': True,
    'titles_only': False
}
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

# -- Breathe configuration -------------------------------------------------

breathe_projects = {
	"C++ Sphinx Doxygen Breathe": "_build/xml/"
}
breathe_default_project = "C++ Sphinx Doxygen Breathe"
breathe_default_members = ('members', 'undoc-members')


# -- Cpp files creation ----------------------------------------------------

from bs4 import BeautifulSoup

marmaths_xml_path = "_build/xml/"
marmaths_classes_xml = [marmaths_xml_path + x for x in os.listdir(marmaths_xml_path) if x.endswith("8h.xml")]

references_path = "references/"
cpp_rst_file_template = """
.. _api_{}:

{}
{}

.. doxygenfile:: {}
   :project: C++ Sphinx Doxygen Breathe

"""

for xml_file in marmaths_classes_xml:
    print("Parsing file {}...".format(xml_file))

    xml_parsed = None
    with open(xml_file, "r") as f:
        xml_source = f.read()
        xml_parsed = BeautifulSoup(xml_source, features="lxml")

    xml_filename = xml_parsed.doxygen.compounddef.compoundname.get_text()
    location = xml_parsed.doxygen.compounddef.location['file'].split("MARMaths/src/")[1]

    xml_classname = None
    try:
        xml_classname = xml_parsed.doxygen.compounddef.innerclass.get_text()[len("marengine::maths::"):]
    except AttributeError:
        continue

    xml_filename_without_ext = xml_filename[:(len(xml_filename) - 2)]
    create_file = references_path + xml_filename_without_ext.lower() + ".rst"
    
    print("Creating file {} and pushing code to it...".format(create_file))
    with open(create_file, "w") as f:
        should_use_page_name = "Definitions" in xml_filename_without_ext or "Components" in xml_filename_without_ext or "Uniforms" in xml_filename_without_ext
        page_name = xml_filename_without_ext if should_use_page_name else xml_classname
    
        rst_source = cpp_rst_file_template.format(
            xml_filename_without_ext.lower(), 
            page_name, 
            "=" * len(page_name), 
            location
        )
        f.write(rst_source)
