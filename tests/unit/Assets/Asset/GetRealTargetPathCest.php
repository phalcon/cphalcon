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
 */
class GetRealTargetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $expected = 'css/docs.css';
        $this->assetGetRealTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false);

        $expected = 'https://phalcon.ld/css/docs.css';
        $this->assetGetRealTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - js local');
        $asset = new Asset('js', 'js/jquery.js');

        $expected = 'js/jquery.js';
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
    public function assetsAssetGetAssetKeyJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);

        $expected = 'https://phalcon.ld/js/jquery.js';
        $this->assetGetRealTargetPath($I, $asset, $expected);
    }
}
