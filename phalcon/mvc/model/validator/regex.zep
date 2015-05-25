
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

use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Validator;
use Phalcon\Mvc\Model\ValidatorInterface;
use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Regex as RegexValidator;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new RegexValidator(array(
 *          "field" => 'created_at',
 *          'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])/'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 */
class Regex extends Validator implements ValidatorInterface
{
	/**
	 * Executes the validator
	 */
	public function validate(<ModelInterface> record) -> boolean
	{
		var field, value, failed, matches, pattern, message;

		let field = this->getOption("field");
		if typeof field != "string" {
			throw new Exception("Field name must be a string");
		}

		/**
		 * The 'pattern' option must be a valid regular expression
		 */
		if !this->isSetOption("pattern") {
			throw new Exception("Validator requires a perl-compatible regex pattern");
		}

		let value = record->readAttribute(field);
		if this->isSetOption("allowEmpty") && empty value {
			return true;
		}

		/**
		 * The regular expression is set in the option 'pattern'
		 */
		let pattern = this->getOption("pattern");

		/**
		 * Check if the value match using preg_match in the PHP userland
		 */
		let failed = false;
		let matches = null;
		if preg_match(pattern, value, matches) {
			let failed = matches[0] != value;
		} else {
			let failed = true;
		}

		if failed === true {

			/**
			 * Check if the developer has defined a custom message
			 */
			let message = this->getOption("message");
			if empty message {
				let message = "Value of field ':field' doesn't match regular expression";
			}

			this->appendMessage(strtr(message, [":field": field]), field, "Regex");
			return false;
		}

		return true;
	}
}
