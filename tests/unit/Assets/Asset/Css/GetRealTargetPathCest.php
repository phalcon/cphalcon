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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
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
     * Tests Phalcon\Assets\Asset\Css :: getRealTargetPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetRealTargetPath(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Css - getRealTargetPath()");
        $asset = new Css('css/docs.css');
        $expected = 'css/docs.css';
        $this->assetGetRealTargetPath($I, $asset, $expected);
    }
}
