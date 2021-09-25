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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Codeception\Example;
use Phalcon\Flash\Direct;
use Phalcon\Flash\Exception;
use Phalcon\Html\Escaper;
use UnitTester;

use const PHP_EOL;

/**
 * Class OutputMessageCest
 *
 * @package Phalcon\Tests\Unit\Flash\Direct
 */
class OutputMessageCest
{
    /**
     * Tests Phalcon\Flash\Direct :: outputMessage() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectOutputMessageException(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - outputMessage() - exception');

        $I->expectThrowable(
            new Exception('The message must be an array or a string'),
            function () {
                $flash   = new Direct(new Escaper());
                $message = $flash->outputMessage('success', false);
            }
        );
    }

    /**
     * Tests Phalcon\Flash\Direct :: outputMessage() - exception
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function flashDirectOutputMessage(UnitTester $I, Example $example)
    {
        $I->wantToTest('Flash\Direct - outputMessage() - ' . $example[0]);

        $flash = new Direct(new Escaper());
        $flash->setImplicitFlush(false);

        $source   = 'sample <phalcon> message';
        $type     = $example[0];
        $expected = '<div class="' . $type . 'Message">'
            . 'sample &lt;phalcon&gt; message</div>' . PHP_EOL;
        $actual   = $flash->outputMessage($type, $source);
        $I->assertEquals($expected, $actual);

        $actual = $flash->message($type, $source);
        $I->assertEquals($expected, $actual);

        $actual = $flash->$type($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'error',
            ],
            [
                'notice',
            ],
            [
                'success',
            ],
            [
                'warning',
            ],
        ];
    }
}
