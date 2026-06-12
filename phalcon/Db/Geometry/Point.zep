
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

class Point extends AbstractGeometry
{
    /**
     * @var float
     */
    protected x;
    /**
     * @var float
     */
    protected y;

    public function __construct(float x, float y, int srid = 0)
    {
        let this->x = x,
            this->y = y,
            this->srid = srid;
    }

    public function getType() -> int
    {
        return Column::TYPE_POINT;
    }

    public function getX() -> float
    {
        return this->x;
    }

    public function getY() -> float
    {
        return this->y;
    }

    public function toWkt() -> string
    {
        return "POINT(" . this->coordsWkt() . ")";
    }

    public function coordsWkt() -> string
    {
        return this->x . " " . this->y;
    }
}
