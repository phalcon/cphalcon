
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Link\Serializer;

use Phalcon\Contracts\Html\Link\LinkTypes;

/**
 * Class Phalcon\Http\Link\Serializer\SerializerInterface
 *
 * @phpstan-import-type link_collection from LinkTypes
 */
interface SerializerInterface
{
    /**
     * Serializer method
     *
     * @phpstan-param link_collection $links
     */
    public function serialize(array links) -> string | null;
}
