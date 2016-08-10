<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use APCIterator;
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
        if (!function_exists('apc_fetch')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: apc extension is not loaded'
            );
        }

        if (ini_get('apc.enable_cli') != 1) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: apc.enable_cli must be set to "On"'
            );
        }
    }

    public function _after(UnitTester $I)
    {
        foreach (new APCIterator('user') as $counter) {
            apc_delete($counter['key']);
        }
    }

    public function increment(UnitTester $I)
    {
        $I->wantTo('Increment counter by using APC as cache backend');

        $key   = '_PHCA' . 'increment';
        $cache = new Apc(new Data(['lifetime' => 20]));

        apc_store($key, 1);

        $I->assertEquals(2, $cache->increment('increment'));
        $I->assertEquals(2, apc_fetch($key));

        $I->assertEquals(4, $cache->increment('increment', 2));
        $I->assertEquals(4, apc_fetch($key));

        $I->assertEquals(14, $cache->increment('increment', 10));
        $I->assertEquals(14, apc_fetch($key));

        $key = '_PHCA' . 'increment-2';
        $cache->save('increment-2', 90);

        $I->assertEquals(90, apc_fetch($key));

        $I->assertEquals(91, $cache->increment('increment-2'));
        $I->assertEquals(91, apc_fetch($key));

        $I->assertEquals(97, $cache->increment('increment-2', 6));
        $I->assertEquals(97, apc_fetch($key));

        $I->assertEquals(200, $cache->increment('increment-2', 103));
        $I->assertEquals(200, apc_fetch($key));
    }

    public function decrement(UnitTester $I)
    {
        $I->wantTo('Decrement counter by using APC as cache backend');

        $key   = '_PHCA' . 'decrement';
        $cache = new Apc(new Data(['lifetime' => 20]));

        apc_store($key, 100);

        $I->assertEquals(99, $cache->decrement('decrement'));
        $I->assertEquals(99, apc_fetch($key));

        $I->assertEquals(96, $cache->decrement('decrement', 3));
        $I->assertEquals(96, apc_fetch($key));

        $I->assertEquals(90, $cache->decrement('decrement', 6));
        $I->assertEquals(90, apc_fetch($key));

        $key = '_PHCA' . 'decrement-2';
        $cache->save('decrement-2', 90);

        $I->assertEquals(90, apc_fetch($key));

        $I->assertEquals(89, $cache->decrement('decrement-2'));
        $I->assertEquals(89, apc_fetch($key));

        $I->assertEquals(78, $cache->decrement('decrement-2', 11));
        $I->assertEquals(78, apc_fetch($key));

        $I->assertEquals(8, $cache->decrement('decrement-2', 70));
        $I->assertEquals(8, apc_fetch($key));
    }
}
