
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Validation;
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
	public function validate(<Validation> validation, var field) -> bool
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
	protected final function compare(string a, string b) -> bool
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
