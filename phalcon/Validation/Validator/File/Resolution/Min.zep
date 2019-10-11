
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator\File\Resolution;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\Validator\File\AbstractFile;

/**
 * Checks if a file has the rigth resolution
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Resolution\Min;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Min(
 *         [
 *             "resolution" => "800x600",
 *             "message"    => "Min resolution of :field is :resolution",
 *             "included"   => true,
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Min(
 *         [
 *             "resolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "Min resolution of file is 800x600",
 *                 "anotherFile" => "Min resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Min extends AbstractFile
{
    protected template = "File :field can not have the minimum resolution of :resolution";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'resolution' => '1000x1000',
     *     'included' => false
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
        var height, minHeight, minWidth, resolution, resolutionArray,
            tmp, value, width, replacePairs, included = false, result;

        // Check file upload
        if this->checkUpload(validation, field) === false {
            return false;
        }

        let value  = validation->getValue(field),
            tmp    = getimagesize(value["tmp_name"]),
            width  = tmp[0],
            height = tmp[1];

        let resolution = this->getOption("resolution");

        if typeof resolution == "array" {
            let resolution = resolution[field];
        }

        let resolutionArray = explode("x", resolution),
            minWidth = resolutionArray[0],
            minHeight = resolutionArray[1];

        let included = this->getOption("included");

        if typeof included == "array" {
            let included = (bool) included[field];
        } else {
            let included = (bool) included;
        }

        if included {
            let result = width <= minWidth || height <= minHeight;
        } else {
            let result = width < minWidth || height < minHeight;
        }

        if typeof resolution == "array" {
            let resolution = resolution[field];
        }

        if result {
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
