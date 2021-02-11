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

namespace Phalcon\Test\Unit\Messages\Message;

use InvalidArgumentException;
use Phalcon\Messages\Message;
use TypeError;
use UnitTester;

use function substr;

class ConstructCest
{
    /**
     * Tests Phalcon\Messages\Message :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function messagesMessageConstruct(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - __construct()');

        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111
        );

        $I->assertEquals(
            'This is a message #1',
            $message->getMessage()
        );

        $I->assertEquals(
            'MyField',
            $message->getField()
        );

        $I->assertEquals(
            'MyType',
            $message->getType()
        );

        $I->assertEquals(
            111,
            $message->getCode()
        );
    }

    /**
     * Tests Phalcon\Messages\Message :: __construct() - chain
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function messagesMessageConstructChain(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - __construct() - chain');

        $message = new Message('This is a message #1');

        $message
            ->setField('MyField')
            ->setType('MyType')
            ->setCode(111)
        ;

        $I->assertEquals(
            'This is a message #1',
            $message->getMessage()
        );

        $I->assertEquals(
            'MyField',
            $message->getField()
        );

        $I->assertEquals(
            'MyType',
            $message->getType()
        );

        $I->assertEquals(
            111,
            $message->getCode()
        );
    }

    /**
     * Tests Phalcon\Messages\Message :: __construct() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function messagesMessageConstructException(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - __construct() - exception');

        /**
         * Sometimes Travis reports 'boolean' vs 'bool' and the test fails. This
         * is why `expectThrowable` is not used here
         */
        $actual = '';

        try {
            (new Message(true));
            // 7.4 - TypeError, 8.0 - InvalidArgumentException
        } catch (TypeError | InvalidArgumentException $ex) {
            $actual = $ex->getMessage();
        }

        $I->assertEquals(
            'Argument 1 passed to Phalcon\Messages\Message::__construct() must be of the type string, bool',
            substr($actual, 0, 93)
        );
    }
}
