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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function outputDir;
use function sort;

class GetKeysCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function storageAdapterStreamGetKeys(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getKeys()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

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
            'phstrm-key-1',
            'phstrm-key-2',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @author       ekmst <https://github.com/ekmst>
     * @since        2019-06-26
     */
    public function storageAdapterStreamGetKeysIssue14190(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getKeys() - issue 14190');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
                'prefix'     => 'basePrefix-',
            ]
        );

        $adapter->clear();

        $adapter->set('key', 'test');
        $adapter->set('key1', 'test');

        $expected = [
            'basePrefix-key',
            'basePrefix-key1',
        ];

        $actual = $adapter->getKeys();
        sort($actual);

        $I->assertEquals($expected, $actual);

        foreach ($expected as $key) {
            $I->assertTrue(
                $adapter->delete($key)
            );
        }
    }
}
