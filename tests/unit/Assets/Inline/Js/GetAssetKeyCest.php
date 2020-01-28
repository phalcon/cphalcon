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

namespace Phalcon\Test\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use UnitTester;

class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getAssetKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineJsGetAssetKey(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - getAssetKey()');

        $content = '<script>alert("Hello");</script>';

        $asset = new Js($content);

        $expected = md5(
            'js:' . $content
        );

        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }
}
