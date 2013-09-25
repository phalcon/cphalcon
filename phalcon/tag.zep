
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
	 * Sets the dependency injector container.
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public static function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Tag\Exception("Parameter dependencyInjector must be an Object");
		}
		let self::_dependencyInjector = dependencyInjector;
	}

	/**
	 * Internally gets the request dispatcher
	 *
	 * @return Phalcon\DiInterface
	 */
	public static function getDI() -> <Phalcon\DiInterface>
	{
		return self::_dependencyInjector;
	}

	/**
	 * Return a URL service from the default DI
     *
	 * @return Phalcon\Mvc\UrlInterface
	 */
	public static function getUrlService() -> <Phalcon\Mvc\UrlInterface>
	{
		var url, dependencyInjector;

		let url = self::_urlService;
		if typeof url != "object" {

			//let dependencyInjector = <Phalcon\DiInterface> self::_dependencyInjector;
			let dependencyInjector = self::_dependencyInjector;
			if typeof dependencyInjector != "object" {
				let dependencyInjector = Phalcon\Di::getDefault();
			}

			if typeof dependencyInjector != "object" {
				throw new Phalcon\Tag\Exception("A dependency injector container is required to obtain the 'url' service");
			}

			let url = <Phalcon\Mvc\UrlInterface> dependencyInjector->getShared("url"),
				self::_urlService = url;
		}
		return url;
	}

	/**
	 * Returns an Escaper service from the default DI
	 *
	 * @return Phalcon\EscaperInterface
	 */
	public static function getEscaperService() -> <Phalcon\EscaperInterface>
	{
		var escaper, dependencyInjector;

		let escaper = self::_escaperService;
		if typeof escaper != "object" {

			//let dependencyInjector = <Phalcon\DiInterface> self::_dependencyInjector;
			let dependencyInjector = self::_dependencyInjector;
			if typeof dependencyInjector != "object" {
				let dependencyInjector = Phalcon\DI::getDefault();
			}

			if typeof dependencyInjector != "object" {
				throw new Phalcon\Tag\Exception("A dependency injector container is required to obtain the 'escaper' service");
			}

			let escaper = <Phalcon\EscaperInterface> dependencyInjector->getShared("escaper"),
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
	public static function setDefault(string id, value){
		if value !== null {
			if typeof value == "array" || typeof value == "object" {
				throw new Phalcon\Tag\Exception("Only scalar values can be assigned to UI components");
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
			throw new Phalcon\Tag\Exception("An array is required as default values");
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
	public static function hasValue(name)
	{
		var displayValues;

		let displayValues = self::_displayValues;

		/**
		 * Check if there is a predefined value for it
		 */
		if isset displayValues[name] {
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
		var value, autoescape, displayValues, escaper;

		let displayValues = self::_displayValues;

		/**
		 * Check if there is a predefined value for it
		 */
		if !fetch value, displayValues[name] {
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
				let escaper = self::getEscaperService();
				return escaper->escapeHtmlAttr(value);
			}

			if typeof params == "array" {
				if fetch autoescape, params["escape"] {
					if autoescape {
						let escaper = self::getEscaperService();
						return escaper->escapeHtmlAttr(value);
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
	 *	echo Phalcon\Tag::linkTo('signup/register', 'Register Here!');
	 *	echo Phalcon\Tag::linkTo(array('signup/register', 'Register Here!'));
	 *	echo Phalcon\Tag::linkTo(array('signup/register', 'Register Here!', 'class' => 'btn-primary'));
	 *</code>
	 *
	 * @param	array|string parameters
	 * @param   string text
	 * @return	string
	 */
	public static function linkTo(parameters, text=null)
	{
		var key, value, params, action, url, code;

		if typeof parameters != "array" {
			let params = array(parameters, text);
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

		let url = self::getUrlService(),
			code = "<a href=\"" . url->get(action) . "\"";
		for key, value in params {
			if typeof key != "integer" {
				let code .= " " . key . "=\"" . value . "\"";
			}
		}
		let code .= ">" . text . "</a>";

		return code;
	}

}
