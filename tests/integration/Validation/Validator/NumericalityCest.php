<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator;

use IntegrationTester;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Numericality;

class NumericalityCest
{
    /**
     * Tests numericality validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Andrey Izman <izmanw@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorSingleField(IntegrationTester $I)
    {
        $validation = new Validation();
        $validation->add('amount', new Numericality());
        $messages = $validation->validate(['amount' => 123]);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => 123.12]);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123abc']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123.12e3']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests numericality validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorMultipleField(IntegrationTester $I)
    {
        $validation         = new Validation();
        $validationMessages = [
            'amount' => 'Amount must be digit.',
            'price'  => 'Price must be digit.',
        ];
        $validation->add(
            [
                'amount',
                'price',
            ],
            new Numericality(
                [
                    'message' => $validationMessages,
                ]
            )
        );
        $messages = $validation->validate(['amount' => 123, 'price' => 123]);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123abc', 'price' => 123]);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123abc', 'price' => '123abc']);
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['amount'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['price'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests numericality validator for custom locales
     *
     * @link   https://github.com/phalcon/cphalcon/issues/13450
     *
     * @author Andrey Izman <izmanw@gmail.com>
     * @since  2018-08-08
     */
    public function validationValidatorLocales(IntegrationTester $I)
    {
        $validation = new Validation();
        $validation->add('amount', new Numericality());

        // get default locale
        $locale = setlocale(LC_ALL, 0);
        $this->setTestLocale('en_US.UTF8');

        $messages = $validation->validate(['amount' => 123.12]);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123.12']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['amount' => '123,12']);
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $this->setTestLocale('fr_FR.UTF8');

        $messages = $validation->validate(['amount' => 123.12]);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        // revert back locale
        $this->setTestLocale($locale);
    }

    /**
     * Set locale
     *
     * @param string $locale
     *
     * @return string
     *
     * @author Andrey Izman <izmanw@gmail.com>
     * @since  2018-08-08
     */
    protected function setTestLocale($locale)
    {
        putenv('LC_ALL=' . $locale);
        putenv('LANG=' . $locale);
        putenv('LANGUAGE=' . $locale);
        return setlocale(LC_ALL, $locale);
    }
}
