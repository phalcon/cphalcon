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
 * Class GetLocalCest
 */
class GetLocalCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetLocalLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - js local');
        $asset    = new Js('js/jquery.js');
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
    public function assetsAssetJsGetLocalRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - js remote');
        $asset    = new Js('https://phalcon.ld/js/jquery.js');
        $expected = md5('js:https://phalcon.ld/js/jquery.js');

        $this->assetGetLocal($I, $asset, $expected);
    }
}
