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

namespace Phalcon\Test\Integration\Cache\Adapter\Stream;

use Phalcon\Cache\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use IntegrationTester;

use function outputDir;
use function sort;

class GetKeysCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: getKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function cacheAdapterStreamGetKeys(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - getKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['storageDir' => outputDir()]);

        $adapter->clear();

        $key = 'key-1';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $key = 'key-2';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $expected = [
            'ph-strmkey-1',
            'ph-strmkey-2',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: getKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function cacheAdapterStreamGetNoNExistingKeys(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - GetNoNExistingKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['storageDir' => outputDir()]);

        $adapter->clear();

        $key = 'random-non-existing-key';

        $I->assertNull($adapter->get($key));
        $I->assertEquals(123, $adapter->get($key, 123));
        $I->assertFalse($adapter->get($key, false));
    }
}
