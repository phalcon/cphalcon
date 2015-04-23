
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

use Phalcon\Validation\Validator;
use Phalcon\Validation\Exception;
use Phalcon\Validation\Message;

/**
 * Phalcon\Validation\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 *<code>
 *use Phalcon\Validation\Validator\InclusionIn;
 *
 *$validator->add('status', new InclusionIn(array(
 *   'message' => 'The status must be A or B',
 *   'domain' => array('A', 'B')
 *)));
 *</code>
 */
class InclusionIn extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<\Phalcon\Validation> validation, string! field) -> boolean
	{
		var value, domain, message, label, replacePairs, strict;

		let value = validation->getValue(field);

		if this->isSetOption("allowEmpty") && empty value {
			return true;
		}

		/**
		 * A domain is an array with a list of valid values
		 */
		let domain = this->getOption("domain");
		if typeof domain != "array" {
			throw new Exception("Option 'domain' must be an array");
		}
		
		let strict = false;
		if this->isSetOption("strict") {
			if typeof strict != "boolean" {
			    throw new Exception("Option 'strict' must be a boolean");
			}
			
			let strict = this->getOption("strict");
		}

		/**
		 * Check if the value is contained by the array
		 */
		if !in_array(value, domain, strict) {

			let label = this->getOption("label");
			if empty label {
				let label = validation->getLabel(field);
			}

			let message = this->getOption("message");
			let replacePairs = [":field": label, ":domain":  join(", ", domain)];
			if empty message {
				let message = validation->getDefaultMessage("InclusionIn");
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "InclusionIn"));
			return false;
		}

		return true;
	}
}
