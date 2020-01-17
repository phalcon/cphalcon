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
use function uniqid;

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

        $I->assertTrue($adapter->clear());

        $key1 = uniqid('key');
        $key2 = uniqid('key');
        $key3 = uniqid('one');
        $key4 = uniqid('one');

        $adapter->set($key1, 'test');
        $adapter->set($key2, 'test');
        $adapter->set($key3, 'test');
        $adapter->set($key4, 'test');

        $I->assertTrue($adapter->has($key1));
        $I->assertTrue($adapter->has($key2));
        $I->assertTrue($adapter->has($key3));
        $I->assertTrue($adapter->has($key4));

        $expected = [
            'ph-strm' . $key1,
            'ph-strm' . $key2,
            'ph-strm' . $key3,
            'ph-strm' . $key4,
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);

        $expected = [
            'ph-strm' . $key3,
            'ph-strm' . $key4,
        ];
        $actual   = $adapter->getKeys("one");
        sort($actual);
        $I->assertEquals($expected, $actual);

        $I->safeDeleteDirectory(outputDir('ph-strm'));
    }

    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getKeys()
     *
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

        $I->safeDeleteDirectory(outputDir('basePrefix-'));
    }

    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getKeys()
     *
     * @author       ekmst <https://github.com/ekmst>
     * @since        2020-01-17
     */
    public function storageAdapterStreamGetKeysPrefix(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getKeys() - prefix');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
                'prefix'     => 'pref-',
            ]
        );

        $I->assertTrue($adapter->clear());

        $adapter->set('key', 'test');
        $adapter->set('key1', 'test');
        $adapter->set('somekey', 'test');
        $adapter->set('somekey1', 'test');

        $expected = [
            'pref-key',
            'pref-key1',
            'pref-somekey',
            'pref-somekey1',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);

        $expected1 = [
            'pref-somekey',
            'pref-somekey1',
        ];

        $actual1 = $adapter->getKeys('so');
        sort($actual1);
        $I->assertEquals($expected1, $actual1);

        $I->assertTrue($adapter->clear());

        $I->safeDeleteDirectory(outputDir('pref-'));
    }
}
