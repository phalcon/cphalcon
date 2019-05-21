
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
use Phalcon\Validation\Validator\StringLength\Max;
use Phalcon\Validation\Validator\StringLength\Min;
use Phalcon\Validation\Exception;

/**
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
 * The test is passed if for a string's length L, min<=L<=max, i.e. L must
 * be at least min, and at most max.
 * Since Phalcon v4.0 this valitor works like a container
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\StringLength as StringLength;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new StringLength(
 *         [
 *             "max"            => 50,
 *             "min"            => 2,
 *             "messageMaximum" => "We don't like really long names",
 *             "messageMinimum" => "We want more than just their initials",
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new StringLength(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "min" => [
 *                 "name_last"  => 2,
 *                 "name_first" => 4,
 *             ],
 *             "messageMaximum" => [
 *                 "name_last"  => "We don't like really long last names",
 *                 "name_first" => "We don't like really long first names",
 *             ],
 *             "messageMinimum" => [
 *                 "name_last"  => "We don't like too short last names",
 *                 "name_first" => "We don't like too short first names",
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
class StringLength extends Validator
{
    private validators = [];

    public function __construct(array! options = []) -> void
    {
        var key, value, message, validator;

        // create individual validators
        for key, value in options {
            if strtolower(key) === "min" {
                // get custom message
                if isset options["message"] {
                    let message = options["message"];
                } elseif isset options["messageMinimum"] {
                    let message = options["messageMinimum"];
                }

                let validator = new Min(
                    [
                        "min" : value,
                        "message" : message
                    ]
                );

                unset options["min"];
                unset options["message"];
                unset options["messageMinimum"];
            } elseif strtolower(key) === "max" {
                // get custom message
                if isset options["message"] {
                    let message = options["message"];
                } elseif isset options["messageMaximum"] {
                    let message = options["messageMaximum"];
                }

                let validator = new Max(
                    [
                        "max" : value,
                        "message" : message
                    ]
                );

                unset options["max"];
                unset options["message"];
                unset options["messageMaximum"];
            } else {
                continue;
            }

            let this->validators[] = validator;
        }

        parent::__construct(options);
    }

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var validator;

        if unlikely count(this->validators) === 0 {
            throw new Exception("A minimum or maximum must be set");
        }

        for validator in this->validators {
            if validator->validate(validation, field) === false {
                return false;
            }
        }

        return true;
    }
}
