<?php

namespace Phalcon\Test\Unit\Forms;

use Phalcon\Forms\Form;
use Phalcon\Forms\Element\Text;
use Phalcon\Validation\Message;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\Validator\Regex;

/**
 * \Phalcon\Test\Unit\Forms\FormTest
 * Tests the \Phalcon\Forms\Form component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FormTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
        parent::_after();
    }

    /**
     * Tests Form::hasMessagesFor
     *
     * @author Sid Roberts <Sid@SidRoberts.co.uk>
     * @since  2016-04-03
     */
    public function testFormHasMessagesFor()
    {
        $this->specify('Form::hasMessagesFor does not check correctly if the Group is empty', function () {
            // First element
            $telephone = new Text('telephone');

            $telephone->addValidators([
                new Regex([
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format'
                ])
            ]);

            // Second element
            $address = new Text('address');
            $form = new Form();

            $form->add($telephone);
            $form->add($address);

            expect($form->isValid(['telephone' => '12345', 'address' => 'hello']))->false();

            expect($form->getMessagesFor('telephone'))->equals(
                Group::__set_state([
                    '_messages' => [
                        Message::__set_state([
                            '_type'    => 'Regex',
                            '_message' => 'The telephone has an invalid format',
                            '_field'   => 'telephone',
                            '_code'    => 0,
                        ])
                    ],
                ])
            );

            expect($form->getMessagesFor('address'))->equals(Group::__set_state(['_messages' => []]));
            expect($form->hasMessagesFor('telephone'))->true();
            expect($form->hasMessagesFor('address'))->false();

        });
    }
}
