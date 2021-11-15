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
use Codeception\Stub;
use Phalcon\Assets\Asset;
use UnitTester;

use function dataDir;

/**
 * Class GetRealTargetPathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - css local
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetRealTargetPath(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath()');

        $asset = new Asset($example['type'], $example['path'], $example['local']);

        $expected = $example['path'];
        $actual   = $asset->getRealTargetPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - css local 404
     *
     * @param UnitTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetRealTargetPath404(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - css local 404');


        $file = 'assets/assets/1198.css';
        /** @var Asset $asset */
        $asset = Stub::construct(
            Asset::class,
            [
                'css',
                $file,
            ],
            [
                'phpFileExists' => true,
            ]
        );

        $expected = dataDir($file);
        $actual   = $asset->getRealTargetPath(dataDir());
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    protected function provider(): array
    {
        return [
            [
                'type'  => 'css',
                'path'  => 'css/docs.css',
                'local' => true,
            ],
            [
                'type'  => 'js',
                'path'  => 'js/jquery.js',
                'local' => true,
            ],
            [
                'type'  => 'css',
                'path'  => 'https://phalcon.ld/css/docs.css',
                'local' => false,
            ],
            [
                'type'  => 'js',
                'path'  => 'https://phalcon.ld/js/jquery.js',
                'local' => false,
            ],
        ];
    }
}
