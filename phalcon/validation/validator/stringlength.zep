
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

namespace Phalcon\Validation\Validator;

use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
 * The test is passed if for a string's length L, min<=L<=max, i.e. L must
 * be at least min, and at most max.
 *
 *<code>
 *use Phalcon\Validation\Validator\StringLength as StringLength;
 *
 *$validation->add('name_last', new StringLength(array(
 *      'max' => 50,
 *      'min' => 2,
 *      'messageMaximum' => 'We don\'t like really long names',
 *      'messageMinimum' => 'We want more than just their initials'
 *)));
 *</code>
 *
 */
class StringLength extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<\Phalcon\Validation> validation, string! field) -> boolean
	{
		var isSetMin, isSetMax, value, length, message, minimum, maximum, label, replacePairs;

		/**
		 * At least one of 'min' or 'max' must be set
		 */
		let isSetMin = this->isSetOption("min"),
			isSetMax = this->isSetOption("max");

		if !isSetMin && !isSetMax {
			throw new \Phalcon\Validation\Exception("A minimum or maximum must be set");
		}

		let value = validation->getValue(field);

		if this->isSetOption("allowEmpty") && empty value {
			return true;
		}

		let label = this->getOption("label");
		if empty label {
			let label = validation->getLabel(field);
		}

		/**
		 * Check if mbstring is available to calculate the correct length
		 */
		if function_exists("mb_strlen") {
			let length = mb_strlen(value);
		} else {
			let length = strlen(value);
		}

		/**
		 * Maximum length
		 */
		if isSetMax {

			let maximum = this->getOption("max");
			if length > maximum {

				/**
				 * Check if the developer has defined a custom message
				 */
				let message = this->getOption("messageMaximum");
								let replacePairs = [":field": label, ":max":  maximum];
				if empty message {
					let message = validation->getDefaultMessage("TooLong");
				}

				validation->appendMessage(new \Phalcon\Validation\Message(strtr(message, replacePairs), field, "TooLong"));
				return false;
			}
		}

		/**
		 * Minimum length
		 */
		if isSetMin {

			let minimum = this->getOption("min");
			if length < minimum {

				/**
				 * Check if the developer has defined a custom message
				 */
				let message = this->getOption("messageMinimum");
				let replacePairs = [":field": label, ":min":  minimum];
				if empty message {
					let message = validation->getDefaultMessage("TooShort");
				}

				validation->appendMessage(new \Phalcon\Validation\Message(strtr(message, replacePairs), field, "TooShort"));
				return false;
			}
		}

		return true;
	}

}
