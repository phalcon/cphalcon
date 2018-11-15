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

class GetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getType()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testGetType(UnitTester $I, $scenario)
    {
        $resource = new Inline('js', '<script>alert("Hello");</script>');

        $expected = 'js';
        $actual   = $resource->getType();
        $I->assertEquals($expected, $actual);
    }
}
