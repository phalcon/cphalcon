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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Db\Geometry\Point;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Spatial;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 * PostgreSQL is not covered here because the dev container has no PostGIS
 * extension; PostGIS EWKB parsing is verified in the unit WkbParserTest.
 *
 * @group mysql
 */
final class SpatialHydrationTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        $connection->exec("DROP TABLE IF EXISTS co_spatial");
        $connection->exec(
            "CREATE TABLE co_spatial (id INT PRIMARY KEY, location POINT NOT NULL)"
        );
        $connection->exec(
            "INSERT INTO co_spatial (id, location) VALUES (1, ST_GeomFromText('POINT(1 2)'))"
        );
    }

    public function tearDown(): void
    {
        self::getConnection()->exec("DROP TABLE IF EXISTS co_spatial");
        Settings::set("orm.cast_on_hydrate", false);
    }

    public function testPointHydratesWhenCastOnHydrate(): void
    {
        Settings::set("orm.cast_on_hydrate", true);

        $record = Spatial::findFirst("id = 1");

        $this->assertInstanceOf(Spatial::class, $record);
        $this->assertInstanceOf(Point::class, $record->location);
        $this->assertEqualsWithDelta(1.0, $record->location->getX(), 0.0001);
        $this->assertEqualsWithDelta(2.0, $record->location->getY(), 0.0001);
    }

    public function testRawWhenCastOff(): void
    {
        Settings::set("orm.cast_on_hydrate", false);

        $record = Spatial::findFirst("id = 1");

        $this->assertInstanceOf(Spatial::class, $record);
        $this->assertNotInstanceOf(Point::class, $record->location);
    }
}
