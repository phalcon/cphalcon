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
use Phalcon\Di;
use UnitTester;

class GetSetDICest
{
    /**
     * Unit Tests Phalcon\Assets\Manager :: getDI() / setDI()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-28
     */
    public function assetsManagerGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - getDI() / setDI()');

        $container = new Di();

        $manager = new Manager();

        $manager->setDI($container);

        $I->assertSame(
            $container,
            $manager->getDI()
        );
    }
}
