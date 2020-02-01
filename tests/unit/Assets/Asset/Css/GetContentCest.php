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

use function dataDir;

class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getContent()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getContent()');

        $asset = new Css('assets/assets/1198.css');

        $I->openFile(
            dataDir('assets/assets/1198.css')
        );

        $I->seeFileContentsEqual(
            $asset->getContent(
                dataDir()
            )
        );
    }
}
