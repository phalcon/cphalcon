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

use Phalcon\Assets\Collection;
use UnitTester;

class AddCssCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addCss()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionAddCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addCss()');

        $collection = new Collection();

        $collection->addCss(
            'css/docs.css'
        );

        $collection->addCss(
            'https://assets.phalcon.io/phalcon/css/core.css'
        );

        foreach ($collection as $asset) {
            $I->assertEquals(
                'css',
                $asset->getType()
            );
        }

        $I->assertCount(2, $collection);
    }
}
