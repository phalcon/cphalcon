
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
use Phalcon\Filter\Validation\AbstractValidator;
use Phalcon\Filter\Validation\AbstractValidatorComposite;
use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Filter\Validation\Exception;

/**
 * Validates that a string has the specified maximum and minimum constraints
 * The test is passed if for a string's length L, min<=L<=max, i.e. L must
 * be at least min, and at most max.
 * Since Phalcon v4.0 this validator works like a container
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\StringLength as StringLength;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new StringLength(
 *         [
 *             "max"             => 50,
 *             "min"             => 2,
 *             "messageMaximum"  => "We don't like really long names",
 *             "messageMinimum"  => "We want more than just their initials",
 *             "includedMaximum" => true,
 *             "includedMinimum" => false,
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
 *             ],
 *             "includedMaximum" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ],
 *             "includedMinimum" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
class StringLength extends AbstractValidatorComposite
{
    /**
     * Constructor
     *
     * @param array options = [
     *     'min' => 100,
     *     'message' => '',
     *     'messageMinimum' => '',
     *     'included' => '',
     *     'includedMinimum' => false,
     *     'max' => 1000,
     *     'messageMaximum' => '',
     *     'includedMaximum' => false
     * ]
     */
    public function __construct(array! options = [])
    {
        var included = null, key, message = null, validator, value;

        // create individual validators
        for key, value in options {
            if strcasecmp(key, "min") === 0 {
                // get custom message
                if isset options["message"] {
                    let message = options["message"];
                } elseif isset options["messageMinimum"] {
                    let message = options["messageMinimum"];
                }

                // get included option
                if isset options["included"] {
                    let included = options["included"];
                } elseif isset options["includedMinimum"] {
                    let included = options["includedMinimum"];
                }

                let validator = new Min(
                    [
                        "min" : value,
                        "message" : message,
                        "included" : included
                    ]
                );

                unset options["min"];
                unset options["message"];
                unset options["messageMinimum"];
                unset options["included"];
                unset options["includedMinimum"];
            } elseif strcasecmp(key, "max") === 0 {
                // get custom message
                if isset options["message"] {
                    let message = options["message"];
                } elseif isset options["messageMaximum"] {
                    let message = options["messageMaximum"];
                }

                // get included option
                if isset options["included"] {
                    let included = options["included"];
                } elseif isset options["includedMaximum"] {
                    let included = options["includedMaximum"];
                }

                let validator = new Max(
                    [
                        "max" : value,
                        "message" : message,
                        "included" : included
                    ]
                );

                unset options["max"];
                unset options["message"];
                unset options["messageMaximum"];
                unset options["included"];
                unset options["includedMaximum"];
            } else {
                continue;
            }

            let this->validators[] = validator;
        }

        parent::__construct(options);
    }
}
