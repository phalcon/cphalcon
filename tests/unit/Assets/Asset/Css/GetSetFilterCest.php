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

namespace Phalcon\Tests\Unit\Assets\Asset\Css;

use Codeception\Example;
use Phalcon\Assets\Asset\Css;
use UnitTester;

/**
 * Class GetSetFilterCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Css
 */
class GetSetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getFilter()/setFilter()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetCssGetSetFilter(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Css - getFilter()/setFilter()');

        $asset  = new Css($example['path'], $example['local']);
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
                'path'  => 'css/docs.css',
                'local' => true,
            ],
            [
                'path'  => 'https://phalcon.ld/css/docs.css',
                'local' => false,
            ],
        ];
    }
}
