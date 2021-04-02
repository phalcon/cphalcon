
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Helper\Arr;
use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\AbstractValidatorComposite;
use Phalcon\Validation\Validator\File\MimeType;
use Phalcon\Validation\Validator\File\Resolution\Equal as EqualResolution;
use Phalcon\Validation\Validator\File\Resolution\Max as MaxResolution;
use Phalcon\Validation\Validator\File\Resolution\Min as MinResolution;
use Phalcon\Validation\Validator\File\Size\Equal as EqualFileSize;
use Phalcon\Validation\Validator\File\Size\Max as MaxFileSize;
use Phalcon\Validation\Validator\File\Size\Min as MinFileSize;

/**
 * Checks if a value has a correct file
 *
 * ```php
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
 *             "messageSize"          => ":field exceeds the max file size (:size)",
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
 *                 "file"        => "file exceeds the max file size 2M",
 *                 "anotherFile" => "anotherFile exceeds the max file size 4M",
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
 * ```
 */
class File extends AbstractValidatorComposite
{
    /**
     * Constructor
     *
     * @param array options = [
     *     'messageMinSize' => '',
     *     'includedMinSize' => false,
     *     'minSize' => 100,
     *     'maxSize' => 1000,
     *     'messageSize' => '',
     *     'includedSize' => false,
     *     'equalSize' => '',
     *     'messageEqualSize' => '',
     *     'allowedTypes' => [],
     *     'messageType' => '',
     *     'maxResolution' => '1000x1000',
     *     'messageMaxResolution' => '',
     *     'includedMaxResolution' => false,
     *     'minResolution => '500x500',
     *     'includedMinResolution' => false,
     *     'messageMinResolution' => '',
     *     'equalResolution' => '1000x1000',
     *     'messageEqualResolution' => '',
     *     'allowEmpty' => false
     * ]
     */
    public function __construct(array! options = [])
    {
        var included = null, key, message = null, validator, value;

        // create individual validators
        for key, value in options {
            // min file size
            if strcasecmp(key, "minSize") === 0 {
                let message  = Arr::get(options, "messageMinSize"),
                    included = Arr::get(options, "includedMinSize");

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

            // max file size
            elseif strcasecmp(key, "maxSize") === 0 {
                let message  = Arr::get(options, "messageSize"),
                    included = Arr::get(options, "includedSize");

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

            // equal file size
            elseif strcasecmp(key, "equalSize") === 0 {
                let message = Arr::get(options, "messageEqualSize");

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
            elseif strcasecmp(key, "allowedTypes") === 0 {
                let message = Arr::get(options, "messageType");

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
            elseif strcasecmp(key, "maxResolution") === 0 {
                let message  = Arr::get(options, "messageMaxResolution"),
                    included = Arr::get(options, "includedMaxResolution");

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
            elseif strcasecmp(key, "minResolution") === 0 {
                let message  = Arr::get(options, "messageMinResolution"),
                    included = Arr::get(options, "includedMinResolution");

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
            elseif strcasecmp(key, "equalResolution") === 0 {
                let message = Arr::get(options, "messageEqualResolution");

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
