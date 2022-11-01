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

use function uniqid;

class ClearCest
{
    /**
     * Tests Phalcon\Forms\Form :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-01
     */
    public function formsFormGet(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - clear()');

        $store = $_POST ?? [];

        $addressValue = uniqid('add-');
        $address   = new Text('address');
        $address->setDefault($addressValue);

        $expected = $addressValue;
        $actual   = $address->getValue();
        $I->assertSame($expected, $actual);

        $addressValueNew   = uniqid('addn-');

        $form = new Form();
        $form->add($address);

        $_POST = [
            'address' => $addressValueNew,
        ];

        $actual = $form->isValid($_POST);
        $I->assertTrue($actual);

        $expected = $addressValueNew;
        $actual   = $address->getValue();
        $I->assertSame($expected, $actual);

        $form->clear();

        $expected = $addressValue;
        $actual   = $address->getValue();
        $I->assertSame($expected, $actual);
    }
}
