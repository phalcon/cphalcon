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
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Form;

class GetCest
{
    /**
     * Tests Phalcon\Forms\Form :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-05
     */
    public function formsFormGet(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - get()');

        $form = new Form();

        $address   = new Text('address');
        $telephone = new Text('telephone');

        $form->add($address);
        $form->add($telephone);

        $expected = $address;
        $actual   = $form->get("address");
        $I->assertSame($expected, $actual);

        $expected = $telephone;
        $actual   = $form->get("telephone");
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Forms\Form :: get() non-existent element
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-05
     */
    public function formsFormGetNonexistentElement(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - get() non-existent element');

        $form = new Form();

        $I->expectThrowable(
            new Exception('Element with ID=address is not part of the form'),
            function () use ($form) {
                $loginForm = $form->get('address');
            }
        );
    }
}
