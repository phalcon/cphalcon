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
 * Class SetLocalCest
 */
class SetLocalCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: setLocal() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetLocalLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setLocal() - css local');
        $asset = new Css('https://phalcon.ld/css/docs.css');

        $expected = true;
        $asset->setLocal($expected);
        $this->assetGetLocal($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setLocal() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetLocalRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setLocal() - css remote');
        $I->skipTest('TODO - Need checking');
        $asset = new Css('https://phalcon.ld/css/docs.css');

        $expected = false;
        $asset->setLocal($expected);
        $this->assetGetLocal($I, $asset, $expected);
    }
}
