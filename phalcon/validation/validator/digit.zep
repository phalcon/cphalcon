
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

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Digit
 *
 * Check for numeric character(s)
 *
 *<code>
 *use Phalcon\Validation\Validator\Digit as DigitValidator;
 *
 *$validator->add('height', new DigitValidator(array(
 *   'message' => ':field must be numeric'
 *)));
 *</code>
 */
class Digit extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, string! field) -> boolean
	{
		var value, message, label, replacePairs;

		let value = validation->getValue(field);

		if this->isSetOption("allowEmpty") && empty value {
			return true;
		}

		if !ctype_digit(value) {

			let label = this->getOption("label");
			if empty label {
				let label = validation->getLabel(field);
			}

			let message = this->getOption("message");
			let replacePairs = [":field": label];
			if empty message {
				let message = validation->getDefaultMessage("Digit");
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "Digit"));
			return false;
		}

		return true;
	}
}
