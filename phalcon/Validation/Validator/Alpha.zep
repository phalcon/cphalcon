
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
 * Check for alphabetic character(s)
 *
 * ```php
 * use Phalcon\Validation\Validation;
 * use Phalcon\Validation\Validator\Alpha as AlphaValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "username",
 *     new AlphaValidator(
 *         [
 *             "message" => ":field must contain only letters",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "username",
 *         "name",
 *     ],
 *     new AlphaValidator(
 *         [
 *             "message" => [
 *                 "username" => "username must contain only letters",
 *                 "name"     => "name must contain only letters",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Alpha extends AbstractValidator
{
    protected template = "Field :field must contain only letters";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value;

        let value = validation->getValue(field);

        if preg_match("/[^[:alpha:]]/imu", value) {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }
}
