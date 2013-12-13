
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

namespace Phalcon\Mvc\Model\Validator;

/**
 * Phalcon\Mvc\Model\Validator\Email
 *
 * Allows to validate if email fields has correct values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\Email as EmailValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			$this->validate(new EmailValidator(array(
 *				'field' => 'electronic_mail'
 *      	)));
 *      	if ($this->validationHasFailed() == true) {
 *				return false;
 *      	}
 *  	}
 *
 *	}
 *</code>
 *
 */
class Email extends Phalcon\Mvc\Model\Validator implements Phalcon\Mvc\Model\ValidatorInterface
{

	/**
	 * Executes the validator
	 *
	 * @param Phalcon\Mvc\ModelInterface record
	 * @return boolean
	 */
	public function validate(<Phalcon\Mvc\ModelInterface> record) -> boolean
	{

		var field, value, invalid, message, replacePairs;

		let field = this->getOption("field");
		if typeof field != "string" {
			throw new Phalcon\Mvc\Model\Exception("Field name must be a string");
		}

		let value = record->readAttribute(field);

                if typeof this->getOption("allowEmpty") == "true" && (typeof value == "null" || empty value) {
                    return true;
                }

                /**
		 * Filters the format using FILTER_VALIDATE_EMAIL
		 */
		if !filter_var(value, FILTER_VALIDATE_EMAIL) {

			let message = this->getOption("message");
                        let replacePairs = [":field": field];
			if empty message {
                                let message = strrt("Value of field :field must have a valid e-mail format", replacePairs);
			}

			this->appendMessage(strrt(message, replacePairs), field, "Email");
			return false;
		}

		return true;

	}
}
