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
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class SaveCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: save()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdSave(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - save()');

        $this->checkJpegSupport($I);

        $outputDir   = 'tests/image/gd';
        $resultImage = 'save.';

        foreach ($this->getImages() as $type => $imagePath) {
            $image = new Gd(
                $imagePath
            );

            $output = outputDir($outputDir . '/' . $resultImage . $type);

            $actual = $image->save($output);

            $I->assertInstanceOf(Gd::class, $actual);

            $I->amInPath(
                outputDir($outputDir)
            );

            $I->seeFileFound($resultImage . $type);

            $I->safeDeleteFile($resultImage . $type);
        }
    }
}
