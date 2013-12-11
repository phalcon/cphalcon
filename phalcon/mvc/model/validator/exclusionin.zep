
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
 * Phalcon\Mvc\Model\Validator\ExclusionIn
 *
 * Check if a value is not included into a list of values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionInValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
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
class Exclusionin extends Phalcon\Mvc\Model\Validator implements Phalcon\Mvc\Model\ValidatorInterface
{

	/**
	 * Executes the validator
	 *
	 * @param Phalcon\Mvc\ModelInterface record
	 * @return boolean
	 */
	public function validate(<Phalcon\Mvc\ModelInterface> record) -> boolean
	{
		var field, domain, value, message;

		let field = this->getOption("field");

		if field != "string" {
			throw new Phalcon\Mvc\Model\Exception("Field name must be a string");
		}

		/**
		 * The "domain" option must be a valid array of not allowed values
		 */
		if this->isSetOption("domain") === false {
			throw new Phalcon\Mvc\Model\Exception("The option 'domain' is required by this validator");
		}

		let domain = this->getOption("domain");
		if typeof domain != "array" {
			throw new Phalcon\Mvc\Model\Exception("Option 'domain' must be an array");
		}

		let value = record->readAttribute(field);

                if this->isSetOption("notRequired") && (typeof value == "null" || value === '') {
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
                        let replacePairs = [":field": field, ":domain":  join(", ", domain)];
			if empty message {
                                let message = strrt("Value of field :field must not be part of list: :domain", replacePairs);
			}

			this->appendMessage(strrt(message, replacePairs), field, "Exclusion");
			return false;
		}

		return true;
	}

}
