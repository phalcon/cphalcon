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

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Test\Fixtures\Traits\ImagickTrait;
use UnitTester;

use function dataDir;
use function outputDir;

class TextCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: text()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function imageAdapterImagickText(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - text()');

        $image = new Imagick(
            dataDir('assets/images/phalconphp.jpg')
        );

        $image->setResourceLimit(6, 1);

        $image->text(
            'Phalcon',
            10,
            10,
            100,
            '000099',
            12,
            dataDir('assets/fonts/Roboto-Thin.ttf')
        )->save(outputDir('tests/image/imagick/text.jpg'))
        ;

        $I->amInPath(
            outputDir('tests/image/imagick/')
        );

        $I->seeFileFound('text.jpg');

        $I->assertEquals(
            1820,
            $image->getWidth()
        );
        $I->assertEquals(
            694,
            $image->getHeight()
        );

        $I->safeDeleteFile('text.jpg');
    }
}
