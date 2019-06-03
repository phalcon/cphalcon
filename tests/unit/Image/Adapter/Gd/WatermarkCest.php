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

use Phalcon\Image;
use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class WatermarkCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: watermark()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdWatermarkJpgInsideJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - watermark() - jpg inside jpg');

        $image = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $watermark = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );
        $watermark->resize(250, null, Image::WIDTH);

        $outputDir   = 'tests/image/gd';
        $outputImage = 'watermark.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $offsetX     = 200;
        $offsetY     = 200;
        $opacity     = 50;

        $hash = 'fbf9f3e3c3c18183';

        // Resize to 200 pixels on the shortest side
        $image->watermark($watermark, $offsetX, $offsetY, $opacity)->save($output);

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($outputImage);

        $I->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $I->safeDeleteFile($outputImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: watermark()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdWatermarkPngInsideJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - watermark() - png inside jpg');

        $image = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $watermark = new Gd(
            dataDir('assets/images/logo.png')
        );

        $outputDir   = 'tests/image/gd';
        $outputImage = 'watermark.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $offsetX     = 200;
        $offsetY     = 200;

        $hash = 'fbf9f3e3c3c18183';

        $image->watermark($watermark, $offsetX, $offsetY)->save($output);

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($outputImage);

        $I->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $I->safeDeleteFile($outputImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: watermark()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdWatermarkJpgInsidePng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - watermark() - jpg inside png');

        $image = new Gd(
            dataDir('assets/images/logo.png')
        );

        $watermark = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );
        $watermark->resize(50, 50, Image::NONE);

        $outputDir   = 'tests/image/gd';
        $outputImage = 'watermark.png';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $offsetX     = 10;
        $offsetY     = 10;
        $opacity     = 50;

        $hash = '107c7c7c7e1c1818';

        // Resize to 200 pixels on the shortest side
        $image->watermark($watermark, $offsetX, $offsetY, $opacity)->save($output);

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($outputImage);

        $I->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $I->safeDeleteFile($outputImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: watermark()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdWatermarkPngInsidePng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - watermark() - png inside png');

        $image = new Gd(
            dataDir('assets/images/logo.png')
        );

        $watermark = new Gd(
            dataDir('assets/images/logo.png')
        );
        $watermark->resize(null, 30, Image::HEIGHT);

        $outputDir   = 'tests/image/gd';
        $outputImage = 'watermark.png';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $offsetX     = 20;
        $offsetY     = 20;
        $opacity     = 75;

        $hash = '10787c3c3e181818';

        $image->watermark($watermark, $offsetX, $offsetY, $opacity)->save($output);

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($outputImage);

        $I->assertTrue(
            $this->checkImageHash($output, $hash)
        );

        $I->safeDeleteFile($outputImage);
    }
}
