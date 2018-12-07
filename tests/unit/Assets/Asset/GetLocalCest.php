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
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetLocalCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalCss(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset - getLocal() - css");
        $asset = new Asset('css', 'css/docs.css');
        $expected = md5('css:css/docs.css');

        $this->assetGetLocal($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalJs(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset - getLocal() - js");
        $asset = new Asset('js', 'js/jquery.js');
        $expected = md5('js:js/jquery.js');

        $this->assetGetLocal($I, $asset, $expected);
    }
}
