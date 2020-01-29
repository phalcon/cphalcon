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

namespace Phalcon\Test\Integration\Forms\Element\Select;

use IntegrationTester;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Form;

class GetSetFormCest
{
    /**
     * Tests Phalcon\Forms\Element\Select :: getForm() / setForm()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-25
     */
    public function formsElementSelectGetSetForm(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Select - getForm() / setForm()');

        $address = new Select('address');

        $form = new Form();

        $address->setForm($form);

        $I->assertSame(
            $form,
            $address->getForm()
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Select :: getForm() / setForm()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-25
     */
    public function formsElementSelectGetSetFormViaForm(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Select - getForm() / setForm()');

        $address = new Select('address');

        $form = new Form();

        $form->add($address);

        $I->assertSame(
            $form,
            $address->getForm()
        );
    }
}
