
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

class InvalidColor extends Exception
{
    public function __construct(string color)
    {
        parent::__construct(
            "The color '" . color . "' is not a valid hex color"
        );
    }
}
