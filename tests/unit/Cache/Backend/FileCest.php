<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Codeception\Example;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Frontend\Output;
use Phalcon\Cache\Frontend\Igbinary;

/**
 * Phalcon\Test\Unit\Cache\Backend\FileCest
 * Tests the \Phalcon\Cache\Backend\File component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Cache\Backend
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
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
            $actual = $cache->queryKeys();

            $I->assertTrue(
                2 === count($actual),
                sprintf('%s', json_encode($actual, JSON_PRETTY_PRINT))
            );
            $I->assertArrayHasKey('.gitignore', array_flip($actual));
            $I->assertArrayHasKey('unit_' . $cache->getKey('test_output'), array_flip($actual));

            $I->assertTrue($cache->exists('test_output'));
            $I->assertTrue($cache->delete('test_output'));

            // Delete cache
            $I->dontSeeFileFound('unit_' . $cache->getKey('test_output'));
        }
    }

    /**
     * @param UnitTester $I
     * @param Example $example
     *
     * @dataprovider frontendProvider
     */
    public function shouldWorkWithAnyFrontend(UnitTester $I, Example $example)
    {
        $I->haveFrontendAdapter($example['frontend'], ['prefix' => $example['prefix']]);
        $I->dontSeeCacheStarted();

        foreach ($example['data'] as $data) {
            $I->haveInCacheStorage($example['key'], $data);
            $I->seeInCacheStorage($example['key'], $data);
        }

        $I->deleteCacheData($example['key']);
        $I->dontSeeCacheFound($example['key']);
    }

    protected function frontendProvider()
    {
        return [
            [
                'frontend' => Igbinary::class,
                'prefix'   => 'igbinary_',
                'key'      => 'test-data',
                'data'     => [
                    'nothing interesting',
                    'something interesting',
                    [
                        'null' => null,
                        'array' => [1, 2, 3, 4 => 5],
                        'string',
                        123.45,
                        6,
                        true,
                        false,
                        null,
                        0,
                        "",
                        '0',
                    ],
                ],
            ],
            [
                'frontend' => Data::class,
                'prefix'   => 'data_',
                'key'      => 'test-data',
                'data'     => [
                    'nothing interesting',
                    'something interesting',
                    [
                        'null' => null,
                        'array' => [1, 2, 3, 4 => 5],
                        'string',
                        123.45,
                        6,
                        true,
                        false,
                        null,
                        0,
                        "",
                        '0',
                    ],
                ],
            ],
        ];
    }
}
