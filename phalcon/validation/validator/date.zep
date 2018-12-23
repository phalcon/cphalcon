
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
 * Phalcon\Validation\Validator\Date
 *
 * Checks if a value is a valid date
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Date as DateValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "date",
 *     new DateValidator(
 *         [
 *             "format"  => "d-m-Y",
 *             "message" => "The date is invalid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "date",
 *         "anotherDate",
 *     ],
 *     new DateValidator(
 *         [
 *             "format" => [
 *                 "date"        => "d-m-Y",
 *                 "anotherDate" => "Y-m-d",
 *             ],
 *             "message" => [
 *                 "date"        => "The date is invalid",
 *                 "anotherDate" => "The another date is invalid",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class Date extends Validator
{
	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, var field) -> bool
	{
		var value, format, label, message, replacePairs, code;

		let value = validation->getValue(field);
		let format = this->getOption("format");

		if typeof format == "array" {
			let format = format[field];
		}

		if empty format {
			let format = "Y-m-d";
		}

		if !this->checkDate(value, format) {
			let label = this->prepareLabel(validation, field),
				message = this->prepareMessage(validation, field, "Date"),
				code = this->prepareCode(field);

			let replacePairs = [":field": label];

			validation->appendMessage(
				new Message(
					strtr(message, replacePairs),
					field,
					"Date",
					code
				)
			);

			return false;
		}

		return true;
	}

	private function checkDate(value, format) -> bool
	{
		var date, errors;

		if !is_string(value) {
			return false;
		}

		let date = \DateTime::createFromFormat(format, value);
		let errors = \DateTime::getLastErrors();

		if errors["warning_count"] > 0 || errors["error_count"] > 0 {
			return false;
		}

		return true;
	}
}
