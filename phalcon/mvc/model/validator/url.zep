
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\Mvc\EntityInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Validator;

/**
 * Phalcon\Mvc\Model\Validator\Url
 *
 * Allows to validate if a field has a url format
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\Url as UrlValidator;
 *
 * class Posts extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new UrlValidator(
 *                 [
 *                     "field" => "source_url",
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() === true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 * @deprecated 3.1.0
 * @see Phalcon\Validation\Validator\Url
 */
class Url extends Validator
{
	/**
	 * Executes the validator
	 */
	public function validate(<EntityInterface> record) -> boolean
	{
		var field, value, message;

		let field = this->getOption("field");
		if typeof field != "string" {
			throw new Exception("Field name must be a string");
		}

		let value = record->readAttribute(field);
		if this->isSetOption("allowEmpty") && empty value {
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
			if empty message {
				let message = ":field does not have a valid url format";
			}

			this->appendMessage(strtr(message, [":field": field]), field, "Url");
			return false;
		}

		return true;
	}
}
