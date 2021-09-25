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

use function dataDir;

class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getContent()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - getContent()');

        $asset = new Js('assets/assets/signup.js');

        $I->openFile(
            dataDir('assets/assets/signup.js')
        );

        $I->seeFileContentsEqual(
            $asset->getContent(
                dataDir()
            )
        );
    }
}
