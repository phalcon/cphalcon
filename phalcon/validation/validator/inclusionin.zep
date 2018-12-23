
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
use Phalcon\Validation\Exception;

/**
 * Phalcon\Validation\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\InclusionIn;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "status",
 *     new InclusionIn(
 *         [
 *             "message" => "The status must be A or B",
 *             "domain"  => ["A", "B"],
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "status",
 *         "type",
 *     ],
 *     new InclusionIn(
 *         [
 *             "message" => [
 *                 "status" => "The status must be A or B",
 *                 "type"   => "The status must be 1 or 2",
 *             ],
 *             "domain" => [
 *                 "status" => ["A", "B"],
 *                 "type"   => [1, 2],
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
class InclusionIn extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, var field) -> bool
	{
		var value, domain, message, label, replacePairs, strict, fieldDomain, code;

		let value = validation->getValue(field);

		/**
		 * A domain is an array with a list of valid values
		 */
		let domain = this->getOption("domain");
		if fetch fieldDomain, domain[field] {
			if typeof fieldDomain == "array" {
				let domain = fieldDomain;
			}
		}
		if typeof domain != "array" {
			throw new Exception("Option 'domain' must be an array");
		}

		let strict = false;
		if this->hasOption("strict") {
			let strict = this->getOption("strict");

			if typeof strict == "array" {
				let strict = strict[field];
			}

			if typeof strict != "boolean" {
			    throw new Exception("Option 'strict' must be a bool");
			}
		}

		/**
		 * Check if the value is contained by the array
		 */
		if !in_array(value, domain, strict) {
			let label = this->prepareLabel(validation, field),
				message = this->prepareMessage(validation, field, "InclusionIn"),
				code = this->prepareCode(field);

			let replacePairs = [":field": label, ":domain":  join(", ", domain)];

			validation->appendMessage(
				new Message(
					strtr(message, replacePairs),
					field,
					"InclusionIn",
					code
				)
			);

			return false;
		}

		return true;
	}
}
