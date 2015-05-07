
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 * Dumps information about a variable(s)
 *
 * <code>
 *    $foo = 123;
 *    echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 *</code>
 *
 * <code>
 *    $foo = "string";
 *    $bar = ["key" => "value"];
 *    $baz = new stdClass();
 *    echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 *</code>
 */
class Dump
{

	protected _detailed = false { get, set };

	protected _methods = null;

	protected _styles;

	/**
	 * Phalcon\Debug\Dump constructor
	 *
	 * @param boolean detailed debug object's private and protected properties
	 */
	public function __construct(array styles = null, boolean detailed = false)
	{
		if styles && typeof styles != "array" {
			throw new Exception("The styles must be an array");
		}
		this->setStyles(styles);
		let this->_methods = [],
			this->_detailed = detailed;
	}


	/**
	 * Alias of variables() method
	 *
	 * @param mixed variable
	 * @param ...
	 */
	public function all() -> string
	{
		return call_user_func_array([this, "variables"], func_get_args());
	}

	/**
	 * Get style for type
	 */
	protected function getStyle(string! type) -> string
	{
		var style;

		if fetch style, this->_styles[type] {
			return style;
		} else {
			return "color:gray";
		}
	}

	/**
	 * Set styles for vars type
	 */
	public function setStyles(var styles = null) -> array
	{
		var defaultStyles;

		if typeof styles == "null" {
			let styles = [];
		}
		if typeof styles != "array" {
			throw new Exception("The styles must be an array");
		}

		let defaultStyles = [
			"pre": "background-color:#f3f3f3; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333",
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
	 * Alias of variable() method
	 */
	public function one(var variable, string name = null) -> string
	{
		return this->variable(variable, name);
	}

	/**
	 * Prepare an HTML string of information about a single variable.
	 */
	protected function output(var variable, string name = null, int tab = 1) -> string
	{
		var key, value, output, space, type, attr;
		let space = "  ",
			output = "";

		if name {
			let output = name . " ";
		}

		if typeof variable == "array" {
			let output .= strtr("<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", [":style": this->getStyle("arr"), ":count": count(variable)]);

			for key, value in variable {
				let output .= str_repeat(space, tab) . strtr("[<span style=':style'>:key</span>] => ", [":style": this->getStyle("arr"), ":key": key]);

				if tab == 1 && name != "" && !is_int(key) && name == key {
					continue;
				} else {
					let output .= this->output(value, "", tab + 1) . "\n";
				}
			}
			return output . str_repeat(space, tab - 1) . ")";
		}

		if typeof variable == "object" {

			let output .= strtr("<b style=':style'>Object</b> :class", [":style": this->getStyle("obj"), ":class": get_class(variable)]);

			if get_parent_class(variable) {
				let output .= strtr(" <b style=':style'>extends</b> :parent", [":style": this->getStyle("obj"), ":parent": get_parent_class(variable)]);
			}
			let output .= " (\n";

			if !this->_detailed {
				for key, value in get_object_vars(variable) {
					let output .= str_repeat(space, tab) . strtr("-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", [":style": this->getStyle("obj"), ":key": key, ":type": "public"]);
					let output .= this->output(value, "", tab + 1) . "\n";
				}
			} else {
				do {
					let attr = each(variable);

					if !attr {
						continue;
					}
					let key = attr["key"],
						value = attr["value"];

					if !key {
						continue;
					}
					let key = explode(chr(ord("\x00")), key),
						type = "public";

					if isset key[1] {
						let type = "private";

						if key[1] == "*" {
							let type = "protected";
						}
					}
					let output .= str_repeat(space, tab) . strtr("-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", [":style": this->getStyle("obj"), ":key": end(key), ":type": type]);
					let output .= this->output(value, "", tab + 1) . "\n";
				} while attr;
			}

			let attr = get_class_methods(variable);
			let output .= str_repeat(space, tab) . strtr(":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", [":style": this->getStyle("obj"), ":class": get_class(variable), ":count": count(attr)]);

			if (in_array(get_class(variable), this->_methods)) {
				let output .= str_repeat(space, tab) . "[already listed]\n";
			} else {
				for value in attr {
					let this->_methods[] = get_class(variable);

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

		if is_int(variable) {
			return strtr("<b style=':style'>Integer</b> (<span style=':style'>:var</span>)", [":style": this->getStyle("int"), ":var": variable]);
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
			return strtr("<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", [":style": this->getStyle("bool"), ":var": (variable ? "TRUE" : "FALSE")]);
		}

		if is_null(variable) {
			return strtr("<b style=':style'>NULL</b>", [":style": this->getStyle("null")]);
		}
		return strtr("(<span style=':style'>:var</span>)", [":style": this->getStyle("other"), ":var": variable]);
	}

	/**
	 * Returns an HTML string of information about a single variable.
	 *
	 * <code>
	 *    echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
	 * </code>
	 */
	public function variable(var variable, string name = null) -> string
	{
		return strtr("<pre style=':style'>:output</pre>", [
			":style": this->getStyle("pre"),
			":output": this->output(variable, name)
		]);
	}

	/**
	 * Returns an HTML string of debugging information about any number of
	 * variables, each wrapped in a "pre" tag.
	 *
	 * <code>
	 *    $foo = "string";
	 *    $bar = ["key" => "value"];
	 *    $baz = new stdClass();
	 *    echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
	 *</code>
	 *
	 * @param mixed variable
	 * @param ...
	 */
	public function variables() -> string
	{
		var key, value, output;

		let output = "";
		for key, value in func_get_args() {
			let output .= this->one(value, "var " . key);
		}

		return output;
	}
}
