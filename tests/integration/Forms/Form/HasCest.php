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
use Phalcon\Forms\Form;

class HasCest
{
    /**
     * Tests Phalcon\Forms\Form :: has()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsFormHas(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - has()');

        $form = new Form();

        $address   = new Text('address');
        $telephone = new Text('telephone');

        $form->add($address);

        $I->assertTrue(
            $form->has('address')
        );

        $I->assertFalse(
            $form->has('telephone')
        );
    }
}
