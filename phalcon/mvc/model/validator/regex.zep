
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
 * Phalcon\Mvc\Model\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Regex as RegexValidator;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      this->validate(new RegexValidator(array(
 *          "field" => 'created_at',
 *          'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])/'
 *      )));
 *      if (this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 *
 */
class Regex extends Phalcon\Mvc\Model\Validator implements Phalcon\Mvc\Model\ValidatorInterface
{
	/**
	 * Executes the validator
	 *
	 * @param Phalcon\Mvc\ModelInterface record
	 * @return boolean
	 */
	public function validate(<Phalcon\Mvc\ModelInterface> record) -> boolean
	{
 		var field, visSet, value, failed, matches, pattern, matchPattern, matchZero, message, replacePairs;

		let field = this->getOption("field");
		if typeof field != "string" {
			throw new Phalcon\Mvc\Model\Exception("Field name must be a string");
		}
 
		/**
		 * The 'pattern' option must be a valid regular expression
		 */
		let visSet = this->isSetOption("pattern");
		if !visSet {
			throw new Phalcon\Mvc\Model\Exception("Validator requires a perl-compatible regex pattern");
		}
 
		let value = record->readAttribute(field);
 		let failed = false;
 		let matches = null;

                if this->isSetOption("notRequired") && (typeof value == "null" || value === '') {
                    return true;
                }
		
		/**
		 * The regular expression is set in the option 'pattern'
		 */
		let pattern = this->getOption("pattern");
 
		/**
		 * Check if the value match using preg_match in the PHP userland
		 */
		let matchPattern = preg_match(pattern, value, matches);
		if matchPattern {
			let matchZero = matches[0];
			let failed = (matchZero != value);
		} else {
			let failed = true;
		}
 
		if failed===true {
 
			/**
			 * Check if the developer has defined a custom message
			 */
			let message = this->getOption("message");
                        let replacePairs = [":field": field];
			if empty message {
                                let message = strrt("Value of field :field doesn't match regular expression", replacePairs);
			}
 
			this->appendMessage(strrt(message, replacePairs), field, "Regex");
			return false;
		}
 
		return true;
 
	}
}