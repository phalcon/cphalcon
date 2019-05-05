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

class BackgroundCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: background()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-02-19
     */
    public function imageAdapterImagickBackground(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - background()');
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
