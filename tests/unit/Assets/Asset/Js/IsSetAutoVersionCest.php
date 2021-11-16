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
 * Class IsSetAutoVersionCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class IsSetAutoVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset\Js :: isAutoVersion() / setAutoVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsIsSetAutoVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - isAutoVersion()/setAutoVersion()');

        $asset  = new Js('js/jquery.js');
        $actual = $asset->isAutoVersion();
        $I->assertFalse($actual);

        $asset->setAutoVersion(true);

        $actual = $asset->isAutoVersion();
        $I->assertTrue($actual);
    }
}
