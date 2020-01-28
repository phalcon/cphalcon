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

class HasCest
{
    /**
     * Tests Phalcon\Assets\Collection :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsCollectionHas(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - has()');

        $collection = new Collection();

        $asset1 = new Asset('js', 'js/jquery.js');
        $asset2 = new Asset('js', 'js/jquery-ui.js');

        $collection->add($asset1);

        $I->assertTrue(
            $collection->has($asset1)
        );

        $I->assertFalse(
            $collection->has($asset2)
        );
    }
}
