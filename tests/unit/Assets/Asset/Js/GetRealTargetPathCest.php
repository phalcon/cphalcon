<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class GetRealTargetPathCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetRealTargetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealTargetPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetRealTargetPath(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Js - getRealTargetPath()");
        $asset = new Js('js/jquery.js');
        $expected = 'js/jquery.js';
        $this->assetGetRealTargetPath($I, $asset, $expected);
    }
}
