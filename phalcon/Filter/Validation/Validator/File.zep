
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator;

use Phalcon\Contracts\Filter\FilterTypes;
use Phalcon\Messages\Message;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractValidatorComposite;
use Phalcon\Filter\Validation\Validator\File\MimeType;
use Phalcon\Filter\Validation\Validator\File\Resolution\AspectRatio;
use Phalcon\Filter\Validation\Validator\File\Resolution\Equal as EqualResolution;
use Phalcon\Filter\Validation\Validator\File\Resolution\Max as MaxResolution;
use Phalcon\Filter\Validation\Validator\File\Resolution\Min as MinResolution;
use Phalcon\Filter\Validation\Validator\File\Size\Equal as EqualFileSize;
use Phalcon\Filter\Validation\Validator\File\Size\Max as MaxFileSize;
use Phalcon\Filter\Validation\Validator\File\Size\Min as MinFileSize;
use Phalcon\Traits\Support\Helper\Arr\GetTrait;

/**
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File as FileValidator;
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
 *             "messageFileEmpty"     => "File is empty",
 *             "messageIniSize"       => "Ini size is not valid",
 *             "messageValid"         => "File is not valid",
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
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
class File extends AbstractValidatorComposite
{
    use GetTrait;

    /**
     * Constructor
     *
     * @phpstan-param filter_validator_options $options
     */
    public function __construct( array options = [])
    {
        var key, value,
            allowWildcards   = false,
            included         = null,
            message          = null,
            messageFileEmpty = null,
            messageIniSize   = null,
            messageValid     = null,
            validator        = null;

        if isset options["messageFileEmpty"] {
            let messageFileEmpty  = this->getArrVal(options, "messageFileEmpty");
            unset options["messageFileEmpty"];
        }

        if isset options["messageIniSize"] {
            let messageIniSize  = this->getArrVal(options, "messageIniSize");
            unset options["messageIniSize"];
        }

        if isset options["messageValid"] {
            let messageValid  = this->getArrVal(options, "messageValid");
            unset options["messageValid"];
        }

        if isset options["allowWildcards"] {
            let allowWildcards = (bool) this->getArrVal(options, "allowWildcards");
            unset options["allowWildcards"];
        }

        // create individual validators
        for key, value in options {
            // min file size
            if strcasecmp(key, "minSize") === 0 {
                let message  = this->getArrVal(options, "messageMinSize"),
                    included = this->getArrVal(options, "includedMinSize");

                let validator = new MinFileSize(
                    [
                        "size"     : value,
                        "message"  : message,
                        "included" : included
                    ]
                );

                unset options["minSize"];
                unset options["messageMinSize"];
                unset options["includedMinSize"];
            }

            // max file size
            elseif strcasecmp(key, "maxSize") === 0 {
                let message  = this->getArrVal(options, "messageSize"),
                    included = this->getArrVal(options, "includedSize");

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
                let message = this->getArrVal(options, "messageEqualSize");

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
                let message = this->getArrVal(options, "messageType");

                let validator = new MimeType(
                    [
                        "types"          : value,
                        "message"        : message,
                        "allowWildcards" : allowWildcards
                    ]
                );

                unset options["allowedTypes"];
                unset options["messageType"];
            }

            // max resolution
            elseif strcasecmp(key, "maxResolution") === 0 {
                let message  = this->getArrVal(options, "messageMaxResolution"),
                    included = this->getArrVal(options, "includedMaxResolution");

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
                let message  = this->getArrVal(options, "messageMinResolution"),
                    included = this->getArrVal(options, "includedMinResolution");

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
                let message = this->getArrVal(options, "messageEqualResolution");

                let validator = new EqualResolution(
                    [
                        "resolution" : value,
                        "message"    : message
                    ]
                );

                unset options["equalResolution"];
                unset options["messageEqualResolution"];
            }

            // aspect ratio
            elseif strcasecmp(key, "aspectRatio") === 0 {
                let message = this->getArrVal(options, "messageAspectRatio");

                let validator = new AspectRatio(
                    [
                        "ratio"   : value,
                        "message" : message
                    ]
                );

                unset options["aspectRatio"];
                unset options["messageAspectRatio"];
            } else {
                continue;
            }

            if messageFileEmpty !== null {
                validator->setMessageFileEmpty(messageFileEmpty);
            }

            if messageIniSize !== null {
                validator->setMessageIniSize(messageIniSize);
            }

            if messageValid !== null {
                validator->setMessageValid(messageValid);
            }

            let this->validators[] = validator;
        }

        parent::__construct(options);
    }
}
