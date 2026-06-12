<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Db\Geometry;

use Phalcon\Db\Column;
use Phalcon\Db\Geometry\GeometryCollection;
use Phalcon\Db\Geometry\LineString;
use Phalcon\Db\Geometry\Point;
use Phalcon\Db\Geometry\Polygon;
use Phalcon\Tests\AbstractUnitTestCase;

final class GeometryWktTest extends AbstractUnitTestCase
{
    public function testPointWkt(): void
    {
        $point = new Point(1.0, 2.0, 4326);

        $this->assertSame(Column::TYPE_POINT, $point->getType());
        $this->assertSame(4326, $point->getSrid());
        $this->assertSame(1.0, $point->getX());
        $this->assertSame(2.0, $point->getY());
        $this->assertSame("POINT(1 2)", $point->toWkt());
        $this->assertSame("POINT(1 2)", (string) $point);
    }

    public function testLineStringWkt(): void
    {
        $line = new LineString(
            [new Point(0.0, 0.0), new Point(1.0, 1.0)],
            4326
        );

        $this->assertSame(Column::TYPE_LINESTRING, $line->getType());
        $this->assertSame("LINESTRING(0 0, 1 1)", $line->toWkt());
    }

    public function testPolygonWkt(): void
    {
        $ring = [
            new Point(0.0, 0.0),
            new Point(1.0, 0.0),
            new Point(1.0, 1.0),
            new Point(0.0, 0.0),
        ];

        $poly = new Polygon([$ring]);

        $this->assertSame(Column::TYPE_POLYGON, $poly->getType());
        $this->assertSame("POLYGON((0 0, 1 0, 1 1, 0 0))", $poly->toWkt());
    }

    public function testGeometryCollectionWkt(): void
    {
        $gc = new GeometryCollection([new Point(1.0, 2.0)]);

        $this->assertSame(Column::TYPE_GEOMETRYCOLLECTION, $gc->getType());
        $this->assertSame("GEOMETRYCOLLECTION(POINT(1 2))", $gc->toWkt());
    }
}
