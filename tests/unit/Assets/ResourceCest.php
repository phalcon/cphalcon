<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Assets\Resource;
use UnitTester;

class ResourceCest
{
    /**
     * Tests getType
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceGetType(UnitTester $I)
    {
        $resource = new Resource('js', 'js/jquery.js');
        $expected = 'js';
        $actual   = $resource->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getResourceKey
     *
     * @test
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-02
     */
    public function getResourceKey(UnitTester $I)
    {
        $resource = new Resource('js', 'js/jquery.js');

        $expected = md5('js:js/jquery.js');
        $actual   = $resource->getResourceKey();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getPath
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceGetPath(UnitTester $I)
    {
        $resource = new Resource('js', 'js/jquery.js');
        $expected = 'js/jquery.js';
        $actual   = $resource->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests getLocal
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceGetLocal(UnitTester $I)
    {
        $resource = new Resource('js', 'js/jquery.js');
        $actual   = $resource->getLocal();
        $I->assertTrue($actual);
    }
}
