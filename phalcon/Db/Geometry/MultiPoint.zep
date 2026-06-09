
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

class MultiPoint extends AbstractGeometry
{
    /**
     * @var array
     */
    protected points;

    public function __construct(array points, int srid = 0)
    {
        let this->points = points,
            this->srid = srid;
    }

    public function getType() -> int
    {
        return Column::TYPE_MULTIPOINT;
    }

    public function getPoints() -> array
    {
        return this->points;
    }

    public function toWkt() -> string
    {
        var point, parts = [];

        for point in this->points {
            let parts[] = point->coordsWkt();
        }

        return "MULTIPOINT(" . join(", ", parts) . ")";
    }
}
