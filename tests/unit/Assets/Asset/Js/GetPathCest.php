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
 * Class GetPathCest
 */
class GetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetPathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - js local');
        $asset = new Js('js/jquery.js');

        $expected = 'js/jquery.js';
        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetPathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - js remote');
        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $expected = 'https://phalcon.ld/js/jquery.js';
        $this->assetGetPath($I, $asset, $expected);
    }
}
