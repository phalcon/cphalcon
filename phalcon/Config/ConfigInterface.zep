
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config;

use Phalcon\Collection\CollectionInterface;

/**
 * Phalcon\Config\ConfigInterface
 *
 * Interface for Phalcon\Config class
 */
interface ConfigInterface extends CollectionInterface
{
    public function getPathDelimiter() -> string;

    public function merge(var toMerge) -> <ConfigInterface>;

    public function path(string path, defaultValue = null, var delimiter = null) -> var | null;

    public function setPathDelimiter(string delimiter = null) -> <ConfigInterface>;
}
