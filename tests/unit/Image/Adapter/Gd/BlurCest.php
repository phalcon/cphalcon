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

class BlurCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: blur()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdBlur(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - blur()');

        $this->checkJpegSupport($I);

        $params = [
            'jpg' => [
                [1, 'fbf9f3e3c3c18183'],
                [2, 'fbf9f3e3c3c18183'],
                [5, 'fbf9f3e3c3c18183'],
            ],
            'png' => [
                [1, '30787c3c1e1c1818'],
                [2, '30787c3c3e181818'],
                [5, '30787c3c3e181818'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as [$level, $hash]) {
                $resultImage = 'blur-' . $level . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->blur($level)->save($output);

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
