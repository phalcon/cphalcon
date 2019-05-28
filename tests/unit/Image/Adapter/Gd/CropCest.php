<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class CropCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: crop()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdCropJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - crop()');

        $image = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $outputDir = 'tests/image/gd';
        $width     = 200;
        $height    = 200;
        $cropImage = 'crop.jpg';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $hash      = '7f7f7b571f1f1f7f';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height)->save(outputDir($outputDir . '/' . $cropImage));

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($cropImage);

        $I->assertSame(
            $width,
            $image->getWidth()
        );

        $I->assertSame(
            $height,
            $image->getHeight()
        );

        $I->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $I->safeDeleteFile($cropImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: crop()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdCropJpgWithOffset(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - crop()');

        $image = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $outputDir = 'tests/image/gd';
        $width     = 200;
        $height    = 200;
        $offsetX   = 200;
        $offsetY   = 200;
        $cropImage = 'crop.jpg';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $hash       = 'fffff00000000000';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height, $offsetX, $offsetY)->save($output);

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($cropImage);

        $I->assertSame(
            $width,
            $image->getWidth(),
            'Checking width'
        );

        $I->assertSame(
            $height,
            $image->getHeight(),
            'Checking height'
        );

        $I->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $I->safeDeleteFile($cropImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: crop()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdCropPng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - crop() - png image');

        $image = new Gd(
            dataDir('assets/images/logo.png')
        );

        $outputDir = 'tests/image/gd';
        $width     = 40;
        $height    = 40;
        $cropImage = 'crop.png';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $hash       = '0203273b3f1f0f0f';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height)->save(outputDir($outputDir . '/' . $cropImage));

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($cropImage);

        $I->assertSame(
            $width,
            $image->getWidth(),
            'Checking width'
        );

        $I->assertSame(
            $height,
            $image->getHeight(),
            'Checking height'
        );

        $I->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $I->safeDeleteFile($cropImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: crop()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdCropPngWithOffset(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - crop() - png with offset');

        $image = new Gd(
            dataDir('assets/images/logo.png')
        );

        $outputDir = 'tests/image/gd';
        $width     = 42;
        $height    = 42;
        $offsetX   = 25;
        $offsetY   = 25;
        $cropImage = 'crop.png';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $hash       = '0cc6f07f3f3cf838';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height, $offsetX, $offsetY)->save($output);

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($cropImage);

        $I->assertSame(
            $width,
            $image->getWidth(),
            'Checking width'
        );

        $I->assertSame(
            $height,
            $image->getHeight(),
            'Checking height'
        );

        $I->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $I->safeDeleteFile($cropImage);
    }
}
