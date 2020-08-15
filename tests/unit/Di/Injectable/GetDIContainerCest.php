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

use Phalcon\Di;
use InjectableComponent;
use stdClass;
use UnitTester;

class GetDIDefaultCest
{
    /**
     * Unit Tests Phalcon\Di\Injectable :: getDI()
     *
     * Test when an Injectable object has no DI set and a call has been made to getDI(), should set the container property.
     * It's tested with the Controller class
     *
     * @author Stijn Leenknegt <stijn@diagro.be>
     * @since  2020-08-13
     */
    public function diInjectableGetDIContainer(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getDI()');

        require_once dataDir('fixtures/Di/InjectableComponent.php');
        Di::reset();
        $di = new Di();
        $di->set('std', function () {
            return new stdClass();
        });
        
        $ic = new InjectableComponent(); //no DI is set in this Injectable object
        $std = $ic->std; //calls __get which calls getDI() method, which should set the container to the default DI
        
        try {
            $className = get_class($ic);
            $reflection = new \ReflectionClass($className);
        } catch (\ReflectionException $e) {
        }
        
        $prop = $reflection->getProperty('container');
        $prop->setAccessible(true);
        
        $I->assertEquals($di, $prop->getValue($ic));
    }
    
    /**
     * Unit Tests Phalcon\Di\Injectable :: getDI()
     *
     * Test when an Injectable object has set an other DI.
     * Setting the container to the default DI, should not happen!
     *
     * @author Stijn Leenknegt <stijn@diagro.be>
     * @since  2020-08-13
     */
    public function diInjectableGetDIOtherContainer(UnitTester $I)
    {
        $I->wantToTest('Di\Injectable - getDI()');

        require_once dataDir('fixtures/Di/InjectableComponent.php');
        Di::reset();
        $di = new Di();
        $other = new Di();
        $other->set('std', function () {
            return new stdClass();
        });
        
        $ic = new InjectableComponent(); //no DI is set in this Injectable object
        $ic->setDI($other);
        $std = $ic->std; //calls __get which calls getDI() method, which should not set the container to the default DI!
        
        try {
            $className = get_class($ic);
            $reflection = new \ReflectionClass($className);
        } catch (\ReflectionException $e) {
        }
        
        $prop = $reflection->getProperty('container');
        $prop->setAccessible(true);
        
        $I->assertEquals($other, $prop->getValue($ic));
        $I->assertNotEquals($di, $prop->getValue($ic));
    }
}
