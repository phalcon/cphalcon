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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use UnitTester;
use function outputDir;
use function sort;

/**
 * Class GetKeysCest
 */
class GetKeysCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getKeys()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     *
     * @throws \Exception
     */
    public function storageAdapterStreamGetKeys(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getKeys()');

        $factory = new SerializerFactory();
        $adapter = new Stream($factory, ['cacheDir' => outputDir()]);

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
