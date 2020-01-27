
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Asset;

use Phalcon\Assets\Asset as AssetBase;

/**
 * Represents JavaScript assets
 */
class Js extends AssetBase
{
    /**
     * Phalcon\Assets\Asset\Js constructor
     */
    public function __construct(
        string! path,
        bool local = true,
        bool filter = true,
        array attributes = [],
        string version = null,
        bool autoVersion = false
    )
    {
        parent::__construct("js", path, local, filter, attributes, version, autoVersion);
    }
}
