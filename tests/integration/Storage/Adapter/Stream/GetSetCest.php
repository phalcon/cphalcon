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

namespace Phalcon\Test\Integration\Storage\Adapter\Stream;

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function file_put_contents;
use function is_dir;
use function mkdir;
use function outputDir;
use function sleep;

class GetSetCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: set()
     *
     * @throws Exception
     * @since  2019-04-24
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterStreamSet(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - set()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $data   = 'Phalcon Framework';
        $result = $adapter->set('test-key', $data);
        $I->assertTrue($result);

        $target = outputDir() . 'ph-strm/te/st/-k/';
        $I->amInPath($target);
        $I->openFile('test-key');
        $expected = 's:3:"ttl";i:3600;s:7:"content";s:25:"s:17:"Phalcon Framework";";}';

        $I->seeInThisFile($expected);
        $I->safeDeleteFile($target . 'test-key');
    }

    /**
     * Tests Phalcon\Storage\Adapter\Stream :: get()
     *
     * @throws Exception
     * @since  2019-04-24
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterStreamGet(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - get()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $target = outputDir() . 'ph-strm/te/st/-k/';
        $data   = 'Phalcon Framework';

        $I->assertTrue(
            $adapter->set('test-key', $data)
        );

        $expected = 'Phalcon Framework';
        $actual   = $adapter->get('test-key');
        $I->assertNotNull($actual);
        $I->assertEquals($expected, $actual);

        $expected        = new \stdClass();
        $expected->one   = 'two';
        $expected->three = 'four';

        $I->assertTrue(
            $adapter->set('test-key', $expected)
        );

        $I->assertEquals($expected, $adapter->get('test-key'));
        $I->safeDeleteFile($target . 'test-key');
    }

    /**
     * Tests Phalcon\Storage\Adapter\Stream :: get() - errors
     *
     * @throws Exception
     * @since  2019-04-24
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterStreamGetErrors(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - get() - errors');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $target = outputDir() . 'ph-strm/te/st/-k/';
        if (true !== is_dir($target)) {
            mkdir($target, 0777, true);
        }

        // Unknown key
        $I->assertEquals(
            'test',
            $adapter->get('unknown', 'test')
        );

        // Invalid stored object
        $I->assertNotFalse(
            file_put_contents(
                $target . 'test-key',
                '{'
            )
        );

        $I->assertEquals(
            'test',
            $adapter->get('test-key', 'test')
        );

        // Expiry
        $data = 'Phalcon Framework';

        $I->assertTrue(
            $adapter->set('test-key', $data, 1)
        );

        sleep(2);

        $I->assertEquals(
            'test',
            $adapter->get('test-key', 'test')
        );

        $I->safeDeleteFile($target . 'test-key');
    }
}
