<?php

namespace Phalcon\Test\Unit\Image\Adapter;

use Phalcon\Image;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Image\Adapter\Imagick;

/**
 * \Phalcon\Test\Unit\Image\Adapter\ImagickTest
 * Tests the \Phalcon\Image\Adapter\Imagick component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Image\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ImagickTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        if (!class_exists('imagick')) {
            $this->markTestSkipped('Warning: imagick extension is not loaded');
        }
    }

    /**
     * Tests create a new image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickSave()
    {
        $this->specify(
            "Imagick::save does not create a new image",
            function () {
                $I = $this->tester;

                $image = new Imagick(PATH_OUTPUT . 'tests/image/imagick/new.jpg', 100, 100);
                $image->setResourceLimit(6, 1);
                $image->save();

                $I->amInPath(PATH_OUTPUT . 'tests/image/imagick/');
                $I->seeFileFound('new.jpg');
                $I->deleteFile('new.jpg');
            }
        );
    }

    /**
     * Tests resize image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickResize()
    {
        $this->specify(
            "Imagick::resize does not resize image correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests liquid rescaling
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickLiquidRescale()
    {
        $this->specify(
            "Imagick::liquidRescale does not resize image correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests crop image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickCrop()
    {
        $this->specify(
            "Imagick::crop does not crop image correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests rotate image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickRotate()
    {
        $this->specify(
            "Imagick::rotate does not rotate image correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests flip image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickFlip()
    {
        $this->specify(
            "Imagick::flip does not flip image correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests sharpen image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickSharpen()
    {
        $this->specify(
            "Imagick::sharpen does not sharpe image correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests reflection image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickReflection()
    {
        $this->specify(
            "Imagick::reflection does not reflect image correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests watermark
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testImagickWatermark()
    {
        $this->specify(
            "Imagick::watermark does not create watermark correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests mask
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testImagickMask()
    {
        $this->specify(
            "Imagick::mask does not create mask correctly",
            function () {
                $I = $this->tester;

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
        );
    }

    /**
     * Tests background
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testImagickBackground()
    {
        $this->specify(
            "Imagick::background does not create background correctly",
            function () {
                $I = $this->tester;

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
        );
    }
}
