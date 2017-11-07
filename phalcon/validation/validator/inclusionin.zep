
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
use Phalcon\Validation\Validator;
use Phalcon\Validation\Exception;
use Phalcon\Validation\Message;

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
	public function validate(<Validation> validation, string! field) -> boolean
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
			    throw new Exception("Option 'strict' must be a boolean");
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
