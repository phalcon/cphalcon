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

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use IntegrationTester;

class DeleteCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: delete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterApcuDelete(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - delete()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key = 'cache-data';
        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );

        $I->assertTrue(
            $adapter->delete($key)
        );

        $I->assertFalse(
            $adapter->has($key)
        );
    }

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: delete() - twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterApcuDeleteTwice(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - delete() - twice');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key = 'cache-data';
        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );

        $I->assertTrue(
            $adapter->delete($key)
        );

        $I->assertFalse(
            $adapter->delete($key)
        );
    }

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: delete() - unknown
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterApcuDeleteUnknown(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - delete() - unknown');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key = 'cache-data';

        $I->assertFalse(
            $adapter->delete($key)
        );
    }
}
