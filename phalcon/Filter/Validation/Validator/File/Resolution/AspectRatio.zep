
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\File\Resolution;

use Phalcon\Contracts\Filter\FilterTypes;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\File\AbstractFile;

/**
 * Checks if a file has the exact aspect ratio
 *
 * The ratio is compared with integer cross-multiplication, so the image
 * dimensions must match the ratio exactly: 1920x1080 matches "16x9",
 * 1366x768 does not.
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\Resolution\AspectRatio;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new AspectRatio(
 *         [
 *             "ratio"   => "16x9",
 *             "message" => "The aspect ratio of the field :field has to be :ratio",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new AspectRatio(
 *         [
 *             "ratio" => [
 *                 "file"        => "16x9",
 *                 "anotherFile" => "4x3",
 *             ],
 *             "message" => [
 *                 "file"        => "Aspect ratio of file has to be 16x9",
 *                 "anotherFile" => "Aspect ratio of anotherFile has to be 4x3",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 * @phpstan-import-type filter_uploaded_file from FilterTypes
 */
class AspectRatio extends AbstractFile
{
    /**
     * @var string|null
     */
    protected template = "File :field does not have the exact aspect ratio of :ratio";

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
        var dimensions, height, ratio, ratioHeight, ratioWidth, replacePairs,
            size, width;

        let size = this->getUploadedImageSize(validation, field);

        if size === false {
            return false;
        }

        let width  = size[0],
            height = size[1];

        let dimensions  = this->getDimensionsOption(field, "ratio"),
            ratio       = dimensions[0],
            ratioWidth  = (int) dimensions[1],
            ratioHeight = (int) dimensions[2];

        if width * ratioHeight != height * ratioWidth {
            let replacePairs = [
                ":ratio" : ratio
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }
}
