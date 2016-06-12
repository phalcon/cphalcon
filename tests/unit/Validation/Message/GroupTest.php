<?php

namespace Phalcon\Test\Unit\Validation\Message;

use Phalcon\Validation\Message;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Validation\Message\Group;

/**
 * \Phalcon\Test\Unit\Validation\Message\GroupTest
 * Tests the \Phalcon\Validation\Message\Group component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Validation\Message
 * @group     validation
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class GroupTest extends UnitTest
{
    /**
     * Tests append messages
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-06-12
     */
    public function testValidationGroup()
    {
        $this->specify(
            'The Message Group does not work with Messages as expected',
            function () {
                $message1 = new Message('This a message #1', 'field1', 'Type1');
                $message2 = new Message('This a message #2', 'field2', 'Type2');
                $message3 = new Message('This a message #3', 'field3', 'Type3');

                $messages = new Group([$message1, $message2]);

                expect($messages)->count(2);

                expect(isset($messages[0]))->true();
                expect(isset($messages[1]))->true();

                expect($messages[0])->equals($message1);
                expect($messages[1])->equals($message2);

                $messages->appendMessage($message3);

                expect($messages[2])->equals($message3);

                expect($messages)->count(3);

                foreach ($messages as $position => $message) {
                    expect($messages[$position]->getMessage())->equals($message->getMessage());
                    expect($messages[$position]->getField())->equals($message->getField());
                    expect($messages[$position]->getType())->equals($message->getType());
                }
            }
        );
    }
}
