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

use Phalcon\Image\Adapter\Gd;
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

class RotateCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: rotate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdRotate(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - rotate()');

        $this->checkJpegSupport($I);

        $params = [
            'jpg' => [
                [0, 'fbf9f3e3c3c18183'],
                [45, '60f0f83c1c0f0f06'],
                [90, 'ff3f0f0703009dff'],
                [180, 'c18183c3c7cf9fdf'],
                [270, 'ffb900c0e0f0fcff'],
            ],
            'png' => [
                [0, '30787c3c1e181818'],
                [45, '001c1c1c7c3c0000'],
                [90, '00060ffffe1c1000'],
                [180, '181818783c3e1e0c'],
                [270, '0008387ffff06000'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as [$degrees, $hash]) {
                $resultImage = 'rotate-' . $degrees . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->rotate($degrees)->save($output);

                $I->amInPath(
                    outputDir($outputDir)
                );

                $I->seeFileFound($resultImage);

                $I->assertTrue(
                    $this->checkImageHash($output, $hash)
                );

                $I->safeDeleteFile($output);
            }
        }
    }
}
