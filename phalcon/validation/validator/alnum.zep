
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
use Phalcon\Validation\Validator;
use Phalcon\Validation\Message;

/**
 * Phalcon\Validation\Validator\Alnum
 *
 * Check for alphanumeric character(s)
 *
 * <code>
 * use Phalcon\Validation\Validator\Alnum as AlnumValidator;
 *
 * $validator->add('username', new AlnumValidator([
 *     'message' => ':field must contain only alphanumeric characters'
 * ]));
 *
 * $validator->add(['username', 'name'], new AlnumValidator([
 *     'message' => [
 *         'username' => 'username must contain only alphanumeric characters',
 *         'name' => 'name must contain only alphanumeric characters'
 *     ]
 * ]));
 * </code>
 */
class Alnum extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, string! field) -> boolean
	{
		var value, message, label, replacePairs, code;

		let value = validation->getValue(field);

		if !ctype_alnum(value) {

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
				let message = validation->getDefaultMessage("Alnum");
			}

			let code = this->getOption("code");

			if typeof code == "array" {
				let code = code[field];
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "Alnum", code));
			return false;
		}

		return true;
	}
}
