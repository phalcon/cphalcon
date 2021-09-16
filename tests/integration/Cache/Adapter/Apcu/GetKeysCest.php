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

namespace Phalcon\Test\Integration\Cache\Adapter\Apcu;

use IntegrationTester;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;

class GetKeysCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: getKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-13
     */
    public function cacheAdapterApcuGetKeys(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - getKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $adapter->clear();


        $key = 'key-1';

        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );


        $key = 'key-2';

        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );


        $expected = [
            'ph-apcu-key-1',
            'ph-apcu-key-2',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: GetNoNExistingKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-03-28
     */
    public function cacheAdapterApcuGetNoNExistingKeys(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - GetNoNExistingKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $adapter->clear();
        $key = 'random-non-existing-key';

        $I->assertNull($adapter->get($key));
        $I->assertEquals(123, $adapter->get($key, 123));
        $I->assertFalse($adapter->get($key, false));
    }
}
