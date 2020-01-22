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

namespace Phalcon\Test\Integration\Storage\Adapter\Libmemcached;

use DateInterval;
use Exception;
use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Storage\Adapter\Libmemcached;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;

use function getOptionsLibmemcached;

class ConstructCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-09
     */
    public function storageAdapterLibmemcachedConstruct(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - __construct()');

        $serializer = new SerializerFactory();

        $adapter = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

        $I->assertInstanceOf(
            Libmemcached::class,
            $adapter
        );

        $I->assertInstanceOf(
            AdapterInterface::class,
            $adapter
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct() - empty
     * options
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-09
     */
    public function storageAdapterLibmemcachedConstructEmptyOptions(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - __construct() - empty options');

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached($serializer);

        $expected = [
            'servers' => [
                0 => [
                    'host'   => '127.0.0.1',
                    'port'   => 11211,
                    'weight' => 1,
                ],
            ],
        ];

        $I->assertEquals(
            $expected,
            $adapter->getOptions()
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct() - getTtl
     * options
     *
     * @throws Exception
     * @since  2019-04-09
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterLibmemcachedConstructGetTtl(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - __construct() - getTtl');

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached($serializer);

        $I->assertEquals(
            3600,
            $adapter->getTtl(null)
        );

        $I->assertEquals(
            20,
            $adapter->getTtl(20)
        );

        $time = new DateInterval('PT5S');

        $I->assertEquals(
            5,
            $adapter->getTtl($time)
        );
    }
}
