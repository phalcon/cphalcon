<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use Phalcon\Test\Fixtures\Traits\Cache\LibmemcachedTrait;
use UnitTester;

/**
 * \Phalcon\Test\Unit\Cache\Backend\LibmemcachedCest
 * Tests the \Phalcon\Cache\Backend\Libmemcached component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          https://www.phalconphp.com
 * @author        Andres Gutierrez <andres@phalconphp.com>
 * @author        Phalcon Team <team@phalconphp.com>
 * @package       Phalcon\Test\Unit\Cache\Backend
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class LibmemcachedCest
{
    use LibmemcachedTrait;

    public function output(UnitTester $I)
    {
        $I->wantTo('Cache output fragments by using Libmemcached as cache backend');

        $time     = date('H:i:s');
        $lifetime = 2;
        $cache    = $this->getOutputCache($lifetime);

        ob_start();

        // First time cache
        $content = $cache->start('test-output');
        $I->assertNull($content);

        echo $time;
        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $I->assertEquals($time, $obContent);
        $I->seeInLibmemcached('test-output', $time);

        // Expect same cache
        $content = $cache->start('test-output');
        $I->assertNotNull($content);

        $I->assertEquals($time, $obContent);
        $I->seeInLibmemcached('test-output', $time);

        sleep($lifetime);
        $content = $cache->start('test-output');

        $I->assertNull($content);
        $I->dontSeeInLibmemcached('test-output');
    }
}
