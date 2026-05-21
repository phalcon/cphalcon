
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class ExtensionNotLoaded extends Exception
{
    public function __construct(string extension)
    {
        parent::__construct(extension . " is not installed, or the extension is not loaded");
    }
}
