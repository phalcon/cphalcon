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

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset :: __construct() - local
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetConstructLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - local');

        $asset  = new Asset($example['type'], $example['path']);
        $actual = $asset->isLocal();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - remote
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetConstructRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - remote');

        $asset  = new Asset($example['type'], $example['path'], false);
        $actual = $asset->isLocal();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - filter
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetConstructFilter(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');

        $asset = new Asset($example['type'], $example['path']);

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - filter set
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
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

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - attributes
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetConstructAttributes(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes');

        $asset = new Asset($example['type'], $example['path']);

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - attributes set
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
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

        $actual = $asset->getAttributes();
        $I->assertEquals($attributes, $actual);
    }

    /**
     * @return string[][]
     */
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
