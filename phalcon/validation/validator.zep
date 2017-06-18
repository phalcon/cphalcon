/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Validation;

use Phalcon\Validation;
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
	public function __construct(array! options = null)
	{
		let this->_options = options;
	}

	/**
	 * Checks if an option has been defined

	 * @deprecated since 2.1.0
	 * @see \Phalcon\Validation\Validator::hasOption()
	 */
	deprecated public function isSetOption(string! key) -> boolean
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
		var options, value, fieldValue;
		let options = this->_options;

		if typeof options == "array" {
			if fetch value, options[key] {
				/*
				 * If we have attribute it means it's Uniqueness validator, we
				 * can have here multiple fields, so we need to check it
				 */
				if key == "attribute" && typeof value == "array" {
					if fetch fieldValue, value[key] {
						return fieldValue;
					}
				}
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
	abstract public function validate(<Validation> validation, string! attribute) -> boolean;

	/**
	 * Prepares a label for the field.
	 */
	protected function prepareLabel(<Validation> validation, string! field) -> var
	{
		var label;

		let label = this->getOption("label");
		if typeof label == "array" {
			let label = label[field];
		}

		if empty label {
			let label = validation->getLabel(field);
		}

		return label;
	}

	/**
	 * Prepares a validation message.
	 */
	protected function prepareMessage(<Validation> validation, string! field, string! type, string! option = "message") -> var
	{
		var message;

		let message = this->getOption(option);
		if typeof message == "array" {
			let message = message[field];
		}

		if empty message {
			let message = validation->getDefaultMessage(type);
		}

		return message;
	}

	/**
	 * Prepares a validation code.
	 */
	protected function prepareCode(string! field) -> int | null
	{
		var code;

		let code = this->getOption("code");
		if typeof code == "array" {
			let code = code[field];
		}

		return code;
	}
}
