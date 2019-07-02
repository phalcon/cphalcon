
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Validation\Validation;
use Phalcon\Validation\AbstractValidator;

/**
 * Validates that a value is not null or empty string
 *
 * ```php
 * use Phalcon\Validation\Validation;
 * use Phalcon\Validation\Validator\PresenceOf;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "name",
 *     new PresenceOf(
 *         [
 *             "message" => "The name is required",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "name",
 *         "email",
 *     ],
 *     new PresenceOf(
 *         [
 *             "message" => [
 *                 "name"  => "The name is required",
 *                 "email" => "The email is required",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class PresenceOf extends AbstractValidator
{
    protected template = "Field :field is required";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value = validation->getValue(field);

        if value === null || value === "" {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }
}
