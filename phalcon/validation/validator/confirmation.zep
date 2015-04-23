
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

use Phalcon\Validation\Exception;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Confirmation
 *
 * Checks that two values have the same value
 *
 *<code>
 *use Phalcon\Validation\Validator\Confirmation;
 *
 *$validator->add('password', new Confirmation(array(
 *   'message' => 'Password doesn\'t match confirmation',
 *   'with' => 'confirmPassword'
 *)));
 *</code>
 */
class Confirmation extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<\Phalcon\Validation> validation, string! field) -> boolean
	{
		var fieldWith, value, valueWith, message, label, labelWith, replacePairs;

		let fieldWith = this->getOption("with"),
			value = validation->getValue(field),
			valueWith = validation->getValue(fieldWith);

		if !this->compare(value, valueWith) {

			let label = this->getOption("label");
			if empty label {
				let label = validation->getLabel(field);
			}

			let labelWith = this->getOption("labelWith");
			if empty labelWith {
				let labelWith = validation->getLabel(fieldWith);
			}

			let message = this->getOption("message");
			let replacePairs = [":field": label, ":with":  labelWith];
			if empty message {
				let message = validation->getDefaultMessage("Confirmation");
			}

			validation->appendMessage(new \Phalcon\Validation\Message(strtr(message, replacePairs), field, "Confirmation"));
			return false;
		}

		return true;
	}

	/**
	 * Compare strings
	 */
	protected function compare(string a, string b) -> boolean
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
