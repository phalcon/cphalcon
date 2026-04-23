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

use Phalcon\Assets\Asset;
use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Asset\Js;
use Phalcon\Assets\AssetInterface;
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class CollectionAssetsByTypeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function testAssetsManagerCollectionAssetsByType(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $assets  = [
            new Css('/scripts/style1.css'),
            new Css('/scripts/style2.css'),
            new Css('/scripts/style3.css'),
            new Js('/scripts/js1.css'),
            new Js('/scripts/js2.css'),
        ];

        $filtered = $manager->collectionAssetsByType($assets, 'css');

        $expected = 3;
        $actual   = count($filtered);
        $this->assertSame($expected, $actual);

        foreach ($filtered as $asset) {
            $class  = Css::class;
            $actual = $asset;
            $this->assertInstanceOf($class, $actual);
            $class = Asset::class;
            $this->assertInstanceOf($class, $actual);
            $class = AssetInterface::class;
            $this->assertInstanceOf($class, $actual);
        }
    }
}
