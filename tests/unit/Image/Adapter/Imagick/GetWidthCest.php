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

use UnitTester;

class GetWidthCest
{
    /**
     * Unit Tests Phalcon\Image\Adapter\Imagick :: getWidth()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function imageAdapterImagickGetWidth(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - getWidth()');

        $I->skipTest('Need implementation');
    }
}
