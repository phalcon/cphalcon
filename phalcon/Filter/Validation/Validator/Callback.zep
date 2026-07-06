
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractValidator;
use Phalcon\Filter\Validation\Exceptions\InvalidCallbackReturn;
use Phalcon\Filter\Validation\ValidatorInterface;
use Phalcon\Messages\Message;

/**
 * Calls user function for validation
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Callback as CallbackValidator;
 * use Phalcon\Filter\Validation\Validator\Numericality as NumericalityValidator;
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
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'callback' => null
     * ]
     */
    public function __construct( array options = [])
    {
        parent::__construct(options);
    }

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var callback, returnedValue, data, savedTemplate, savedChanged, savedTemplates;

        let callback = this->getOption("callback");

        if is_callable(callback) {
            let data = validation->getEntity();

            if empty data {
                let data = validation->getData();
            }

            /**
             * Snapshot the message state so a setTemplate()/setTemplates()
             * call inside the bound closure cannot leak into later
             * validations that reuse this validator instance. Restored below
             * once the failure message (if any) has been built.
             */
            let savedTemplate  = this->template,
                savedChanged   = this->templateChanged,
                savedTemplates = this->templates;

            if callback instanceof \Closure {
                let callback = \Closure::bind(callback, this);
            }

            let returnedValue = call_user_func(callback, data);

            if typeof returnedValue == "boolean" && !returnedValue {
                validation->appendMessage(
                    this->messageFactory(validation, field)
                );
            }

            let this->template        = savedTemplate,
                this->templateChanged = savedChanged,
                this->templates       = savedTemplates;

            if typeof returnedValue == "boolean" {
                return returnedValue;
            }

            if typeof returnedValue == "object" && returnedValue instanceof ValidatorInterface {
                return returnedValue->validate(validation, field);
            }

            throw new InvalidCallbackReturn();
        }

        return true;
    }
}
