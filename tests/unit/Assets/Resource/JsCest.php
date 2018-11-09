<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Resource;

use Phalcon\Assets\Resource\Js;
use UnitTester;

class JsCest
{
    /**
     * Tests Js getType
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceJsGetType(UnitTester $I)
    {
        $resource = new Js('/js/jquery.js', false);
        $expected = 'js';
        $actual   = $resource->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Js getPath
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceJsGetPath(UnitTester $I)
    {
        $resource = new Js('/js/jquery.js', false);
        $expected = '/js/jquery.js';
        $actual   = $resource->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Js getLocal
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceJsGetLocal(UnitTester $I)
    {
        $resource = new Js('/js/jquery.js', false);
        $actual   = $resource->getLocal();
        $I->assertFalse($actual);
    }
}
