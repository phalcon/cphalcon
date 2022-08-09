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

namespace Phalcon\Tests\Unit\Image\Adapter\Imagick;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Image\Exception;
use UnitTester;

use function dataDir;

class SetResourceLimitCest
{
    /**
     * Unit Tests Phalcon\Image\Adapter\Imagick :: setResourceLimit() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function imageAdapterImagickSetResourceLimitException(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - setResourceLimit() - exception');

        $I->expectThrowable(
            new Exception('Cannot set the Resource Type for this image'),
            function () {
                $source = dataDir('assets/images/example-jpg.jpg');
                $image  = new Imagick($source);

                $image->setResourceLimit(100, 1);
            }
        );
    }
}
