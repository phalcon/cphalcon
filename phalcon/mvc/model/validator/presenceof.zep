
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
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Validator;
use Phalcon\Mvc\Model\ValidatorInterface;

/**
 * Phalcon\Mvc\Model\Validator\PresenceOf
 *
 * Allows to validate if a filed have a value different of null and empty string ("")
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\PresenceOf;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new PresenceOf(array(
 *          "field" => 'name',
 *          "message" => 'The name is required'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 */
class PresenceOf extends Validator implements ValidatorInterface
{
	/**
	 * Executes the validator
	 */
	public function validate(<ModelInterface> record) -> boolean
	{
		var field, value, message;

		let field = this->getOption("field");
		if typeof field != "string" {
			throw new Exception("Field name must be a string");
		}

		/**
		 * A value is null when it is identical to null or a empty string
		 */
		let value = record->readAttribute(field);
		if is_null(value) || (is_string(value) && !strlen(value)) {

			/**
			 * Check if the developer has defined a custom message
			 */
			let message = this->getOption("message");
			if empty message {
				let message = "':field' is required";
			}

			this->appendMessage(strtr(message, [":field": field]), field, "PresenceOf");
			return false;
		}

		return true;
	}
}
