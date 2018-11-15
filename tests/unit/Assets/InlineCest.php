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

use Phalcon\Assets\Inline;
use UnitTester;

class InlineCest
{
    /**
     * Tests getType
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-02
     */
    public function getResourceKey(UnitTester $I)
    {
        $resource = new Inline('js', '<script>alert("Hello");</script>');

        $expected = $resource->getResourceKey();
        $actual   = md5('js:<script>alert("Hello");</script>');
        $I->assertEquals($expected, $actual);
    }
}
