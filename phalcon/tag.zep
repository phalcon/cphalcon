
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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
	protected _displayValues;

	/**
	 * HTML document title
	 */
	protected _documentTitle = null;

	protected _documentAppendTitle = null;

	protected _documentPrependTitle = null;

	protected _documentTitleSeparator = null;

	protected _documentType = 11;

	/**
	 * Framework Dispatcher
	 */
	protected _dependencyInjector;

	protected _urlService = null;

	protected _dispatcherService = null;

	protected _escaperService = null;

	protected _autoEscape = true;

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
	public function getEscaper(array! params)
	{
		var autoescape;

		if !fetch autoescape, params["escape"] {
			let autoescape = this->_autoEscape;
		}

		if !autoescape {
			return null;
		}

		return this->getEscaperService();
	}

	/**
	 * Renders parameters keeping order in their HTML attributes
	 */
	public function renderAttributes(string! code, array! attributes) -> string
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

		let escaper = <EscaperInterface> this->getEscaper(attributes);

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
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Internally gets the request dispatcher
	 */
	public function getDI() -> <DiInterface>
	{
		var di;
		let di = this->_dependencyInjector;
		if typeof di != "object" {
			let di = Di::getDefault();
		}
		return di;
	}

	/**
	 * Returns a URL service from the default DI
	 */
	public function getUrlService() -> <UrlInterface>
	{
		var url, dependencyInjector;

		let url = this->_urlService;
		if typeof url != "object" {

			let dependencyInjector = this->getDI();

			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the 'url' service");
			}

			let url = <UrlInterface> dependencyInjector->getShared("url"),
				this->_urlService = url;
		}
		return url;
	}

	/**
	 * Returns an Escaper service from the default DI
	 */
	public function getEscaperService() -> <EscaperInterface>
	{
		var escaper, dependencyInjector;

		let escaper = this->_escaperService;
		if typeof escaper != "object" {

			let dependencyInjector = this->getDI();

			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the 'escaper' service");
			}

			let escaper = <EscaperInterface> dependencyInjector->getShared("escaper"),
				this->_escaperService = escaper;
		}
		return escaper;
	}

	/**
	 * Set autoescape mode in generated html
	 */
	public function setAutoescape(boolean autoescape) -> void
	{
		let this->_autoEscape = autoescape;
	}

	/**
	 * Assigns default values to generated tags by helpers
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * // Assigning "peter" to "name" component
	 * $tag->setDefault("name", "peter");
	 *
	 * // Later in the view
	 * echo $tag->textField("name"); // Will have the value "peter" by default
	 * </code>
	 *
	 * @param string id
	 * @param string value
	 */
	public function setDefault(string! id, value) -> void
	{
		if value !== null {
			if typeof value == "array" || typeof value == "object" {
				throw new Exception("Only scalar values can be assigned to UI components");
			}
		}
		let this->_displayValues[id] = value;
	}

	/**
	 * Assigns default values to generated tags by helpers
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * // Assigning "peter" to "name" component
	 * $tag->setDefaults(
	 *     [
	 *         "name" => "peter",
	 *     ]
	 * );
	 *
	 * // Later in the view
	 * echo $tag->textField("name"); // Will have the value "peter" by default
	 * </code>
	 */
	public function setDefaults(array! values, boolean merge = false) -> void
	{
		if merge && typeof this->_displayValues == "array" {
			let this->_displayValues = array_merge(this->_displayValues, values);
		} else {
			let this->_displayValues = values;
		}
	}

	/**
	 * Alias of Phalcon\Tag::setDefault
	 *
	 * @param string id
	 * @param string value
	 */
	public function displayTo(id, value) -> void
	{
		this->setDefault(id, value);
	}

	/**
	 * Check if a helper has a default value set using Phalcon\Tag::setDefault or value from $_POST
	 *
	 * @param string name
	 * @return boolean
	 */
	public function hasValue(var name) -> boolean
	{
		/**
		 * Check if there is a predefined or a POST value for it
		 */
		return isset this->_displayValues[name] || isset _POST[name];
	}

	/**
	 * Every helper calls this function to check whether a component has a predefined
	 * value using Phalcon\Tag::setDefault or value from $_POST
	 *
	 * @param string name
	 * @param array params
	 * @return mixed
	 */
	public function getValue(var name, params = null)
	{
		var value;

		if !params || !fetch value, params["value"] {
			/**
			 * Check if there is a predefined value for it
			 */
			if !fetch value, this->_displayValues[name] {
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
	 * Builds a HTML A tag using framework conventions
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->linkTo("signup/register", "Register Here!");
	 *
	 * echo $tag->linkTo(
	 *     [
	 *         "signup/register",
	 *         "Register Here!"
	 *     ]
	 * );
	 *
	 * echo $tag->linkTo(
	 *     [
	 *         "signup/register",
	 *         "Register Here!",
	 *         "class" => "btn-primary",
	 *     ]
	 * );
	 *
	 * echo $tag->linkTo("http://phalconphp.com/", "Phalcon", false);
	 *
	 * echo $tag->linkTo(
	 *     [
	 *         "http://phalconphp.com/",
	 *         "Phalcon Home",
	 *         false,
	 *     ]
	 * );
	 *
	 * echo $tag->linkTo(
	 *     [
	 *         "http://phalconphp.com/",
	 *         "Phalcon Home",
	 *         "local" => false,
	 *     ]
	 * );
	 *
	 * echo $tag->linkTo(
	 *     [
	 *         "action" => "http://phalconphp.com/",
	 *         "text"   => "Phalcon Home",
	 *         "local"  => false,
	 *         "target" => "_new"
	 *     ]
	 * );
	 *</code>
	 *
	 * @param array|string parameters
	 * @param string text
	 * @param boolean local
	 */
	public function linkTo(parameters, text = null, local = true) -> string
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

		let url = this->getUrlService(),
			params["href"] = url->get(action, query, local),
			code = this->renderAttributes("<a", params),
			code .= ">" . text . "</a>";

		return code;
	}

	/**
	 * Builds generic INPUT tags
	 *
	 * @param string type
	 * @param array parameters
	 * @param boolean asValue
	 * @return string
	 */
	protected final function _inputField(string type, parameters, boolean asValue = false) -> string
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

			let params["value"] = this->getValue(id, params);

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
			code = this->renderAttributes("<input", params);

		/**
		 * Check if Doctype is XHTML
		 */
		if this->_documentType > self::HTML5 {
			let code .= " />";
		} else {
			let code .= ">";
		}

		return code;
	}

	/**
	 * Builds INPUT tags that implements the checked attribute
	 *
	 * @param string type
	 * @param array parameters
	 * @return string
	 */
	protected final function _inputFieldChecked(string type, var parameters) -> string
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
		if !isset params["name"] {
			let params["name"] = id;
		} else {
			let name = params["name"];
			if empty name {
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

			let value = this->getValue(id, params);

			if value != null && currentValue == value {
				let params["checked"] = "checked";
			}
			let params["value"] = currentValue;
		} else {
			let value = this->getValue(id, params);

			/**
			* Evaluate the value in POST
			*/
			if value != null {
				let params["checked"] = "checked";
			}

			/**
			* Update the value anyways
			*/
			let params["value"] = value;
		}

		let params["type"] = type,
			code = this->renderAttributes("<input", params);

		/**
		 * Check if Doctype is XHTML
		 */
		if this->_documentType > self::HTML5 {
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
	public function colorField(var parameters) -> string
	{
		return this->_inputField("color", parameters);
	}

	/**
	 * Builds a HTML input[type="text"] tag
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->textField(
	 *     [
	 *         "name",
	 *         "size" => 30,
	 *     ]
	 * );
	 * </code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function textField(var parameters) -> string
	{
		return this->_inputField("text", parameters);
	}

	/**
	 * Builds a HTML input[type="number"] tag
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->numericField(
	 *     [
	 *         "price",
	 *         "min" => "1",
	 *         "max" => "5",
	 *     ]
	 * );
	 * </code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function numericField(var parameters) -> string
	{
		return this->_inputField("number", parameters);
	}


	/**
	* Builds a HTML input[type="range"] tag
	*
	* @param array parameters
	* @return string
	*/
	public function rangeField(var parameters) -> string
	{
		return this->_inputField("range", parameters);
	}

	/**
	 * Builds a HTML input[type="email"] tag
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->emailField("email");
	 * </code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function emailField(var parameters) -> string
	{
		return this->_inputField("email", parameters);
	}

	/**
	 * Builds a HTML input[type="date"] tag
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->dateField(
	 *     [
	 *         "born",
	 *         "value" => "14-12-1980",
	 *     ]
	 * );
	 * </code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function dateField(var parameters) -> string
	{
		return this->_inputField("date", parameters);
	}

	/**
	* Builds a HTML input[type="datetime"] tag
	*
	* @param array parameters
	* @return string
	*/
	public function dateTimeField(var parameters) -> string
	{
		return this->_inputField("datetime", parameters);
	}

	/**
	* Builds a HTML input[type="datetime-local"] tag
	*
	* @param array parameters
	* @return string
	*/
	public function dateTimeLocalField(var parameters) -> string
	{
		return this->_inputField("datetime-local", parameters);
	}

	/**
	 * Builds a HTML input[type="month"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public function monthField(var parameters) -> string
	{
		return this->_inputField("month", parameters);
	}

	/**
	 * Builds a HTML input[type="time"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public function timeField(var parameters) -> string
	{
		return this->_inputField("time", parameters);
	}

	/**
	 * Builds a HTML input[type="week"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public function weekField(var parameters) -> string
	{
		return this->_inputField("week", parameters);
	}

	/**
	 * Builds a HTML input[type="password"] tag
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->passwordField(
	 *     [
	 *         "name",
	 *         "size" => 30,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function passwordField(var parameters) -> string
	{
		return this->_inputField("password", parameters);
	}

	/**
	 * Builds a HTML input[type="hidden"] tag
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->hiddenField(
	 *     [
	 *         "name",
	 *         "value" => "mike",
	 *     ]
	 * );
	 *</code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function hiddenField(var parameters) -> string
	{
		return this->_inputField("hidden", parameters);
	}

	/**
	 * Builds a HTML input[type="file"] tag
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->fileField("file");
	 *</code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function fileField(var parameters) -> string
	{
		return this->_inputField("file", parameters);
	}

	/**
	 * Builds a HTML input[type="search"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public function searchField(var parameters) -> string
	{
		return this->_inputField("search", parameters);
	}

	/**
	* Builds a HTML input[type="tel"] tag
	*
	* @param array parameters
	* @return string
	*/
	public function telField(var parameters) -> string
	{
		return this->_inputField("tel", parameters);
	}

	/**
	 * Builds a HTML input[type="url"] tag
	 *
	 * @param array parameters
	 * @return string
	 */
	public function urlField(var parameters) -> string
	{
		return this->_inputField("url", parameters);
	}

	/**
	 * Builds a HTML input[type="check"] tag
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->checkField(
	 *     [
	 *         "terms",
	 *         "value" => "Y",
	 *     ]
	 * );
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ check_field("terms") }}
	 *</code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function checkField(var parameters) -> string
	{
		return this->_inputFieldChecked("checkbox", parameters);
	}

	/**
	 * Builds a HTML input[type="radio"] tag
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->radioField(
	 *     [
	 *         "weather",
	 *         "value" => "hot",
	 *     ]
	 * );
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ radio_field("Save") }}
	 *</code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function radioField(var parameters) -> string
	{
		return this->_inputFieldChecked("radio", parameters);
	}

	/**
	 * Builds a HTML input[type="image"] tag
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->imageInput(
	 *     [
	 *         "src" => "/img/button.png",
	 *     ]
	 * );
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ image_input("src": "/img/button.png") }}
	 *</code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function imageInput(var parameters) -> string
	{
		return this->_inputField("image", parameters, true);
	}

	/**
	 * Builds a HTML input[type="submit"] tag
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->submitButton("Save")
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ submit_button("Save") }}
	 *</code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function submitButton(var parameters) -> string
	{
		return this->_inputField("submit", parameters, true);
	}

	/**
	 * Builds a HTML SELECT tag using a PHP array for options
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->selectStatic(
	 *     "status",
	 *     [
	 *         "A" => "Active",
	 *         "I" => "Inactive",
	 *     ]
	 * );
	 *</code>
	 *
	 * @param array parameters
	 * @param array data
	 * @return string
	 */
	public function selectStatic(parameters, data = null) -> string
	{
		return Select::selectField(parameters, data);
	}

	/**
	 * Builds a HTML SELECT tag using a Phalcon\Mvc\Model resultset as options
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->select(
	 *     [
	 *         "robotId",
	 *         Robots::find("type = "mechanical""),
	 *         "using" => ["id", "name"],
	 *     ]
	 * );
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ select("robotId", robots, "using": ["id", "name"]) }}
	 *</code>
	 *
	 * @param array parameters
	 * @param array data
	 * @return string
	 */
	public function select(var parameters, data = null) -> string
	{
		return Select::selectField(parameters, data);
	}

	/**
	 * Builds a HTML TEXTAREA tag
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->textArea(
	 *     [
	 *         "comments",
	 *         "cols" => 10,
	 *         "rows" => 4,
	 *     ]
	 * );
	 *</code>
	 *
	 * Volt syntax:
	 *<code>
	 * {{ text_area("comments", "cols": 10, "rows": 4) }}
	 *</code>
	 *
	 * @param array parameters
	 * @return string
	 */
	public function textArea(var parameters) -> string
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
			let content = this->getValue(id, params);
		}

		let code = this->renderAttributes("<textarea", params),
			code .= ">" . content . "</textarea>";

		return code;
	}

	/**
	 * Builds a HTML FORM tag
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->form("posts/save");
	 *
	 * echo $tag->form(
	 *     [
	 *         "posts/save",
	 *         "method" => "post",
	 *     ]
	 * );
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
	public function form(var parameters) -> string
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
			let action = this->getUrlService()->get(paramsAction);
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

		let code = this->renderAttributes("<form", params),
			code .= ">";

		return code;
	}

	/**
	 * Builds a HTML close FORM tag
	 */
	public function endForm() -> string
	{
		return "</form>";
	}

	/**
	 * Set the title of view content
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * $tag->setTitle("Welcome to my Page");
	 *</code>
	 */
	public function setTitle(string title) -> void
	{
		let this->_documentTitle = title;
	}

	/**
	 * Set the title separator of view content
	 *
	 *<code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * $tag->setTitleSeparator("-");
	 *</code>
	 */
	public function setTitleSeparator(string titleSeparator) -> void
	{
		let this->_documentTitleSeparator = titleSeparator;
	}

	/**
	 * Appends a text to current document title
	 */
	public function appendTitle(var title) -> void
	{
		if typeof this->_documentAppendTitle == "null" {
			let this->_documentAppendTitle = [];
		}

		if typeof title == "array" {
			let this->_documentAppendTitle = title;
		} else {
			let this->_documentAppendTitle[] = title;
		}
	}

	/**
	 * Prepends a text to current document title
	 */
	public function prependTitle(var title) -> void
	{
		if typeof this->_documentPrependTitle == "null" {
			let this->_documentPrependTitle = [];
		}

		if typeof title == "array" {
			let this->_documentPrependTitle = title ;
		} else {
			let this->_documentPrependTitle[] = title ;
		}
	}

	/**
	 * Gets the current document title.
	 * The title will be automatically escaped.
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->getTitle();
	 * </code>
	 *
	 * <code>
	 * {{ get_title() }}
	 * </code>
	 */
	public function getTitle(boolean tags = true) -> string
	{
		var items, output, title, documentTitle, documentAppendTitle, documentPrependTitle, documentTitleSeparator, escaper;

		let escaper = <EscaperInterface> this->getEscaper(["escape": true]);
		let items = [];
		let output = "";

		let documentTitle = escaper->escapeHtml(this->_documentTitle);
		let documentTitleSeparator = escaper->escapeHtml(this->_documentTitleSeparator);

		if typeof this->_documentAppendTitle == "null" {
			let this->_documentAppendTitle = [];
		}

		let documentAppendTitle = this->_documentAppendTitle;

		if typeof this->_documentPrependTitle == "null" {
			let this->_documentPrependTitle = [];
		}

		let documentPrependTitle = this->_documentPrependTitle;

		if !empty documentPrependTitle {
			var tmp = array_reverse(documentPrependTitle);
			for title in tmp {
				let items[] = escaper->escapeHtml(title);
			}
		}

		if !empty documentTitle {
			let items[] = documentTitle;
		}

		if !empty documentAppendTitle {
			for title in documentAppendTitle {
				let items[] = escaper->escapeHtml(title);
			}
		}

		if empty documentTitleSeparator {
			let documentTitleSeparator = "";
		}

		if !empty items {
			let output = implode(documentTitleSeparator, items);
		}

		if tags {
			return "<title>" . output . "</title>" . PHP_EOL;
		}

		return output;
	}

	/**
	 * Gets the current document title separator
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->getTitleSeparator();
	 * </code>
	 *
	 * <code>
	 * {{ get_title_separator() }}
	 * </code>
	 */
	public function getTitleSeparator() -> string
	{
		return this->_documentTitleSeparator;
	}

	/**
	 * Builds a LINK[rel="stylesheet"] tag
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->stylesheetLink("http://fonts.googleapis.com/css?family=Rosario", false);
	 * echo $tag->stylesheetLink("css/style.css");
	 * </code>
	 *
	 * Volt Syntax:
	 *<code>
	 * {{ stylesheet_link("http://fonts.googleapis.com/css?family=Rosario", false) }}
	 * {{ stylesheet_link("css/style.css") }}
	 *</code>
	 *
	 * @param array parameters
	 * @param boolean local
	 * @return string
	 */
	public function stylesheetLink(var parameters = null, boolean local = true) -> string
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
			let params["href"] = this->getUrlService()->getStatic(params["href"]);
		}

		if !isset params["rel"] {
			let params["rel"] = "stylesheet";
		}

		let code = this->renderAttributes("<link", params);

		/**
		 * Check if Doctype is XHTML
		 */
		if this->_documentType > self::HTML5 {
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
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->javascriptInclude("http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js", false);
	 * echo $tag->javascriptInclude("javascript/jquery.js");
	 * </code>
	 *
	 * Volt syntax:
	 * <code>
	 * {{ javascript_include("http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js", false) }}
	 * {{ javascript_include("javascript/jquery.js") }}
	 * </code>
	 *
	 * @param array parameters
	 * @param boolean local
	 * @return string
	 */
	public function javascriptInclude(var parameters = null, boolean local = true) -> string
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
			let params["src"] = this->getUrlService()->getStatic(params["src"]);
		}

		let code = this->renderAttributes("<script", params),
			code .= "></script>" . PHP_EOL;

		return code;
	}

	/**
	 * Builds HTML IMG tags
	 *
	 * <code>
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->image("img/bg.png");
	 *
	 * echo $tag->image(
	 *     [
	 *         "img/photo.jpg",
	 *         "alt" => "Some Photo",
	 *     ]
	 * );
	 * </code>
	 *
	 * Volt Syntax:
	 * <code>
	 * {{ image("img/bg.png") }}
	 * {{ image("img/photo.jpg", "alt": "Some Photo") }}
	 * {{ image("http://static.mywebsite.com/img/bg.png", false) }}
	 * </code>
	 *
	 * @param  array parameters
	 * @param  boolean local
	 * @return string
	 */
	public function image(var parameters = null, boolean local = true) -> string
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
			let params["src"] = this->getUrlService()->getStatic(params["src"]);
		}

		let code = this->renderAttributes("<img", params);

		/**
		 * Check if Doctype is XHTML
		 */
		if this->_documentType > self::HTML5 {
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
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->friendlyTitle("These are big important news", "-");
	 *</code>
	 */
	public function friendlyTitle(string text, string separator = "-", boolean lowercase = true, var replace = null) -> string
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
	public function setDocType(int doctype) -> void
	{
		if (doctype < self::HTML32 || doctype > self::XHTML5) {
			let this->_documentType = self::HTML5;
		} else {
			let this->_documentType = doctype;
		}
	}

	/**
	 * Get the document type declaration of content
	 */
	public function getDocType() -> string
	{
		switch this->_documentType
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
	 */
	public function tagHtml(string tagName, var parameters = null, boolean selfClose = false,
		boolean onlyStart = false, boolean useEol = false) -> string
	{
		var params, localCode;

		if typeof parameters != "array" {
			let params = [parameters];
		} else {
			let params = parameters;
		}

		let localCode = this->renderAttributes("<" . tagName, params);

		/**
		 * Check if Doctype is XHTML
		 */
		if this->_documentType > self::HTML5 {
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
	 * $tag = new \Phalcon\Tag();
	 *
	 * echo $tag->tagHtmlClose("script", true);
	 *</code>
	 */
	public function tagHtmlClose(string tagName, boolean useEol = false) -> string
	{
		if useEol {
			return "</" . tagName . ">" . PHP_EOL;
		}
		return "</" . tagName . ">";
	}
}
