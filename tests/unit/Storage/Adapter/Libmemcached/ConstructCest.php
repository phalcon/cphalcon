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
use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Storage\Adapter\Libmemcached;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;
use function getOptionsLibmemcached;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-09
     */
    public function storageAdapterLibmemcachedConstruct(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - __construct()');
        $factory = new SerializerFactory();
        $adapter = new Libmemcached($factory, getOptionsLibmemcached());

        $class = Libmemcached::class;
        $I->assertInstanceOf($class, $adapter);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct() - empty
     * options
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-09
     */
    public function storageAdapterLibmemcachedConstructEmptyOptions(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - __construct() - empty options');
        $factory = new SerializerFactory();
        $adapter = new Libmemcached($factory);

        $expected = [
            'servers' => [
                0 => [
                    "host"   => "127.0.0.1",
                    "port"   => 11211,
                    "weight" => 1,
                ],
            ],
        ];
        $actual   = $adapter->getOptions();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct() - getTtl
     * options
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2019-04-09
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function storageAdapterLibmemcachedConstructGetTtl(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - __construct() - getTtl');
        $factory = new SerializerFactory();
        $adapter = new Libmemcached($factory);

        $expected = 3600;
        $actual   = $adapter->getTtl(null);
        $I->assertEquals($expected, $actual);

        $expected = 20;
        $actual   = $adapter->getTtl(20);
        $I->assertEquals($expected, $actual);

        $time     = new DateInterval('PT5S');
        $expected = 5;
        $actual   = $adapter->getTtl($time);
        $I->assertEquals($expected, $actual);
    }
}
