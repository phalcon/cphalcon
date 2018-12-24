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
    public function assetsAssetGetAssetKeyCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - css local');
        $asset    = new Asset('css', 'css/docs.css');
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
    public function assetsAssetGetAssetKeyCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - css remote');
        $asset    = new Asset('css', 'https://phalcon.ld/css/docs.css');
        $expected = md5('css:https://phalcon.ld/css/docs.css');

        $this->assetGetAssetKey($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - js local');
        $asset    = new Asset('js', 'js/jquery.js');
        $expected = md5('js:js/jquery.js');

        $this->assetGetAssetKey($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - js remote');
        $asset    = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);
        $expected = md5('js:https://phalcon.ld/js/jquery.js');

        $this->assetGetAssetKey($I, $asset, $expected);
    }
}
