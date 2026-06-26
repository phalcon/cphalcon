
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Exceptions;

use Phalcon\Assets\Exception;

class InvalidTargetPath extends Exception
{
    public function __construct(string path)
    {
        parent::__construct(
            "Path '" . path . "' is not a valid target path"
        );
    }
}
