
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
 * Phalcon\Validation\Validator\PresenceOf
 *
 * Validates that a value is not null or empty string
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\PresenceOf;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "name",
 *     new PresenceOf(
 *         [
 *             "message" => "The name is required",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "name",
 *         "email",
 *     ],
 *     new PresenceOf(
 *         [
 *             "message" => [
 *                 "name"  => "The name is required",
 *                 "email" => "The email is required",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class PresenceOf extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, var field) -> bool
	{
		var value, message, label, replacePairs, code;

		let value = validation->getValue(field);
		if value === null || value === "" {
			let label = this->prepareLabel(validation, field),
				message = this->prepareMessage(validation, field, "PresenceOf"),
				code = this->prepareCode(field);

			let replacePairs = [":field": label];

			validation->appendMessage(
				new Message(
					strtr(message, replacePairs),
					field,
					"PresenceOf",
					code
				)
			);

			return false;
		}

		return true;
	}
}
