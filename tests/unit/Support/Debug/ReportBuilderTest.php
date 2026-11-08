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

namespace Phalcon\Tests\Unit\Support\Debug;

use LogicException;
use Phalcon\Support\Debug\ReportBuilder;
use Phalcon\Support\Exception;
use Phalcon\Support\Version;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\BackupGlobals;
use RuntimeException;

use function bin2hex;
use function dirname;
use function file_put_contents;
use function random_bytes;
use function unlink;

#[BackupGlobals(true)]
final class ReportBuilderTest extends AbstractUnitTestCase
{
    /**
     * @issue https://github.com/phalcon/cphalcon/issues/17746
     */
    public function testBuildCollectsThePreviousExceptions(): void
    {
        $first  = new RuntimeException('first');
        $second = new LogicException('second', 0, $first);
        $main   = new Exception('main', 0, $second);

        $report = (new ReportBuilder())->build(
            $main,
            ['request' => [], 'server' => []],
            false,
            false,
            false,
            'https://cdn/',
            []
        );

        $this->assertSame(
            [
                [
                    'className' => LogicException::class,
                    'message'   => 'second',
                    'file'      => __FILE__,
                    'line'      => $second->getLine(),
                ],
                [
                    'className' => RuntimeException::class,
                    'message'   => 'first',
                    'file'      => __FILE__,
                    'line'      => $first->getLine(),
                ],
            ],
            $report->getPreviousExceptions()
        );
    }

