
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\File\Resolution;

use Phalcon\Contracts\Filter\FilterTypes;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\File\AbstractFile;
use Phalcon\Messages\Message;

/**
 * Checks if a file has the right resolution
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\Resolution\Equal;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Equal(
 *         [
 *             "resolution" => "800x600",
 *             "message"    => "The resolution of the field :field has to be equal :resolution",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Equal(
 *         [
 *             "resolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "message" => [
 *                 "file"        => "Equal resolution of file has to be 800x600",
 *                 "anotherFile" => "Equal resolution of file has to be 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 * @phpstan-import-type filter_uploaded_file from FilterTypes
 */
class Equal extends AbstractFile
{
    /**
     * @var string|null
     */
    protected template = "The resolution of the field :field has to be equal :resolution";

    /**
     * Constructor
     *
     * @phpstan-param filter_validator_options $options
     */
    public function __construct(array options = [])
    {
        parent::__construct(options);
    }

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var height, equalHeight, equalWidth, resolution, resolutionArray,
            tmp, value, width, replacePairs;

        // Check file upload
        if this->checkUpload(validation, field) === false {
            return false;
        }

        let value = validation->getValue(field),
            tmp   = getimagesize(value["tmp_name"]);

        // The file cannot be read as an image
        if (false === tmp) {
            this->appendMessageValid(validation, field);

            return false;
        }

        let width  = tmp[0],
            height = tmp[1];

        let resolution = this->getOption("resolution");

        if typeof resolution == "array" {
            let resolution = resolution[field];
        }

        let resolutionArray = explode("x", resolution),
            equalWidth = resolutionArray[0],
            equalHeight = resolutionArray[1];

       if width != equalWidth || height != equalHeight {
            let replacePairs = [
                ":resolution" : resolution
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }
}
