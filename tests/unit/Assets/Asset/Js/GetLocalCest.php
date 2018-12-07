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
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetLocalCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset\Js :: getLocal()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetLocal(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Js - getLocal()");
        $asset = new Js('js/jquery.js');
        $this->assetGetLocal($I, $asset, 'js');
    }
}
