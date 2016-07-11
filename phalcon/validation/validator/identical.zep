
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)       |
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

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Identical
 *
 * Checks if a value is identical to other
 *
 * <code>
 * use Phalcon\Validation\Validator\Identical;
 *
 * $validator->add('terms', new Identical([
 *     'accepted' => 'yes',
 *     'message' => 'Terms and conditions must be accepted'
 * ]));
 *
 * $validator->add(['terms', 'anotherTerms'], new Identical([
 *     'accepted' => [
 *         'terms' => 'yes',
 *         'anotherTerms' => 'yes'
 *     ],
 *     'message' => [
 *         'terms' => 'Terms and conditions must be accepted',
 *         'anotherTerms' => 'Another terms  must be accepted'
 *     ]
 * ]));
 * </code>
 *
 */
class Identical extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, string! field) -> boolean
	{
		var message, label, replacePairs, value, valid, accepted, valueOption, code;

		let value = validation->getValue(field);

		if this->hasOption("accepted") {
			let accepted = this->getOption("accepted");
			if typeof accepted == "array" {
				let accepted = accepted[field];
			}
			let valid = value == accepted;
		} else {
			if this->hasOption("value") {
				let valueOption = this->getOption("value");
				if typeof valueOption == "array" {
					let valueOption = valueOption[field];
				}
				let valid = value == valueOption;
			}
		}

		if !valid {

			let label = this->getOption("label");
			if typeof label == "array" {
				let label = label[field];
			}
			if empty label {
				let label = validation->getLabel(field);
			}

			let message = this->getOption("message");
			if typeof message == "array" {
				let message = message[field];
			}
			let replacePairs = [":field": label];
			if empty message {
				let message = validation->getDefaultMessage("Identical");
			}

			let code = this->getOption("code");
			if typeof code == "array" {
				let code = code[field];
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "Identical", code));
			return false;
		}

		return true;
	}
}
