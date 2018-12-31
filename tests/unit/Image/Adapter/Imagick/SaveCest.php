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
use function outputFolder;

/**
 * Class SaveCest
 */
class SaveCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: save()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-02-19
     */
    public function imageAdapterImagickSave(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - save()');
        $image = new Imagick(outputFolder('tests/image/imagick/new.jpg'), 100, 100);
        $image->setResourceLimit(6, 1);
        $image->save();

        $I->amInPath(outputFolder('tests/image/imagick/'));
        $I->seeFileFound('new.jpg');
        $I->safeDeleteFile('new.jpg');
    }
}
