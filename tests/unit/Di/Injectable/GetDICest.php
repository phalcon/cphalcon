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

namespace Phalcon\Test\Unit\Di\Injectable;

use InjectableComponent;
use Phalcon\Di;
use stdClass;
use UnitTester;

class GetDICest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: getDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diInjectableGetDI(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getDI()');

        require_once dataDir('fixtures/Di/InjectableComponent.php');
        Di::reset();
        $di = new Di();
        // Injection of parameters in the constructor
        $di->set('std', function () {
            return new stdClass();
        });
        $di->set('component', InjectableComponent::class);
        $component = $di->get('component');
        $I->assertEquals($di, $component->getDI());
        $stdObject = $component->std;
        $I->assertEquals($stdObject, $component->std);
    }
}
