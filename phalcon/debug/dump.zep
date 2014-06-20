
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

	public static detailed = false;

	protected static methods = null;


	/**
	 * Returns an HTML string of debugging information about any number of
	 * variables, each wrapped in a "pre" tag.
	 *
	 *<code>
	 *echo Phalcon\Debug\Dump::all($foo, $bar, $baz);
	 *</code>
	 *
	 * @param mixed variable
	 * @param ...
	 * @return string
	 */
	public static function all()
	{
		var key, value, output;

		let output = "";
		for key, value in func_get_args() {
			let output .= self::one(value, "var " . key);
		}

		return output;
	}

	/**
	 * Get style for type
	 *
	 * @param string type
	 * @return string
	 */
	protected static function getStyle(string! type)
	{
		var style, styles;
		let styles = [
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

		if fetch style, styles[type] {
			return style;
		} else {
			return "color:gray";
		}
	}

	/**
	 * Returns an HTML string of information about a single variable.
	 *
	 *<code>
	 *echo Phalcon\Debug\Dump::one($foo, "foo");
	 *</code>
	 *
	 * @param mixed variable
	 * @param string name
	 * @return string
	 */
	public static function one(variable, name=null)
	{
		return strtr("<pre style=':style'>:output</pre>", [":style": self::getStyle("pre"), ":output": self::output(variable, name)]);
	}	

	/**
	 * Prepare an HTML string of information about a single variable.
	 *
	 * @param mixed variable
	 * @param string name
	 * @param intiger tab
	 * @return  string
	 */
	protected static function output(variable, name=null, tab=1)
	{
		var key, value, output, space, type, attr;
		let space = "  ", 
			output = "";

		if name {
			let output = name . " ";
		}

		if typeof self::methods == "null" {
			let self::methods = [];
		}

		if typeof variable == "array" {
			let output .= strtr("<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", [":style": self::getStyle("arr"), ":count": count(variable)]);

			for key, value in variable {
				let output .= str_repeat(space, tab) . strtr("[<span style=':style'>:key</span>] => ", [":style": self::getStyle("arr"), ":key": key]);

				if tab == 0 && name != "" && !is_int(key) && name == key {
					continue;
				} else {
					let output .= self::output(value, "", tab + 1) . "\n";
				}
			}
			return output . str_repeat(space, tab - 1) . ")";
		}

		if is_object(variable) {
			let output .= str_repeat(space, tab) . ")\n";
			let output .= strtr("<b style=':style'>Object</b> :class", [":style": self::getStyle("obj"), ":class": get_class(variable)]);

			if get_parent_class(variable) {
				let output .= strtr(" <b style=':style'>extends</b> :parent", [":style": self::getStyle("obj"), ":parent": get_parent_class(variable)]);
			}
			let output .= " (\n";

			if !self::detailed {
				for key, value in get_object_vars(variable) {
					let output .= str_repeat(space, tab) . strtr("-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", [":style": self::getStyle("obj"), ":key": key, ":type": "public"]);
					let output .= self::output(value, "", tab + 1) . "\n";
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
					let output .= str_repeat(space, tab) . strtr("-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", [":style": self::getStyle("obj"), ":key": end(key), ":type": type]);
					let output .= self::output(value, "", tab + 1) . "\n";
				} while attr;
			}

			let attr = get_class_methods(variable);
			let output .= str_repeat(space, tab) . strtr(":class <b style=':style'>:methods</b>: (<span style=':style'>:count</span>) (\n", [":style": self::getStyle("obj"), ":class": get_class(variable), ":count": count(attr)]);

			if (in_array(get_class(variable), self::methods)) {
				let output .= str_repeat(space, tab) . "[already listed]\n";
			} else {
				for key, value in attr {
					let self::methods[] = get_class(variable);

					if value == "__construct" {
						let output .= str_repeat(space, tab + 1) . strtr("-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", [":style": self::getStyle("obj"), ":method": value]);
					} else {
						let output .= str_repeat(space, tab + 1) . strtr("-><span style=':style'>:method</span>();\n", [":style": self::getStyle("obj"), ":method": value]);
					}
				}
			}
		}

		if is_string(variable) {
			return strtr("<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", [":style": self::getStyle("str"), ":length": strlen(variable), ":var": nl2br(htmlentities(variable, ENT_IGNORE, "utf-8"))]);
		}

		if is_bool(variable) {
			let type = "FALSE";

			if variable {
				let type = "TRUE";
			}
			return strtr("<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", [":style": self::getStyle("bool"), ":var": type]);
		}

		if is_null(variable) {
			return strtr("<b style=':style'>NULL</b>", [":style": self::getStyle("null")]);
		}
		return strtr("(<span style=':style'>:var</span>)", [":style": self::getStyle("other"), ":var": variable]);
	}

	/**
	 * Alias of Phalcon\Debug\Dump::one
	 *
	 * @param mixed variable
	 * @param string name
	 * @return string
	 */
	public static function variable(variable, name=null)
	{
		return self::one(variable, name);
	}

	/**
	 * Alias of Phalcon\Debug\Dump::all
	 *
	 * @param mixed variable
	 * @param ...
	 * @return string
	 */
	public static function variables()
	{
		return call_user_func_array("self::all", func_get_args());
	}

}
