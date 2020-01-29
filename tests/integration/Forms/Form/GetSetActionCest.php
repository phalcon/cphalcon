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

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Form;
use Phalcon\Test\Fixtures\Forms\SetActionForm;

class GetSetActionCest
{
    /**
     * Tests Phalcon\Forms\Form :: getAction() / setAction()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-11
     */
    public function formsFormGetSetAction(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getAction() / setAction()');

        $form = new Form();

        // empty action
        $I->assertSame(
            '',
            $form->getAction()
        );

        // set an action
        $form->setAction('/some-url');

        $I->assertSame(
            '/some-url',
            $form->getAction()
        );

        // clean action
        $form->setAction('');

        $I->assertSame(
            '',
            $form->getAction()
        );
    }

    /**
     * Tests Phalcon\Forms\Form :: getAction() / setAction() - initialize
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-11
     */
    public function formsFormGetSetActionInitialize(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getAction() / setAction() - initialize');

        $form = new SetActionForm();

        $I->assertSame(
            '/users/login',
            $form->getAction()
        );
    }
}
