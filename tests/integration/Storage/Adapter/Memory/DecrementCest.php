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

namespace Phalcon\Test\Integration\Storage\Adapter\Memory;

use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use IntegrationTester;

class DecrementCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Memory :: decrement()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterMemoryDecrement(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Memory - decrement()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key    = uniqid();
        $result = $adapter->set($key, 100);
        $I->assertTrue($result);

        $expected = 99;
        $actual   = $adapter->decrement($key);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        $expected = 90;
        $actual   = $adapter->decrement($key, 9);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }
}
