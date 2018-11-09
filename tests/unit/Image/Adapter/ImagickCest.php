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

class ImagickTest
{
    /**
     * executed before each test
     */
    public function _before(UnitTester $I, $scenario)
    {
        if (!class_exists('imagick')) {
            $scenario->skip('Warning: imagick extension is not loaded');
        }
    }

    /**
     * Tests create a new image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickSave(UnitTester $I)
    {
        $image = new Imagick(PATH_OUTPUT . 'tests/image/imagick/new.jpg', 100, 100);
        $image->setResourceLimit(6, 1);
        $image->save();

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('new.jpg');
        $I->deleteFile('new.jpg');
    }

    /**
     * Tests resize image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickResize(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);

        // Resize to 200 pixels on the shortest side
        $image->resize(200, 200)->save(PATH_OUTPUT . 'tests/image/imagick/resize.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('resize.jpg');

        expect($image->getWidth() <= 200)->true();
        expect($image->getHeight() <= 200)->true();

        $I->deleteFile('resize.jpg');
    }

    /**
     * Tests liquid rescaling
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickLiquidRescale(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);

        // Resize to 200 pixels on the shortest side
        $image->liquidRescale(200, 200)->save(PATH_OUTPUT . 'tests/image/imagick/liquidRescale.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('liquidRescale.jpg');

        expect($image->getWidth() == 200)->true();
        expect($image->getHeight() == 200)->true();

        $I->deleteFile('liquidRescale.jpg');
    }

    /**
     * Tests crop image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickCrop(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);

        // Crop the image to 200x200 pixels, from the center
        $image->crop(200, 200)->save(PATH_OUTPUT . 'tests/image/imagick/crop.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('crop.jpg');

        expect($image->getWidth() == 200)->true();
        expect($image->getHeight() == 200)->true();

        $I->deleteFile('crop.jpg');
    }

    /**
     * Tests rotate image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickRotate(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);

        // Rotate 45 degrees clockwise
        $image->rotate(45)->save(PATH_OUTPUT . 'tests/image/imagick/rotate.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('rotate.jpg');

        expect($image->getWidth() > 200)->true();
        expect($image->getHeight() > 200)->true();

        $I->deleteFile('rotate.jpg');
    }

    /**
     * Tests flip image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickFlip(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);

        // Flip the image from top to bottom
        $image->flip(Image::HORIZONTAL)->save(PATH_OUTPUT . 'tests/image/imagick/flip.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('flip.jpg');

        expect($image->getWidth() > 200)->true();
        expect($image->getHeight() > 200)->true();

        $I->deleteFile('flip.jpg');
    }

    /**
     * Tests sharpen image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickSharpen(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);

        // Sharpen the image by 20%
        $image->sharpen(20)->save(PATH_OUTPUT . 'tests/image/imagick/sharpen.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('sharpen.jpg');

        expect($image->getWidth() > 200)->true();
        expect($image->getHeight() > 200)->true();

        $I->deleteFile('sharpen.jpg');
    }

    /**
     * Tests reflection image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickReflection(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);

        // Create a 50 pixel reflection that fades from 0-100% opacity
        $image->reflection(50)->save(PATH_OUTPUT . 'tests/image/imagick/reflection.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('reflection.jpg');

        expect($image->getWidth() > 200)->true();
        expect($image->getHeight() > 200)->true();

        $I->deleteFile('reflection.jpg');
    }

    /**
     * Tests watermark
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickWatermark(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);
        $mark = new Imagick(PATH_DATA . 'assets/logo.png');

        // Add a watermark to the bottom right of the image
        $image->watermark($mark, true, true)->save(PATH_OUTPUT . 'tests/image/imagick/watermark.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('watermark.jpg');

        expect($image->getWidth() > 200)->true();
        expect($image->getHeight() > 200)->true();

        $I->deleteFile('watermark.jpg');
    }

    /**
     * Tests mask
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testImagickMask(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);
        $mask = new Imagick(PATH_DATA . 'assets/logo.png');

        // Add a watermark to the bottom right of the image
        $image->mask($mask)->save(PATH_OUTPUT . 'tests/image/imagick/mask.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('mask.jpg');

        expect($image->getWidth() > 200)->true();
        expect($image->getHeight() > 200)->true();

        $I->deleteFile('mask.jpg');
    }

    /**
     * Tests background
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testImagickBackground(UnitTester $I)
    {
        $image = new Imagick(PATH_DATA . 'assets/phalconphp.jpg');
        $image->setResourceLimit(6, 1);

        // Add a watermark to the bottom right of the image
        $image->background('#000')->save(PATH_OUTPUT . 'tests/image/imagick/background.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
        $I->seeFileFound('background.jpg');

        expect($image->getWidth() > 200)->true();
        expect($image->getHeight() > 200)->true();

        $I->deleteFile('background.jpg');
    }
}
