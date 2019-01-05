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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use UnitTester;

/**
 * Class ExistsCest
 */
class ExistsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: exists()
     *
     * @param UnitTester $I
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

        $actual = $assets->exists('css');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: exists() - empty
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerExistsEmpty(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - exists() - empty');
        $assets = new Manager();

        $actual = $assets->exists('some-non-existent-collection');
        $I->assertFalse($actual);
    }
}
