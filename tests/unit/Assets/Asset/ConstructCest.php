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

namespace Phalcon\Tests\Unit\Assets\Asset;

use Codeception\Example;
use Phalcon\Assets\Asset;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset :: __construct() - local
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetConstructLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - local');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - remote
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetConstructRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - remote');

        $asset = new Asset(
            $example['type'],
            $example['path'],
            false
        );

        $I->assertFalse(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - filter
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetConstructFilter(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - filter set
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetConstructFilterSet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter set');

        $asset = new Asset(
            $example['type'],
            $example['path'],
            true,
            false
        );

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - attributes
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetConstructAttributes(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $I->assertEquals(
            [],
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - attributes set
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetConstructAttributesSet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Asset(
            $example['type'],
            $example['path'],
            true,
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

    protected function provider(): array
    {
        return [
            [
                'type' => 'css',
                'path' => 'css/docs.css',
            ],
            [
                'type' => 'js',
                'path' => 'js/jquery.js',
            ],
        ];
    }
}
