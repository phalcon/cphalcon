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

use Phalcon\Db\Exceptions\InvalidWkb;
use Phalcon\Db\Geometry\GeometryCollection;
use Phalcon\Db\Geometry\LineString;
use Phalcon\Db\Geometry\MultiPoint;
use Phalcon\Db\Geometry\Point;
use Phalcon\Db\Geometry\WkbParser;
use Phalcon\Tests\AbstractUnitTestCase;

final class WkbParserTest extends AbstractUnitTestCase
{
    // little-endian IEEE-754 doubles
    private const D0 = "0000000000000000"; // 0.0
    private const D1 = "000000000000F03F"; // 1.0
    private const D2 = "0000000000000040"; // 2.0

    public function testMysqlPoint(): void
    {
        // SRID(0) + bo(LE) + type(1) + X(1) + Y(2)
        $raw  = hex2bin("00000000" . "01" . "01000000" . self::D1 . self::D2);
        $geom = (new WkbParser())->parse($raw);

        $this->assertInstanceOf(Point::class, $geom);
        $this->assertSame(0, $geom->getSrid());
        $this->assertSame(1.0, $geom->getX());
        $this->assertSame(2.0, $geom->getY());
    }

    public function testPostgisEwkbPointWithSrid(): void
    {
        // EWKB hex (as PostGIS returns it): bo + (type|SRID flag) + srid(4326) + X(1) + Y(2)
        $raw  = "0101000020E6100000" . self::D1 . self::D2;
        $geom = (new WkbParser())->parse($raw);

        $this->assertInstanceOf(Point::class, $geom);
        $this->assertSame(4326, $geom->getSrid());
        $this->assertSame(1.0, $geom->getX());
        $this->assertSame(2.0, $geom->getY());
    }

    public function testMysqlLineString(): void
    {
        // SRID(0) + bo + type(2) + numPoints(2) + (0 0) + (1 1)
        $raw = hex2bin(
            "00000000" . "01" . "02000000" . "02000000"
            . self::D0 . self::D0
            . self::D1 . self::D1
        );
        $geom = (new WkbParser())->parse($raw);

        $this->assertInstanceOf(LineString::class, $geom);
        $this->assertCount(2, $geom->getPoints());
        $this->assertSame(1.0, $geom->getPoints()[1]->getX());
        $this->assertSame(1.0, $geom->getPoints()[1]->getY());
    }

    public function testMysqlMultiPoint(): void
    {
        // each member is a full WKB point
        $pt0 = "01" . "01000000" . self::D0 . self::D0;
        $pt1 = "01" . "01000000" . self::D1 . self::D1;
        $raw = hex2bin("00000000" . "01" . "04000000" . "02000000" . $pt0 . $pt1);

        $geom = (new WkbParser())->parse($raw);

        $this->assertInstanceOf(MultiPoint::class, $geom);
        $this->assertCount(2, $geom->getPoints());
        $this->assertSame(1.0, $geom->getPoints()[1]->getX());
    }

    public function testMysqlGeometryCollection(): void
    {
        $point = "01" . "01000000" . self::D1 . self::D2; // POINT(1 2)
        $raw   = hex2bin("00000000" . "01" . "07000000" . "01000000" . $point);

        $geom = (new WkbParser())->parse($raw);

        $this->assertInstanceOf(GeometryCollection::class, $geom);
        $this->assertCount(1, $geom->getGeometries());
        $this->assertInstanceOf(Point::class, $geom->getGeometries()[0]);
        $this->assertSame(2.0, $geom->getGeometries()[0]->getY());
    }

    public function testInvalidThrows(): void
    {
        $this->expectException(InvalidWkb::class);

        (new WkbParser())->parse("zz"); // not hex, too short for MySQL prefix
    }
}
