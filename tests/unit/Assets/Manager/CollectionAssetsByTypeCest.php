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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Asset;
use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Asset\Js;
use Phalcon\Assets\AssetInterface;
use Phalcon\Assets\Manager;
use UnitTester;

class CollectionAssetsByTypeCest
{
    /**
     * Tests Phalcon\Assets\Manager :: collectionAssetsByType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerCollectionAssetsByType(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - collectionAssetsByType()');

        $manager = new Manager();
        $assets  = [
            new Css('/scripts/style1.css'),
            new Css('/scripts/style2.css'),
            new Css('/scripts/style3.css'),
            new Js('/scripts/js1.css'),
            new Js('/scripts/js2.css'),
        ];

        $filtered = $manager->collectionAssetsByType($assets, 'css');
        $I->assertCount(3, $filtered);
        foreach ($filtered as $asset) {
            $I->assertInstanceOf(Css::class, $asset);
            $I->assertInstanceOf(Asset::class, $asset);
            $I->assertInstanceOf(AssetInterface::class, $asset);
        }
    }
}
