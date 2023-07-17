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

namespace Phalcon\Tests\Integration\Cache\Adapter\Weak;

use IntegrationTester;
use Phalcon\Cache\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as HelperException;

class GetKeysCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Weak :: getKeys()
     *
     * @param IntegrationTester $I
     *
     * @throws HelperException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cacheAdapterWeakGetKeys(IntegrationTester $I)
    {
        $I->wantToTest('cache\Adapter\Weak - getKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $I->assertTrue($adapter->clear());
        $obj1 = new \stdClass();
        $obj1->id = 1;
        $obj2 = new \stdClass();
        $obj2->id = 2;
        $obj3 = new \stdClass();
        $obj3->id = 3;


        $adapter->set('key-1', $obj1);
        $adapter->set('key-2', $obj2);
        $adapter->set('key-3', $obj3);
        $adapter->set('one-1', $obj1);
        $adapter->set('one-2', $obj2);
        $adapter->set('one-3', $obj3);


        $actual = $adapter->has('key-1');
        $I->assertTrue($actual);
        $actual = $adapter->has('key-2');
        $I->assertTrue($actual);
        $actual = $adapter->has('key-3');
        $I->assertTrue($actual);

        $expected = [
            'key-1',
            'key-2',
            'key-3',
            'one-1',
            'one-2',
            'one-3',
        ];
        $actual = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);

        $expected = [
            'one-1',
            'one-2',
            'one-3',
        ];
        $actual   = $adapter->getKeys("one");
        sort($actual);
        $I->assertEquals($expected, $actual);
    }
}
