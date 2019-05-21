<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Storage\Adapter\Libmemcached;

use DateInterval;
use Exception;
use function getOptionsLibmemcached;
use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Storage\Adapter\Libmemcached;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;

class ConstructCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
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
