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

namespace Phalcon\Test\Unit\Assets\Collection;

use Phalcon\Assets\Asset;
use Phalcon\Assets\Collection;
use UnitTester;

class CurrentCest
{
    /**
     * Tests Phalcon\Assets\Collection :: current()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionCurrent(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - current()');

        $collection = new Collection();

        $asset = new Asset('js', 'js/jquery.js');

        $collection->add(
            $asset
        );

        $asset1 = new Asset('js', 'js/jquery-ui.js');

        $collection->add(
            $asset1
        );
        
        // ERROR TO FIX IN PHALCON Undefined index:  in phalcon/Assets/Collection.zep on line 261
        $I->assertEquals($asset, $collection->current());

        $collection->next();

        $I->assertEquals($asset1, $collection->current());
    }
}
