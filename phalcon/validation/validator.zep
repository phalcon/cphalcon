
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * Checks if an option is defined
	 */
	public function hasOption(string! key) -> bool
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
	abstract public function validate(<Validation> validation, var field) -> bool;

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
