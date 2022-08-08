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
use Phalcon\Image\Enum;
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

class FlipCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: flip()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdFlip(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - flip()');

        $params = [
            'gif'  => [
                [4, 'ffffffffdfffffff'], // Unknown direction: revert to HORIZONTAL
                [Enum::HORIZONTAL, 'ffffffffdfffffff'],
                [Enum::VERTICAL, 'fffffffbffffffff'],
            ],
            'jpg'  => [
                [Enum::HORIZONTAL, 'df9fcfc7c38381c1'],
                [Enum::VERTICAL, '8381c1c3e3f3f9fb'],
            ],
            'png'  => [
                [Enum::HORIZONTAL, '0c1e3e3c78181818'],
                [Enum::VERTICAL, '1818181e3c7c7830'],
            ],
            'wbmp' => [
                [Enum::HORIZONTAL, '02e3f17f1ec04000'],
                [Enum::VERTICAL, '00020378fe8fc700'],
            ],
            'webp' => [
                [Enum::HORIZONTAL, 'e46002183c3c3e3f'],
                [Enum::VERTICAL, 'fc7c3c3c18400627'],
            ],
            'xmb'  => [
                [Enum::HORIZONTAL, 'e46002183c3c3e3f'],
                [Enum::VERTICAL, 'fc7c3c3c18400627'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as [$direction, $hash]) {
                $resultImage = 'flip-' . $direction . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->flip($direction)
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
