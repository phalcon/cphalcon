
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Validation\Validator\ExclusionIn
 *
 * Check if a value is not included into a list of values
 *
 *<code>
 *use Phalcon\Validation\Validator\ExclusionIn;
 *
 *$validator->add('status', new ExclusionIn(array(
 *   'message' => 'The status must not be A or B',
 *   'domain' => array('A', 'B')
 *)));
 *</code>
 */
class ExclusionIn extends Phalcon\Validation\Validator implements Phalcon\Validation\ValidatorInterface
{

	/**
	 * Executes the validation
	 *
	 * @param Phalcon\Validation validation
	 * @param string field
	 * @return boolean
	 */
	public function validate(<Phalcon\Validation> validation, string! field) -> boolean
	{
		var value, domain, message, replacePairs;

		let value = validation->getValue(field);

                if this->isSetOption("allowEmpty") && (typeof value == "null" || empty value) {
                    return true;
                }

		/**
		 * A domain is an array with a list of valid values
		 */
		let domain = this->getOption("domain");
		if typeof domain != "array" {
			throw new Phalcon\Validation\Exception("Option 'domain' must be an array");
		}

		/**
		 * Check if the value is contained by the array
		 */
		if in_array(value, domain) {

			let message = this->getOption("message");
                        let replacePairs = [":field": field, ":domain":  join(", ", domain)];
			if empty message {
                                let message = "Value of field :field must not be part of list: :domain";
			}

			validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "ExclusionIn"));
			return false;
		}

		return true;
	}

}
