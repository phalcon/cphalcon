<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Numericality;

/**
 * \Phalcon\Test\Unit\Validation\Validator\NumericalityTest
 * Tests the \Phalcon\Validation\Validator\Numericality component
 *
 * @copyright (c) 2011-2018 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @author    Andrey Izman <izmanw@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class NumericalityTest extends UnitTest
{
    /**
     * Tests numericality validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @author Andrey Izman <izmanw@gmail.com>
     * @since  2016-06-05
     */
    public function testSingleField()
    {
        $this->specify('Test numericality validator with single field.', function () {
            $validation = new Validation();
            $validation->add('amount', new Numericality());
            $messages = $validation->validate(['amount' => 123]);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['amount' => 123.12]);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['amount' => '123abc']);
            expect($messages->count())->equals(1);
            $messages = $validation->validate(['amount' => '123.12e3']);
            expect($messages->count())->equals(1);
        });
    }

    /**
     * Tests numericality validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testMultipleField()
    {
        $this->specify('Test numericality validator with multiple field', function () {
            $validation = new Validation();
            $validationMessages = [
                'amount' => 'Amount must be digit.',
                'price' => 'Price must be digit.',
            ];
            $validation->add(['amount', 'price'], new Numericality([
                'message' => $validationMessages,
            ]));
            $messages = $validation->validate(['amount'=>123, 'price' => 123]);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['amount'=>'123abc', 'price' => 123]);
            expect($messages->count())->equals(1);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['amount']);
            $messages = $validation->validate(['amount'=>'123abc', 'price' => '123abc']);
            expect($messages->count())->equals(2);
            expect($messages->offsetGet(0)->getMessage())->equals($validationMessages['amount']);
            expect($messages->offsetGet(1)->getMessage())->equals($validationMessages['price']);
        });
    }

    /**
     * Set locale
     *
     * @param string $locale
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

    /**
     * Tests numericality validator for custom locales
     *
     * @link https://github.com/phalcon/cphalcon/issues/13450
     *
     * @author Andrey Izman <izmanw@gmail.com>
     * @since  2018-08-08
     */
    public function testLocales()
    {
        $this->specify('Test numericality validator with custom locales.', function () {
            $validation = new Validation();
            $validation->add('amount', new Numericality());

            // get default locale
            $locale = setlocale(LC_ALL, 0);

            $this->setTestLocale('en_US.UTF8');

            $messages = $validation->validate(['amount' => 123.12]);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['amount' => '123.12']);
            expect($messages->count())->equals(0);
            $messages = $validation->validate(['amount' => '123,12']);
            expect($messages->count())->equals(1);

            $this->setTestLocale('fr_FR.UTF8');

            $messages = $validation->validate(['amount' => 123.12]);
            expect($messages->count())->equals(0);

            // revert back locale
            $this->setTestLocale($locale);
        });
    }
}
