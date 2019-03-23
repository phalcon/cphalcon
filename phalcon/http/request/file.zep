
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request;

use Phalcon\Http\Request\FileInterface;

/**
 * Phalcon\Http\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *<code>
 * use Phalcon\Mvc\Controller;
 *
 * class PostsController extends Controller
 * {
 *     public function uploadAction()
 *     {
 *         // Check if the user has uploaded files
 *         if ($this->request->hasFiles() == true) {
 *             // Print the real file names and their sizes
 *             foreach ($this->request->getUploadedFiles() as $file) {
 *                 echo $file->getName(), " ", $file->getSize(), "\n";
 *             }
 *           }
 *     }
 * }
 *</code>
 */
class File implements FileInterface
{

    protected name;

    protected tmp;

    protected size;

    protected type;

    protected realType;

    /**
     * @var string|null
     */
    protected _error { get };

    /**
     * @var string|null
     */
    protected _key { get };

    /**
     * @var string
     */
    protected _extension { get };

    /**
     * Phalcon\Http\Request\File constructor
     */
    public function __construct(array! file, key = null)
    {
        var name, tempName, size, type, error;

        if fetch name, file["name"] {
            let this->name = name;

            if defined("PATHINFO_EXTENSION") {
                let this->_extension = pathinfo(name, PATHINFO_EXTENSION);
            }
        }

        if fetch tempName, file["tmpname"] {
            let this->tmp = tempName;
        }

        if fetch size, file["size"] {
            let this->size = size;
        }

        if fetch type, file["type"] {
            let this->type = type;
        }

        if fetch error, file["error"] {
            let this->_error = error;
        }

        if key {
            let this->_key = key;
        }
    }

    /**
     * Returns the file size of the uploaded file
     */
    public function getSize() -> int
    {
        return this->size;
    }

    /**
     * Returns the real name of the uploaded file
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Returns the temporary name of the uploaded file
     */
    public function getTempName() -> string
    {
        return this->tmp;
    }

    /**
     * Returns the mime type reported by the browser
     * This mime type is not completely secure, use getRealType() instead
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Gets the real mime type of the upload file using finfo
     */
    public function getRealType() -> string
    {
        var finfo, mime;

        let finfo = finfo_open(FILEINFO_MIME_TYPE);
        if typeof finfo != "resource" {
            return "";
        }

        let mime = finfo_file(finfo, this->tmp);
        finfo_close(finfo);

        return mime;
    }

    /**
     * Checks whether the file has been uploaded via Post.
     */
    public function isUploadedFile() -> bool
    {
        var tmp;

        let tmp = this->getTempName();
        return typeof tmp == "string" && is_uploaded_file(tmp);
    }

    /**
     * Moves the temporary file to a destination within the application
     */
    public function moveTo(string! destination) -> bool
    {
        return move_uploaded_file(this->tmp, destination);
    }
}
