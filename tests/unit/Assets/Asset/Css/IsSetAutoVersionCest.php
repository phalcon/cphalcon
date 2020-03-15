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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

class IsSetAutoVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset\Css :: isAutoVersion() / setAutoVersion()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-02
     */
    public function assetsAssetCssIsSetAutoVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - isAutoVersion() / setAutoVersion()');

        $asset = new Css('css/docs.css');

        $I->assertFalse($asset->isAutoVersion());

        $asset->setAutoVersion(true);

        $I->assertTrue($asset->isAutoVersion());
    }
}
