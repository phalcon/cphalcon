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

namespace Phalcon\Test\Integration\Forms\Element;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;

/**
 * Class GetFormCest
 */
class GetFormCest
{
    /**
     * Tests Phalcon\Forms\Element :: getForm()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-25
     */
    public function formsElementGetForm(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element - getForm()');

        $address = new Text('address');

        $form = new Form();

        $address->setForm($form);

        $I->assertSame(
            $form,
            $address->getForm()
        );
    }

    /**
     * Tests Phalcon\Forms\Element :: getForm()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-25
     */
    public function formsElementGetFormViaForm(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element - getForm()');

        $address = new Text('address');

        $form = new Form();

        $form->add($address);

        $I->assertSame(
            $form,
            $address->getForm()
        );
    }
}
