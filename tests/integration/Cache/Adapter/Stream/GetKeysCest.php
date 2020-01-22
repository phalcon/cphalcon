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
use UnitTester;

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
    public function cacheAdapterStreamGetKeys(UnitTester $I)
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
}
