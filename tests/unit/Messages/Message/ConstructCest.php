<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Messages\Message;

use Phalcon\Messages\Message;
use TypeError;
use UnitTester;
use function substr;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Messages\Message :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessageConstruct(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - __construct()');
        $message = new Message('This is a message #1', 'MyField', 'MyType', 111);

        $expected = 'This is a message #1';
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = 'MyField';
        $actual   = $message->getField();
        $I->assertEquals($expected, $actual);

        $expected = 'MyType';
        $actual   = $message->getType();
        $I->assertEquals($expected, $actual);

        $expected = 111;
        $actual   = $message->getCode();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Messages\Message :: __construct() - chain
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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

        $expected = 'This is a message #1';
        $actual   = $message->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = 'MyField';
        $actual   = $message->getField();
        $I->assertEquals($expected, $actual);

        $expected = 'MyType';
        $actual   = $message->getType();
        $I->assertEquals($expected, $actual);

        $expected = 111;
        $actual   = $message->getCode();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Messages\Message :: __construct() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
        } catch (TypeError $ex) {
            $actual = $ex->getMessage();
        }

        $expected = 'Argument 1 passed to Phalcon\Messages\Message::__construct() '
            . 'must be of the type string, bool';
        $actual   = substr($actual, 0, 93);
        $I->assertEquals($expected, $actual);
    }
}
