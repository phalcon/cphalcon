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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Image\Enum;
use Phalcon\Test\Fixtures\Traits\GdTrait;
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
            'jpg' => [
                [Enum::HORIZONTAL, 'df9fcfc7c38381c1'],
                [Enum::VERTICAL, '8381c1c3e3f3f9fb'],
            ],
            'png' => [
                [Enum::HORIZONTAL, '0c1e3e3c78181818'],
                [Enum::VERTICAL, '1818181e3c7c7830'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as [$direction, $hash]) {
                $resultImage = 'flip-' . $direction . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->flip($direction)->save($output);

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
