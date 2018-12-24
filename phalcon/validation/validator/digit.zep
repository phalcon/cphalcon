
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
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Digit
 *
 * Check for numeric character(s)
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Digit as DigitValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "height",
 *     new DigitValidator(
 *         [
 *             "message" => ":field must be numeric",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "height",
 *         "width",
 *     ],
 *     new DigitValidator(
 *         [
 *             "message" => [
 *                 "height" => "height must be numeric",
 *                 "width"  => "width must be numeric",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class Digit extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, var field) -> bool
	{
		var value, message, label, replacePairs, code;

		let value = validation->getValue(field);

		if is_int(value) || ctype_digit(value) {
			return true;
		}

		let label = this->prepareLabel(validation, field),
			message = this->prepareMessage(validation, field, "Digit"),
			code = this->prepareCode(field);

		let replacePairs = [":field": label];

		validation->appendMessage(
			new Message(
				strtr(message, replacePairs),
				field,
				"Digit",
				code
			)
		);

		return false;
	}
}
