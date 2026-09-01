
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

class MultiLineString extends AbstractGeometry
{
    /**
     * @var array
     */
    protected lineStrings;

    public function __construct(array lineStrings, int srid = 0)
    {
        let this->lineStrings = lineStrings,
            this->srid = srid;
    }

    public function getType() -> int
    {
        return Column::TYPE_MULTILINESTRING;
    }

    public function getLineStrings() -> array
    {
        return this->lineStrings;
    }

    public function toWkt() -> string
    {
        var line, parts = [];

        for line in this->lineStrings {
            let parts[] = "(" . line->pointsWkt() . ")";
        }

        return "MULTILINESTRING(" . join(", ", parts) . ")";
    }
}
