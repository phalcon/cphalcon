<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Tag;

use Error;
use Phalcon\Tag;
use Phalcon\Tag\Exception;
use Phalcon\Tag\Select;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\IgnoreDeprecations;
use stdClass;
use TypeError;

use function restore_error_handler;
use function set_error_handler;

use const PHP_EOL;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/843
 */
final class ParameterTypesTest extends AbstractTagTestCase
{
    private const NOT_STRING = 'Object of class stdClass could not be converted to string';

    /**
     * @return array<string, array{0: string, 1: mixed, 2: string}>
     */
    public static function getHelpers(): array
    {
        return [
            'checkField null'         => ['checkField', null, '<input type="checkbox">'],
            'checkField int'          => ['checkField', 5, '<input type="checkbox" id="5" name="5">'],
            'colorField null'         => ['colorField', null, '<input type="color" id="" name="">'],
            'colorField int'          => ['colorField', 5, '<input type="color" id="5" name="5">'],
            'dateField null'          => ['dateField', null, '<input type="date" id="" name="">'],
            'dateField int'           => ['dateField', 5, '<input type="date" id="5" name="5">'],
            'dateTimeField null'      => ['dateTimeField', null, '<input type="datetime" id="" name="">'],
            'dateTimeField int'       => ['dateTimeField', 5, '<input type="datetime" id="5" name="5">'],
            'dateTimeLocalField null' => [
                'dateTimeLocalField',
                null,
                '<input type="datetime-local" id="" name="">',
            ],
            'dateTimeLocalField int' => [
                'dateTimeLocalField',
                5,
                '<input type="datetime-local" id="5" name="5">',
            ],
            'emailField null'        => ['emailField', null, '<input type="email" id="" name="">'],
            'emailField int'         => ['emailField', 5, '<input type="email" id="5" name="5">'],
            'fileField null'         => ['fileField', null, '<input type="file" id="" name="">'],
            'fileField int'          => ['fileField', 5, '<input type="file" id="5" name="5">'],
            'formLegacy null'        => ['formLegacy', null, '<form method="post">'],
            'formLegacy int'         => ['formLegacy', 5, '<form action="https://phalcon.io/5" method="post">'],
            'hiddenField null'       => ['hiddenField', null, '<input type="hidden" id="" name="">'],
            'hiddenField int'        => ['hiddenField', 5, '<input type="hidden" id="5" name="5">'],
            'image null'             => ['image', null, '<img src="https://phalcon.io/">'],
            'image int'              => ['image', 5, '<img src="https://phalcon.io/5">'],
            'imageInput null'        => ['imageInput', null, '<input type="image">'],
            'imageInput int'         => ['imageInput', 5, '<input type="image" value="5">'],
            'javascriptInclude null' => [
                'javascriptInclude',
                null,
                '<script src="https://phalcon.io/"></script>' . PHP_EOL,
            ],
            'javascriptInclude int' => [
                'javascriptInclude',
                5,
                '<script src="https://phalcon.io/5"></script>' . PHP_EOL,
            ],
            'linkTo null'         => ['linkTo', null, '<a href="https://phalcon.io/"></a>'],
            'linkTo int'          => ['linkTo', 5, '<a href="https://phalcon.io/5"></a>'],
            'monthField null'     => ['monthField', null, '<input type="month" id="" name="">'],
            'monthField int'      => ['monthField', 5, '<input type="month" id="5" name="5">'],
            'numericField null'   => ['numericField', null, '<input type="number" id="" name="">'],
            'numericField int'    => ['numericField', 5, '<input type="number" id="5" name="5">'],
            'passwordField null'  => ['passwordField', null, '<input type="password" id="" name="">'],
            'passwordField int'   => ['passwordField', 5, '<input type="password" id="5" name="5">'],
            'radioField null'     => ['radioField', null, '<input type="radio">'],
            'radioField int'      => ['radioField', 5, '<input type="radio" id="5" name="5">'],
            'rangeField null'     => ['rangeField', null, '<input type="range" id="" name="">'],
            'rangeField int'      => ['rangeField', 5, '<input type="range" id="5" name="5">'],
            'searchField null'    => ['searchField', null, '<input type="search" id="" name="">'],
            'searchField int'     => ['searchField', 5, '<input type="search" id="5" name="5">'],
            'select null'         => ['select', null, '<select id="" name="">' . PHP_EOL . '</select>'],
            'select int'          => ['select', 5, '<select id="5" name="5">' . PHP_EOL . '</select>'],
            'selectStatic null'   => ['selectStatic', null, '<select id="" name="">' . PHP_EOL . '</select>'],
            'selectStatic int'    => ['selectStatic', 5, '<select id="5" name="5">' . PHP_EOL . '</select>'],
            'stylesheetLink null' => [
                'stylesheetLink',
                null,
                '<link rel="stylesheet" type="text/css" href="https://phalcon.io/">' . PHP_EOL,
            ],
            'stylesheetLink int' => [
                'stylesheetLink',
                5,
                '<link rel="stylesheet" type="text/css" href="https://phalcon.io/5">' . PHP_EOL,
            ],
            'submitButton null' => ['submitButton', null, '<input type="submit">'],
            'submitButton int'  => ['submitButton', 5, '<input type="submit" value="5">'],
            'telField null'     => ['telField', null, '<input type="tel" id="" name="">'],
            'telField int'      => ['telField', 5, '<input type="tel" id="5" name="5">'],
            'textArea null'     => ['textArea', null, '<textarea></textarea>'],
            'textArea int'      => ['textArea', 5, '<textarea id="5" name="5"></textarea>'],
            'textField null'    => ['textField', null, '<input type="text" id="" name="">'],
            'textField int'     => ['textField', 5, '<input type="text" id="5" name="5">'],
            'timeField null'    => ['timeField', null, '<input type="time" id="" name="">'],
            'timeField int'     => ['timeField', 5, '<input type="time" id="5" name="5">'],
            'urlField null'     => ['urlField', null, '<input type="url" id="" name="">'],
            'urlField int'      => ['urlField', 5, '<input type="url" id="5" name="5">'],
            'weekField null'    => ['weekField', null, '<input type="week" id="" name="">'],
            'weekField int'     => ['weekField', 5, '<input type="week" id="5" name="5">'],
        ];
    }

