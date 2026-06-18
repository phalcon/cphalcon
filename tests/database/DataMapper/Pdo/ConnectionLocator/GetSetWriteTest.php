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

namespace Phalcon\Tests\Database\DataMapper\Pdo\ConnectionLocator;

use Phalcon\DataMapper\Pdo\ConnectionLocator;
use Phalcon\DataMapper\Pdo\Exception\ConnectionNotFound;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

use function in_array;
use function spl_object_hash;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetSetWriteTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionLocatorGetSetWrite(): void
    {
        $master  = self::getDataMapperConnection();
        $write1  = self::getDataMapperConnection();
        $write2  = self::getDataMapperConnection();
        $locator = new ConnectionLocator(
            $master,
            [],
            [
                "write1" => function () use ($write1) {
                    return $write1;
                },
                "write2" => function () use ($write2) {
                    return $write2;
                },
            ]
        );

        $actual = $locator->getWrite("write1");
        $this->assertEquals(spl_object_hash($write1), spl_object_hash($actual));

        $actual = $locator->getWrite("write2");
        $this->assertEquals(spl_object_hash($write2), spl_object_hash($actual));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionLocatorGetWriteRandom(): void
    {
        $master  = self::getDataMapperConnection();
        $write1  = self::getDataMapperConnection();
        $write2  = self::getDataMapperConnection();
        $locator = new ConnectionLocator(
            $master,
            [],
            [
                "write1" => function () use ($write1) {
                    return $write1;
                },
                "write2" => function () use ($write2) {
                    return $write2;
                },
            ]
        );

        $hashes = [
            spl_object_hash($write1),
            spl_object_hash($write2),
        ];

        $actual = $locator->getWrite();
        $this->assertTrue(in_array(spl_object_hash($actual), $hashes));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionLocatorGetWriteEmpty(): void
    {
        $master  = self::getDataMapperConnection();
        $locator = new ConnectionLocator($master);

        $actual = $locator->getWrite("write1");
        $this->assertEquals(spl_object_hash($master), spl_object_hash($actual));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionLocatorGetWriteException(): void
    {
        $this->expectException(ConnectionNotFound::class);
        $this->expectExceptionMessage("Connection not found: write:unknown");

        $master  = self::getDataMapperConnection();
        $write1  = self::getDataMapperConnection();
        $locator = new ConnectionLocator(
            $master,
            [],
            [
                "write1" => function () use ($write1) {
                    return $write1;
                },
            ]
        );

        $locator->getWrite("unknown");
    }
}
