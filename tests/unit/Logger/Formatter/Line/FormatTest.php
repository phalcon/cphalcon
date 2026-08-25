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

namespace Phalcon\Tests\Unit\Logger\Formatter\Line;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Item;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

use function date_default_timezone_get;
use function uniqid;

final class FormatTest extends AbstractUnitTestCase
{
    /**
     * @return array<int, array<int, string>>
     */
    public static function getControlCharacterExamples(): array
    {
        return [
            ["\x00", '\\x00'],
            ["\x08", '\\x08'],
            ["\x0B", '\\x0B'],
            ["\x1B", '\\x1B'],
            ["\x1F", '\\x1F'],
            ["\x7F", '\\x7F'],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterLineFormat(): void
    {
        $timezone  = date_default_timezone_get();
        $datetime  = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $formatter = new Line();
        $item      = new Item(
            'log message',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $expected = sprintf(
            '[%s][debug] log message',
            $datetime->format('c')
        );
        $actual   = $formatter->format($item);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterLineFormatCustom(): void
    {
        $formatter = new Line('%message%-[%level%]-%date%');
        $timezone  = date_default_timezone_get();
        $datetime  = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item      = new Item(
            'log message',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $expected = sprintf(
            'log message-[debug]-%s',
            $datetime->format('c')
        );
        $actual   = $formatter->format($item);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-09-11
     */
    public function testLoggerFormatterLineFormatCustomInterpolator(): void
    {
        $formatter = new Line(
            '%message%-[%level%]-%date%-%server%:%user%',
            'U.u'
        );

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $context  = [
            'server' => uniqid('srv-'),
            'user'   => uniqid('usr-'),
        ];
        $item     = new Item(
            'log message',
            'debug',
            Enum::DEBUG,
            $datetime,
            $context
        );

        $expected = sprintf(
            'log message-[debug]-%s-%s:%s',
            $datetime->format('U.u'),
            $context['server'],
            $context['user']
        );
        $actual   = $formatter->format($item);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterLineFormatCustomWithMilliseconds(): void
    {
        $formatter = new Line(
            '%message%-[%level%]-%date%',
            'U.u'
        );

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item     = new Item(
            'log message',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $result = $formatter->format($item);
        $parts  = explode('-', $result);
        $parts  = explode('.', $parts[2]);

        $expected = 2;
        $actual   = $parts;
        $this->assertCount($expected, $actual);

        $expected = 0;
        $actual   = (int)$parts[0];
        $this->assertGreaterThan($expected, $actual);

        $expected = 0;
        $actual   = (int)$parts[1];
        $this->assertGreaterThan($expected, $actual);
    }

    /**
     * Each C0 control character, and DEL, becomes its \xNN escape.
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2026-08-25
     */
    #[DataProvider('getControlCharacterExamples')]
    public function testLoggerFormatterLineFormatEscapesControlCharacterRange(
        string $character,
        string $escaped
    ): void {
        $timezone  = date_default_timezone_get();
        $datetime  = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $formatter = new Line('%message%');
        $item      = new Item(
            'a' . $character . 'b',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $expected = 'a' . $escaped . 'b';
        $actual   = $formatter->format($item);
        $this->assertSame($expected, $actual);
    }

    /**
     * A message or context value carrying CR/LF must not forge extra log
     * lines (CWE-117); control characters are escaped, tab is preserved.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testLoggerFormatterLineFormatEscapesControlCharacters(): void
    {
        $timezone  = date_default_timezone_get();
        $datetime  = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $formatter = new Line('%message%');
        $item      = new Item(
            "hello\r\nCRITICAL forged\tkeep",
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $actual = $formatter->format($item);

        // No raw newline survives to start a forged line.
        $this->assertStringNotContainsString("\n", $actual);
        $this->assertStringNotContainsString("\r", $actual);
        // The control bytes are escaped visibly; tab is kept.
        $this->assertSame('hello\x0D\x0ACRITICAL forged' . "\t" . 'keep', $actual);
    }

    /**
     * A control character that arrives through a context value is escaped
     * after interpolation, not before it.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testLoggerFormatterLineFormatEscapesControlCharactersFromContext(): void
    {
        $timezone  = date_default_timezone_get();
        $datetime  = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $formatter = new Line('%message%');
        $item      = new Item(
            'user %name%',
            'debug',
            Enum::DEBUG,
            $datetime,
            ['name' => "a\x0Ab"]
        );

        $actual = $formatter->format($item);

        // The context value cannot forge a second log line.
        $this->assertStringNotContainsString("\n", $actual);
        $this->assertSame('user a\\x0Ab', $actual);
    }
}
