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

namespace Phalcon\Tests\Unit\Assets\Asset;

use Phalcon\Assets\Asset;
use UnitTester;

/**
 * Class IsSetAutoVersionCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class IsSetAutoVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset :: isAutoVersion() / setAutoVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetIsSetAutoVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - isAutoVersion()/setAutoVersion()');

        $asset = new Asset('css', 'css/docs.css');

        $actual = $asset->isAutoVersion();
        $I->assertFalse($actual);

        $asset->setAutoVersion(true);

        $actual = $asset->isAutoVersion();
        $I->assertTrue($actual);
    }
}
