
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
 * Phalcon\Validation\Validator\CreditCard
 *
 * Checks if a value has a valid credit card number
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\CreditCard as CreditCardValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "creditCard",
 *     new CreditCardValidator(
 *         [
 *             "message" => "The credit card number is not valid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "creditCard",
 *         "secondCreditCard",
 *     ],
 *     new CreditCardValidator(
 *         [
 *             "message" => [
 *                 "creditCard"       => "The credit card number is not valid",
 *                 "secondCreditCard" => "The second credit card number is not valid",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class CreditCard extends Validator
{
	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, var field) -> bool
	{
		var message, label, replacePairs, value, valid, code;

		let value = validation->getValue(field);

		let valid = this->verifyByLuhnAlgorithm(value);

		if !valid {
			let label = this->prepareLabel(validation, field),
				message = this->prepareMessage(validation, field, "CreditCard"),
				code = this->prepareCode(field);

			let replacePairs = [":field": label];

			validation->appendMessage(
				new Message(
					strtr(message, replacePairs),
					field,
					"CreditCard",
					code
				)
			);

			return false;
		}

		return true;
	}

	/**
	 * is a simple checksum formula used to validate a variety of identification numbers
	 */
	private function verifyByLuhnAlgorithm(string number) -> bool
	{
		array digits;
		let digits = (array) str_split(number);

		var digit, position, hash = "";

		for position, digit in digits->reversed() {
			let hash .= (position % 2 ? digit * 2 : digit);
		}

		var result;
		let result = array_sum(str_split(hash));

		return (result % 10 == 0);
	}
}
