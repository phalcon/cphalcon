
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Debug;

/**
 * Phalcon\Debug\Dump
 *
 * Dumps information about a variable
 */
class Dump
{
	protected _styles;

	protected methods;

	/**
	 * Phalcon\Debug\Dump constructor
	 *
	 * @param array styles
	 */
	public function __construct(styles=null)
	{
		if typeof styles != "array" {
			if typeof styles != "null" {
				throw new \Phalcon\Debug\Exception("The styles must be a array");
			}
		}
		this->setStyles(styles);
		let this->methods = [];
	}

	/**
	 * Returns an HTML string of debugging information about any number of
	 * variables, each wrapped in a "pre" tag.
	 *
	 *<code>
	 * echo (new \Phalcon\Debug\Dump())->vars($foo, $bar, $baz);
	 *</code>
	 *
	 * @param mixed variable
	 * @param ...
	 * @return string
	 */
	public function vars()
	{
		var key, value, output;

		let output = "";
		for key, value in func_get_args() {
			let output .= this->dump(value, "var " . key);
		}

		return output;
	}

	/**
	 * Returns an HTML string of information about a single variable.
	 *
	 *<code>
	 *echo (new \Phalcon\Debug\Dump())->dump($foo, "foo");
	 *</code>
	 *
	 * @param mixed variable
	 * @param string name
	 * @return string
	 */
	public function dump(variable, name=null)
	{
		return "<pre style='" . this->getStyle("pre") . "'>" . name . " " . this->output(variable, name) . "</pre>";
	}

	/**
	 * Prepare an HTML string of information about a single variable.
	 *
	 * @param mixed variable
	 * @param string name
	 * @param intiger tab
	 * @return  string
	 */
	public function output(variable, name=null, tab=1)
	{
		var key, value, output, space, type, attr;
		let space = "  ", output = "";

		if typeof variable == "array" {

			let output .= strtr("<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", [":style": this->getStyle("arr"), ":count": count(variable)]);
			for key, value in variable {
				let output .= str_repeat(space, tab) . strtr("[<span style=':style'>:key</span>] => ", [":style": this->getStyle("arr"), ":key": key]);
				if tab == 0 && name != "" && !is_int(key) && name == key {
					continue;
				} else {
					let output .= this->output(value, "", tab + 1) . "\n";
				}
			}
			return output . str_repeat(space, tab - 1) . ")";
		}

		if is_object(variable) {

			let output .= strtr("<b style=':style'>Object</b> :class", [
				":style": this->getStyle("obj"),
				":class": get_class(variable)
			]);

			if get_parent_class(variable) {
				let output .= strtr(" <b style=':style'>extends</b> :parent", [
					":style": this->getStyle("obj"),
					":parent": get_parent_class(variable)
				]);
			}
			let output .= " (\n";

			do {

				let attr = each(variable);
				if !attr {
					continue;
				}

				let key = attr["key"], value = attr["value"];

				if !key {
					continue;
				}

				let key = explode(chr(ord("\x00")), key), type = "public";

				if isset key[1] {
					let type = "private";
					if key[1] == "*" {
						let type = "protected";
					}
				}

				let output .= str_repeat(space, tab) . strtr("-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", [":style": this->getStyle("obj"), ":key": end(key), ":type": type]);
				let output .= this->output(value, "", tab + 1) . "\n";
			} while attr;

			let attr = get_class_methods(variable);
			let output .= str_repeat(space, tab) . strtr(":class <b style=':style'>:methods</b>: (<span style=':style'>:count</span>) (\n", [":style": this->getStyle("obj"), ":class": get_class(variable), ":count": count(attr)]);
			if in_array(get_class(variable), this->methods) {
				let output .= str_repeat(space, tab) . "[already listed]\n";
			} else {
				for key, value in attr {
					let this->methods[] = get_class(variable);
					if value == "__construct" {
						let output .= str_repeat(space, tab + 1) . strtr("-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", [":style": this->getStyle("obj"), ":method": value]);
					} else {
						let output .= str_repeat(space, tab + 1) . strtr("-><span style=':style'>:method</span>();\n", [":style": this->getStyle("obj"), ":method": value]);
					}
				}
				let output .= str_repeat(space, tab) . ")\n";
			}

			return output . str_repeat(space, tab - 1) . ")";
		}

		if is_resource(variable) {
			return "<b style='" . this->getStyle("res") . "'>Resource</b> [" . get_resource_type(variable) . "] ( <span style='" . this->getStyle("res") . "'>" . variable . "</span> )";
		}

		if is_int(variable) {
			return strtr("<b style=':style'>Intiger</b> (<span style=':style'>:var</span>)", [":style": this->getStyle("int"), ":var": variable]);
		}

		if is_float(variable) {
			return strtr("<b style=':style'>Float</b> (<span style=':style'>:var</span>)", [":style": this->getStyle("float"), ":var": variable]);
		}

		if is_numeric(variable) {
			return strtr("<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", [":style": this->getStyle("num"), ":length": strlen(variable), ":var": variable]);
		}

		if is_string(variable) {
			return strtr("<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", [":style": this->getStyle("str"), ":length": strlen(variable), ":var": nl2br(htmlentities(variable, ENT_IGNORE, "utf-8"))]);
		}

		if is_bool(variable) {
			let type = "FALSE";
			if variable {
				let type = "TRUE";
			}
			return strtr("<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", [":style": this->getStyle("bool"), ":var": type]);
		}

		if is_null(variable) {
			return strtr("<b style=':style'>NULL</b>", [":style": this->getStyle("null")]);
		}
		return strtr("(<span style=':style'>:var</span>)", [":style": this->getStyle("other"), ":var": variable]);
	}

	public function setStyles(styles)
	{
		var defaultStyles;

		if typeof styles == "null" {
			let styles = [];
		}
		if typeof styles != "array" {
			throw new \Phalcon\Debug\Exception("Styles must be an array");
		}

		let defaultStyles = [
			"pre": "background-color:#f3f3f3;font-size:11px;padding:10px; border:1px solid #ccc; text-align:left; color:#333",
			"arr": "color:red",
			"bool": "color:green",
			"float": "color:fuchsia",
			"int": "color:blue",
			"null": "color:black",
			"num": "color:navy",
			"obj": "color:purple",
			"other": "color:maroon",
			"res": "color:lime",
			"str": "color:teal"
		];

		let this->_styles = array_merge(defaultStyles, styles);
		return this->_styles;
	}

	/**
	 * Get style for type
	 *
	 * @param string type
	 * @return string
	 */
	public function getStyle(string! type)
	{
		return this->_styles[type];
	}
}
