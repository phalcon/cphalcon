<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Frontend\Data;

/**
 * \Phalcon\Test\Unit\Cache\Backend\ApcCest
 * Tests the \Phalcon\Cache\Backend\Apc component
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
class ApcCest
{
    public function _before(UnitTester $I)
    {
        if (!extension_loaded('apc')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: apc extension is not loaded'
            );
        }

        if (!ini_get('apc.enabled') || (PHP_SAPI === 'cli' && !ini_get('apc.enable_cli'))) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: apc.enable_cli must be set to "On"'
            );
        }

        if (extension_loaded('apcu') && version_compare(phpversion('apcu'), '5.1.6', '=')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: APCu v5.1.6 was broken. See: https://github.com/krakjoe/apcu/issues/203'
            );
        }
    }

    public function _after(UnitTester $I)
    {
        $I->flushApc();
    }

    public function increment(UnitTester $I)
    {
        $I->wantTo('Increment counter by using APC as cache backend');

        $key   = '_PHCA' . 'increment';
        $cache = new Apc(new Data(['lifetime' => 20]));

        $I->dontSeeInApc($key);
        $I->haveInApc($key, 1);

        $I->assertEquals(2, $cache->increment('increment'));
        $I->seeInApc($key, 2);

        $I->assertEquals(4, $cache->increment('increment', 2));
        $I->seeInApc($key, 4);

        $I->assertEquals(14, $cache->increment('increment', 10));
        $I->seeInApc($key, 14);

        $key = '_PHCA' . 'increment-2';

        $I->dontSeeInApc($key);
        $I->haveInApc($key, 90);

        $I->assertEquals(91, $cache->increment('increment-2'));
        $I->seeInApc($key, 91);

        $I->assertEquals(97, $cache->increment('increment-2', 6));
        $I->seeInApc($key, 97);

        $I->assertEquals(200, $cache->increment('increment-2', 103));
        $I->seeInApc($key, 200);
    }

    public function decrement(UnitTester $I)
    {
        $I->wantTo('Decrement counter by using APC as cache backend');

        $key   = '_PHCA' . 'decrement';
        $cache = new Apc(new Data(['lifetime' => 20]));

        $I->dontSeeInApc($key);
        $I->haveInApc($key, 100);

        $I->assertEquals(99, $cache->decrement('decrement'));
        $I->seeInApc($key, 99);

        $I->assertEquals(96, $cache->decrement('decrement', 3));
        $I->seeInApc($key, 96);

        $I->assertEquals(90, $cache->decrement('decrement', 6));
        $I->seeInApc($key, 90);

        $key = '_PHCA' . 'decrement-2';

        $I->dontSeeInApc($key);
        $I->haveInApc($key, 60);

        $I->assertEquals(59, $cache->decrement('decrement-2'));
        $I->seeInApc($key, 59);

        $I->assertEquals(47, $cache->decrement('decrement-2', 12));
        $I->seeInApc($key, 47);

        $I->assertEquals(7, $cache->decrement('decrement-2', 40));
        $I->seeInApc($key, 7);
    }
}
