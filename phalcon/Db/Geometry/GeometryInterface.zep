
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Geometry;

interface GeometryInterface
{
    public function getSrid() -> int;

    public function getType() -> int;

    public function toWkt() -> string;
}
