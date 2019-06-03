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
use UnitTester;

class GetMimeCest
{
    /**
     * Tests Phalcon\Image\Adapter\Gd :: getMime()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetMimeImageJpeg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getMime() - image/jpg');

        $gd = new Gd(dataDir('assets/images/phalconphp.jpg'));

        $I->assertSame(
            'image/jpeg',
            $gd->getMime()
        );
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getMime()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetMimeImagePng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getMime() - image/png');

        $gd = new Gd(dataDir('assets/images/logo.png'));

        $I->assertSame(
            'image/png',
            $gd->getMime()
        );
    }
}
