
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\ValidatorInterface;
use Phalcon\Validation\AbstractValidator;

/**
 * Calls user function for validation
 *
 * ```php
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
 * ```
 */
class Callback extends AbstractValidator
{
    protected template = "Field :field must match the callback function";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var callback, returnedValue, data;

        let callback = this->getOption("callback");

        if is_callable(callback) {
            let data = validation->getEntity();

            if empty data {
                let data = validation->getData();
            }

            let returnedValue = call_user_func(callback, data);

            if typeof returnedValue == "boolean" {
                if !returnedValue {
                    validation->appendMessage(
                        this->messageFactory(validation, field)
                    );

                    return false;
                }

                return true;
            } elseif typeof returnedValue == "object" && returnedValue instanceof ValidatorInterface {
                return returnedValue->validate(validation, field);
            }

            throw new Exception(
                "Callback must return bool or Phalcon\\Validation\\Validator object"
            );
        }

        return true;
    }
}
