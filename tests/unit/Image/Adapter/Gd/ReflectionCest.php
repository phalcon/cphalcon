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

class ReflectionCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: reflection()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdReflection(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - reflection()');

        $params = [
            'gif'  => [
                [100, 75, false, 'ffffffffffffffff'],
                [100, 75, true, 'ffffffffffffffff'],
                [60, 40, false, 'f7f7f7ffffffffff'],
                [60, 40, true, 'f7f7f7ffffffffff'],
            ],
            'jpg'  => [
                [100, 75, false, 'fbfbf7c3c3c18383'],
                [100, 75, true, 'fbfbf7c3c3c18383'],
                [60, 40, false, 'fbfbf3e3c3c38303'],
                [60, 40, true, 'fbfbf3e3c3c38303'],
            ],
            'png'  => [
                [10, 75, false, '30787c3e1f381800'],
                [10, 75, true, '30787c3e1f381800'],
                [30, 40, false, '307c3c1f38180010'],
                [30, 40, true, '307c3c1f38180018'],
            ],
            'wbmp' => [
                [10, 75, false, '008ffffe382c0000'],
                [10, 75, true, '008ffffe382c0000'],
                [30, 40, false, '81c7fffc38050005'],
                [30, 40, true, '81c7fffc38050005'],
            ],
            'webp' => [
                [10, 75, false, 'c702001c3c3c3cf8'],
                [10, 75, true, 'c702001c3c3c3cf8'],
                [30, 40, false, '070240183c3c3c7a'],
                [30, 40, true, '070240183c3c3c7a'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as [$height, $opacity, $fade, $hash]) {
                $resultImage = 'reflection-' . $height . '-' . $opacity . '-' . ((int) $fade) . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->reflection($height, $opacity, $fade)
                      ->save($output)
                ;

                $I->amInPath(outputDir($outputDir));
                $I->seeFileFound($resultImage);

                $actual = $this->checkImageHash($output, $hash);
                $I->assertTrue($actual);

                $I->safeDeleteFile($output);
            }
        }
    }
}
