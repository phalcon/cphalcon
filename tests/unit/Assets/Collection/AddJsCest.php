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

class AddJsCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addJs()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionAddJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addJs()');

        $collection = new Collection();

        $collection->addJs(
            'js/jquery.css'
        );

        $collection->addJs(
            'https://assets.phalcon.io/phalcon/js/core.js'
        );

        foreach ($collection as $asset) {
            $I->assertEquals(
                'js',
                $asset->getType()
            );
        }

        $I->assertCount(2, $collection);
    }
}
