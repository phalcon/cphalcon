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

namespace Phalcon\Test\Unit\Assets\Asset;

use Phalcon\Assets\Asset;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class GetRealTargetPathCest
 *
 * @package Phalcon\Test\Unit\Assets\Asset
 */
class GetRealTargetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCss(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset - getRealTargetPath() - css");
        $asset = new Asset('css', 'css/docs.css');

        $expected = 'css/docs.css';
        $this->assetGetRealTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJs(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset - getRealTargetPath() - js");
        $asset = new Asset('js', 'js/jquery.js');

        $expected = 'js/jquery.js';
        $this->assetGetRealTargetPath($I, $asset, $expected);
    }
}
