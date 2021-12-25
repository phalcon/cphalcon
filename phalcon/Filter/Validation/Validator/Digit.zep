
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
 * Check for numeric character(s)
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Digit as DigitValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "height",
 *     new DigitValidator(
 *         [
 *             "message" => ":field must be numeric",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "height",
 *         "width",
 *     ],
 *     new DigitValidator(
 *         [
 *             "message" => [
 *                 "height" => "height must be numeric",
 *                 "width"  => "width must be numeric",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Digit extends AbstractValidator
{
    protected template = "Field :field must be numeric";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'allowEmpty' => false
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
        var value = validation->getValue(field);
        if this->allowEmpty(field, value) {
            return true;
        }

        if is_int(value) || ctype_digit(value) {
            return true;
        }

        validation->appendMessage(
            this->messageFactory(validation, field)
        );

        return false;
    }
}
