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

namespace Phalcon\Tests\Integration\Cache\Adapter\Stream;

use IntegrationTester;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\Exception as CacheException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as HelperException;
use stdClass;

use function file_put_contents;
use function is_dir;
use function mkdir;
use function outputDir;
use function sleep;

class GetSetCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: set()
     *
     * @param IntegrationTester $I
     *
     * @throws HelperException
     * @throws CacheException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cacheAdapterStreamSet(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - set()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $data   = 'Phalcon Framework';
        $actual = $adapter->set('test-key', $data);
        $I->assertTrue($actual);

        $target = outputDir() . 'ph-strm/te/st/-k/';
        $I->amInPath($target);
        $I->openFile('test-key');
        $expected = 's:3:"ttl";i:3600;s:7:"content";s:25:"s:17:"Phalcon Framework";";}';

        $I->seeInThisFile($expected);
        $I->safeDeleteFile($target . 'test-key');
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: get()
     *
     * @param IntegrationTester $I
     *
     * @throws HelperException
     * @throws CacheException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cacheAdapterStreamGet(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - get()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $target = outputDir() . 'ph-strm/te/st/-k/';
        $data   = 'Phalcon Framework';
        $actual = $adapter->set('test-key', $data);
        $I->assertTrue($actual);

        $expected = 'Phalcon Framework';
        $actual   = $adapter->get('test-key');
        $I->assertNotNull($actual);
        $I->assertEquals($expected, $actual);

        $expected        = new stdClass();
        $expected->one   = 'two';
        $expected->three = 'four';

        $actual = $adapter->set('test-key', $expected);
        $I->assertTrue($actual);

        $actual = $adapter->get('test-key');
        $I->assertEquals($expected, $actual);

        $I->safeDeleteFile($target . 'test-key');
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: get() - with prefix
     *
     * @param IntegrationTester $I
     *
     * @throws HelperException
     * @throws CacheException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-06-01
     * @issue  16348
     */
    public function cacheAdapterStreamGetWithPrefix(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - get() with prefix');

        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
                'prefix'     => 'en',
            ]
        );

        $target = outputDir() . 'en/';

        $data   = 123;
        $actual = $adapter->set('men', $data);
        $I->assertTrue($actual);

        $expected = 123;
        $actual   = $adapter->get('men');
        $I->assertNotNull($actual);
        $I->assertEquals($expected, $actual);


        $data   = 'abc';
        $actual = $adapter->set('barmen', $data);
        $I->assertTrue($actual);

        $expected = 'abc';
        $actual   = $adapter->get('barmen');
        $I->assertNotNull($actual);
        $I->assertEquals($expected, $actual);

        $data   = 'xyz';
        $actual = $adapter->set('bar', $data);
        $I->assertTrue($actual);

        $expected = 'xyz';
        $actual   = $adapter->get('bar');
        $I->assertNotNull($actual);
        $I->assertEquals($expected, $actual);

        $expected = [
            'enbar',
            'enbarmen',
            'enmen',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);

        $I->safeDeleteFile($target);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: get() - errors
     *
     * @param IntegrationTester $I
     *
     * @throws HelperException
     * @throws CacheException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cacheAdapterStreamGetErrors(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - get() - errors');

        if (version_compare(PHP_VERSION, '8.3.0', '>=')) {
            $I->markTestSkipped('Since PHP 8.3 warnings causing session ID/Name lock.');
        }

        $serializer = new SerializerFactory();
        $adapter    = new Stream(
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
        $expected = 'test';
        $actual   = $adapter->get(uniqid(), 'test');
        $I->assertEquals($expected, $actual);

        // Invalid stored object
        $actual = file_put_contents(
            $target . 'test-key',
            '{'
        );
        $I->assertNotFalse($actual);

        $expected = 'test';
        $actual   = $adapter->get('test-key', 'test');
        $I->assertEquals($expected, $actual);

        // Expiry
        $data = 'Phalcon Framework';

        $actual = $adapter->set('test-key', $data, 1);
        $I->assertTrue($actual);

        sleep(2);

        $expected = 'test';
        $actual   = $adapter->get('test-key', 'test');
        $I->assertEquals($expected, $actual);

        $I->safeDeleteFile($target . 'test-key');
    }
}
