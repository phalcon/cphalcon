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

/**
 * Class GetAssetKeyCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline\Js
 */
class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getAssetKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsGetAssetKey(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - getAssetKey()');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Js($content);

        $expected = sha1('js:' . $content);
        $actual   = $asset->getAssetKey();
        $I->assertEquals($expected, $actual);
    }
}
