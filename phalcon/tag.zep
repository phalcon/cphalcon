
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
 |          Nikolaos Dimopoulos <nikos@phalconphp.com>                    |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

use Phalcon\Tag\Exception;

/**
 * Phalcon\Tag
 *
 * Phalcon\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */
class Tag
{
	/**
	 * Pre-asigned values for components
	 */
	protected static _displayValues;

	/**
	 * HTML document title
	 */
	protected static _documentTitle = null;

	protected static _documentTitleSeparator = null;

	protected static _documentType = 11;

	/**
	 * Framework Dispatcher
	 */
	protected static _dependencyInjector;

	protected static _urlService = null;

	protected static _dispatcherService = null;

	protected static _escaperService = null;

	protected static _autoEscape = true;

	const HTML32 = 1;

	const HTML401_STRICT = 2;

	const HTML401_TRANSITIONAL = 3;

	const HTML401_FRAMESET = 4;

	const HTML5 = 5;

	const XHTML10_STRICT = 6;

	const XHTML10_TRANSITIONAL = 7;

	const XHTML10_FRAMESET = 8;

	const XHTML11 = 9;

	const XHTML20 = 10;

	const XHTML5 = 11;


	public static function getEscaper(params)
	{
		var result, autoescape;

		if !fetch autoescape, params["escape"] {
			let autoescape = self::_autoEscape;
		}

		if autoescape {
			let result = self::getEscaperService();
		} else {
			let result = null;
		}

		return result;
	}

	public static function renderAttributes(string code, attributes)
	{
		var order, escaper, attrs, value, escaped, attribute, key;

		let attrs = [];
		let order = ["type", "for", "src", "href", "action", "id", "name", "value", "class"];

		let escaper = self::getEscaper(attributes);

		for attribute, value in attributes {
			if isset order[attribute] {
				let attrs[attribute] = value;
			}
		}

		let attrs = array_merge_recursive(attrs, attributes);

		unset attrs["escape"];

		for key, value in attrs {
			if typeof key == "string" {
				if escaper {
					let escaped = escaper->escapeHtmlAttr(value);
				} else {
					let escaped = value;
				}
				let code .= " " . key . "=\"" . escaped . "\"";
			}
		}

		return code;
	}

	/**
	 * Sets the dependency injector container.
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public static function setDI(<\Phalcon\DiInterface> dependencyInjector)
	{
		if typeof dependencyInjector != "object" {
			throw new Exception("Parameter dependencyInjector must be an Object");
		}
		let self::_dependencyInjector = dependencyInjector;
	}

	/**
	 * Internally gets the request dispatcher
	 *
	 * @return Phalcon\DiInterface
	 */
	public static function getDI() -> <\Phalcon\DiInterface>
	{
		return self::_dependencyInjector;
	}

