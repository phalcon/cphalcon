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

namespace Phalcon\Test\Integration\Forms\Element\Password;

use IntegrationTester;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Form;

class GetSetFormCest
{
    /**
     * Tests Phalcon\Forms\Element\Password :: getForm() / setForm()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-25
     */
    public function formsElementPasswordGetSetForm(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Password - getForm() / setForm()');

        $address = new Password('address');

        $form = new Form();

        $address->setForm($form);

        $I->assertSame(
            $form,
            $address->getForm()
        );
    }

    /**
     * Tests Phalcon\Forms\Element\Password :: getForm() / setForm()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-25
     */
    public function formsElementPasswordGetSetFormViaForm(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Password - getForm() / setForm()');

        $address = new Password('address');

        $form = new Form();

        $form->add($address);

        $I->assertSame(
            $form,
            $address->getForm()
        );
    }
}
