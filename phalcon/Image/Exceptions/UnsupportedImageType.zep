
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class UnsupportedImageType extends Exception
{
    public function __construct(string format = "")
    {
        var message;

        if empty(format) {
            let message = "Installed GD does not support such images";
        } else {
            let message = "Installed GD does not support " . format . " images";
        }

        parent::__construct(message);
    }
}
