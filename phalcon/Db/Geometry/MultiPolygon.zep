
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

class MultiPolygon extends AbstractGeometry
{
    /**
     * @var array
     */
    protected polygons;

    public function __construct(array polygons, int srid = 0)
    {
        let this->polygons = polygons,
            this->srid = srid;
    }

    public function getType() -> int
    {
        return Column::TYPE_MULTIPOLYGON;
    }

    public function getPolygons() -> array
    {
        return this->polygons;
    }

    public function toWkt() -> string
    {
        var polygon, parts = [];

        for polygon in this->polygons {
            let parts[] = "(" . polygon->ringsWkt() . ")";
        }

        return "MULTIPOLYGON(" . join(", ", parts) . ")";
    }
}
