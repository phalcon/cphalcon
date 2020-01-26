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

class GetSetReadCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator :: getRead()/setRead()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetSetRead(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getRead()/setRead()');

        $master  = $I->getConnection();
        $read1   = $I->getConnection();
        $read2   = $I->getConnection();
        $locator = new ConnectionLocator(
            $master,
            [
                "read1" => function () use ($read1) {
                    return $read1;
                },
                "read2" => function () use ($read2) {
                    return $read2;
                },
            ]
        );

        $actual = $locator->getRead("read1");
        $I->assertEquals(spl_object_hash($read1), spl_object_hash($actual));

        $actual = $locator->getRead("read2");
        $I->assertEquals(spl_object_hash($read2), spl_object_hash($actual));
    }

    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator :: getRead() - random
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetReadRandom(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getRead() - random');

        $master  = $I->getConnection();
        $read1   = $I->getConnection();
        $read2   = $I->getConnection();
        $locator = new ConnectionLocator(
            $master,
            [
                "read1" => function () use ($read1) {
                    return $read1;
                },
                "read2" => function () use ($read2) {
                    return $read2;
                },
            ]
        );

        $hashes = [
            spl_object_hash($read1),
            spl_object_hash($read2),
        ];

        $actual = $locator->getRead();
        $I->assertTrue(in_array(spl_object_hash($actual), $hashes));
    }

    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator :: getRead() - empty
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetReadEmpty(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getRead() - empty');

        $master  = $I->getConnection();
        $locator = new ConnectionLocator($master);

        $actual = $locator->getRead("read1");
        $I->assertEquals(spl_object_hash($master), spl_object_hash($actual));
    }

    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator :: getRead() -
     * exception
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetReadException(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getRead() - exception');

        $I->expectThrowable(
            new ConnectionNotFound(
                "Connection not found: read:unknown"
            ),
            function () use ($I) {
                $master  = $I->getConnection();
                $read1   = $I->getConnection();
                $locator = new ConnectionLocator(
                    $master,
                    [
                        "read1" => function () use ($read1) {
                            return $read1;
                        },
                    ]
                );

                $locator->getRead("unknown");
            }
        );
    }
}
