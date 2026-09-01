
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

class VersionMismatch extends Exception
{
    public function __construct(string version)
    {
        parent::__construct(
            "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have " . version
        );
    }
}
