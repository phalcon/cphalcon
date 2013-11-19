
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

		let fieldName = this->getOption("field");
		if typeof fieldName != "string" {
			throw new Phalcon\Mvc\Model\Exception("Field name must be a string");
		}

		let value = record->readAttribute(fieldName);

		/**
		 * We check if the email has a valid format using a regular expression
		 */
		let regs = null;
		if preg_match("/^[a-zA-Z0-9\-_\.\+]+@[a-zA-Z0-9_\-]+(\.[a-zA-Z0-9_\-]+)*/", value, regs) {
			let invalid = regs[0] != value;
		} else {
			let invalid = true;
		}

		if invalid === true {

			/**
			 * Check if the developer has defined a custom message
			 */
			let message = this->getOption("message");
			if message {
				let message = "Value of field '" . fieldName . "' must have a valid e-mail format";
			}

			this->appendMessage(message, fieldName, "Email");
			return false;
		}

		return true;

	}
}
