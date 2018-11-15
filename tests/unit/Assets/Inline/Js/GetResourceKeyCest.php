<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline;
use UnitTester;

class GetResourceKeyCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getResourceKey()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testGetResourceKey(UnitTester $I)
    {
        $resource = new Inline('js', '<script>alert("Hello");</script>');

        $expected = md5('js:<script>alert("Hello");</script>');
        $actual   = $resource->getResourceKey();
        $I->assertEquals($expected, $actual);
    }
}
