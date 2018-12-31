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

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Test\Fixtures\Traits\ImagickTrait;
use UnitTester;
use function dataFolder;
use function outputFolder;

/**
 * Class WatermarkCest
 */
class WatermarkCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: watermark()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-02-19
     */
    public function imageAdapterImagickWatermark(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - watermark()');
        $image = new Imagick(dataFolder('assets/images/phalconphp.jpg'));
        $image->setResourceLimit(6, 1);
        $mark = new Imagick(dataFolder('assets/images/logo.png'));

        // Add a watermark to the bottom right of the image
        $image->watermark($mark, 10, 10)->save(outputFolder('tests/image/imagick/watermark.jpg'));

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('watermark.jpg');

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->safeDeleteFile('watermark.jpg');
    }
}
