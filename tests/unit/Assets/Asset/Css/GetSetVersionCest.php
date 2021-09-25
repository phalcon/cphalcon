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

class GetSetVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset\Css :: getVersion() / setVersion()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-02
     */
    public function assetsAssetCssGetSetVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getVersion() / setVersion()');

        $asset = new Css('css/docs.css');

        $version = '4.1.0-rc.3';
        $asset->setVersion($version);

        $I->assertEquals($version, $asset->getVersion());
    }
}
