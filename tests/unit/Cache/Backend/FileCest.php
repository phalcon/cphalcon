<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Output;
use Phalcon\Cache\Frontend\Igbinary;

/**
 * \Phalcon\Test\Unit\Cache\Backend\FileCest
 * Tests the \Phalcon\Cache\Backend\File component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Cache\Backend
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FileCest
{
    public function checkFreshState(UnitTester $I)
    {
        $I->wantTo("Check fresh state by using file cache as backend");

        $cache = new File(new Output(['lifetime' => 2]), ['cacheDir' => PATH_CACHE]);

        $I->assertFalse($cache->isStarted());
        $I->assertFalse($cache->isFresh());

        ob_start();

        $cache->start('start-keyname');
        $I->assertTrue($cache->isStarted());

        echo 'start-value';
        $cache->save(null, null, null, true);

        $I->assertTrue($cache->isFresh());

        ob_get_contents();
        ob_end_clean();

        $I->assertTrue($cache->isFresh());
        $cache->start('start-keyname');
        $I->assertFalse($cache->isFresh());

        sleep(2);

        $cache->start('start-keyname');
        $I->assertTrue($cache->isFresh());

        $I->amInPath(PATH_CACHE);
        $I->deleteFile('start-keyname');
    }

    public function outputFrontend(UnitTester $I)
    {
        $I->wantTo("Use File cache with Output frontend");

        for ($i = 0; $i < 2; $i++) {
            $time = date('H:i:s');

            $frontCache = new Output(['lifetime' => 2]);
            $cache = new File($frontCache, [
                'cacheDir' => PATH_CACHE,
                'prefix'   => 'unit_'
            ]);

            // on the second run set useSafeKey to true to test the compatibility toggle
            if ($i == 1) {
                $cache->useSafeKey(true);
            }

            $I->assertFalse($cache->isStarted());

            ob_start();

            // First time cache
            $content = $cache->start('test_output');
            $I->assertTrue($cache->isStarted());

            if ($content !== null) {
                $I->assertTrue(false);
            }

            echo $time;
            $cache->save(null, null, null, true);

            $obContent = ob_get_contents();
            ob_end_clean();

            $I->assertEquals($time, $obContent);
            $I->amInPath(PATH_CACHE);
            $I->seeFileFound('unit_' . $cache->getKey('test_output'));

            // Same cache
            $content = $cache->start('test_output');
            $I->assertTrue($cache->isStarted());

            if ($content === null) {
                $I->assertTrue(false);
            }

            $I->assertEquals($time, $obContent);

            // Refresh cache
            sleep(3);

            $time2 = date('H:i:s');

            ob_start();

            $content = $cache->start('test_output');
            $I->assertTrue($cache->isStarted());

            if ($content !== null) {
                $I->assertTrue(false);
            }

            echo $time2;
            $cache->save(null, null, null, true);

            $obContent2 = ob_get_contents();
            ob_end_clean();

            $I->assertNotEquals($time, $obContent2);
            $I->assertEquals($time2, $obContent2);

            // Check keys
            $keys = $cache->queryKeys();
            $I->assertEquals($keys, [
                'unit_' . $cache->getKey('test_output'),
                '.gitignore'
            ]);

            $I->assertTrue($cache->exists('test_output'));
            $I->assertTrue($cache->delete('test_output'));

            // Delete cache
            $I->dontSeeFileFound('unit_' . $cache->getKey('test_output'));
        }
    }

    public function dataIgbinary(UnitTester $I)
    {
        if (!extension_loaded('igbinary')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: igbinary extension is not loaded'
            );
        }

        $I->wantTo("Use File cache with Igbinary frontend");

        $frontend = new Igbinary(['lifetime' => 600]);
        $backend  = new File($frontend, [
            'cacheDir' => PATH_CACHE,
            'prefix'   => 'igbinary_'
        ]);

        $I->assertFalse($backend->isStarted());

        $backend->save('test-data', 'nothing interesting');

        $I->amInPath(PATH_CACHE);

        $I->seeFileFound('igbinary_' . $backend->getKey('test-data'));
        $I->seeFileContentsEqual(igbinary_serialize('nothing interesting'));
        $I->assertEquals('nothing interesting', $backend->get('test-data'));

        $backend->save('test-data', 'something interesting');
        $I->assertEquals('something interesting', $backend->get('test-data'));

        $data = [
            'null' => null,
            'array' => [1, 2, 3, 4 => 5],
            'string',
            123.45,
            6,
            true,
            false,
            null,
            0,
            ""
        ];

        $serialized = igbinary_serialize($data);
        $I->assertEquals($data, igbinary_unserialize($serialized));

        $backend->save('test-data', $data);
        $I->assertEquals($data, $backend->get('test-data'));

        $I->assertTrue($backend->exists('test-data'));
        $I->assertTrue($backend->delete('test-data'));

        // Delete cache
        $I->dontSeeFileFound('igbinary_' . $backend->getKey('test-data'));
    }
}
