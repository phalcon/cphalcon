
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

class AssetSourceTargetCollision extends Exception
{
    public function __construct(string path)
    {
        parent::__construct(
            "Asset '" . path . "' has the same source and target paths"
        );
    }
}
