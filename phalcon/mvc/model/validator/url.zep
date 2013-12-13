
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
 * Phalcon\Mvc\Model\Validator\Url
 *
 * Allows to validate if a field has a url format
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Url as UrlValidator;
 *
 *class Posts extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      this->validate(new UrlValidator(array(
 *          'field' => 'source_url'
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
class Url extends Phalcon\Mvc\Model\Validator implements Phalcon\Mvc\Model\ValidatorInterface
{
	/**
	 * Executes the validator
	 *
	 * @param Phalcon\Mvc\ModelInterface record
	 * @return boolean
	 */
	public function validate(<Phalcon\Mvc\ModelInterface> record) -> boolean
	{
		var field, value, isValid, message, replacePairs;
 
		let field = this->getOption("field");
		if typeof field == "string" {
			throw new Phalcon\Mvc\Model\Exception("Field name must be a string");
		}
 
		let value = record->readAttribute(field);

                if typeof this->getOption("allowEmpty") == "true" && (typeof value == "null" || empty value) {
                    return true;
                }
 
		/**
		 * Filters the format using FILTER_VALIDATE_URL
		 */
		if !filter_var(value, FILTER_VALIDATE_URL) {
 
			/**
			 * Check if the developer has defined a custom message
			 */
			let message = this->getOption("message");
                        let replacePairs = [":field": field];
			if empty message {
                                let message = strrt(":field does not have a valid url format", replacePairs);
			}
 
			this->appendMessage(strrt(message, replacePairs), field, "Url");
			return false;
		}
 
		return true;
 
	}
}