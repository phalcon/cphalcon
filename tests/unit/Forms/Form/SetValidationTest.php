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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetValidationTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/12465
     * @author Mohamad Rostami <rostami@outlook.com>
     */
    public function testCustomValidation(): void
    {
        // First element
        $telephone = new Text('telephone');

        $customValidation = new Validation();

        $customValidation->add(
            'telephone',
            new Regex(
                [
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format',
                ]
            )
        );

        $form    = new Form();
        $address = new Text('address');

        $form->add($telephone);
        $form->add($address);

        $form->setValidation($customValidation);


        $actual = $form->isValid(
            [
                'telephone' => '12345',
                'address'   => 'hello',
            ]
        );

        $this->assertFalse($actual);


        $actual = $form->get('telephone')->hasMessages();

        $this->assertTrue($actual);


        $actual = $form->get('address')->hasMessages();

        $this->assertFalse($actual);


        $expected = new Messages(
            [
                new Message(
                    'The telephone has an invalid format',
                    'telephone',
                    Regex::class,
                    0
                ),
            ]
        );

        $actual = $form->get('telephone')->getMessages();

        $this->assertEquals($expected, $actual);


        $expected = $form->getMessages();
        $actual   = $form->get('telephone')->getMessages();

        $this->assertEquals($expected, $actual);


        $expected = new Messages();
        $actual   = $form->get('address')->getMessages();

        $this->assertEquals($expected, $actual);
    }
}
