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

namespace Phalcon\Validation;

use Phalcon\Validation\Exception;

/**
 * Phalcon\Validation\Validator
 *
 * This is a base class for validators
 */
abstract class Validator implements ValidatorInterface
{
	protected _options;

	/**
	 * Phalcon\Validation\Validator constructor
	 *
	 * @param mixed options
	 */
	public function __construct(var options = null)
	{
		if typeof options != "array" && typeof options != "null" {
			throw new Exception("Options must be an array");
		} else {
			let this->_options = options;
		}
	}

	/**
	 * Checks if an option is defined
	 *
	 * @param string key
	 * @return boolean
	 * @deprecated since 2.1.0
	 * @see \Phalcon\Validation\Validator::hasOption()
	 */
	public function isSetOption(string! key) -> boolean
	{
		return isset this->_options[key];
	}

	/**
	 * Checks if an option is defined
	 *
	 * @param string key
	 * @return boolean
	 */
	public function hasOption(string! key) -> boolean
	{
		return isset this->_options[key];
	}

	/**
	 * Returns an option in the validator's options
	 * Returns null if the option hasn't set
	 *
	 * @param string key
	 * @return mixed
	 */
	public function getOption(string! key, _default = null)
	{
		var options, value;
		let options = this->_options;

		if typeof options == "array" {
			if fetch value, options[key] {
				return value;
			}
		}

		return _default;
	}

	/**
	 * Sets an option in the validator
	 *
	 * @param string key
	 * @param mixed value
	 */
	public function setOption(string! key, value) -> void
	{
		let this->_options[key] = value;
	}

}
