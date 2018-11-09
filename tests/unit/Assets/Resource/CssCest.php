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

use Phalcon\Assets\Resource\Css;
use UnitTester;

class CssCest
{
    /**
     * Tests Css getType
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetType(UnitTester $I)
    {
        $resource = new Css('/css/style.css', false);
        $expected = 'css';
        $actual   = $resource->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Css getPath
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetPath(UnitTester $I)
    {
        $resource = new Css('/css/style.css', false);
        $expected = '/css/style.css';
        $actual   = $resource->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Css getLocal
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsResourceCssGetLocal(UnitTester $I)
    {
        $resource = new Css('/css/style.css', false);
        $actual   = $resource->getLocal();
        $I->assertFalse($actual);
    }
}
