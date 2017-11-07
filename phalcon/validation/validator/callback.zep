
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

namespace Phalcon\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Callback
 *
 * Calls user function for validation
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Callback as CallbackValidator;
 * use Phalcon\Validation\Validator\Numericality as NumericalityValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     ["user", "admin"],
 *     new CallbackValidator(
 *         [
 *             "message" => "There must be only an user or admin set",
 *             "callback" => function($data) {
 *                 if (!empty($data->getUser()) && !empty($data->getAdmin())) {
 *                     return false;
 *                 }
 *
 *                 return true;
 *             }
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     "amount",
 *     new CallbackValidator(
 *         [
 *             "callback" => function($data) {
 *                 if (!empty($data->getProduct())) {
 *                     return new NumericalityValidator(
 *                         [
 *                             "message" => "Amount must be a number."
 *                         ]
 *                     );
 *                 }
 *             }
 *         ]
 *     )
 * );
 * </code>
 */
class Callback extends Validator
{
	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, string! field) -> boolean
	{
		var message, label, replacePairs, code, callback, returnedValue, data;

		let callback = this->getOption("callback");

		if is_callable(callback) {
			let data = validation->getEntity();
			if empty data {
				let data = validation->getData();
			}
			let returnedValue = call_user_func(callback, data);
			if typeof returnedValue == "boolean" {
				if !returnedValue {
					let label = this->prepareLabel(validation, field),
						message = this->prepareMessage(validation, field, "Callback"),
						code = this->prepareCode(field);

					let replacePairs = [":field": label];

					validation->appendMessage(
						new Message(
							strtr(message, replacePairs),
							field,
							"Callback",
							code
						)
					);

					return false;
				}

				return true;
			}
			elseif typeof returnedValue == "object" && returnedValue instanceof Validator {
				return returnedValue->validate(validation, field);
			}
			throw new Exception("Callback must return boolean or Phalcon\\Validation\\Validator object");
		}

		return true;
	}
}
