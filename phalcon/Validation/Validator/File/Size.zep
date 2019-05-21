
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
use Phalcon\Validation;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\File
 *
 * Checks if a value has a correct file
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Size;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Size(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max filesize (:max)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new FileValidator(
 *         [
 *             "maxSize" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "messageSize" => [
 *                 "file"        => "file exceeds the max filesize 2M",
 *                 "anotherFile" => "anotherFile exceeds the max filesize 4M",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class Size extends Validator
{
    protected advice = "Field :field must contain only letters";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value, label, replacePairs, code;

        let value = validation->getValue(field);

        if preg_match("/[^[:alpha:]]/imu", value) {
            let label = this->prepareLabel(validation, field),
                code = this->prepareCode(field);

            let replacePairs = [
                ":field": label
            ];

            validation->appendMessage(
                new Message(
                    strtr(this->getAdvice(field), replacePairs),
                    field,
                    get_class(this),
                    code
                )
            );

            return false;
        }

        return true;
    }
}
