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

use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class HasMessagesForTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2016-04-03
     */
    public function testFormHasMessagesFor(): void
    {
        $telephone = new Text('telephone');
        $telephone->addValidators(
            [
                new Regex(
                    [
                        'pattern' => '/\+44 [0-9]+ [0-9]+/',
                        'message' => 'The telephone has an invalid format',
                    ]
                ),
            ]
        );

        $address = new Text('address');
        $form    = new Form();

        $form->add($telephone);
        $form->add($address);

        $actual = $form->isValid(
            [
                'telephone' => '12345',
                'address'   => 'hello',
            ]
        );

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

        $this->assertEquals(
            $expected,
            $form->getMessagesFor('telephone')
        );


        $expected = new Messages();

        $this->assertEquals(
            $expected,
            $form->getMessagesFor('address')
        );


        $this->assertTrue(
            $form->hasMessagesFor('telephone')
        );

        $this->assertFalse(
            $form->hasMessagesFor('address')
        );
    }
}
