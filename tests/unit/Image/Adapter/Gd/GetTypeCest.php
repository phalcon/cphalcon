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

class GetTypeCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getType()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetTypeJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getType() - from jpg image');

        $gd = new Gd(dataDir('assets/images/phalconphp.jpg'));

        $I->assertSame(
            2,
            $gd->getType()
        );
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getType()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetTypePng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getType() - from png image');

        $gd = new Gd(dataDir('assets/images/logo.png'));

        $I->assertSame(
            3,
            $gd->getType()
        );
    }
}
