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
 * Class GetPathCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathCss(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset - getPath() - css");
        $asset = new Asset('css', 'css/docs.css');
        $expected = md5('css:css/docs.css');

        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathJs(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset - getPath() - js");
        $asset = new Asset('js', 'js/jquery.js');
        $expected = md5('js:js/jquery.js');

        $this->assetGetPath($I, $asset, $expected);
    }
}
