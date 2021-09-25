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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Manager;
use UnitTester;

class AddAssetByTypeCest
{
    /**
     * Tests Phalcon\Assets\Manager :: addAssetByType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerAddAssetByType(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addAssetByType()');

        $assets = new Manager();

        $assets->addAssetByType(
            "css",
            new Css('/css/style1.css')
        );

        $assets->addAssetByType(
            "css",
            new Css('/css/style2.css')
        );


        $collection = $assets->get('css');

        foreach ($collection as $resource) {
            $I->assertEquals(
                'css',
                $resource->getType()
            );
        }

        $I->assertCount(2, $collection);
    }
}
