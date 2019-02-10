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

namespace Phalcon\Test\Unit\Image\Adapter;

use UnitTester;

/**
 * Class GetImageCest
 */
class GetImageCest
{
    /**
     * Tests Phalcon\Image\Adapter :: getImage()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function imageAdapterGetImage(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter - getImage()');
        $I->skipTest('Need implementation');
    }
}
