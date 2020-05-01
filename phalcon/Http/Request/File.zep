
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request;

use Phalcon\Helper\Arr;

/**
 * Phalcon\Http\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *```php
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
 *         }
 *     }
 * }
 *```
 */
class File implements FileInterface
{
    /**
     * @var string|null
     */
    protected error { get };

    /**
     * @var string
     */
    protected extension { get };

    /**
     * @var string|null
     */
    protected key { get };

    protected name;

    protected realType;

    protected size;

    protected tmp;

    protected type;

    /**
     * Phalcon\Http\Request\File constructor
     */
    public function __construct(array! file, key = null)
    {
        var name;

        if fetch name, file["name"] {
            let this->name = name;

            if defined("PATHINFO_EXTENSION") {
                let this->extension = pathinfo(name, PATHINFO_EXTENSION);
            }
        }

        let this->tmp   = Arr::get(file, "tmp_name"),
            this->size  = Arr::get(file, "size"),
            this->type  = Arr::get(file, "type"),
            this->error = Arr::get(file, "error");

        if key {
            let this->key = key;
        }
    }

    /**
     * Returns the real name of the uploaded file
     */
    public function getName() -> string
    {
        return this->name;
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
     * Returns the file size of the uploaded file
     */
    public function getSize() -> int
    {
        return this->size;
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
