
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

class GeometryCollection extends AbstractGeometry
{
    /**
     * @var array
     */
    protected geometries;

    public function __construct(array geometries, int srid = 0)
    {
        let this->geometries = geometries,
            this->srid = srid;
    }

    public function getType() -> int
    {
        return Column::TYPE_GEOMETRYCOLLECTION;
    }

    public function getGeometries() -> array
    {
        return this->geometries;
    }

    public function toWkt() -> string
    {
        var geometry, parts = [];

        for geometry in this->geometries {
            let parts[] = geometry->toWkt();
        }

        return "GEOMETRYCOLLECTION(" . join(", ", parts) . ")";
    }
}
