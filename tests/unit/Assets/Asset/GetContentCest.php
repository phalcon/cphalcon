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
use Phalcon\Assets\Exception;
use UnitTester;

use function dataDir;

/**
 * Class GetContentCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getContent()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetContent(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getContent()');

        $asset = new Asset($example['type'], $example['path']);

        $I->openFile(dataDir($example['path']));

        $actual = $asset->getContent(dataDir());
        $I->seeFileContentsEqual($actual);
    }

    /**
     * @return string[][]
     */
    protected function provider(): array
    {
        return [
            [
                'type' => 'css',
                'path' => 'assets/assets/1198.css',
            ],
            [
                'type' => 'js',
                'path' => 'assets/assets/signup.js',
            ],
        ];
    }
}
