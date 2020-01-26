<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\ConnectionLocator;

use IntegrationTester;
use Phalcon\DM\Pdo\ConnectionLocator;
use Phalcon\DM\Pdo\Exception\ConnectionNotFound;

use function in_array;
use function spl_object_hash;

class GetSetWriteCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator ::
     * getWrite()/setWrite()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetSetWrite(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getWrite()/setWrite()');

        $master  = $I->getConnection();
        $write1  = $I->getConnection();
        $write2  = $I->getConnection();
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
        $I->assertEquals(spl_object_hash($write1), spl_object_hash($actual));

        $actual = $locator->getWrite("write2");
        $I->assertEquals(spl_object_hash($write2), spl_object_hash($actual));
    }

    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator :: getWrite() - random
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetWriteRandom(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getWrite() - random');

        $master  = $I->getConnection();
        $write1  = $I->getConnection();
        $write2  = $I->getConnection();
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
        $I->assertTrue(in_array(spl_object_hash($actual), $hashes));
    }

    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator :: getWrite() - empty
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetWriteEmpty(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getWrite() - empty');

        $master  = $I->getConnection();
        $locator = new ConnectionLocator($master);

        $actual = $locator->getWrite("write1");
        $I->assertEquals(spl_object_hash($master), spl_object_hash($actual));
    }

    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator :: getWrite() -
     * exception
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetWriteException(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getWrite() - exception');

        $I->expectThrowable(
            new ConnectionNotFound(
                "Connection not found: write:unknown"
            ),
            function () use ($I) {
                $master  = $I->getConnection();
                $write1  = $I->getConnection();
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
        );
    }
}
