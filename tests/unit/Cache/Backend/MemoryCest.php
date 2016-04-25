<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Frontend\None;
use Phalcon\Test\Proxy\Cache\Backend\Memory;

/**
 * \Phalcon\Test\Unit\Cache\Backend\MemoryCest
 * Tests the \Phalcon\Cache\Backend\Memory component
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
class MemoryCest
{
    public function dataNone(UnitTester $I)
    {
        $I->wantTo("Use Memory cache with None frontend");

        $frontend = new None(['lifetime' => 10]);
        $backend  = new Memory($frontend);

        $I->assertFalse($backend->isStarted());

        $backend->save('test-data', 'nothing interesting');
        $I->assertEquals('nothing interesting', $backend->get('test-data'));

        $backend->save('test-data', 'something interesting');
        $I->assertEquals('something interesting', $backend->get('test-data'));

        $I->assertTrue($backend->exists('test-data'));
        $I->assertTrue($backend->delete('test-data'));

        $string = str_repeat('a', 5000000);

        $backend->save('test-data', $string);

        $s1 = $backend->get('test-data');
        $s2 = $backend->get('test-data');
        $s3 = $backend->get('test-data');

        $I->assertEquals($s1, $s2);
        $I->assertEquals($s1, $s3);
        $I->assertEquals(strlen($s1), 5000000);
        $I->assertEquals($s1, $string);

        $I->assertTrue($backend->delete('test-data'));

        unset($s1, $s2, $s3);

        gc_collect_cycles();

        $s1 = $frontend->afterRetrieve($string);
        $s2 = $frontend->afterRetrieve($string);
        $s3 = $frontend->afterRetrieve($string);

        $I->assertEquals($s1, $s2);
        $I->assertEquals($s1, $s3);
        $I->assertEquals($s1, $string);
    }
}