    /**
     * @return array<string, array{0: callable, 1: mixed}>
     */
    public static function getNullNames(): array
    {
        return [
            'getValue null' => [
                static function (mixed $value): mixed {
                    Tag::setDefault('5', 'five');
                    $_POST = ['' => 'empty'];

                    return Tag::getValue($value);
                },
                'empty',
            ],
            'hasValue null' => [
                static function (mixed $value): bool {
                    Tag::setDefault('5', 'five');

                    return Tag::hasValue($value);
                },
                false,
            ],
        ];
    }

    /**
     * @return array<string, array{0: string, 1: class-string<Error>, 2: string|null}>
     */
    public static function getObjectHelpers(): array
    {
        return [
            'checkField'   => ['checkField', TypeError::class, null],
            'formLegacy'   => ['formLegacy', Error::class, self::NOT_STRING],
            'imageInput'   => ['imageInput', Error::class, self::NOT_STRING],
            'linkTo'       => ['linkTo', Error::class, self::NOT_STRING],
            'radioField'   => ['radioField', TypeError::class, null],
            'submitButton' => ['submitButton', Error::class, self::NOT_STRING],
            'textArea'     => ['textArea', TypeError::class, null],
        ];
    }

    /**
     * @return array<string, array{0: callable, 1: mixed, 2: mixed}>
     */
    public static function getOthers(): array
    {
        return [
            'appendTitle null' => [
                static function (mixed $value): string {
                    Tag::setTitle('Home');
                    Tag::appendTitle($value);

                    return Tag::getTitle();
                },
                null,
                'Home',
            ],
            'appendTitle int' => [
                static function (mixed $value): string {
                    Tag::setTitle('Home');
                    Tag::appendTitle($value);

                    return Tag::getTitle();
                },
                5,
                'Home5',
            ],
            'friendlyTitle replace false' => [
                static fn (mixed $value): string => Tag::friendlyTitle('Hello World 5', '-', true, $value),
                false,
                'hello-world-5',
            ],
            'getValue int' => [
                static function (mixed $value): mixed {
                    Tag::setDefault('5', 'five');
                    $_POST = ['' => 'empty'];

                    return Tag::getValue($value);
                },
                5,
                'five',
            ],
            'hasValue int' => [
                static function (mixed $value): bool {
                    Tag::setDefault('5', 'five');

                    return Tag::hasValue($value);
                },
                5,
                true,
            ],
            'linkTo local null' => [
                static fn (mixed $value): string => Tag::linkTo('https://example.com/about', 'About', $value),
                null,
                '<a href="https://example.com/about">About</a>',
            ],
            'linkTo local int' => [
                static fn (mixed $value): string => Tag::linkTo('https://example.com/about', 'About', $value),
                5,
                '<a href="https://phalcon.io/https://example.com/about">About</a>',
            ],
            'linkTo text null' => [
                static fn (mixed $value): string => Tag::linkTo('about', $value),
                null,
                '<a href="https://phalcon.io/about"></a>',
            ],
            'linkTo text int' => [
                static fn (mixed $value): string => Tag::linkTo('about', $value),
                5,
                '<a href="https://phalcon.io/about">5</a>',
            ],
            'prependTitle null' => [
                static function (mixed $value): string {
                    Tag::setTitle('Home');
                    Tag::prependTitle($value);

                    return Tag::getTitle();
                },
                null,
                'Home',
            ],
            'prependTitle int' => [
                static function (mixed $value): string {
                    Tag::setTitle('Home');
                    Tag::prependTitle($value);

                    return Tag::getTitle();
                },
                5,
                '5Home',
            ],
            'selectField null' => [
                static fn (mixed $value): string => Select::selectField($value),
                null,
                '<select id="" name="">' . PHP_EOL . '</select>',
            ],
            'selectField int' => [
                static fn (mixed $value): string => Select::selectField($value),
                5,
                '<select id="5" name="5">' . PHP_EOL . '</select>',
            ],
            'tagHtml null' => [
                static fn (mixed $value): string => Tag::tagHtml('div', $value),
                null,
                '<div></div>',
            ],
            'tagHtml int' => [
                static fn (mixed $value): string => Tag::tagHtml('div', $value),
                5,
                '<div></div>',
            ],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    public function testTagDefaultParameters(): void
    {
        $this->assertSame('<img src="https://phalcon.io/">', Tag::image());
        $this->assertSame(
            '<script src="https://phalcon.io/"></script>' . PHP_EOL,
            Tag::javascriptInclude()
        );
        $this->assertSame(
            '<link rel="stylesheet" type="text/css" href="https://phalcon.io/">' . PHP_EOL,
            Tag::stylesheetLink()
        );
        $this->assertSame('<div></div>', Tag::tagHtml('div'));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testTagFriendlyTitleReplaceInt(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Parameter replace must be an array or a string');

        Tag::friendlyTitle('Hello World 5', '-', true, 5);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    public function testTagGetValueObject(): void
    {
        $this->expectException(TypeError::class);

        Tag::getValue(new stdClass());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    #[DataProvider('getHelpers')]
    public function testTagHelpers(string $method, mixed $value, string $expected): void
    {
        $this->assertSame(
            $expected,
            $this->callQuietly(static fn (): string => Tag::$method($value))
        );
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    #[DataProvider('getObjectHelpers')]
    public function testTagHelpersObject(
        string $method,
        string $exception,
        ?string $message
    ): void {
        $this->expectException($exception);
        if (null !== $message) {
            $this->expectExceptionMessage($message);
        }

        $this->callQuietly(static fn (): string => Tag::$method(new stdClass()));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    public function testTagLinkToArrayLocalNull(): void
    {
        $this->assertSame(
            '<a href="https://example.com/about">About</a>',
            Tag::linkTo(['https://example.com/about', 'About', null])
        );
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    public function testTagLinkToLocalObject(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'Phalcon\\Mvc\\Url::get(): Argument #3 ($local) must be of type ?bool, stdClass given'
        );

        Tag::linkTo('about', 'About', new stdClass());
    }

    /**
     * On PHP 8.5 and later, a null name gives the deprecation "Using null as
     * an array offset". cphalcon gives the same deprecation.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getNullNames')]
    #[IgnoreDeprecations]
    public function testTagNullNames(callable $call, mixed $expected): void
    {
        $this->assertSame($expected, $call(null));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    #[DataProvider('getOthers')]
    public function testTagOthers(callable $call, mixed $value, mixed $expected): void
    {
        $this->assertSame($expected, $call($value));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/843
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    public function testTagTextAreaId(): void
    {
        $this->assertSame(
            '<textarea id="comment" name="comment"></textarea>',
            Tag::textArea(['id' => 'comment'])
        );
    }

    /**
     * cphalcon gives warnings for some of these values, for example
     * "Invalid arguments supplied for strpos()"
     */
    private function callQuietly(callable $call): mixed
    {
        set_error_handler(
            static function (): bool {
                return true;
            }
        );

        try {
            return $call();
        } finally {
            restore_error_handler();
        }
    }
}
