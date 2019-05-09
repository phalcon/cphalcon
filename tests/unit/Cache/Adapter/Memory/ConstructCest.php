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

namespace Phalcon\Test\Unit\Cache\Adapter\Memory;

use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-09
     */
    public function cacheAdapterMemoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - __construct()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $class = Memory::class;
        $I->assertInstanceOf($class, $adapter);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
