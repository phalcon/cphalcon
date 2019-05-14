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

namespace Phalcon\Test\Unit\Cache\Adapter\Stream;

use function outputDir;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use function sort;
use UnitTester;

class GetKeysCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: getKeys()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function cacheAdapterStreamGetKeys(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - getKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['cacheDir' => outputDir()]);

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
            'phstrm-key-1',
            'phstrm-key-2',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);
    }
}
