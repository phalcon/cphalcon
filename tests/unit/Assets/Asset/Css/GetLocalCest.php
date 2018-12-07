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
 * Class GetLocalCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetLocalCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset\Css :: getLocal()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetLocal(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Css - getLocal()");
        $asset = new Css('css/docs.css');
        $this->assetGetLocal($I, $asset, 'css');
    }
}
