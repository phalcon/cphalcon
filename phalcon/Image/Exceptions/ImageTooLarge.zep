
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class ImageTooLarge extends Exception
{
    public function __construct(int pixels, int maxPixels)
    {
        parent::__construct(
            "Image size " . pixels . " pixels exceeds the maximum allowed "
            . maxPixels . " pixels"
        );
    }
}
