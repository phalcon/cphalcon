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

use Codeception\Example;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use IntegrationTester;
use Phalcon\Test\Fixtures\Cache\CacheFixtureData;

use function file_put_contents;
use function outputDir;
use function sleep;

class GetSetCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: set()
     *
     * @throws Exception
     * @since  2019-04-24
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterStreamSet(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - set()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['storageDir' => outputDir()]);

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
     * Tests Phalcon\Cache\Adapter\Stream :: get()
     *
     * @throws Exception
     * @since  2019-04-24
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterStreamGet(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - get()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['storageDir' => outputDir()]);

        $target = outputDir() . 'ph-strm/te/st/-k/';
        $data   = 'Phalcon Framework';
        $result = $adapter->set('test-key', $data);
        $I->assertTrue($result);

        $expected = 'Phalcon Framework';
        $actual   = $adapter->get('test-key');
        $I->assertNotNull($actual);
        $I->assertEquals($expected, $actual);

        $I->safeDeleteFile($target . 'test-key');
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: get() - errors
     *
     * @throws Exception
     * @since  2019-04-24
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterStreamGetErrors(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - get() - errors');

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['storageDir' => outputDir()]);

        $target = outputDir() . 'ph-strm/te/st/-k/';

        // Unknown key
        $expected = 'test';
        $actual   = $adapter->get('unknown', 'test');
        $I->assertEquals($expected, $actual);

        // Invalid JSON object
        $result = file_put_contents($target . 'test-key', '{');
        $I->assertNotFalse($result);

        $expected = 'test';
        $actual   = $adapter->get('test-key', 'test');
        $I->assertEquals($expected, $actual);

        // Expiry
        $data   = 'Phalcon Framework';
        $result = $adapter->set('test-key', $data, 1);
        $I->assertTrue($result);

        sleep(2);

        $expected = 'test';
        $actual   = $adapter->get('test-key', 'test');
        $I->assertEquals($expected, $actual);

        $I->safeDeleteFile($target . 'test-key');
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: get()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     * @since        2021-03-28
     *
     * @author       Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterStreamGetSet(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Cache\Adapter\Stream - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['storageDir' => outputDir()]);

        $key = 'cache-data';

        $result = $adapter->set($key, $example[1]);
        $I->assertTrue($result);

        $expected = $example[1];
        $actual   = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return CacheFixtureData::getExamples();
    }
}
