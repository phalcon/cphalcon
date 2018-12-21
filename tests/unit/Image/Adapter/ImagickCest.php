<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image\Adapter;

use Phalcon\Image;
use Phalcon\Image\Adapter\Imagick;
use UnitTester;
use function dataFolder;
use function outputFolder;

class ImagickCest
{
    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('imagick');
    }

    /**
     * Tests create a new image
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickSave(UnitTester $I)
    {
        $image = new Imagick(outputFolder('tests/image/imagick/new.jpg'), 100, 100);
        $image->setResourceLimit(6, 1);
        $image->save();

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('new.jpg');
        $I->safeDeleteFile('new.jpg');
    }

    /**
     * Tests resize image
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickResize(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);

        // Resize to 200 pixels on the shortest side
        $image->resize(200, 200)->save(outputFolder('tests/image/imagick/resize.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('resize.jpg');

        $actual = $image->getWidth() <= 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() <= 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('resize.jpg');
    }

    /**
     * Tests liquid rescaling
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickLiquidRescale(UnitTester $I)
    {
        $I->skipTest('TODO: Check library error');
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);

        // Resize to 200 pixels on the shortest side
        $image->liquidRescale(200, 200)->save(outputFolder('tests/image/imagick/liquidRescale.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('liquidRescale.jpg');

        $actual = $image->getWidth() == 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() == 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('liquidRescale.jpg');
    }

    /**
     * Tests crop image
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickCrop(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);

        // Crop the image to 200x200 pixels, from the center
        $image->crop(200, 200)->save(outputFolder('tests/image/imagick/crop.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('crop.jpg');

        $actual = $image->getWidth() == 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() == 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('crop.jpg');
    }

    /**
     * Tests rotate image
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickRotate(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);

        // Rotate 45 degrees clockwise
        $image->rotate(45)->save(outputFolder('tests/image/imagick/rotate.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('rotate.jpg');

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('rotate.jpg');
    }

    /**
     * Tests flip image
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickFlip(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);

        // Flip the image from top to bottom
        $image->flip(Image::HORIZONTAL)->save(outputFolder('tests/image/imagick/flip.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('flip.jpg');

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('flip.jpg');
    }

    /**
     * Tests sharpen image
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickSharpen(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);

        // Sharpen the image by 20%
        $image->sharpen(20)->save(outputFolder('tests/image/imagick/sharpen.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('sharpen.jpg');

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('sharpen.jpg');
    }

    /**
     * Tests reflection image
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickReflection(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);

        // Create a 50 pixel reflection that fades from 0-100% opacity
        $image->reflection(50)->save(outputFolder('tests/image/imagick/reflection.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('reflection.jpg');

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('reflection.jpg');
    }

    /**
     * Tests watermark
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickWatermark(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);
        $mark = new Imagick(dataFolder('assets/images/logo.png'));

        // Add a watermark to the bottom right of the image
        $image->watermark($mark, true, true)->save(outputFolder('tests/image/imagick/watermark.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('watermark.jpg');

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('watermark.jpg');
    }

    /**
     * Tests mask
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-02-19
     */
    public function testImagickMask(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);
        $mask = new Imagick(dataFolder('assets/images/logo.png'));

        // Add a watermark to the bottom right of the image
        $image->mask($mask)->save(outputFolder('tests/image/imagick/mask.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('mask.jpg');

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('mask.jpg');
    }

    /**
     * Tests background
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-02-19
     */
    public function testImagickBackground(UnitTester $I)
    {
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);

        // Add a watermark to the bottom right of the image
        $image->background('#000')->save(outputFolder('tests/image/imagick/background.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('background.jpg');

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('background.jpg');
    }
}
