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

namespace Phalcon\Test\Unit\Storage\Adapter\Memory;

use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class HasCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Memory :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterMemoryGetSetHas(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Memory - has()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key = uniqid();

        $actual = $adapter->has($key);
        $I->assertFalse($actual);

        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);
    }
}
