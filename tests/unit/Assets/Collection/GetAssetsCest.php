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

namespace Phalcon\Tests\Unit\Assets\Collection;

use Phalcon\Assets\Asset;
use Phalcon\Assets\Collection;
use UnitTester;

class GetAssetsCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getAssets()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionGetAssets(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getAssets()');

        $collection = new Collection();

        $asset = new Asset('js', 'js/jquery.js');

        $collection->add(
            $asset
        );

        $asset1 = new Asset('js', 'js/jquery-ui.js');

        $collection->add(
            $asset1
        );

        $asserts = $collection->getAssets();

        $I->assertEquals(
            2,
            count($asserts)
        );

        $I->assertEquals(
            [$asset, $asset1],
            $asserts
        );
    }
}
