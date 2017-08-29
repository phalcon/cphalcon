
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

namespace Phalcon\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\Exception;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Confirmation
 *
 * Checks that two values have the same value
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Confirmation;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "password",
 *     new Confirmation(
 *         [
 *             "message" => "Password doesn't match confirmation",
 *             "with"    => "confirmPassword",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "password",
 *         "email",
 *     ],
 *     new Confirmation(
 *         [
 *             "message" => [
 *                 "password" => "Password doesn't match confirmation",
 *                 "email"    => "Email doesn't match confirmation",
 *             ],
 *             "with" => [
 *                 "password" => "confirmPassword",
 *                 "email"    => "confirmEmail",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class Confirmation extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, string! field) -> boolean
	{
		var fieldWith, value, valueWith, message, label, labelWith, replacePairs, code;

		let fieldWith = this->getOption("with");

		if typeof fieldWith == "array" {
			let fieldWith = fieldWith[field];
		}

		let value = validation->getValue(field),
			valueWith = validation->getValue(fieldWith);

		if !this->compare(value, valueWith) {
			let label = this->prepareLabel(validation, field),
				message = this->prepareMessage(validation, field, "Confirmation"),
				code = this->prepareCode(field);

			let labelWith = this->getOption("labelWith");
			if typeof labelWith == "array" {
				let labelWith = labelWith[fieldWith];
			}
			if empty labelWith {
				let labelWith = validation->getLabel(fieldWith);
			}

			let replacePairs = [":field": label, ":with":  labelWith];

			validation->appendMessage(
				new Message(
					strtr(message, replacePairs),
					field,
					"Confirmation",
					code
				)
			);

			return false;
		}

		return true;
	}

	/**
	 * Compare strings
	 */
	protected final function compare(string a, string b) -> boolean
	{
		if this->getOption("ignoreCase", false) {

			/**
			 * mbstring is required here
			 */
			if !function_exists("mb_strtolower") {
				throw new Exception("Extension 'mbstring' is required");
			}

			let a = mb_strtolower(a, "utf-8");
			let b = mb_strtolower(b, "utf-8");
		}

		return a == b;
	}
}
