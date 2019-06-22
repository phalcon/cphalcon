
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator\File\Resolution;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\Validator\File\FileAbstract;

/**
 * Phalcon\Validation\Validator\File\Resolution\Max
 *
 * Checks if a file has the rigth resolution
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Resolution\Max;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Max(
 *         [
 *             "resolution"      => "800x600",
 *             "message"  => "Max resolution of :field is :resolution",
 *             "included" => true,
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Max(
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
 *                 "file"        => "Max resolution of file is 800x600",
 *                 "anotherFile" => "Max resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Max extends FileAbstract
{
    protected template = "File :field exceeds the maximum resolution of :resolution";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var height, maxHeight, maxWidth, resolution, resolutionArray,
            tmp, value, width, replacePairs, included = false, result;

        // Check file upload
        if (this->checkUpload(validation, field) === false) {
            return false;
        }

        let tmp = getimagesize(value["tmp_name"]),
            width = tmp[0],
            height = tmp[1],
            value = validation->getValue(field);

        let resolution = this->getOption("resolution");

        if typeof resolution == "array" {
            let resolution = resolution[field];
        }

        let resolutionArray = explode("x", resolution),
            maxWidth = resolutionArray[0],
            maxHeight = resolutionArray[1];

        let included = this->getOption("included");

        if typeof included == "array" {
            let included = (bool) included[field];
        } else {
            let included = (bool) included;
        }

        if (included) {
            let result = width >= maxWidth || height >= maxHeight;
        } else {
            let result = width > maxWidth || height > maxHeight;
        }

        if typeof resolution == "array" {
            let resolution = resolution[field];
        }

        if (result) {
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
