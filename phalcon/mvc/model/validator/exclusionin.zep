
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

namespace Phalcon\Mvc\Model\Validator;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Validator;
use Phalcon\Mvc\Model\ValidatorInterface;
use Phalcon\Mvc\Model\Exception;

/**
 * Phalcon\Mvc\Model\Validator\ExclusionIn
 *
 * Check if a value is not included into a list of values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionInValidator;
 *
 *	class Subscriptors extends \Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			$this->validate(new ExclusionInValidator(array(
 *				'field' => 'status',
 *				'domain' => array('A', 'I')
 *			)));
 *			if ($this->validationHasFailed() == true) {
 *				return false;
 *			}
 *		}
 *
 *	}
 *</code>
 */
class Exclusionin extends Validator implements ValidatorInterface
{

	/**
	 * Executes the validator
	 */
	public function validate(<ModelInterface> record) -> boolean
	{
		var field, domain, value, message;

		let field = this->getOption("field");

		if typeof field != "string" {
			throw new Exception("Field name must be a string");
		}

		/**
		 * The "domain" option must be a valid array of not allowed values
		 */
		if this->isSetOption("domain") === false {
			throw new Exception("The option 'domain' is required by this validator");
		}

		let domain = this->getOption("domain");
		if typeof domain != "array" {
			throw new Exception("Option 'domain' must be an array");
		}

		let value = record->readAttribute(field);
		if this->isSetOption("allowEmpty") && empty value {
			return true;
		}

		/**
		 * We check if the value contained into the array
		 */
		if in_array(value, domain) {

			/**
			 * Check if the developer has defined a custom message
			 */
			let message = this->getOption("message");
			if empty message {
				let message = "Value of field ':field' must not be part of list: :domain";
			}

			this->appendMessage(strtr(message, [":field": field, ":domain":  join(", ", domain)]), field, "Exclusion");
			return false;
		}

		return true;
	}
}
