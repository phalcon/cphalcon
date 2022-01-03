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

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

use function hash;

/**
 * Class GetAssetKeyCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getAssetKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsGetAssetKey(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - getAssetKey()');

        $path     = 'js/jquery.js';
        $asset    = new Js($path);
        $expected = hash("sha256", 'js:' . $path);
        $actual   = $asset->getAssetKey();

        $I->assertEquals($expected, $actual);
    }
}
