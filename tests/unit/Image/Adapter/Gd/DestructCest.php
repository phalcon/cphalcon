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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class DestructCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: __destruct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdDestruct(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - __destruct()');

        foreach ($this->getImages() as $image) {
            $gd = new Gd($image);

            $I->assertInstanceOf(
                Gd::class,
                $gd
            );

            $gd->__destruct();

            $I->assertFalse(is_resource($gd->getImage()));
        }
    }
}
