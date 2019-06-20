
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
use Phalcon\Validation\ValidatorComposite;
use Phalcon\Validation\Validator\File\MimeType;
use Phalcon\Validation\Validator\File\Resolution\Equal as EqualResolution;
use Phalcon\Validation\Validator\File\Resolution\Max as MaxResolution;
use Phalcon\Validation\Validator\File\Resolution\Min as MinResolution;
use Phalcon\Validation\Validator\File\Size\Equal as EqualFileSize;
use Phalcon\Validation\Validator\File\Size\Max as MaxFileSize;
use Phalcon\Validation\Validator\File\Size\Min as MinFileSize;

/**
 * Phalcon\Validation\Validator\File
 *
 * Checks if a value has a correct file
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File as FileValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new FileValidator(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max filesize (:size)",
 *             "allowedTypes"         => [
 *                 "image/jpeg",
 *                 "image/png",
 *             ],
 *             "messageType"          => "Allowed file types are :types",
 *             "maxResolution"        => "800x600",
 *             "messageMaxResolution" => "Max resolution of :field is :resolution",
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
 *             "allowedTypes" => [
 *                 "file"        => [
 *                     "image/jpeg",
 *                     "image/png",
 *                 ],
 *                 "anotherFile" => [
 *                     "image/gif",
 *                     "image/bmp",
 *                 ],
 *             ],
 *             "messageType" => [
 *                 "file"        => "Allowed file types are image/jpeg and image/png",
 *                 "anotherFile" => "Allowed file types are image/gif and image/bmp",
 *             ],
 *             "maxResolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "messageMaxResolution" => [
 *                 "file"        => "Max resolution of file is 800x600",
 *                 "anotherFile" => "Max resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class File extends ValidatorComposite
{
    private validators = [] {get};

    public function __construct(array! options = [])
    {
        var included, key, message, validator, value;

        // create individual validators
        for key, value in options {
            // min filesize
            if strtolower(key) === "minSize" {
                // get custom message
                if isset options["messageMinSize"] {
                    let message = options["messageMinSize"];
                }

                // get included option
                if isset options["includedMinSize"] {
                    let included = options["includedMinSize"];
                }

                let validator = new MinFileSize(
                    [
                        "size"     : value,
                        "message"  : message,
                        "included" : included
                    ]
                );

                unset options["messageMinSize"];
                unset options["includedMinSize"];
            }

            // max filesize
            elseif strtolower(key) === "maxSize" {
                // get custom message
                if isset options["messageSize"] {
                    let message = options["messageSize"];
                }

                // get included option
                if isset options["includedSize"] {
                    let included = options["includedSize"];
                }

                let validator = new MaxFileSize(
                    [
                        "size"      : value,
                        "message"  : message,
                        "included" : included
                    ]
                );

                unset options["maxSize"];
                unset options["messageSize"];
                unset options["includedSize"];
            }

            // equal filesize
            elseif strtolower(key) === "equalSize" {
                // get custom message
                if isset options["messageEqualSize"] {
                    let message = options["messageEqualSize"];
                }

                let validator = new EqualFileSize(
                    [
                        "size"    : value,
                        "message" : message
                    ]
                );

                unset options["equalSize"];
                unset options["messageEqualSize"];
            }

            // mime types
            elseif strtolower(key) === "allowedTypes" {
                if isset options["messageType"] {
                    let message = options["messageType"];
                }

                let validator = new MimeType(
                    [
                        "types"   : value,
                        "message" : message
                    ]
                );

                unset options["allowedTypes"];
                unset options["messageType"];
            }

            // max resolution
            elseif strtolower(key) === "maxResolution" {
                if isset options["messageMaxResolution"] {
                    let message = options["messageMaxResolution"];
                }

                // get included option
                if isset options["includedMaxResolution"] {
                    let included = options["includedMaxResolution"];
                }

                let validator = new MaxResolution(
                    [
                        "resolution" : value,
                        "included"   : included,
                        "message"    : message
                    ]
                );

                unset options["maxResolution"];
                unset options["includedMaxResolution"];
                unset options["messageMaxResolution"];
            }

            // min resolution
            elseif strtolower(key) === "minResolution" {
                if isset options["messageMinResolution"] {
                    let message = options["messageMinResolution"];
                }

                // get included option
                if isset options["includedMinResolution"] {
                    let included = options["includedMinResolution"];
                }

                let validator = new MinResolution(
                    [
                        "resolution" : value,
                        "included"   : included,
                        "message"    : message
                    ]
                );

                unset options["minResolution"];
                unset options["includedMinResolution"];
                unset options["messageMinResolution"];
            }

            // equal resolution
            elseif strtolower(key) === "equalResolution" {
                if isset options["messageEqualResolution"] {
                    let message = options["messageEqualResolution"];
                }

                let validator = new EqualResolution(
                    [
                        "resolution" : value,
                        "message"    : message
                    ]
                );

                unset options["equalResolution"];
                unset options["messageEqualResolution"];
            } else {
                continue;
            }

            let this->validators[] = validator;
        }

        parent::__construct(options);
    }
}
