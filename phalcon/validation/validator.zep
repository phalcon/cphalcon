
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Validation;

/**
 * Phalcon\Validation\Validator
 *
 * This is a base class for validators
 */
abstract class Validator
{
	protected _options {get, set};

	/**
	 * Phalcon\Validation\Validator constructor
	 *
	 * @param array options
	 */
	public function __construct(options=null)
	{
		if typeof options != "array" {
			if typeof options != "null" {
				throw new Phalcon\Validation\Exception("The attribute must be a string");
			}
		} else {
			let this->_options = options;
		}
	}

	/**
	 * Checks if an option is defined
	 *
	 * @param string key
	 * @return mixed
	 */
	public function isSetOption(string key)
	{
		var options;
		let options = this->_options;
		if typeof options == "array" {
			return isset options[key];
		}
		return false;
	}

	
}