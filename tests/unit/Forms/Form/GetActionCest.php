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

namespace Phalcon\Test\Unit\Forms\Form;

use Phalcon\Forms\Form;
use UnitTester;

class GetActionCest
{
    /**
     * Tests Phalcon\Forms\Form :: getAction()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-11
     */
    public function formsFormGetAction(UnitTester $I)
    {
        $I->wantToTest('Forms\Form - getAction()');

        $form = new Form();

        // method exists
        $actual = method_exists($form, 'getAction');

        $I->assertTrue($actual);

        // empty action
        $actual = $form->getAction();
        $expected = '';

        $I->assertSame($expected, $actual);

        // set an action
        $form->setAction('/some-url');
        $actual = $form->getAction();
        $expected = '/some-url';

        $I->assertSame($expected, $actual);

        // clean action
        $form->setAction('');
        $actual = $form->getAction();
        $expected = '';

        $I->assertSame($expected, $actual);
    }
}
