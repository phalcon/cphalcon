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
use Phalcon\Validation\ValidatorInterface;

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

	 * @deprecated since 2.1.0
	 * @see \Phalcon\Validation\Validator::hasOption()
	 */
	public function isSetOption(string! key) -> boolean
	{
		return isset this->_options[key];
	}

	/**
	 * Checks if an option is defined
	 */
	public function hasOption(string! key) -> boolean
	{
		return isset this->_options[key];
	}

	/**
	 * Returns an option in the validator's options
	 * Returns null if the option hasn't set
	 */
	public function getOption(string! key, var defaultValue = null) -> var
	{
		var options, value;
		let options = this->_options;

		if typeof options == "array" {
			if fetch value, options[key] {
				return value;
			}
		}

		return defaultValue;
	}

	/**
	 * Sets an option in the validator
	 */
	public function setOption(string! key, value) -> void
	{
		let this->_options[key] = value;
	}

    /**
     * Executes the validation
     */
     abstract public function validate(<\Phalcon\Validation> validation, string! attribute) -> boolean;
}
