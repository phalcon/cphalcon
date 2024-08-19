
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractValidator;

/**
 * Checks if a value has a correct e-mail format
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Email as EmailValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "email",
 *     new EmailValidator(
 *         [
 *             "message" => "The e-mail is not valid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "email",
 *         "anotherEmail",
 *     ],
 *     new EmailValidator(
 *         [
 *             "message" => [
 *                 "email"        => "The e-mail is not valid",
 *                 "anotherEmail" => "The another e-mail is not valid",
 *             ],
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     "täst@example.com",
 *     new EmailValidator(
 *         [
 *             "message" => "The e-mail is not valid",
 *             "allowUTF8" => true,
 *         ]
 *     )
 * );
 * ```
 */
class Email extends AbstractValidator
{
    protected template = "Field :field must be an email address";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'allowEmpty' => false,
     *     'allowUTF8' => false,
     * ]
     */
    public function __construct(array! options = [])
    {
        parent::__construct(options);
    }

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value, flags;

        let value = validation->getValue(field);
        if this->allowEmpty(field, value) {
            return true;
        }

        let flags = FILTER_DEFAULT;
        if (this->getOption("allowUTF8")) {
            let flags = FILTER_FLAG_EMAIL_UNICODE;
        }

        if !filter_var(value, FILTER_VALIDATE_EMAIL, flags) {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }
}
