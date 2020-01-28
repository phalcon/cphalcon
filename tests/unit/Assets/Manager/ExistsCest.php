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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use UnitTester;

class ExistsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: exists()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerExists(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - exists()');

        $assets = new Manager();

        $assets->addCss('/css/style1.css');
        $assets->addCss('/css/style2.css');

        $I->assertTrue(
            $assets->exists('css')
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: exists() - empty
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerExistsEmpty(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - exists() - empty');

        $assets = new Manager();

        $I->assertFalse(
            $assets->exists('some-non-existent-collection')
        );
    }
}