    public function testBuildFragmentForUnreadableFile(): void
    {
        $builder = new ReportBuilder();

        $method = new \ReflectionMethod(ReportBuilder::class, 'buildFragment');

        $fragment = $method->invoke($builder, '/phalcon/no/such/file.php', 5, false);

        $this->assertSame([], $fragment['lines']);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17733
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testBuildFragmentRaisesNoWarning(): void
    {
        $builder = new ReportBuilder();
        $method  = new \ReflectionMethod(ReportBuilder::class, 'buildFragment');

        $warnings = [];
        set_error_handler(
            static function (int $severity, string $message) use (&$warnings): bool {
                $warnings[] = $message;

                return true;
            }
        );

        try {
            $missing  = $method->invoke($builder, '/phalcon/no/such/file.php', 5, false);
            $evalCode = $method->invoke($builder, __FILE__ . "(10) : eval()'d code", 1, false);
        } finally {
            restore_error_handler();
        }

        $this->assertSame([], $warnings);
        $this->assertSame([], $missing['lines']);
        $this->assertSame([], $evalCode['lines']);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/17746
     */
    public function testEachFileIsReadOnceForEachReport(): void
    {
        $file    = dirname(__DIR__, 3) . '/_output/report-builder-' . bin2hex(random_bytes(4)) . '.php';
        $builder = new ReportBuilder();
        $method  = new \ReflectionMethod(ReportBuilder::class, 'buildFragment');

        file_put_contents($file, "first\n");
        /** @var array{lines: list<string>} $before */
        $before = $method->invoke($builder, $file, 1, false);

        file_put_contents($file, "second\n");
        /** @var array{lines: list<string>} $cached */
        $cached = $method->invoke($builder, $file, 1, false);

        $builder->build(
            new Exception('next report'),
            ['request' => [], 'server' => []],
            false,
            false,
            false,
            'https://cdn/',
            []
        );
        /** @var array{lines: list<string>} $after */
        $after = $method->invoke($builder, $file, 1, false);
        unlink($file);

        $this->assertSame(["first\n"], $before['lines']);
        $this->assertSame(["first\n"], $cached['lines']);
        $this->assertSame(["second\n"], $after['lines']);
    }

    public function testInternalFunctionLinkIsResolved(): void
    {
        $exception = new Exception('placeholder');

        try {
            array_map(
                static function () {
                    throw new Exception('boom', 7);
                },
                [1]
            );
        } catch (Exception $e) {
            $exception = $e;
        }

        $report = (new ReportBuilder())->build(
            $exception,
            ['request' => [], 'server' => []],
            true,
            false,
            false,
            'https://cdn/',
            []
        );

        $found = false;
        foreach ($report->getBacktrace() as $item) {
            $link = $item->getFunctionLink();
            if (null !== $link && str_contains($link, '/function.')) {
                $found = true;
                break;
            }
        }

        $this->assertTrue($found);
    }

    public function testLinkResolution(): void
    {
        $builder = new ReportBuilder();

        $classLink = new \ReflectionMethod(ReportBuilder::class, 'resolveClassLink');
        $version   = new Version();

        $this->assertSame(
            'https://docs.phalcon.io/'
            . $version->getPart(Version::VERSION_MAJOR) . '.'
            . $version->getPart(Version::VERSION_MEDIUM)
            . '/api/phalcon_mvc/',
            $classLink->invoke($builder, 'Phalcon\\Mvc\\Model')
        );
        $this->assertStringContainsString(
            'secure.php.net/manual/en/class.',
            $classLink->invoke($builder, 'ArrayObject')
        );
        $this->assertNull($classLink->invoke($builder, 'PHPUnit\\Framework\\TestCase'));

        $functionLink = new \ReflectionMethod(ReportBuilder::class, 'resolveFunctionLink');

        $this->assertStringContainsString(
            'secure.php.net/manual/en/function.',
            $functionLink->invoke($builder, 'array_map')
        );
        $this->assertNull($functionLink->invoke($builder, 'phalcon_undefined_function_xyz'));
        $this->assertNull($functionLink->invoke($builder, 'supportDir'));
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17733
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testLinkResolutionForGlobalClassWithPhalconPrefix(): void
    {
        if (!class_exists('PhalconHelper', false)) {
            class_alias(self::class, 'PhalconHelper');
        }

        $builder   = new ReportBuilder();
        $classLink = new \ReflectionMethod(ReportBuilder::class, 'resolveClassLink');

        $this->assertNull($classLink->invoke($builder, 'PhalconHelper'));
    }

    public function testMetaWithoutBacktrace(): void
    {
        $exception = new Exception('boom', 7);
        $report    = (new ReportBuilder())->build(
            $exception,
            ['request' => [], 'server' => []],
            false,
            true,
            false,
            'https://cdn/',
            []
        );

        $this->assertSame(Exception::class, $report->getClassName());
        $this->assertSame('boom', $report->getMessage());
        $this->assertSame('https://cdn/', $report->getUri());
        $this->assertSame([], $report->getBacktrace());
    }

    public function testNestedBlacklistIsApplied(): void
    {
        $_REQUEST['user'] = [
            'name'    => 'john',
            'profile' => [
                'city'     => 'athens',
                'PassWord' => 'secret',
            ],
            'Token'   => 'abc',
        ];
        $_SERVER['DATA_SERVER_TEST'] = [
            'API_KEY' => 'hidden',
            'host'    => 'keepme',
        ];

        $report = (new ReportBuilder())->build(
            new Exception('boom', 7),
            [
                'request' => ['password' => 1, 'token' => 1],
                'server'  => ['api_key' => 1],
            ],
            true,
            true,
            false,
            'https://cdn/',
            []
        );

        $expected = [
            'name'    => 'john',
            'profile' => [
                'city' => 'athens',
            ],
        ];
        $this->assertSame($expected, $report->getRequest()['user']);

        $expected = ['host' => 'keepme'];
        $this->assertSame($expected, $report->getServer()['DATA_SERVER_TEST']);
    }

    public function testRequestBlacklistIsApplied(): void
    {
        $_REQUEST['DATA_REQUEST_TEST'] = 'secret';
        $_SERVER['DATA_SERVER_TEST']   = 'keepme';

        $report = (new ReportBuilder())->build(
            new Exception('boom', 7),
            ['request' => ['data_request_test' => 1], 'server' => []],
            true,
            true,
            false,
            'https://cdn/',
            []
        );

        $this->assertArrayNotHasKey('DATA_REQUEST_TEST', $report->getRequest());
        $this->assertArrayHasKey('DATA_SERVER_TEST', $report->getServer());
        $this->assertGreaterThan(0, $report->getMemoryUsage());
        $this->assertGreaterThan(0, $report->getPeakMemoryUsage());
    }
}
