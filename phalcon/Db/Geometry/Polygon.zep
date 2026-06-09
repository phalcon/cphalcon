
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Geometry;

use Phalcon\Db\Column;

class Polygon extends AbstractGeometry
{
    /**
     * @var array
     */
    protected rings;

    public function __construct(array rings, int srid = 0)
    {
        let this->rings = rings,
            this->srid = srid;
    }

    public function getType() -> int
    {
        return Column::TYPE_POLYGON;
    }

    public function getRings() -> array
    {
        return this->rings;
    }

    public function toWkt() -> string
    {
        return "POLYGON(" . this->ringsWkt() . ")";
    }

    public function ringsWkt() -> string
    {
        var ring, point, ringParts, parts = [];

        for ring in this->rings {
            let ringParts = [];

            for point in ring {
                let ringParts[] = point->coordsWkt();
            }

            let parts[] = "(" . join(", ", ringParts) . ")";
        }

        return join(", ", parts);
    }
}
