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

namespace Phalcon\Tests\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

/**
 * Class IsSetAutoVersionCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Css
 */
class IsSetAutoVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset\Css :: isAutoVersion()/setAutoVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetCssIsSetAutoVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - isAutoVersion()/setAutoVersion()');

        $asset  = new Css('css/docs.css');
        $actual = $asset->isAutoVersion();
        $I->assertFalse($actual);

        $asset->setAutoVersion(true);

        $actual = $asset->isAutoVersion();
        $I->assertTrue($actual);
    }
}
