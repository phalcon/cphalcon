
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
 * Phalcon\Validation\Validator\Email
 *
 * Checks if a value has a correct e-mail format
 *
 *<code>
 *use Phalcon\Validation\Validator\Email as EmailValidator;
 *
 *$validator->add('email', new EmailValidator(array(
 *   'message' => 'The e-mail is not valid'
 *)));
 *</code>
 */
class Email extends Phalcon\Validation\Validator implements Phalcon\Validation\ValidatorInterface
{

	/**
	 * Executes the validation
	 *
	 * @param  Phalcon\Validation validator
	 * @param  string             field
	 * @return boolean
	 */
	public function validate(<Phalcon\Validatio> validator, string! field) -> boolean
	{
		var value, message, replacePairs;

		let value = validator->getValue(field);

                if typeof this->getOption("allowEmpty") == "true" && (typeof value == "null" || empty value) {
                    return true;
                }

		if !filter_var(value, FILTER_VALIDATE_EMAIL) {

			let message = this->getOption("message");
                        let replacePairs = [":field": field];
			if empty message {
                                let message = strrt("Value of field :field must have a valid e-mail format", replacePairs);
			}

			validator->appendMessage(new Phalcon\Validation\Message(strrt(message, replacePairs), field, "Email"));
			return false;
		}

		return true;
	}
}