	/**
	 * Return a URL service from the default DI
	 *
	 * @return Phalcon\Mvc\UrlInterface
	 */
	public static function getUrlService() -> <\Phalcon\Mvc\UrlInterface>
	{
		var url, dependencyInjector;

		let url = self::_urlService;
		if typeof url != "object" {

			let dependencyInjector = <\Phalcon\DiInterface> self::_dependencyInjector;
			if typeof dependencyInjector != "object" {
				let dependencyInjector = \Phalcon\Di::getDefault();
			}

			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the 'url' service");
			}

			let url = <\Phalcon\Mvc\UrlInterface> dependencyInjector->getShared("url"),
				self::_urlService = url;
		}
		return url;
	}

	/**
	 * Returns an Escaper service from the default DI
	 *
	 * @return Phalcon\EscaperInterface
	 */
	public static function getEscaperService() -> <\Phalcon\EscaperInterface>
	{
		var escaper, dependencyInjector;

		let escaper = self::_escaperService;
		if typeof escaper != "object" {

			//let dependencyInjector = <\Phalcon\DiInterface> self::_dependencyInjector;
			let dependencyInjector = self::_dependencyInjector;
			if typeof dependencyInjector != "object" {
				let dependencyInjector = \Phalcon\Di::getDefault();
			}

			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the 'escaper' service");
			}

			let escaper = <\Phalcon\EscaperInterface> dependencyInjector->getShared("escaper"),
				self::_escaperService = escaper;
		}
		return escaper;
	}

	/**
	 * Set autoescape mode in generated html
	 *
	 * @param boolean autoescape
	 */
	public static function setAutoescape(boolean autoescape)
	{
		let self::_autoEscape = autoescape;
	}

	/**
	 * Assigns default values to generated tags by helpers
	 *
	 * <code>
	 * //Assigning "peter" to "name" component
	 * Phalcon\Tag::setDefault("name", "peter");
	 *
	 * //Later in the view
	 * echo Phalcon\Tag::textField("name"); //Will have the value "peter" by default
	 * </code>
	 *
	 * @param string id
	 * @param string value
	 */
	public static function setDefault(string id, value)
	{
		if value !== null {
			if typeof value == "array" || typeof value == "object" {
				throw new Exception("Only scalar values can be assigned to UI components");
			}
		}
		let self::_displayValues[id] = value;
	}

	/**
	 * Assigns default values to generated tags by helpers
	 *
	 * <code>
	 * //Assigning "peter" to "name" component
	 * Phalcon\Tag::setDefaults(array("name" => "peter"));
	 *
	 * //Later in the view
	 * echo Phalcon\Tag::textField("name"); //Will have the value "peter" by default
	 * </code>
	 *
	 * @param array values
	 */
	public static function setDefaults(values)
	{
		if typeof values != "array" {
			throw new Exception("An array is required as default values");
		}
		let self::_displayValues = values;
	}

	/**
	 * Alias of Phalcon\Tag::setDefault
	 *
	 * @param string id
	 * @param string value
	 */
	public static function displayTo(id, value)
	{
		return self::setDefault(id, value);
	}

	/**
	 * Check if a helper has a default value set using Phalcon\Tag::setDefault or value from _POST
	 *
	 * @param string name
	 * @return boolean
	 */
	public static function hasValue(name) -> boolean
	{
		/**
		 * Check if there is a predefined value for it
		 */
		if isset self::_displayValues[name] {
			return true;
		} else {
			/**
			 * Check if there is a post value for the item
			 */
			if isset _POST[name] {
				return true;
			}
		}

		return false;
	}

	/**
	 * Every helper calls this function to check whether a component has a predefined
	 * value using Phalcon\Tag::setDefault or value from _POST
	 *
	 * @param string name
	 * @param array params
	 * @return mixed
	 */
	public static function getValue(name, params=null)
	{
		var value, autoescape;

		/**
		 * Check if there is a predefined value for it
		 */
		if !fetch value, self::_displayValues[name] {
			/**
			 * Check if there is a post value for the item
			 */
			if !fetch value, _POST[name] {
				return null;
			}
		}

		/**
		 * Escape all values in autoescape mode. Only escaping values
		 */
		if typeof value == "string" {

			if self::_autoEscape {
				return self::getEscaperService()->escapeHtmlAttr(value);
			}

			if typeof params == "array" {
				if fetch autoescape, params["escape"] {
					if autoescape {
						return self::getEscaperService()->escapeHtmlAttr(value);
					}
				}
			}
		}

		return value;
	}

	/**
	 * Resets the request and internal values to avoid those fields will have any default value
	 */
	public static function resetInput()
	{
		var key, value;

		let self::_displayValues = [];
		for key, value in _POST {
			unset _POST[key];
		}
	}

	/**
	 * Builds a HTML A tag using framework conventions
	 *
	 *<code>
	 *	echo Phalcon\Tag::linkTo("signup/register", "Register Here!");
	 *	echo Phalcon\Tag::linkTo(array("signup/register", "Register Here!"));
	 *	echo Phalcon\Tag::linkTo(array("signup/register", "Register Here!", "class" => "btn-primary"));
	 *	echo Phalcon\Tag::linkTo("http://phalconphp.com/", "Phalcon", FALSE);
	 *	echo Phalcon\Tag::linkTo(array("http://phalconphp.com/", "Phalcon Home", FALSE));
	 *	echo Phalcon\Tag::linkTo(array("http://phalconphp.com/", "Phalcon Home", "local" =>FALSE));
	 *</code>
	 *
	 * @param array|string parameters
	 * @param string text
	 * @param boolean local
	 * @return string
	 */
	public static function linkTo(parameters, text=null, local=true)
	{
		var key, value, params, action, url, code;

		if typeof parameters != "array" {
			let params = [parameters, text, local];
		} else {
			let params = parameters;
		}

		if !fetch action, params[0] {
			if !fetch action, params["action"] {
				let action = "";
			} else {
				unset params["action"];
			}
		}

		if !fetch text, params[1] {
			if !fetch text, params["text"] {
				let text = "";
			} else {
				unset params["text"];
			}
		}

		if !fetch local, params[2] {
			if !fetch local, params["local"] {
				let local = true;
			} else {
				unset params["local"];
			}
		}

		if local {
			let url = self::getUrlService(),
				code = "<a href=\"" . url->get(action) . "\"";
		} else {
			let code = "<a href=\"" . action . "\"";
		}

		for key, value in params {
			if typeof key != "integer" {
				let code .= " " . key . "=\"" . value . "\"";
			}
		}
		let code .= ">" . text . "</a>";

		return code;
	}

	/**
	 * Builds generic INPUT tags
	 *
	 * @param   string type
	 * @param	array parameters
	 * @param 	boolean asValue
	 * @return	string
	 */
	static protected function _inputField(string type, parameters, boolean asValue=false) -> string
	{
		var params, id, value, key, code, name;

		let params = [];

		if typeof parameters != "array" {
			let params[] = parameters;
		} else {
			let params = parameters;
		}

		if asValue == false {

			if !fetch id, params[0] {
				let params[0] = params["id"];
			}

			if fetch name, params["name"] {
				if empty name {
					let params["name"] = id;
				}
			} else {
				let params["name"] = id;
			}

			/**
			* Automatically assign the id if the name is not an array
			*/
			if !memstr(id, "[") {
				if !isset params["id"] {
					let params["id"] = id;
				}
			}

			/**
			 * Use the parameter "value" if the developer had set it
			 */
			if !isset params["value"] {
				let params["value"] = self::getValue(id, params);
			}

		} else {
			/**
			 * Use the "id" as value if the user hadn"t set it
			 */
			if !isset params["value"] {
				if fetch value, params[0] {
					let params["value"] = value;
				}
			}
		}

		let code = "<input type=\"" . type . "\"";
		for key, value in params {
			if typeof key != "integer" {
				let code .= " " . key . "=\"" . value . "\"";
			}
		}

		/**
		 * Check if Doctype is XHTML
		 */
		if self::_documentType > self::HTML5 {
			let code .= " />";
		} else {
			let code .= ">";
		}

		return code;
	}

	/**
	 * Builds INPUT tags that implements the checked attribute
	 *
	 * @param   string type
	 * @param	array parameters
	 * @return	string
	 */
	static protected function _inputFieldChecked(string type, parameters) -> string
	{
		var params, value, id, key, code, name, currentValue;

		if  typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
		}

		let value = null;

		if !isset params[0] {
			let params[0] = params["id"];
		}

		let id = params[0];
		if  !isset params["name"] {
			let params["name"] = id;
		} else {
			let name = params["name"];
			if  empty name {
				let params["name"] = id;
			}
		}

		/**
		* Automatically assign the id if the name is not an array
		*/
		if !strpos(id, "[") {
			if !isset params["id"] {
				let params["id"] = id;
			}
		}

		let value = self::getValue(id, params);

		/**
		 * Automatically check inputs
		 */
		if isset params["value"] {
			let currentValue = params["value"];
			if currentValue == value {
				let params["checked"] = "checked";
			}
		} else {
			/**
			* Evaluate the value in POST
			*/
			if value {
				let params["checked"] = "checked";
			}

			/**
			* Update the value anyways
			*/
			let params["value"] = value;
		}

		let code = "<input type=\"" . type . "\"";
		for key, value in params {
			if typeof key != "integer" {
				let code .= " " . key . "=\"" . value . "\"";
			}
		}

		/**
		 * Check if Doctype is XHTML
		 */
		if self::_documentType > self::HTML5 {
			let code .= " />";
		} else {
			let code .= ">";
		}

		return code;
	}

	/**
	 * Builds a HTML input[type="color"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	static public function colorField(parameters) -> string
	{
		return self::_inputField("color", parameters);
	}

	/**
	 * Builds a HTML input[type="text"] tag
	 *
	 * <code>
	 *	echo Phalcon\Tag::textField(array("name", "size" => 30));
	 * </code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function textField(parameters) -> string
	{
		return self::_inputField("text", parameters);
	}

	/**
	 * Builds a HTML input[type="number"] tag
	 *
	 * <code>
	 *	echo Phalcon\Tag::numericField(array("price", "min" => "1", "max" => "5"));
	 * </code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function numericField(parameters) -> string
	{
		return self::_inputField("number", parameters);
	}


	/**
	* Builds a HTML input[type="range"] tag
	*
	* @param array parameters
	* @return string
	*/
	static public function rangeField(parameters) -> string
	{
		return self::_inputField("range", parameters);
	}

	/**
	 * Builds a HTML input[type="email"] tag
	 *
	 * <code>
	 *	echo Phalcon\Tag::emailField("email");
	 * </code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function emailField(parameters) -> string
	{
		return self::_inputField("email", parameters);
	}

	/**
	 * Builds a HTML input[type="date"] tag
	 *
	 * <code>
	 *	echo Phalcon\Tag::dateField(array("born", "value" => "14-12-1980"))
	 * </code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function dateField(parameters) -> string
	{
		return self::_inputField("date", parameters);
	}

	/**
	* Builds a HTML input[type="datetime"] tag
	*
	* @param array parameters
	* @return string
	*/
	static public function dateTimeField(parameters) -> string
	{
		return self::_inputField("datetime", parameters);
	}

	/**
	* Builds a HTML input[type="datetime-local"] tag
	*
	* @param array parameters
	* @return string
	*/
	static public function dateTimeLocalField(parameters) -> string
	{
		return self::_inputField("datetime-local", parameters);
	}

	/**
	 * Builds a HTML input[type="month"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	static public function monthField(parameters) -> string
	{
		return self::_inputField("month", parameters);
	}

	/**
	 * Builds a HTML input[type="time"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	static public function timeField(parameters) -> string
	{
		return self::_inputField("time", parameters);
	}

	/**
	 * Builds a HTML input[type="week"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	static public function weekField(parameters) -> string
	{
		return self::_inputField("week", parameters);
	}

	/**
	 * Builds a HTML input[type="password"] tag
	 *
	 *<code>
	 * echo Phalcon\Tag::passwordField(array("name", "size" => 30));
	 *</code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function passwordField(parameters) -> string
	{
		return self::_inputField("password", parameters);
	}

	/**
	 * Builds a HTML input[type="hidden"] tag
	 *
	 *<code>
	 * echo Phalcon\Tag::hiddenField(array("name", "value" => "mike"));
	 *</code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function hiddenField(parameters) -> string
	{
		return self::_inputField("hidden", parameters);
	}

	/**
	 * Builds a HTML input[type="file"] tag
	 *
	 *<code>
	 * echo Phalcon\Tag::fileField("file");
	 *</code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function fileField(parameters) -> string
	{
		return self::_inputField("file", parameters);
	}

	/**
	 * Builds a HTML input[type="search"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	static public function searchField(parameters) -> string
	{
		return self::_inputField("search", parameters);
	}

	/**
	* Builds a HTML input[type="tel"] tag
	*
	* @param array parameters
	* @return string
	*/
	static public function telField(parameters) -> string
	{
		return self::_inputField("tel", parameters);
	}

	/**
	 * Builds a HTML input[type="url"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	static public function urlField(parameters) -> string
	{
		return self::_inputField("url", parameters);
	}

	/**
	 * Builds a HTML input[type="check"] tag
	 *
	 *<code>
	 * echo Phalcon\Tag::checkField(array("terms", "value" => "Y"));
	 *</code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function checkField(parameters) -> string
	{
		return self::_inputFieldChecked("checkbox", parameters);
	}

	/**
	 * Builds a HTML input[type="radio"] tag
	 *
	 *<code>
	 * echo Phalcon\Tag::radioField(array("wheather", "value" => "hot"))
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ radio_field("Save") }}
	 *</code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function radioField(parameters) -> string
	{
		return self::_inputFieldChecked("radio", parameters);
	}

	/**
	 * Builds a HTML input[type="image"] tag
	 *
	 *<code>
	 * echo Phalcon\Tag::imageInput(array("src" => "/img/button.png"));
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ image_input("src": "/img/button.png") }}
	 *</code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function imageInput(parameters) -> string
	{
		return self::_inputField("image", parameters, true);
	}

	/**
	 * Builds a HTML input[type="submit"] tag
	 *
	 *<code>
	 * echo Phalcon\Tag::submitButton("Save")
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ submit_button("Save") }}
	 *</code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function submitButton(parameters) -> string
	{
		return self::_inputField("submit", parameters, true);
	}

	/**
	 * Builds a HTML SELECT tag using a PHP array for options
	 *
	 *<code>
	 *	echo Phalcon\Tag::selectStatic("status", array("A" => "Active", "I" => "Inactive"))
	 *</code>
	 *
	 * @param	array parameters
	 * @param   array data
	 * @return	string
	 */
	public static function selectStatic(parameters, data=null) -> string
	{
		return \Phalcon\Tag\Select::selectField(parameters, data);
	}

	/**
	 * Builds a HTML SELECT tag using a Phalcon\Mvc\Model resultset as options
	 *
	 *<code>
	 *	echo Phalcon\Tag::select(array(
	 *		"robotId",
	 *		Robots::find("type = "mechanical""),
	 *		"using" => array("id", "name")
	 * 	));
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ select("robotId", robots, "using": ["id", "name"]) }}
	 *</code>
	 *
	 * @param	array parameters
	 * @param   array data
	 * @return	string
	 */
	public static function select(parameters, data=null) -> string
	{
		return \Phalcon\Tag\Select::selectField(parameters, data);
	}

	/**
	 * Builds a HTML TEXTAREA tag
	 *
	 *<code>
	 * echo Phalcon\Tag::textArea(array("comments", "cols" => 10, "rows" => 4))
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ text_area("comments", "cols": 10, "rows": 4) }}
	 *</code>
	 *
	 * @param	array parameters
	 * @return	string
	 */
	static public function textArea(parameters) -> string
	{
		var params, id, key, name, avalue, content, code;

		if typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
		}

		if !isset params[0] {
			if isset params["id"] {
				let params[0] = params["id"];
			}
		}

		let id = params[0];
		if !isset params["name"] {
			let params["name"] = id;
		} else {
			let name = params["name"];
			if empty name {
				let params["name"] = id;
			}
		}

		if !isset params["id"] {
			let params["id"] = id;
		}

		if isset params["value"] {
			let content = params["value"];
			unset params["value"];
		} else {
			let content = self::getValue(id, params);
		}

		let code = "<textarea";
		for key,avalue in params {
			if typeof key != "integer" {
				let code .=  " ".key."=\"".avalue."\"";
			}
		}

		let code .= ">".content."</textarea>";

		return code;
	}

	/**
	 * Builds a HTML FORM tag
	 *
	 * <code>
	 * echo Phalcon\Tag::form("posts/save");
	 * echo Phalcon\Tag::form(array("posts/save", "method" => "post"));
	 * </code>
	 *
	 * Volt syntax:
	 * <code>
	 * {{ form("posts/save") }}
	 * {{ form("posts/save", "method": "post") }}
	 * </code>
	 *
	 * @param array parameters
	 * @return string
	 */
	static public function form(parameters) -> string
	{
		var params, paramsAction, action, code, key, avalue;

		if typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
		}

		if !fetch paramsAction, params[0] {
			fetch paramsAction, params["action"];
		}

		/**
		 * By default the method is POST
		 */
		if !isset params["method"] {
			let params["method"] = "post";
		}

		let action = null;

		if !empty paramsAction {
			let action = self::getUrlService()->get(paramsAction);
		}

		/**
		 * Check for extra parameters
		 */
		if fetch parameters, params["parameters"] {
			let action .= "?" . parameters;
		}

		if !empty action {
			let params["action"] = action;
		}

		let code = "<form";
		for key, avalue in params {
			if typeof key != "integer" {
				let code .= " " . key . "=\"" . avalue . "\"";
			}
		}
		let code .= ">";

		return code;
	}

	/**
	 * Builds a HTML close FORM tag
	 *
	 * @return	string
	 */
	public static function endForm()
	{
		return "</form>";
	}

	/**
	 * Set the title of view content
	 *
	 *<code>
	 * Phalcon\Tag::setTitle("Welcome to my Page");
	 *</code>
	 *
	 * @param string title
	 */
	public static function setTitle(string title)
	{
		let self::_documentTitle = title;
	}

	/**
	 * Set the title separator of view content
	 *
	 *<code>
	 * Phalcon\Tag::setTitleSeparator("-");
	 *</code>
	 *
	 * @param string titleSeparator
	 */
	static public function setTitleSeparator(string titleSeparator)
	{
		let self::_documentTitleSeparator = titleSeparator;
	}

	/**
	 * Appends a text to current document title
	 *
	 * @param string title
	 */
	public static function appendTitle(string title)
	{
		let self::_documentTitle = self::_documentTitle . self::_documentTitleSeparator . title;
	}

	/**
	 * Prepends a text to current document title
	 *
	 * @param string title
	 */
	public static function prependTitle(string title)
	{
		let self::_documentTitle = title . self::_documentTitleSeparator . self::_documentTitle;
	}

	/**
	 * Gets the current document title
	 *
	 * <code>
	 * 	echo Phalcon\Tag::getTitle();
	 * </code>
	 *
	 * <code>
	 * 	{{ get_title() }}
	 * </code>
	 *
	 * @return string
	 */
	public static function getTitle(boolean tags=true) -> string
	{
		var documentTitle;
		let documentTitle = self::_documentTitle;
		if tags {
			return "<title>" . documentTitle . "</title>" . PHP_EOL;
		}
		return documentTitle;
	}

	/**
	* Gets the current document title separator
	*
	* <code>
	*         echo Phalcon\Tag::getTitleSeparator();
	* </code>
	*
	* <code>
	*         {{ get_title_separator() }}
	* </code>
	*
	* @return string
	*/
	public static function getTitleSeparator()
	{
		return this->_documentTitleSeparator;
	}

	/**
	 * Builds a LINK[rel="stylesheet"] tag
	 *
	 * <code>
	 * 	echo Phalcon\Tag::stylesheetLink("http://fonts.googleapis.com/css?family=Rosario", false);
	 * 	echo Phalcon\Tag::stylesheetLink("css/style.css");
	 * </code>
	 *
	 * Volt Syntax:
	 *<code>
	 * 	{{ stylesheet_link("http://fonts.googleapis.com/css?family=Rosario", false) }}
	 * 	{{ stylesheet_link("css/style.css") }}
	 *</code>
	 *
	 * @param	array parameters
	 * @param   boolean local
	 * @return	string
	 */
	public static function stylesheetLink(parameters=null, local=true)
	{
		var params, code, key, value;

		if typeof parameters != "array" {
			let params = [parameters, local];
		} else {
			let params = parameters;
		}

		if !isset params["href"] {
			if isset params[0] {
				let params["href"] = params[0];
			} else {
				let params["href"] = "";
			}
		}

		let local = false;

		if isset params[1] {
			let local = params[1];
		} else {
			if isset params["local"] {
				let local = params["local"];
				unset params["local"];
			}
		}

		if !isset params["type"] {
			let params["type"] = "text/css";
		}

		/**
		 * URLs are generated through the "url" service
		 */
		if local {
			let params["href"] = self::getUrlService()->getStatic(params["href"]);;
		}

		let code = "<link rel=\"stylesheet\"";
		for key, value in params {
			if typeof key != "integer" {
				let code .= " " . key . "=\"" . value . "\"";
			}
		}

		/**
		 * Check if Doctype is XHTML
		 */
		if self::_documentType > self::HTML5 {
			let code .= " />" . PHP_EOL;
		} else {
			let code .= ">" . PHP_EOL;
		}

		return code;
	}

	/**
	 * Builds a SCRIPT[type="javascript"] tag
	 *
	 * <code>
	 *         echo Phalcon\Tag::javascriptInclude("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false);
	 *         echo Phalcon\Tag::javascriptInclude("javascript/jquery.js");
	 * </code>
	 *
	 * Volt syntax:
	 * <code>
	 * {{ javascript_include("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false) }}
	 * {{ javascript_include("javascript/jquery.js") }}
	 * </code>
	 *
	 * @param array parameters
	 * @param   boolean local
	 * @return string
	 */
	public static function javascriptInclude(parameters=null, local=true)
	{
		var params, code, key, value;

		if typeof parameters != "array" {
			let params = [parameters, local];
		} else {
			let params = parameters;
		}

		if !isset params["src"] {
			if isset params[0] {
				let params["src"] = params[0];
			} else {
				let params["src"] = "";
			}
		}

		let local = false;

		if isset params[1] {
			let local = params[1];
		} else {
			if isset params["local"] {
				let local = params["local"];
				unset params["local"];
			}
		}

		if !isset params["type"] {
			let params["type"] = "text/javascript";
		}

		/**
		 * URLs are generated through the "url" service
		 */
		if local {
			let params["src"] = self::getUrlService()->getStatic(params["src"]);
		}

		let code = "<script";
		for key, value in params {
			if typeof key != "integer" {
				let code .= " " . key . "=\"" . value . "\"";
			}
		}
		let code .= "></script>" . PHP_EOL;

		return code;
	}

	/**
	 * Builds HTML IMG tags
	 *
	 * <code>
	 *         echo Phalcon\Tag::image("img/bg.png");
	 *         echo Phalcon\Tag::image(array("img/photo.jpg", "alt" => "Some Photo"));
	 * </code>
	 *
	 * Volt Syntax:
	 * <code>
	 *         {{ image("img/bg.png") }}
	 *         {{ image("img/photo.jpg", "alt": "Some Photo") }}
	 *         {{ image("http://static.mywebsite.com/img/bg.png", false) }}
	 * </code>
	 *
	 * @param  array parameters
	 * @param  boolean local
	 * @return string
	 */
	public static function image(parameters=null, local=true)
	{
		var params, code, key, value, src;

		if typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
		}

		if !isset params["src"] {
			if fetch src, params[0] {
				let params["src"] = src;
			} else {
				let params["src"] = "";
			}
		}

		/**
		 * Use the "url" service if the URI is local
		 */
		if local {
			let params["src"] = self::getUrlService()->getStatic(params["src"]);
		}

		let code = "<img";
		for key, value in params {
			if typeof key != "integer" {
				let code .= " ".key."=\"".value."\"";
			}
		}

		/**
		 * Check if Doctype is XHTML
		 */
		if self::_documentType > self::HTML5 {
			let code .= " />";
		} else {
			let code .= ">";
		}

		return code;
	}

	/**
	 * Converts texts into URL-friendly titles
	 *
	 *<code>
	 * echo Phalcon\Tag::friendlyTitle("These are big important news", "-")
	 *</code>
	 *
	 * @param string text
	 * @param string separator
	 * @param boolean lowercase
	 * @return text
	 */
	public static function friendlyTitle(text, separator="-", lowercase=true) -> string
	{
		var friendly;

		let friendly = preg_replace("~[^a-z0-9A-Z]+~", separator, text);
		if !empty lowercase {
			return strtolower(friendly);
		}
		return friendly;
	}

	/**
	 * Set the document type of content
	 *
	 * @param string doctype
	 */
	public static function setDocType(doctype) -> void
	{
		let self::_documentType = doctype;
	}

	/**
	 * Get the document type declaration of content
	 *
	 * @return string
	 */
	public static function getDocType() -> string
	{

		switch self::_documentType
		{
			case 1:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" . PHP_EOL;
			/* no break */
			case 2:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/strict.dtd\">" . PHP_EOL;
			/* no break */
			case 3:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/loose.dtd\">" . PHP_EOL;
			/* no break */
			case 4:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/frameset.dtd\">" . PHP_EOL;
			/* no break */
			case 5:  return "<!DOCTYPE html>" . PHP_EOL;
			/* no break */
			case 6:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" . PHP_EOL;
			/* no break */
			case 7:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" . PHP_EOL."\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" . PHP_EOL;
			/* no break */
			case 8:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" . PHP_EOL;
			/* no break */
			case 9:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" . PHP_EOL;
			/* no break */
			case 10: return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" . PHP_EOL . "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" . PHP_EOL;
		}

		return "";
	}

	/**
	 * Builds a HTML tag
	 *
	 *<code>
	 *        echo Phalcon\Tag::tagHtml(name, parameters, selfClose, onlyStart, eol);
	 *</code>
	 *
	 * @param string tagName
	 * @param array parameters
	 * @param boolean selfClose
	 * @param boolean onlyStart
	 * @param boolean useEol
	 * @return string
	 */
	public static function tagHtml(tagName, parameters=null, selfClose=false, onlyStart=false, useEol=false) -> string
	{
		var params, localCode, key, value;

		if typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
		}

		let localCode = "<" . tagName;

		for key, value in params {
			if typeof key != "integer" {
				let localCode .= " " . key . "=\"" . value . "\"";
			}
		}

		/**
		 * Check if Doctype is XHTML
		 */
		if self::_documentType > self::HTML5 {
			if selfClose {
				let localCode .= " />";
			} else {
				let localCode .= ">";
			}
		} else {
			if onlyStart {
				let localCode .= ">";
			} else {
				let localCode .= "></" . tagName . ">";
			}
		}

		if useEol {
			let localCode .= PHP_EOL;
		}

		return localCode;
	}

	/**
	 * Builds a HTML tag closing tag
	 *
	 *<code>
	 *        echo Phalcon\Tag::tagHtmlClose("script", true)
	 *</code>
	 *
	 * @param string tagName
	 * @param boolean useEol
	 * @return string
	 */
	public static function tagHtmlClose(tagName, useEol=false)
	{
		if useEol {
			return "</" . tagName . ">" . PHP_EOL;
		}
		return "</" . tagName . ">";
	}

}
