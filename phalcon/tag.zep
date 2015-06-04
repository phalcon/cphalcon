
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
 |          Nikolaos Dimopoulos <nikos@phalconphp.com>                    |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

use Phalcon\Tag\Select;
use Phalcon\Tag\Exception;
use Phalcon\Mvc\UrlInterface;

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
	 * Pre-assigned values for components
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

	/**
	 * Obtains the 'escaper' service if required
	 *
	 * @param array params
	 * @return EscaperInterface
	 */
	public static function getEscaper(array! params)
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

	/**
	 * Renders parameters keeping order in their HTML attributes
	 */
	public static function renderAttributes(string! code, array! attributes) -> string
	{
		var order, escaper, attrs, attribute, value, escaped, key, newCode;

		let order = [
			"rel"    : null,
			"type"   : null,
			"for"    : null,
			"src"    : null,
			"href"   : null,
			"action" : null,
			"id"     : null,
			"name"   : null,
			"value"  : null,
			"class"  : null
		];

		let attrs = [];
		for key, value in order {
			if fetch attribute, attributes[key] {
				let attrs[key] = attribute;
			}
		}

		for key, value in attributes {
			if !isset attrs[key] {
				let attrs[key] = value;
			}
		}

		let escaper = <EscaperInterface> self::getEscaper(attributes);

		unset attrs["escape"];

		let newCode = code;
		for key, value in attrs {
			if typeof key == "string" && value !== null {
				if typeof value == "array" || typeof value == "resource" {
					throw new Exception("Value at index: '" . key . "' type: '" . gettype(value) . "' cannot be rendered");
				}
				if escaper {
					let escaped = escaper->escapeHtmlAttr(value);
				} else {
					let escaped = value;
				}
				let newCode .= " " . key . "=\"" . escaped . "\"";
			}
		}

		return newCode;
	}

	/**
	 * Sets the dependency injector container.
	 */
	public static function setDI(<DiInterface> dependencyInjector)
	{
		let self::_dependencyInjector = dependencyInjector;
	}

	/**
	 * Internally gets the request dispatcher
	 */
	public static function getDI() -> <DiInterface>
	{
		var di;
		let di = self::_dependencyInjector;
		if typeof di != "object" {
			let di = Di::getDefault();
		}
		return di;
	}

	/**
	 * Returns a URL service from the default DI
	 */
	public static function getUrlService() -> <UrlInterface>
	{
		var url, dependencyInjector;

		let url = self::_urlService;
		if typeof url != "object" {

			let dependencyInjector = <DiInterface> self::_dependencyInjector;
			if typeof dependencyInjector != "object" {
				let dependencyInjector = Di::getDefault();
			}

			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the 'url' service");
			}

			let url = <UrlInterface> dependencyInjector->getShared("url"),
				self::_urlService = url;
		}
		return url;
	}

	/**
	 * Returns an Escaper service from the default DI
	 */
	public static function getEscaperService() -> <EscaperInterface>
	{
		var escaper, dependencyInjector;

		let escaper = self::_escaperService;
		if typeof escaper != "object" {

			let dependencyInjector = <DiInterface> self::_dependencyInjector;
			if typeof dependencyInjector != "object" {
				let dependencyInjector = Di::getDefault();
			}

			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the 'escaper' service");
			}

			let escaper = <EscaperInterface> dependencyInjector->getShared("escaper"),
				self::_escaperService = escaper;
		}
		return escaper;
	}

	/**
	 * Set autoescape mode in generated html
	 */
	public static function setAutoescape(boolean autoescape) -> void
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
	public static function setDefault(string! id, value) -> void
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
	 */
	public static function setDefaults(array! values, boolean merge = false) -> void
	{
		var displayValues;

		if merge {
			let displayValues = self::_displayValues;
			if typeof displayValues == "array" {
				let self::_displayValues = array_merge(displayValues, values);
			} else {
				let self::_displayValues = values;
			}
		} else {
			let self::_displayValues = values;
		}
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
	public static function hasValue(var name) -> boolean
	{
		/**
		 * Check if there is a predefined value for it
		 */
		if isset self::_displayValues[name] {
			return true;
		}

		/**
		 * Check if there is a post value for the item
		 */
		return isset _POST[name];
	}

	/**
	 * Every helper calls this function to check whether a component has a predefined
	 * value using Phalcon\Tag::setDefault or value from _POST
	 *
	 * @param string name
	 * @param array params
	 * @return mixed
	 */
	public static function getValue(var name, params = null)
	{
		var value;

		if !params || !fetch value, params["value"] {
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
		}

		return value;
	}

	/**
	 * Resets the request and internal values to avoid those fields will have any default value
	 */
	public static function resetInput() -> void
	{
		let self::_displayValues = [], {"_POST"} = [];
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
	public static function linkTo(parameters, text = null, local = true) -> string
	{
		var params, action, query, url, code;

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

		if fetch query, params["query"] {
			unset params["query"];
		} else  {
			let query = null;
		}

		let url = self::getUrlService(),
			params["href"] = url->get(action, query, local),
			code = self::renderAttributes("<a", params),
			code .= ">" . text . "</a>";

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
	static protected final function _inputField(string type, parameters, boolean asValue = false) -> string
	{
		var params, id, value, code, name;

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
			if typeof id == "string" {
				if !memstr(id, "[") && !isset params["id"] {
					let params["id"] = id;
				}
			}

			let params["value"] = self::getValue(id, params);

		} else {
			/**
			 * Use the "id" as value if the user hadn't set it
			 */
			if !isset params["value"] {
				if fetch value, params[0] {
					let params["value"] = value;
				}
			}
		}

		let params["type"] = type,
			code = self::renderAttributes("<input", params);

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
	static protected final function _inputFieldChecked(string type, var parameters) -> string
	{
		var params, value, id, code, name, currentValue;

		if  typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
		}

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

		/**
		 * Automatically check inputs
		 */
		if fetch currentValue, params["value"] {
			unset params["value"];

			let value = self::getValue(id, params);

			if value && currentValue == value {
				let params["checked"] = "checked";
			}
			let params["value"] = currentValue;
		} else {
			let value = self::getValue(id, params);

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

		let params["type"] = type,
			code = self::renderAttributes("<input", params);

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
	public static function colorField(var parameters) -> string
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
	public static function textField(var parameters) -> string
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
	public static function numericField(var parameters) -> string
	{
		return self::_inputField("number", parameters);
	}


	/**
	* Builds a HTML input[type="range"] tag
	*
	* @param array parameters
	* @return string
	*/
	public static function rangeField(var parameters) -> string
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
	public static function emailField(var parameters) -> string
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
	public static function dateField(var parameters) -> string
	{
		return self::_inputField("date", parameters);
	}

	/**
	* Builds a HTML input[type="datetime"] tag
	*
	* @param array parameters
	* @return string
	*/
	public static function dateTimeField(var parameters) -> string
	{
		return self::_inputField("datetime", parameters);
	}

	/**
	* Builds a HTML input[type="datetime-local"] tag
	*
	* @param array parameters
	* @return string
	*/
	public static function dateTimeLocalField(var parameters) -> string
	{
		return self::_inputField("datetime-local", parameters);
	}

	/**
	 * Builds a HTML input[type="month"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public static function monthField(var parameters) -> string
	{
		return self::_inputField("month", parameters);
	}

	/**
	 * Builds a HTML input[type="time"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public static function timeField(var parameters) -> string
	{
		return self::_inputField("time", parameters);
	}

	/**
	 * Builds a HTML input[type="week"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public static function weekField(var parameters) -> string
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
	public static function passwordField(var parameters) -> string
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
	public static function hiddenField(var parameters) -> string
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
	public static function fileField(var parameters) -> string
	{
		return self::_inputField("file", parameters);
	}

	/**
	 * Builds a HTML input[type="search"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public static function searchField(var parameters) -> string
	{
		return self::_inputField("search", parameters);
	}

	/**
	* Builds a HTML input[type="tel"] tag
	*
	* @param array parameters
	* @return string
	*/
	public static function telField(var parameters) -> string
	{
		return self::_inputField("tel", parameters);
	}

	/**
	 * Builds a HTML input[type="url"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public static function urlField(var parameters) -> string
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
	public static function checkField(var parameters) -> string
	{
		return self::_inputFieldChecked("checkbox", parameters);
	}

	/**
	 * Builds a HTML input[type="radio"] tag
	 *
	 *<code>
	 * echo Phalcon\Tag::radioField(array("weather", "value" => "hot"))
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
	public static function radioField(var parameters) -> string
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
	public static function imageInput(var parameters) -> string
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
	public static function submitButton(var parameters) -> string
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
	public static function selectStatic(parameters, data = null) -> string
	{
		return Select::selectField(parameters, data);
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
	public static function select(var parameters, data = null) -> string
	{
		return Select::selectField(parameters, data);
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
	public static function textArea(var parameters) -> string
	{
		var params, id, name, content, code;

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

		let code = self::renderAttributes("<textarea", params),
			code .= ">" . content . "</textarea>";

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
	public static function form(var parameters) -> string
	{
		var params, paramsAction, action, code;

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

		let code = self::renderAttributes("<form", params),
			code .= ">";

		return code;
	}

	/**
	 * Builds a HTML close FORM tag
	 */
	public static function endForm() -> string
	{
		return "</form>";
	}

	/**
	 * Set the title of view content
	 *
	 *<code>
	 * Phalcon\Tag::setTitle("Welcome to my Page");
	 *</code>
	 */
	public static function setTitle(string title) -> void
	{
		let self::_documentTitle = title;
	}

	/**
	 * Set the title separator of view content
	 *
	 *<code>
	 * Phalcon\Tag::setTitleSeparator("-");
	 *</code>
	 */
	public static function setTitleSeparator(string titleSeparator) -> void
	{
		let self::_documentTitleSeparator = titleSeparator;
	}

	/**
	 * Appends a text to current document title
	 */
	public static function appendTitle(string title) -> void
	{
		let self::_documentTitle = self::_documentTitle . self::_documentTitleSeparator . title;
	}

	/**
	 * Prepends a text to current document title
	 */
	public static function prependTitle(string title) -> void
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
	 */
	public static function getTitle(boolean tags = true) -> string
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
	 */
	public static function getTitleSeparator() -> string
	{
		return self::_documentTitleSeparator;
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
	public static function stylesheetLink(var parameters = null, boolean local = true) -> string
	{
		var params, code;

		if typeof parameters != "array" {
			let params = [parameters, local];
		} else {
			let params = parameters;
		}

		if isset params[1] {
			let local = (boolean) params[1];
		} else {
			if isset params["local"] {
				let local = (boolean) params["local"];
				unset params["local"];
			}
		}

		if !isset params["type"] {
			let params["type"] = "text/css";
		}

		if !isset params["href"] {
			if isset params[0] {
				let params["href"] = params[0];
			} else {
				let params["href"] = "";
			}
		}

		/**
		 * URLs are generated through the "url" service
		 */
		if local === true {
			let params["href"] = self::getUrlService()->getStatic(params["href"]);
		}

		if !isset params["rel"] {
			let params["rel"] = "stylesheet";
		}

		let code = self::renderAttributes("<link", params);

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
	public static function javascriptInclude(var parameters = null, boolean local = true) -> string
	{
		var params, code;

		if typeof parameters != "array" {
			let params = [parameters, local];
		} else {
			let params = parameters;
		}

		if isset params[1] {
			let local = (boolean) params[1];
		} else {
			if isset params["local"] {
				let local = (boolean) params["local"];
				unset params["local"];
			}
		}

		if !isset params["type"] {
			let params["type"] = "text/javascript";
		}

		if !isset params["src"] {
			if isset params[0] {
				let params["src"] = params[0];
			} else {
				let params["src"] = "";
			}
		}

		/**
		 * URLs are generated through the "url" service
		 */
		if local === true {
			let params["src"] = self::getUrlService()->getStatic(params["src"]);
		}

		let code = self::renderAttributes("<script", params),
			code .= "></script>" . PHP_EOL;

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
	public static function image(var parameters = null, boolean local = true) -> string
	{
		var params, code, src;

		if typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
			if isset params[1] {
				let local = (boolean) params[1];
			}
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

		let code = self::renderAttributes("<img", params);

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
	 * @param mixed replace
	 * @return text
	 */
	public static function friendlyTitle(string text, string separator = "-", boolean lowercase = true, replace = null) -> string
	{
		var friendly, locale, search;

		if extension_loaded("iconv") {
			/**
			 * Save the old locale and set the new locale to UTF-8
			 */
			let locale = setlocale(LC_ALL, "en_US.UTF-8"),
				text = iconv("UTF-8", "ASCII//TRANSLIT", text);
		}

		if replace {

			if typeof replace != "array" && typeof replace != "string"{
				throw new Exception("Parameter replace must be an array or a string");
			}
			if typeof replace == "array" {
				for search in replace {
					let text = str_replace(search, " ", text);
				}
			} else {
				let text = str_replace(replace, " ", text);
			}
		}

		let friendly = preg_replace("/[^a-zA-Z0-9\\/_|+ -]/", "", text);
		if lowercase {
			let friendly = strtolower(friendly);
		}

		let friendly = preg_replace("/[\\/_|+ -]+/", separator, friendly),
			friendly = trim(friendly, separator);

		if extension_loaded("iconv") {
			/**
			 * Revert back to the old locale
			 */
			setlocale(LC_ALL, locale);
		}
		return friendly;
	}

	/**
	 * Set the document type of content
	 */
	public static function setDocType(int doctype) -> void
	{
		if (doctype < self::HTML32 || doctype > self::XHTML5) {
			let self::_documentType = self::HTML5;
		} else {
			let self::_documentType = doctype;
		}
	}

	/**
	 * Get the document type declaration of content
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

			case 6:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" . PHP_EOL;
			/* no break */

			case 7:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" . PHP_EOL."\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" . PHP_EOL;
			/* no break */

			case 8:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" . PHP_EOL;
			/* no break */

			case 9:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" . PHP_EOL;
			/* no break */

			case 10: return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" . PHP_EOL . "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" . PHP_EOL;
			/* no break */

			case 5:
			case 11: return "<!DOCTYPE html>" . PHP_EOL;
			/* no break */
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
	public static function tagHtml(string tagName, var parameters = null, boolean selfClose = false,
		boolean onlyStart = false, boolean useEol = false) -> string
	{
		var params, localCode;

		if typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
		}

		let localCode = self::renderAttributes("<" . tagName, params);

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
	 */
	public static function tagHtmlClose(string tagName, boolean useEol = false) -> string
	{
		if useEol {
			return "</" . tagName . ">" . PHP_EOL;
		}
		return "</" . tagName . ">";
	}
}
