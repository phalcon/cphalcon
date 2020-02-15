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

use Phalcon\Assets\Collection;
use UnitTester;

class CountCest
{
    /**
     * Tests Phalcon\Assets\Collection :: count()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionCount(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - count()');

        $collection = new Collection();

        $collection->addCss(
            'css/docs.css'
        );

        $collection->addCss(
            'https://assets.phalcon.io/phalcon/css/core.css'
        );

        $collection->addJs(
            'js/jquery.css'
        );

        $collection->addJs(
            'https://assets.phalcon.io/phalcon/js/core.js'
        );

        $I->assertEquals(
            4,
            $collection->count()
        );
    }
}
