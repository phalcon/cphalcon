
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
 * Phalcon\Validation\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 *<code>
 *use Phalcon\Validation\Validator\Regex as RegexValidator;
 *
 *$validator->add('created_at', new RegexValidator(array(
 *   'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/',
 *   'message' => 'The creation date is invalid'
 *)));
 *</code>
 */
class Regex extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, string! field) -> boolean
	{
		var matches, failed, message, value, label, replacePairs;

		/**
		 * Regular expression is set in the option 'pattern'
		 * Check if the value match using preg_match in the PHP userland
		 */
		let matches = null;
		let value = validation->getValue(field);

		if this->isSetOption("allowEmpty") && empty value {
			return true;
		}

		if preg_match(this->getOption("pattern"), value, matches) {
			let failed = matches[0] != value;
		} else {
			let failed = true;
		}

		if failed === true {

			let label = this->getOption("label");
			if empty label {
				let label = validation->getLabel(field);
			}

			let message = this->getOption("message");
			let replacePairs = [":field": label];
			if empty message {
				let message = validation->getDefaultMessage("Regex");
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "Regex"));
			return false;
		}

		return true;
	}

}
