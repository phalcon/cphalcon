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

use Phalcon\Flash\Direct;
use Phalcon\Flash\Exception;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class OutputMessageTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
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

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testFlashDirectOutputMessage(string $type): void
    {
        $flash = new Direct(new Escaper());
        $flash->setImplicitFlush(false);

        $source   = 'sample <phalcon> message';
        $expected = '<div class="' . $type . 'Message">'
            . 'sample &lt;phalcon&gt; message</div>' . PHP_EOL;
        $actual   = $flash->outputMessage($type, $source);
        $this->assertSame($expected, $actual);

        $actual = $flash->message($type, $source);
        $this->assertSame($expected, $actual);

        $actual = $flash->$type($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashDirectOutputMessageException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'The message must be an array or a string'
        );

        $flash = new Direct(new Escaper());
        $flash->outputMessage('success', false);
    }
}
