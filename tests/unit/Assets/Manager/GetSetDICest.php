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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Di;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
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

        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->setDI($container);

        $I->assertSame($container, $manager->getDI());
    }
}
