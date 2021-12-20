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

namespace Phalcon\Tests\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Forms\Form;

class GetSetDICest
{
    /**
     * Tests Phalcon\Forms\Form :: getDI()/setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-12-16
     */
    public function formsFormGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getDI()/setDI()');

        $container = new Di();
        $form      = new Form();

        $class  = FactoryDefault::class;
        $actual = $form->getDI();
        $I->assertInstanceOf($class, $actual);

        $form->setDI($container);

        $expected = $container;
        $actual   = $form->getDI();
        $I->assertSame($expected, $actual);
    }
}
