
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request;

/**
 * Phalcon\Http\Request\FileInterface
 *
 * Interface for Phalcon\Http\Request\File
 *
 */
interface FileInterface
{
    /**
     * Returns the error if any
     */
    public function getError() -> string | null;

    /**
     * Returns the real name of the uploaded file
     */
    public function getName() -> string;

    /**
     * Gets the real mime type of the upload file using finfo
     */
    public function getRealType() -> string;

    /**
     * Returns the file size of the uploaded file
     */
    public function getSize() -> int;

    /**
     * Returns the temporal name of the uploaded file
     */
    public function getTempName() -> string;

    /**
     * Returns the mime type reported by the browser
     * This mime type is not completely secure, use getRealType() instead
     */
    public function getType() -> string;

    /**
     * Move the temporary file to a destination
     */
    public function moveTo(string! destination) -> bool;
}
