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
 * Class GetSetFilterCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class GetSetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getFilter()/setFilter()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetSetFilter(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getFilter()/setFilter()');

        $asset  = new Asset($example['type'], $example['path']);
        $actual = $asset->getFilter();
        $I->assertTrue($actual);

        $asset->setFilter(false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * @return array[]
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
