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

namespace Phalcon\Tests\Unit\Di\Injectable;

use Phalcon\Di\Di;
use Phalcon\Tests\Fixtures\Di\InjectableComponent;
use UnitTester;

/**
 * Class GetSetDICest
 *
 * @package Phalcon\Tests\Unit\Di\Injectable
 */
class GetSetDICest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: getDI()/setDI()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diInjectableGetDI(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getDI()/setDI()');

        Di::reset();
        $container = new Di();
        $component = new InjectableComponent();
        $component->setDI($container);

        $actual = $component->getDI();
        $I->assertEquals($container, $actual);
    }

    /**
     * Unit Tests Phalcon\Di\Injectable :: getDI()/setDI() - constructor
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diInjectableGetDIConstructor(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getDI()/setDI()');

        Di::reset();
        $container = new Di();
        $container->set('component', InjectableComponent::class);
        $component = $container->get('component');
        $actual    = $component->getDI();
        $I->assertEquals($container, $actual);
    }
}
