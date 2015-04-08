
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
 | Authors: Olivier Monaco <olivier.monaco@free.fr>                       |
 +------------------------------------------------------------------------+
 */
namespace Phalcon;

/**
 * Phalcon\Enum
 *
 * Base classes for enums that works like Java Enums. Child classes must implements
 * the static _init method to returns an array of class instances.
 * <code>
 * class MyEnum extends Phalcon\Enum
 * {
 *     protected static function _init()
 *     {
 *         return array(
 *             new self('First'),
 *             new self('Second'),
 *         );
 *     }
 * }
 * </code>
 *
 * Then, each instance can be accessed using a static method equals to the instance
 * name (ie. the constructor argument).
 * <code>
 * MyEnum::First()
 * </code>
 *
 * The same instance if returned for each call so we can use the = operator.
 *
 * Child classes can add other properties.
 * <code>
 * class Country extends Phalcon\Enum
 * {
 *     private $_code;
 *     private $_language;
 *
 *     public function __construct($name, $code, $language)
 *     {
 *         parent::__construct($name);
 *         $this->_code = $code;
 *         $this->_language = $language;
 *     }
 *
 *     public function getCode() ...
 *
 *     public function getLanguage() ...
 *     
 *     protected static function _init()
 *     {
 *         return array(
 *             new self('France', 'fr_FR', 'French'),
 *             ...
 *         );
 *     }
 * }
 * </code>
 */
abstract class Enum
{
	private static _values;

	private _name;

	protected static function _get()
	{
		var bt, name;
		let bt = debug_backtrace();
		let name = bt[1]["function"];
		return static::valueOf(name);
	}

	protected static function _init()
	{
		// This method must be abstract but even if PHP allow abstract static method
		// it produces a warning at runtime... And if I remove this method, Zephir
		// does not want to generate C code. So, here is a dummy method that
		// must be overrided by subclasses
		throw new Exception("You must override the static _init method.");
	}

	public function __get(string! name)
	{
		if ($name === "name") {
			return $this->_name;
		}
		return null;
	}

	/**
	 * Proctected to avoid creation of instance somewhere else than in _init method
	 */
	protected function __construct(string! name)
	{
		let this->_name = name;
	}

	public function __toString() -> string
	{
		return this->_name;
	}

	public static function __callstatic(string! name, array args)
	{
		return static::valueOf(name);
	}

	public static function valueOf(string! name, boolean emptyIsNull = false)
	{
		var values;
		if (empty(name)) {
			return null;
		}
		let values = static::values();
		if (!array_key_exists(name, values)) {
			throw new EnumValueNotExists(name, get_called_class());
		}
		return values[name];
	}

	public static function values() -> array
	{
		var cls, values, value;
		if (is_null(self::_values)) {
			let self::_values = [];
		}
		let cls = get_called_class();
		if (!isset(self::_values[cls])) {
			let values = [];
			for value in static::_init() {
				let values[value->name] = value;
			}
			let self::_values[cls] = values;
		}
		return self::_values[cls];
	}
}
