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

use Phalcon\Cache\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use UnitTester;
use function outputDir;

/**
 * Class GetSetCest
 */
class GetSetCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     *
     * @throws \Exception
     */
    public function storageAdapterStreamSet(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - get()/set()');

        $factory = new SerializerFactory();
        $adapter = new Stream($factory, ['cacheDir' => outputDir()]);

        $data   = 'Phalcon Framework';
        $result = $adapter->set('test-key', $data);
        $I->assertTrue($result);

        $target = outputDir() . 'phstrm-/te/st/-k/';
        $I->amInPath($target);
        $I->openFile('test-key');
        $expected = '"ttl":3600,"content":"s:17:\"Phalcon Framework\";';
        $I->seeInThisFile($expected);
        $I->safeDeleteFile($target . 'test-key');
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: get()/set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     *
     * @throws \Exception
     */
    public function storageAdapterStreamGet(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - get()/set()');

        $factory = new SerializerFactory();
        $adapter = new Stream($factory, ['cacheDir' => outputDir()]);

        $target = outputDir() . 'phstrm-/te/st/-k/';
        $data   = 'Phalcon Framework';
        $result = $adapter->set('test-key', $data);
        $I->assertTrue($result);

        $expected = 'Phalcon Framework';
        $actual   = $adapter->get('test-key');
        $I->assertNotNull($actual);
        $I->assertEquals($expected, $actual);

        $I->safeDeleteFile($target . 'test-key');
    }
}
