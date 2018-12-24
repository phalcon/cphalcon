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
 * Class GetLocalCest
 */
class GetLocalCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - css local');
        $asset    = new Asset('css', 'css/docs.css');
        $expected = md5('css:css/docs.css');

        $this->assetGetLocal($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - css remote');
        $asset    = new Asset('css', 'https://phalcon.ld/css/docs.css');
        $expected = md5('css:https://phalcon.ld/css/docs.css');

        $this->assetGetLocal($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - js local');
        $asset    = new Asset('js', 'js/jquery.js');
        $expected = md5('js:js/jquery.js');

        $this->assetGetLocal($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - js remote');
        $asset    = new Asset('js', 'https://phalcon.ld/js/jquery.js');
        $expected = md5('js:https://phalcon.ld/js/jquery.js');

        $this->assetGetLocal($I, $asset, $expected);
    }
}
