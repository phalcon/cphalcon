<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

/**
 * Class GetSetVersionCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class GetSetVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset\Js :: getVersion()/setVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsGetSetVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - getVersion()/setVersion()');

        $asset = new Js('js/jquery.js');

        $version = '4.1.0-rc.3';
        $asset->setVersion($version);
        $actual = $asset->getVersion();

        $I->assertEquals($version, $actual);
    }
}
