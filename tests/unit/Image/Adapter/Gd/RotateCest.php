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

namespace Phalcon\Tests\Unit\Image\Adapter\Gd;

use Codeception\Example;
use Phalcon\Image\Adapter\Gd;
use Phalcon\Image\Exception;
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

class RotateCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: rotate()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @return void
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function imageAdapterGdRotate(UnitTester $I, Example $example)
    {
        $type    = $example['label'];
        $degrees = $example['degrees'];
        $hash    = $example['hash'];

        $I->wantToTest(
            'Image\Adapter\Gd - rotate() - ' . $type . ' - ' . $degrees
        );

        $this->checkJpegSupport($I);
        $images    = $this->getImages();
        $outputDir = 'tests/image/gd';
        $imagePath = $images[$type];

        $resultImage = 'rotate-' . $degrees . '.' . $type;
        $output      = outputDir($outputDir . '/' . $resultImage);

        $image = new Gd($imagePath);

        $image->rotate($degrees)
              ->save($output)
        ;

        $I->amInPath(outputDir($outputDir));
        $I->seeFileFound($resultImage);

        $actual = $this->checkImageHash($output, $hash);
        $I->assertTrue($actual);

        $I->safeDeleteFile($output);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
//            [
//                'label'   => 'gif',
//                'degrees' => 0,
//                'hash'    => 'ffffffffffffffff',
//            ],
//            [
//                'label'   => 'gif',
//                'degrees' => 45,
//                'hash'    => '387cfeff7f3f1e0c',
//            ],
//            [
//                'label'   => 'gif',
//                'degrees' => 90,
//                'hash'    => 'ffffffffffffffff',
//            ],
//            [
//                'label'   => 'gif',
//                'degrees' => 180,
//                'hash'    => 'ffffffffffffffff',
//            ],
//            [
//                'label'   => 'gif',
//                'degrees' => 270,
//                'hash'    => 'ffffffffffffffff',
//            ],
            [
                'label'   => 'jpg',
                'degrees' => 0,
                'hash'    => 'fbf9f3e3c3c18183',
            ],
            [
                'label'   => 'jpg',
                'degrees' => 45,
                'hash'    => '60f0f83c1c0f0f06',
            ],
            [
                'label'   => 'jpg',
                'degrees' => 90,
                'hash'    => 'ff3f0f0703009dff',
            ],
            [
                'label'   => 'jpg',
                'degrees' => 180,
                'hash'    => 'c18183c3c7cf9fdf',
            ],
            [
                'label'   => 'jpg',
                'degrees' => 270,
                'hash'    => 'ffb900c0e0f0fcff',
            ],
            [
                'label'   => 'png',
                'degrees' => 0,
                'hash'    => '30787c3c1e181818',
            ],
            [
                'label'   => 'png',
                'degrees' => 45,
                'hash'    => '001c1c1c7c3c0000',
            ],
            [
                'label'   => 'png',
                'degrees' => 90,
                'hash'    => '00060ffffe1c1000',
            ],
            [
                'label'   => 'png',
                'degrees' => 180,
                'hash'    => '181818783c3e1e0c',
            ],
            [
                'label'   => 'png',
                'degrees' => 270,
                'hash'    => '0008387ffff06000',
            ],
//            [
//                'label'   => 'wbmp',
//                'degrees' => 0,
//                'hash'    => '00c78ffe78030200',
//            ],
//            [
//                'label'   => 'wbmp',
//                'degrees' => 45,
//                'hash'    => 'fff71b198fc1e9f3',
//            ],
//            [
//                'label'   => 'wbmp',
//                'degrees' => 90,
//                'hash'    => '0e1a18181c0e6e26',
//            ],
//            [
//                'label'   => 'wbmp',
//                'degrees' => 180,
//                'hash'    => '0040c01e7ff1e302',
//            ],
//            [
//                'label'   => 'wbmp',
//                'degrees' => 270,
//                'hash'    => '647670381818d870',
//            ],
//            [
//                'label'   => 'webp',
//                'degrees' => 0,
//                'hash'    => '670640183c3c7cfc',
//            ],
//            [
//                'label'   => 'webp',
//                'degrees' => 45,
//                'hash'    => '1018c4fe7f3a1000',
//            ],
//            [
//                'label'   => 'webp',
//                'degrees' => 90,
//                'hash'    => '00c4f1f8f8f30301',
//            ],
//            [
//                'label'   => 'webp',
//                'degrees' => 180,
//                'hash'    => '3f3e3c3c180260e4',
//            ],
//            [
//                'label'   => 'webp',
//                'degrees' => 270,
//                'hash'    => '80c0cf1f1f8fa301',
//            ],
        ];
    }
}
