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

class AddCest
{
    /**
     * Tests Phalcon\Assets\Collection :: add()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsCollectionAdd(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - add()');

        $collection = new Collection();

        $collection->add(
            new Asset('js', 'js/jquery.js')
        );

        $collection->add(
            new Asset('js', 'js/jquery-ui.js')
        );

        foreach ($collection as $asset) {
            $I->assertEquals(
                'js',
                $asset->getType()
            );
        }

        $I->assertCount(2, $collection);
    }

    /**
     * Tests Phalcon\Assets\Collection :: add() - duplicate
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10938
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-02
     */
    public function assetsCollectionAddDuplicate(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - add() - duplicate');

        $collection = new Collection();

        for ($i = 0; $i < 10; $i++) {
            $collection->add(
                new Asset('js', 'js/jquery.js')
            );

            $collection->add(
                new Asset('js', 'js/jquery-ui.js')
            );
        }

        $I->assertCount(
            2,
            $collection->getAssets()
        );
    }
}
