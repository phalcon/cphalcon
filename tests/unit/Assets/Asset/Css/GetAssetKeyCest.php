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
 * Class GetAssetKeyCest
 */
class GetAssetKeyCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAssetKeyLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - css local');
        $asset    = new Css('css/docs.css');
        $expected = md5('css:css/docs.css');

        $this->assetGetAssetKey($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAssetKeyRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - css remote');
        $asset    = new Css('https://phalcon.ld/css/docs.css');
        $expected = md5('css:https://phalcon.ld/css/docs.css');

        $this->assetGetAssetKey($I, $asset, $expected);
    }
}
