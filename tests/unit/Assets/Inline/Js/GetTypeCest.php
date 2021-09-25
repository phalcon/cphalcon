<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use UnitTester;

class GetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineJsGetType(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - getType()');

        $asset = new Js(
            '<script>alert("Hello");</script>'
        );

        $I->assertEquals(
            'js',
            $asset->getType()
        );
    }
}
