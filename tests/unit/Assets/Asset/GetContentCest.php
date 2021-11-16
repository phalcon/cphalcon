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
use function file_get_contents;

use const PHP_EOL;

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

        $expected = file_get_contents(dataDir($example['path']));
        $expected = str_replace("\r\n", PHP_EOL, $expected);
        $actual   = $asset->getContent(dataDir());
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getContent() - exception 404
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetGetContentException404(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getContent() - exception 404');

        $file    = 'assets/assets/1198.css';
        $message = "Asset's content for '" . dataDir($file) . "' cannot be read";
        $I->expectThrowable(
            new Exception($message),
            function () use ($file) {
                /** @var Asset $asset */
                $asset = Stub::construct(
                    Asset::class,
                    [
                        'css',
                        $file,
                    ],
                    [
                        'phpFileExists' => false,
                    ]
                );

                $data = $asset->getContent(dataDir());
            }
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getContent() - exception cannot read file
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetGetContentExceptionCannotReadFile(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getContent() - exception cannot read file');

        $file    = 'assets/assets/1198.css';
        $message = "Asset's content for '" . dataDir($file) . "' cannot be read";
        $I->expectThrowable(
            new Exception($message),
            function () use ($file) {
                /** @var Asset $asset */
                $asset = Stub::construct(
                    Asset::class,
                    [
                        'css',
                        $file,
                    ],
                    [
                        'phpFileGetContents' => false,
                    ]
                );

                $data = $asset->getContent(dataDir());
            }
        );
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
